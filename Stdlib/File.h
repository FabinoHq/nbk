////////////////////////////////////////////////////////////////////////////////
//              ________           ______________________________________     //
//             // .    /   _______/ . . . . . . . . . . . . . . . . .   /     //
//            // .    /   // . . . .    _______________________________/      //
//           // .     |  //      ______/ \\      |  // .   /_/     __/        //
//          // .      | //    __// .   \_//     /  // .   /     __/           //
//         // .       |//    / // .   _________/  // .       __/              //
//        // .   /|   |/    / // .   /  \\    \  // .        \                //
//       // .   /||        / // .    \__//    / // .   /\     \               //
//      // .   / ||       / //  .            / // .   / \\     \              //
//     //_____/  ||______/  \\______________/ //_____/   \\____/              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//   This is free and unencumbered software released into the public domain.  //
//                                                                            //
//   Anyone is free to copy, modify, publish, use, compile, sell, or          //
//   distribute this software, either in source code form or as a compiled    //
//   binary, for any purpose, commercial or non-commercial, and by any        //
//   means.                                                                   //
//                                                                            //
//   In jurisdictions that recognize copyright laws, the author or authors    //
//   of this software dedicate any and all copyright interest in the          //
//   software to the public domain. We make this dedication for the benefit   //
//   of the public at large and to the detriment of our heirs and             //
//   successors. We intend this dedication to be an overt act of              //
//   relinquishment in perpetuity of all present and future rights to this    //
//   software under copyright law.                                            //
//                                                                            //
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          //
//   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       //
//   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   //
//   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR        //
//   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    //
//   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    //
//   OTHER DEALINGS IN THE SOFTWARE.                                          //
//                                                                            //
//   For more information, please refer to <https://unlicense.org>            //
////////////////////////////////////////////////////////////////////////////////
//    NBK : Network Backend                                                   //
//     Stdlib/File.h : File I/O management                                    //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_STDLIB_FILE_HEADER
#define NBK_STDLIB_FILE_HEADER

    #include "String.h"

    #include <cstddef>
    #include <cstdint>
    #include <cstring>


    #ifdef NBK_WINDOWS

        #include <fcntl.h>
        #include <io.h>
        #include <sys/stat.h>

        #define FILE_OPEN _open
        #define FILE_CLOSE _close
        #define FILE_READ _read
        #define FILE_WRITE _write
        #define FILE_FLUSH _commit

        #define FILE_FLAG_READONLY _O_RDONLY
        #define FILE_FLAG_WRITEONLY _O_WRONLY
        #define FILE_FLAG_CREATE _O_CREAT

        #define FILE_MODE_READ _S_IREAD
        #define FILE_MODE_WRITE _S_IWRITE

    #endif // NBK_WINDOWS
    #ifdef NBK_LINUX

        #include <unistd.h>

        #define FILE_OPEN open
        #define FILE_CLOSE close
        #define FILE_READ read
        #define FILE_WRITE write
        #define FILE_FLUSH fsync

        #define FILE_FLAG_READONLY _O_RDONLY
        #define FILE_FLAG_WRITEONLY _O_WRONLY
        #define FILE_FLAG_CREATE _O_CREAT

        #define FILE_MODE_READ 0
        #define FILE_MODE_WRITE 0

    #endif // NBK_LINUX


    ////////////////////////////////////////////////////////////////////////////
    //  File class definition                                                 //
    ////////////////////////////////////////////////////////////////////////////
    class File
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  File default constructor                                      //
            ////////////////////////////////////////////////////////////////////
            File() :
            m_handle(-1)
            {

            }

            ////////////////////////////////////////////////////////////////////
            //  File destructor                                               //
            ////////////////////////////////////////////////////////////////////
            ~File()
            {
                close();
            }


            ////////////////////////////////////////////////////////////////////
            //  Open file                                                     //
            ////////////////////////////////////////////////////////////////////
            inline bool open(const String& path)
            {
                // Close eventual opened file
                close();

                // Open file
                m_handle = FILE_OPEN(path.str(),
                    (FILE_FLAG_WRITEONLY | FILE_FLAG_CREATE),
                    FILE_MODE_WRITE
                );
                if (m_handle == -1)
                {
                    // Could not open file
                    return false;
                }

                // File sucessfully opened
                return true;
            }

            ////////////////////////////////////////////////////////////////////
            //  Close file                                                    //
            ////////////////////////////////////////////////////////////////////
            inline void close()
            {
                if (m_handle != -1) { FILE_CLOSE(m_handle); }
                m_handle = -1;
            }

            ////////////////////////////////////////////////////////////////////
            //  Flush file I/O                                                //
            ////////////////////////////////////////////////////////////////////
            inline void flush()
            {
                FILE_FLUSH(m_handle);
            }


            ////////////////////////////////////////////////////////////////////
            //  File string left shift operator                               //
            ////////////////////////////////////////////////////////////////////
            inline File& operator<<(String32& string)
            {
                FILE_WRITE(m_handle, string.data(), string.length());
                return *this;
            }
            inline File& operator<<(String256& string)
            {
                FILE_WRITE(m_handle, string.data(), string.length());
                return *this;
            }
            inline File& operator<<(String4096& string)
            {
                FILE_WRITE(m_handle, string.data(), string.length());
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  File character left shift operator                         //
            ////////////////////////////////////////////////////////////////////
            inline File& operator<<(const char character)
            {
                FILE_WRITE(m_handle, &character, 1);
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  File array left shift operator                             //
            ////////////////////////////////////////////////////////////////////
            inline File& operator<<(const char* array)
            {
                FILE_WRITE(m_handle,
                    array, static_cast<unsigned int>(StringLength(array))
                );
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  File integer left shift operator                           //
            ////////////////////////////////////////////////////////////////////
            inline File& operator<<(int32_t value)
            {
                // String buffer
                char buf[12];
                unsigned int cur = 0;

                // Negative number
                if (value < 0)
                {
                    value = -value;
                    buf[cur++] = '-';
                }

                // Store number digit by digit
                for (int32_t i = Math::log10(value); i >= 0; --i)
                {
                    buf[cur++] = static_cast<char>(
                        48 + ((value / Math::power10(i)) % 10)
                    );
                }

                // Write buffer
                FILE_WRITE(m_handle, buf, cur);
                return *this;
            }

            inline File& operator<<(int64_t value)
            {
                // String buffer
                char buf[22];
                unsigned int cur = 0;

                // Negative number
                if (value < 0)
                {
                    value = -value;
                    buf[cur++] = '-';
                }

                // Store number digit by digit
                for (int64_t i = Math::log10(value); i >= 0; --i)
                {
                    buf[cur++] = static_cast<char>(
                        48 + ((value / Math::power10(i)) % 10)
                    );
                }

                // Write buffer
                FILE_WRITE(m_handle, buf, cur);
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  File right shift operator                                     //
            ////////////////////////////////////////////////////////////////////
            inline File& operator>>(String32& string)
            {
                string.size() = FILE_READ(
                    m_handle, string.data(), string.maxSize()-1
                );
                string.sentinel() = '\0';
                return *this;
            }
            inline File& operator>>(String256& string)
            {
                string.size() = FILE_READ(
                    m_handle, string.data(), string.maxSize()-1
                );
                string.sentinel() = '\0';
                return *this;
            }
            inline File& operator>>(String4096& string)
            {
                string.size() = FILE_READ(
                    m_handle, string.data(), string.maxSize()-1
                );
                string.sentinel() = '\0';
                return *this;
            }


        private:
            ////////////////////////////////////////////////////////////////////
            //  File private copy constructor : Not copyable                  //
            ////////////////////////////////////////////////////////////////////
            File(const File&) = delete;

            ////////////////////////////////////////////////////////////////////
            //  File private copy operator : Not copyable                     //
            ////////////////////////////////////////////////////////////////////
            File& operator=(const File&) = delete;


        private:
            int         m_handle;       // File handle
    };


#endif // NBK_STDLIB_FILE_HEADER
