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
//     Stdlib/Console.h : Console management                                  //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_STDLIB_CONSOLE_HEADER
#define NBK_STDLIB_CONSOLE_HEADER

    #include "String.h"

    #include <cstddef>
    #include <cstdint>
    #include <cstring>

    #ifdef NBK_WINDOWS

        #include <fcntl.h>
        #include <io.h>

        #define CONSOLE_INPUT_FILEDESC 0
        #define CONSOLE_OUTPUT_FILEDESC 1
        #define CONSOLE_ERROR_FILEDESC 2

        #define CONSOLE_WRITE _write
        #define CONSOLE_READ _read
        #define CONSOLE_FLUSH _commit

    #endif // NBK_WINDOWS
    #ifdef NBK_LINUX

        #include <unistd.h>

        #define CONSOLE_INPUT_FILEDESC STDIN_FILENO
        #define CONSOLE_OUTPUT_FILEDESC STDOUT_FILENO
        #define CONSOLE_ERROR_FILEDESC STDERR_FILENO

        #define CONSOLE_WRITE write
        #define CONSOLE_READ read
        #define CONSOLE_FLUSH fsync

    #endif // NBK_LINUX


    ////////////////////////////////////////////////////////////////////////////
    //  Console class definition                                              //
    ////////////////////////////////////////////////////////////////////////////
    class Console
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  Console default constructor                                   //
            ////////////////////////////////////////////////////////////////////
            Console()
            {
                CONSOLE_FLUSH(CONSOLE_INPUT_FILEDESC);
                CONSOLE_FLUSH(CONSOLE_OUTPUT_FILEDESC);
            }

            ////////////////////////////////////////////////////////////////////
            //  Console destructor                                            //
            ////////////////////////////////////////////////////////////////////
            ~Console()
            {
                CONSOLE_FLUSH(CONSOLE_INPUT_FILEDESC);
                CONSOLE_FLUSH(CONSOLE_OUTPUT_FILEDESC);
            }


            ////////////////////////////////////////////////////////////////////
            //  Flush console I/O                                             //
            ////////////////////////////////////////////////////////////////////
            inline void flush()
            {
                CONSOLE_FLUSH(CONSOLE_INPUT_FILEDESC);
                CONSOLE_FLUSH(CONSOLE_OUTPUT_FILEDESC);
            }

            ////////////////////////////////////////////////////////////////////
            //  Flush console input                                           //
            ////////////////////////////////////////////////////////////////////
            inline void flushInput()
            {
                CONSOLE_FLUSH(CONSOLE_INPUT_FILEDESC);
            }

            ////////////////////////////////////////////////////////////////////
            //  Flush console ouput                                           //
            ////////////////////////////////////////////////////////////////////
            inline void flushOutput()
            {
                CONSOLE_FLUSH(CONSOLE_OUTPUT_FILEDESC);
            }


            ////////////////////////////////////////////////////////////////////
            //  Console string left shift operator                            //
            ////////////////////////////////////////////////////////////////////
            inline Console& operator<<(String32& string)
            {
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC,
                    string.data(), string.length()
                );
                return *this;
            }
            inline Console& operator<<(String256& string)
            {
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC,
                    string.data(), string.length()
                );
                return *this;
            }
            inline Console& operator<<(String4096& string)
            {
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC,
                    string.data(), string.length()
                );
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  Console character left shift operator                         //
            ////////////////////////////////////////////////////////////////////
            inline Console& operator<<(const char character)
            {
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC, &character, 1);
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  Console array left shift operator                             //
            ////////////////////////////////////////////////////////////////////
            inline Console& operator<<(const char* array)
            {
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC,
                    array, static_cast<unsigned int>(StringLength(array))
                );
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  Console integer left shift operator                           //
            ////////////////////////////////////////////////////////////////////
            inline Console& operator<<(int32_t value)
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
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC, buf, cur);
                return *this;
            }

            inline Console& operator<<(int64_t value)
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
                CONSOLE_WRITE(CONSOLE_OUTPUT_FILEDESC, buf, cur);
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  Console right shift operator                                  //
            ////////////////////////////////////////////////////////////////////
            inline Console& operator>>(String32& string)
            {
                string.size() = CONSOLE_READ(
                    CONSOLE_INPUT_FILEDESC, string.data(), string.maxSize()-1
                );
                string.sentinel() = '\0';
                return *this;
            }
            inline Console& operator>>(String256& string)
            {
                string.size() = CONSOLE_READ(
                    CONSOLE_INPUT_FILEDESC, string.data(), string.maxSize()-1
                );
                string.sentinel() = '\0';
                return *this;
            }
            inline Console& operator>>(String4096& string)
            {
                string.size() = CONSOLE_READ(
                    CONSOLE_INPUT_FILEDESC, string.data(), string.maxSize()-1
                );
                string.sentinel() = '\0';
                return *this;
            }


        private:
            ////////////////////////////////////////////////////////////////////
            //  Console private copy constructor : Not copyable               //
            ////////////////////////////////////////////////////////////////////
            Console(const Console&) = delete;

            ////////////////////////////////////////////////////////////////////
            //  Console private copy operator : Not copyable                  //
            ////////////////////////////////////////////////////////////////////
            Console& operator=(const Console&) = delete;


        private:
    };


    ////////////////////////////////////////////////////////////////////////////
    //  Console global instance                                               //
    ////////////////////////////////////////////////////////////////////////////
    extern Console GConsole;


#endif // NBK_STDLIB_CONSOLE_HEADER
