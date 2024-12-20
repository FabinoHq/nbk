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
//     Nbk.h : NBK Main class management                                      //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_NBK_HEADER
#define NBK_NBK_HEADER

    #include "System/System.h"
    #include "System/SysMessage.h"
    #include "System/SysCPU.h"
    #include "System/SysClock.h"
    #include "System/SysSleep.h"
    #include "System/SysSettings.h"
    #include "Stdlib/String.h"
    #include "Stdlib/Console.h"
    #include "Stdlib/File.h"

    #include "Resources/Resources.h"
    #include "Physics/Physics.h"
    #include "Softwares/Softwares.h"

    #include <cstddef>
    #include <cstdint>


    ////////////////////////////////////////////////////////////////////////////
    //  NBK main class definition                                             //
    ////////////////////////////////////////////////////////////////////////////
    class Nbk
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  Nbk default constructor                                       //
            ////////////////////////////////////////////////////////////////////
            Nbk();

            ////////////////////////////////////////////////////////////////////
            //  Nbk destructor                                                //
            ////////////////////////////////////////////////////////////////////
            ~Nbk();


            ////////////////////////////////////////////////////////////////////
            //  Launch NBK                                                    //
            //  return : True if NBK successfully started, false otherwise    //
            ////////////////////////////////////////////////////////////////////
            bool launch();

            ////////////////////////////////////////////////////////////////////
            //  Run NBK                                                       //
            ////////////////////////////////////////////////////////////////////
            void run();


        private:
            ////////////////////////////////////////////////////////////////////
            //  Nbk private copy constructor : Not copyable                   //
            ////////////////////////////////////////////////////////////////////
            Nbk(const Nbk&) = delete;

            ////////////////////////////////////////////////////////////////////
            //  Nbk private copy operator : Not copyable                      //
            ////////////////////////////////////////////////////////////////////
            Nbk& operator=(const Nbk&) = delete;


        private:
    };


#endif // NBK_NBK_HEADER
