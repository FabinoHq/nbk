////////////////////////////////////////////////////////////////////////////////
//              ________           ______________________________________     //
//             // .    /   _______/ . . . . . . . . . . . . . . . . .   /     //
//            // .    /   // . . . .    _______________________________/      //
//           // .     |  //      ______/ \\      |  // .   /_/     __/        //
//          // .      | //    __// .   \_//     /  // .   /     __/           //
//         // .       |//    / // .   _________/  // .       __/              //
//        // .   /|   |/    / // .   /  \\    \  // .        \                //
//       // .   /||        / // .    \__//    / // .   /\     \               //
//      // .   / ||       / //  .            / // .   /  \     \              //
//     //_____/  ||______/  \\______________/ //_____/    \____/              //
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
//     Stdlib/StringLib.h : Macro template string library                     //
////////////////////////////////////////////////////////////////////////////////
#ifdef NBK_STDLIB_STRINGLIB_HEADER
#undef NBK_STDLIB_STRINGLIB_HEADER

    #include "../Math/Math.h"

    #include <cstddef>
    #include <cstdint>
    #include <cstring>


    ////////////////////////////////////////////////////////////////////////////
    //  StringLib class definition                                            //
    ////////////////////////////////////////////////////////////////////////////
    class StringLib
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  StringLib default constructor                                 //
            ////////////////////////////////////////////////////////////////////
            StringLib() :
            m_size(0),
            m_string()
            {
                m_string[0] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib string constructor                                  //
            ////////////////////////////////////////////////////////////////////
            StringLib(const StringLib& string) :
            m_size(0),
            m_string()
            {
                memcpy(m_string, string.m_string, (m_size = string.m_size)+1);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array constructor                                   //
            ////////////////////////////////////////////////////////////////////
            StringLib(const char* array) :
            m_size(0),
            m_string()
            {
                while (((m_string[m_size] = array[m_size]) != 0) &&
                    (m_size < (StringSize-1))) { ++m_size; }
                m_string[(StringSize-1)] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib destructor                                          //
            ////////////////////////////////////////////////////////////////////
            ~StringLib()
            {

            }


            ////////////////////////////////////////////////////////////////////
            //  Clear the string                                              //
            ////////////////////////////////////////////////////////////////////
            inline void clear()
            {
                m_size = 0;
                m_string[0] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  Erase a substring of the string                               //
            ////////////////////////////////////////////////////////////////////
            inline void erase(int32_t offset, int32_t length)
            {
                (void)offset;
                (void)length;
            }

            ////////////////////////////////////////////////////////////////////
            //  Erase the last character of the string                        //
            ////////////////////////////////////////////////////////////////////
            inline void popback()
            {
                m_size = Math::max(m_size-1, 0);
                m_string[m_size] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  Get a substring of the string                                 //
            ////////////////////////////////////////////////////////////////////
            inline StringLib substr(int32_t offset, int32_t length)
            {
                StringLib result;
                (void)offset;
                (void)length;
                return result;
            }

            ////////////////////////////////////////////////////////////////////
            //  Insert a string within the string                             //
            ////////////////////////////////////////////////////////////////////
            inline void insert(int32_t offset, const StringLib& string)
            {
                (void)offset;
                (void)string;
            }

            ////////////////////////////////////////////////////////////////////
            //  Insert a string within the string                             //
            ////////////////////////////////////////////////////////////////////
            inline void replace(int32_t offset, int32_t length,
                const StringLib& string)
            {
                (void)offset;
                (void)length;
                (void)string;
            }


            ////////////////////////////////////////////////////////////////////
            //  Match a subpart of the string with another string             //
            ////////////////////////////////////////////////////////////////////
            inline bool match(int32_t offset, const StringLib& string)
            {
                (void)offset;
                (void)string;
                return false;
            }

            ////////////////////////////////////////////////////////////////////
            //  Find a string occurence within the string                     //
            ////////////////////////////////////////////////////////////////////
            inline int32_t find(const StringLib& string)
            {
                (void)string;
                return -1;
            }

            ////////////////////////////////////////////////////////////////////
            //  Find the last string occurence within the string              //
            ////////////////////////////////////////////////////////////////////
            inline int32_t rfind(const StringLib& string)
            {
                (void)string;
                return -1;
            }


            ////////////////////////////////////////////////////////////////////
            //  Extract a folder path from a path                             //
            ////////////////////////////////////////////////////////////////////
            inline StringLib folderPath()
            {
                StringLib result;
                return result;
            }

            ////////////////////////////////////////////////////////////////////
            //  Extract a parent folder path from a path                      //
            ////////////////////////////////////////////////////////////////////
            inline StringLib parentFolderPath()
            {
                StringLib result;
                return result;
            }

            ////////////////////////////////////////////////////////////////////
            //  Extract a folder name from a path                             //
            ////////////////////////////////////////////////////////////////////
            inline StringLib folderName()
            {
                StringLib result;
                return result;
            }

            ////////////////////////////////////////////////////////////////////
            //  Extract a file name from a path                               //
            ////////////////////////////////////////////////////////////////////
            inline StringLib fileName()
            {
                StringLib result;
                return result;
            }

            ////////////////////////////////////////////////////////////////////
            //  Extract a file extension from a path or a file name           //
            ////////////////////////////////////////////////////////////////////
            inline StringLib fileExt()
            {
                StringLib result;
                return result;
            }


            ////////////////////////////////////////////////////////////////////
            //  Test if the string is empty                                   //
            ////////////////////////////////////////////////////////////////////
            inline bool isEmpty() const
            {
                return (m_size == 0);
            }

            ////////////////////////////////////////////////////////////////////
            //  Get first character of the string                             //
            ////////////////////////////////////////////////////////////////////
            inline char& front()
            {
                return m_string[0];
            }

            ////////////////////////////////////////////////////////////////////
            //  Get last character of the string (before \0)                  //
            ////////////////////////////////////////////////////////////////////
            inline char& back()
            {
                return m_string[m_size-1];
            }

            ////////////////////////////////////////////////////////////////////
            //  Get string data array                                         //
            ////////////////////////////////////////////////////////////////////
            inline char* data()
            {
                return m_string;
            }

            ////////////////////////////////////////////////////////////////////
            //  Get string length                                             //
            ////////////////////////////////////////////////////////////////////
            inline int32_t length() const
            {
                return m_size;
            }

            ////////////////////////////////////////////////////////////////////
            //  Get maximum allowed size (internal array size)                //
            ////////////////////////////////////////////////////////////////////
            inline int32_t maxSize() const
            {
                return StringSize;
            }


        public:
            ////////////////////////////////////////////////////////////////////
            //  StringLib copy operator                                       //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator=(const StringLib& string)
            {
                memcpy(m_string, string.m_string, (m_size = string.m_size)+1);
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array copy operator                                 //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator=(const char* array)
            {
                m_size = 0;
                while (((m_string[m_size] = array[m_size]) != 0) &&
                    (m_size < (StringSize-1))) { ++m_size; }
                m_string[(StringSize-1)] = 0;
                return *this;
            }


            ////////////////////////////////////////////////////////////////////
            //  StringLib addition operator                                   //
            ////////////////////////////////////////////////////////////////////
            inline StringLib operator+(const StringLib& string) const
            {
                StringLib result(*this);
                return (result << string);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array addition operator                             //
            ////////////////////////////////////////////////////////////////////
            inline StringLib operator+(const char* array) const
            {
                StringLib result(*this);
                return (result << array);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib character addition operator                         //
            ////////////////////////////////////////////////////////////////////
            inline StringLib operator+(const char character) const
            {
                StringLib result(*this);
                return (result << character);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib addition assignment operator                        //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator+=(const StringLib& string)
            {
                return ((*this) << string);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array addition assignment operator                  //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator+=(const char* array)
            {
                return ((*this) << array);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib character addition assignment operator              //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator+=(const char character)
            {
                return ((*this) << character);
            }


            ////////////////////////////////////////////////////////////////////
            //  StringLib left shift operator                                 //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator<<(const StringLib& string)
            {
                int32_t sz = Math::min(string.m_size, (StringSize-m_size-1));
                memcpy(&m_string[m_size], string.m_string, sz);
                m_string[m_size += sz] = 0;
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array left shift operator                           //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator<<(const char* array)
            {
                int32_t i = 0;
                while (((m_string[m_size] = array[i++]) != 0) &&
                    (m_size < (StringSize-1))) { ++m_size; }
                m_string[(StringSize-1)] = 0;
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib character left shift operator                       //
            ////////////////////////////////////////////////////////////////////
            inline StringLib& operator<<(const char character)
            {
                m_string[m_size] = character;
                m_size = Math::min(m_size+1, (StringSize-1));
                m_string[m_size] = 0;
                return *this;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib integer left shift operator                         //
            ////////////////////////////////////////////////////////////////////
            StringLib& operator<<(int32_t value)
            {
                // Negative number
                if (value < 0)
                {
                    value = -value;
                    m_string[m_size] = '-';
                    m_size = Math::min(m_size+1, (StringSize-1));
                }

                // Write number digit by digit
                for (int32_t i = Math::log10(value); i >= 0; --i)
                {
                    m_string[m_size] = static_cast<char>(
                        48 + ((value / Math::power10(i)) % 10)
                    );
                    m_size = Math::min(m_size+1, (StringSize-1));
                }

                // Last nul character
                m_string[m_size] = 0;
                return *this;
            }


            ////////////////////////////////////////////////////////////////////
            //  StringLib array subscript operator []                         //
            ////////////////////////////////////////////////////////////////////
            inline char& operator[](int32_t index)
            {
                return m_string[Math::clamp(index, 0, (StringSize-1))];
            }


            ////////////////////////////////////////////////////////////////////
            //  StringLib equal to operator                                   //
            ////////////////////////////////////////////////////////////////////
            inline bool operator==(const StringLib& string) const
            {
                if (m_size != string.m_size) { return false; }
                return (memcmp(m_string, string.m_string, m_size) == 0);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array equal to operator                             //
            ////////////////////////////////////////////////////////////////////
            inline bool operator==(const char* array) const
            {
                int32_t i = 0;
                while ((m_string[i] == array[i]) && (i <= m_size)) { ++i; }
                return (i == (m_size+1));
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib not equal to operator                               //
            ////////////////////////////////////////////////////////////////////
            inline bool operator!=(const StringLib& string) const
            {
                if (m_size != string.m_size) { return true; }
                return (memcmp(m_string, string.m_string, m_size) != 0);
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array not equal to operator                         //
            ////////////////////////////////////////////////////////////////////
            inline bool operator!=(const char* array) const
            {
                int32_t i = 0;
                while ((m_string[i] == array[i]) && (i <= m_size)) { ++i; }
                return (i != (m_size+1));
            }


        private:
            int32_t         m_size;                     // String size
            char            m_string[StringSize];       // String array
    };


#endif // NBK_STDLIB_STRINGLIB_HEADER
