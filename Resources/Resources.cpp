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
//     Resources/Resources.cpp : Resources management                         //
////////////////////////////////////////////////////////////////////////////////
#include "Resources.h"


////////////////////////////////////////////////////////////////////////////////
//  Resources global instance                                                 //
////////////////////////////////////////////////////////////////////////////////
Resources GResources = Resources();


////////////////////////////////////////////////////////////////////////////////
//  Resources default constructor                                             //
////////////////////////////////////////////////////////////////////////////////
Resources::Resources() :
matrixcols()
{

}

////////////////////////////////////////////////////////////////////////////////
//  Resources destructor                                                      //
////////////////////////////////////////////////////////////////////////////////
Resources::~Resources()
{

}


////////////////////////////////////////////////////////////////////////////////
//  Init resources loaders                                                    //
//  return : True if resources loaders are ready                              //
////////////////////////////////////////////////////////////////////////////////
bool Resources::init()
{
    // Start matrixcol loader thread
    matrixcols.start();

    // Wait for resources init
    bool resourcesReady = false;
    while (!resourcesReady)
    {
        // Get resources loader states
        MatrixColLoaderState matrixcolState = matrixcols.getState();

        // Check matrixcols loader state
        if (matrixcolState == MATRIXCOLLOADER_STATE_ERROR)
        {
            // Mesh loader error
            GSysMessage << "[0x4000] Could not init matrixcols loader\n";
            GSysMessage << "Please check your resources files";
            return false;
        }

        // Check resources init state
        if (matrixcolState == MATRIXCOLLOADER_STATE_IDLE)
        {
            // Resources are ready
            resourcesReady = true;
        }
        else
        {
            // Release some CPU while loading
            SysSleep(ResourcesWaitSleepTime);
        }
    }

    // Resources loaders are ready
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//  Destroy resources                                                         //
////////////////////////////////////////////////////////////////////////////////
void Resources::destroyResources()
{
    // Stop matrixcol loader thread
    matrixcols.stop();

    // Destroy matrixcol loader
    matrixcols.destroyMatrixColLoader();
}
