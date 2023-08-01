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
#ifndef NBK_STDLIB_STRINGLIB_HEADER
#define NBK_STDLIB_STRINGLIB_HEADER

    #include <cstddef>
    #include <cstdint>


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
            m_string(),
            m_size(0)
            {
                m_string[0] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib string constructor                                  //
            ////////////////////////////////////////////////////////////////////
            StringLib(const StringLib& string) :
            m_string(),
            m_size(0)
            {
                memcpy(m_string, string.m_string, (m_size = string.m_size));
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib array constructor                                   //
            ////////////////////////////////////////////////////////////////////
            StringLib(const char* array) :
            m_string(),
            m_size(0)
            {
                while (((m_string[m_size] = array[m_size]) != 0) &&
                    (m_size < (StringSize-2))) { ++ m_size; }
                m_string[(StringSize-1)] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  StringLib destructor                                          //
            ////////////////////////////////////////////////////////////////////
            ~StringLib()
            {

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
            inline int32_t length()
            {
                return m_size;
            }

            ////////////////////////////////////////////////////////////////////
            //  Get maximum allowed size (internal array size)                //
            ////////////////////////////////////////////////////////////////////
            inline int32_t maxSize()
            {
                return StringSize;
            }


        public:
            ////////////////////////////////////////////////////////////////////
            //  StringLib copy operator                                       //
            ////////////////////////////////////////////////////////////////////
            StringLib& operator=(const StringLib& string)
            {
                memcpy(m_string, string.m_string, (m_size = string.m_size));
                return *this;
            }


        private:
            char            m_string[StringSize];       // String array
            int32_t         m_size;                     // String size
    };


#endif // NBK_STDLIB_STRINGLIB_HEADER
