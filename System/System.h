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
//     System/System.h : NBK System management wrapper                        //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_SYSTEM_SYSTEM_HEADER
#define NBK_SYSTEM_SYSTEM_HEADER


    ////////////////////////////////////////////////////////////////////////////
    //  Operating system configuration                                        //
    ////////////////////////////////////////////////////////////////////////////
    #if defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__)
        #define NBK_WINDOWS

        #undef UNICODE
        #define UNICODE
        #undef _WINSOCKAPI_
        #define _WINSOCKAPI_
        #undef NOMINMAX
        #define NOMINMAX
    #endif // Windows

    #if defined(__APPLE__)
        #define NBK_MACOS
    #endif // MacOS

    #if defined(__linux__)
        #define NBK_LINUX
    #endif // Linux

    ////////////////////////////////////////////////////////////////////////////
    //  CPU configuration                                                     //
    ////////////////////////////////////////////////////////////////////////////
    #if defined(__x86_64__) || defined(_WIN64) || defined(__i386__)
        #define NBK_X64
    #endif
    #if defined(__aarch64__) || defined(_M_ARM64) || defined(__arm__) || \
        defined(__ARM_ARCH)
        #define NBK_ARM
    #endif

    ////////////////////////////////////////////////////////////////////////////
    //  64bits or 32bits configuration                                        //
    ////////////////////////////////////////////////////////////////////////////
    #if defined(__x86_64__) || defined(_WIN64) || defined(__LP64__) || \
        defined(__ia64) || defined(_M_X64) || defined(_M_IA64) || \
        defined(__aarch64__) || defined(_M_ARM64) || defined(__powerpc64__)
        #define NBK_64BITS
    #else
        #define NBK_32BITS
    #endif


#endif // NBK_SYSTEM_SYSTEM_HEADER
