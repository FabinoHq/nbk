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
//     Physics/PhysicsTransform3.h : 3D physics transformations               //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_PHYSICS_PHYSICSTRANSFORM3_HEADER
#define NBK_PHYSICS_PHYSICSTRANSFORM3_HEADER

    #include "../System/System.h"
    #include "../Math/Math.h"
    #include "../Math/Vector3.h"
    #include "../Math/Vector3i.h"
    #include "Physics.h"

    #include <cstdint>


    ////////////////////////////////////////////////////////////////////////////
    //  PhysicsTransform3 class definition                                    //
    ////////////////////////////////////////////////////////////////////////////
    class PhysicsTransform3
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  PhysicsTransform3 default constructor                         //
            ////////////////////////////////////////////////////////////////////
            PhysicsTransform3();

            ////////////////////////////////////////////////////////////////////
            //  PhysicsTransform3 destructor                                  //
            ////////////////////////////////////////////////////////////////////
            ~PhysicsTransform3();


            ////////////////////////////////////////////////////////////////////
            //  Reset physics transformations                                 //
            ////////////////////////////////////////////////////////////////////
            void reset();

            ////////////////////////////////////////////////////////////////////
            //  Precompute physics transforms (thread sync)                   //
            ////////////////////////////////////////////////////////////////////
            void prephysics(
                const Vector3i& physicsPos, const Vector3i& physicsAngles);

            ////////////////////////////////////////////////////////////////////
            //  Offset previous transforms position                           //
            ////////////////////////////////////////////////////////////////////
            void offsetPrevPos(const Vector3i& offset);


        private:
            ////////////////////////////////////////////////////////////////////
            //  PhysicsTransform3 private copy constructor : Not copyable     //
            ////////////////////////////////////////////////////////////////////
            PhysicsTransform3(const PhysicsTransform3&) = delete;

            ////////////////////////////////////////////////////////////////////
            //  PhysicsTransform3 private copy operator : Not copyable        //
            ////////////////////////////////////////////////////////////////////
            PhysicsTransform3& operator=(const PhysicsTransform3&) = delete;


        public:
            Vector3         pos;            // Current position
            Vector3         prevPos;        // Previous position
            Vector3         angles;         // Current angles
            Vector3         prevAngles;     // Previous angles
    };


#endif // NBK_PHYSICS_PHYSICSTRANSFORM3_HEADER