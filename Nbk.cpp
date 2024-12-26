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
//     Nbk.cpp : NBK Main class management                                    //
////////////////////////////////////////////////////////////////////////////////
#include "Nbk.h"


////////////////////////////////////////////////////////////////////////////////
//  Nbk default constructor                                                   //
////////////////////////////////////////////////////////////////////////////////
Nbk::Nbk()
{

}

////////////////////////////////////////////////////////////////////////////////
//  Nbk destructor                                                            //
////////////////////////////////////////////////////////////////////////////////
Nbk::~Nbk()
{

}


////////////////////////////////////////////////////////////////////////////////
//  Launch NBK                                                                //
//  return : True if NBK successfully started, false otherwise                //
////////////////////////////////////////////////////////////////////////////////
bool Nbk::launch()
{
    // Check system CPU
    if (!SysCPUCheck())
    {
        // Invalid system CPU
        return false;
    }

    // Init system memory
    if (!GSysMemory.init())
    {
        // Unable to init system memory
        return false;
    }

    // Start physics solver thread
    GPhysics.start();

    // Init NBK resources
    if (!GResources.init())
    {
        // Unable to init NBK resources
        return false;
    }

    // Launch physics solver
    GPhysics.launch();

    // Run NBK
    run();

    // Stop physics solver thread
    GPhysics.stop();

    // Destroy resources
    GResources.destroyResources();

    // Destroy system memory
    GSysMemory.destroySysMemory();

    // NBK successfully terminated
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//  Run NBK                                                                   //
////////////////////////////////////////////////////////////////////////////////
void Nbk::run()
{
    // String test
    /*String str;
    String32 str32;
    String256 str256;
    String4096 str4096;

    // Display maximum array size
    GConsole << "str : " << str.maxSize() << '\n';
    GConsole << "str32 : " << str32.maxSize() << '\n';
    GConsole << "str256 : " << str256.maxSize() << '\n';
    GConsole << "str4096 : " << str4096.maxSize() << '\n' << '\n';

    // Test strings
    String test("test string");
    GConsole << test.length() << ' ' << test << '\n';
    String mystr("mystr");
    GConsole << mystr.length() << ' ' << mystr << '\n' << '\n';

    String concat;
    concat = test;
    GConsole << concat.length() << ' ' << concat << '\n';
    concat << mystr;
    concat << "123";
    GConsole << concat.length() << ' ' << concat << '\n';
    concat = "";
    GConsole << concat.length() << ' ' << concat << '\n';
    concat = (test + " " + mystr);
    GConsole << "concat[2] : " << concat[2] << '\n';
    concat[3] = 97;
    GConsole << concat.length() << ' ' << concat << '\n' << '\n';

    String equalop = "test";
    bool equalres = (equalop == "tes");
    bool equalres2 = (equalop == "test");
    bool equalres3 = (equalop == "testa");
    GConsole << "tes : " << (equalres?"true":"false") << '\n';
    GConsole << "test : " << (equalres2?"true":"false") << '\n';
    GConsole << "testa : " << (equalres3?"true":"false") << '\n' << '\n';

    int testInt = 0;
    if (testInt <= 0) { testInt = 0; }
    if (testInt >= 12) { testInt = 12; }
    if (testInt>= 12) { testInt = 12; }
    if (testInt >=12) { testInt = 12; }
    if (testInt>=12) { testInt = 12; }

    String findmatch = "This is a test string";
    String match = "test";
    String match2 = "tes";
    String match3 = "testa";
    GConsole << (findmatch.find(match2)) << '\n';
    GConsole << (findmatch.find(match)) << '\n';
    GConsole << (findmatch.find(match3)) << '\n';
    GConsole << (findmatch.find("tes")) << '\n';
    GConsole << (findmatch.find("test")) << '\n';
    GConsole << (findmatch.find("testa")) << '\n';
    GConsole << '\n';
    GConsole << (findmatch.match(9, match)) << '\n';
    GConsole << (findmatch.match(10, match)) << '\n';
    GConsole << (findmatch.match(11, match)) << '\n';
    GConsole << (findmatch.match(10, match2)) << '\n';
    GConsole << (findmatch.match(10, match)) << '\n';
    GConsole << (findmatch.match(10, match3)) << '\n';
    GConsole << (findmatch.match(9, "test")) << '\n';
    GConsole << (findmatch.match(10, "test")) << '\n';
    GConsole << (findmatch.match(11, "test")) << '\n';
    GConsole << (findmatch.match(10, "tes")) << '\n';
    GConsole << (findmatch.match(10, "test")) << '\n';
    GConsole << (findmatch.match(10, "testa")) << '\n';
    GConsole << '\n';

    concat = "concat ";
    concat << 123;
    concat = concat + " ";
    concat << -1381272486;
    GConsole << concat << '\n';

    for (int i = 0; i < test.maxSize(); ++i)
    {
        GConsole << (int)test[i] << ' ';
    }
    GConsole << '\n';
    for (int i = 0; i < mystr.maxSize(); ++i)
    {
        GConsole << (int)mystr[i] << ' ';
    }
    GConsole << '\n';
    for (int i = 0; i < concat.maxSize(); ++i)
    {
        GConsole << (int)concat[i] << ' ';
    }
    GConsole << '\n';

    GConsole << '\n' << '\n';
    GConsole << "------------------------------------\n\n";*/

    /*String testIn;
    GConsole >> testIn;
    GConsole << "1 : " << testIn << '\n';
    GConsole.flush();
    testIn.clear();
    GConsole >> testIn;
    GConsole << "2 : " << testIn << '\n';

    GConsole << '\n' << '\n';
    GConsole << "------------------------------------\n\n";
    GConsole.flush();*/

    /*File file;
    if (file.open("test.txt"))
    {
        GConsole << "test.txt opened\n";
    }
    else
    {
        GConsole << "Could not open file\n";
        return;
    }

    file << "test\n";
    file.close();*/

    /*int8_t int8a = 8;
    int8_t int8b = 72;
    int8_t int8c = 108;
    int8_t int8d = -117;

    uint8_t uint8a = 8;
    uint8_t uint8b = 72;
    uint8_t uint8c = 108;
    uint8_t uint8d = 249;

    int16_t int16a = 104;
    int16_t int16b = 3975;
    int16_t int16c = 27347;
    int16_t int16d = -28971;

    uint16_t uint16a = 104u;
    uint16_t uint16b = 3975u;
    uint16_t uint16c = 27347u;
    uint16_t uint16d = 62378u;

    int32_t int32a = 14l;
    int32_t int32b = 7124l;
    int32_t int32c = 1477945875l;
    int32_t int32d = -2142342691l;

    uint32_t uint32a = 14ul;
    uint32_t uint32b = 7124ul;
    uint32_t uint32c = 1477945875ul;
    uint32_t uint32d = 3942342691ul;

    int64_t int64a = 21ll;
    int64_t int64b = 786382ll;
    int64_t int64c = 79477945875ll;
    int64_t int64d = -7126742073207541612ll;

    uint64_t uint64a = 21ull;
    uint64_t uint64b = 786382ull;
    uint64_t uint64c = 79477945875ull;
    uint64_t uint64d = 15438218372394254211ull;

    GConsole << '\n';
    GConsole << int8a << '\n';
    GConsole << int8b << '\n';
    GConsole << int8c << '\n';
    GConsole << int8d << '\n';
    GConsole << '\n';
    GConsole << uint8a << '\n';
    GConsole << uint8b << '\n';
    GConsole << uint8c << '\n';
    GConsole << uint8d << '\n';
    GConsole << '\n';
    GConsole << int16a << '\n';
    GConsole << int16b << '\n';
    GConsole << int16c << '\n';
    GConsole << int16d << '\n';
    GConsole << '\n';
    GConsole << uint16a << '\n';
    GConsole << uint16b << '\n';
    GConsole << uint16c << '\n';
    GConsole << uint16d << '\n';
    GConsole << '\n';
    GConsole << int32a << '\n';
    GConsole << int32b << '\n';
    GConsole << int32c << '\n';
    GConsole << int32d << '\n';
    GConsole << '\n';
    GConsole << uint32a << '\n';
    GConsole << uint32b << '\n';
    GConsole << uint32c << '\n';
    GConsole << uint32d << '\n';
    GConsole << '\n';
    GConsole << int64a << '\n';
    GConsole << int64b << '\n';
    GConsole << int64c << '\n';
    GConsole << int64d << '\n';
    GConsole << '\n';
    GConsole << uint64a << '\n';
    GConsole << uint64b << '\n';
    GConsole << uint64c << '\n';
    GConsole << uint64d << '\n';*/
}
