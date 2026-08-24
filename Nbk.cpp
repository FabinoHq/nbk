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

    /*int8_t int8a = 8;
    int8_t int8b = 72;
    int8_t int8c = 127;
    int8_t int8d = -128;

    uint8_t uint8a = 8;
    uint8_t uint8b = 72;
    uint8_t uint8c = 108;
    uint8_t uint8d = 255;

    int16_t int16a = 104;
    int16_t int16b = 3975;
    int16_t int16c = 32767;
    int16_t int16d = -32768;

    uint16_t uint16a = 104u;
    uint16_t uint16b = 3975u;
    uint16_t uint16c = 27347u;
    uint16_t uint16d = 65535u;

    int32_t int32a = 14l;
    int32_t int32b = 7124l;
    int32_t int32c = 2147483647l;
    int32_t int32d = -2147483648l;

    uint32_t uint32a = 14ul;
    uint32_t uint32b = 7124ul;
    uint32_t uint32c = 1477945875ul;
    uint32_t uint32d = 4294967295ul;

    int64_t int64a = 21ll;
    int64_t int64b = 54294967295ll;
    int64_t int64c = 9223372036854775807ll;
    int64_t int64d = -9223372036854775807ll; int64d -= 1;

    uint64_t uint64a = 21ull;
    uint64_t uint64b = 54294967295ull;
    uint64_t uint64c = 78729477945875ull;
    uint64_t uint64d = 18446744073709551615ull;

    float flta = 0.0f;
    float fltb = 3.14159265358f;
    float fltc = -1.41421356f;
    float fltd = 707106781.18f;

    double dbla = 0.0;
    double dblb = 3.1415926535897932384626;
    double dblc = -1.41421356237309504880;
    double dbld = 707106781.18;*/

    /*String32 str;
    str.clear();
    str << "str : " << int8a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int8b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int8c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int8d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << uint8a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint8b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint8c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint8d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << int16a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int16b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int16c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int16d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << uint16a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint16b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint16c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint16d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << int32a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int32b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int32c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int32d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << uint32a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint32b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint32c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint32d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << int64a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int64b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int64c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << int64d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "str : " << uint64a;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint64b;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint64c;
    GConsole << str << '\n';
    str.clear();
    str << "str : " << uint64d;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "flt : " << flta;
    GConsole << str << '\n';
    str.clear();
    str << "flt : " << fltb;
    GConsole << str << '\n';
    str.clear();
    str << "flt : " << fltc;
    GConsole << str << '\n';
    str.clear();
    str << "flt : " << fltd;
    GConsole << str << '\n';
    GConsole << '\n';

    str.clear();
    str << "dbl : " << dbla;
    GConsole << str << '\n';
    str.clear();
    str << "dbl : " << dblb;
    GConsole << str << '\n';
    str.clear();
    str << "dbl : " << dblc;
    GConsole << str << '\n';
    str.clear();
    str << "dbl : " << dbld;
    GConsole << str << '\n';
    GConsole << '\n';*/

    /*GConsole << '\n';
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
    GConsole << uint64d << '\n';
    GConsole << '\n';
    GConsole << flta << '\n';
    GConsole << fltb << '\n';
    GConsole << fltc << '\n';
    GConsole << fltd << '\n';
    GConsole << '\n';
    GConsole << dbla << '\n';
    GConsole << dblb << '\n';
    GConsole << dblc << '\n';
    GConsole << dbld << '\n';
    GConsole << '\n';*/

    // Open file
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

    file << "Test file\n";
    file << int8a << '\n';
    file << int8b << '\n';
    file << int8c << '\n';
    file << int8d << '\n';
    file << '\n';
    file << uint8a << '\n';
    file << uint8b << '\n';
    file << uint8c << '\n';
    file << uint8d << '\n';
    file << '\n';
    file << int16a << '\n';
    file << int16b << '\n';
    file << int16c << '\n';
    file << int16d << '\n';
    file << '\n';
    file << uint16a << '\n';
    file << uint16b << '\n';
    file << uint16c << '\n';
    file << uint16d << '\n';
    file << '\n';
    file << int32a << '\n';
    file << int32b << '\n';
    file << int32c << '\n';
    file << int32d << '\n';
    file << '\n';
    file << uint32a << '\n';
    file << uint32b << '\n';
    file << uint32c << '\n';
    file << uint32d << '\n';
    file << '\n';
    file << int64a << '\n';
    file << int64b << '\n';
    file << int64c << '\n';
    file << int64d << '\n';
    file << '\n';
    file << uint64a << '\n';
    file << uint64b << '\n';
    file << uint64c << '\n';
    file << uint64d << '\n';
    file << '\n';
    file << flta << '\n';
    file << fltb << '\n';
    file << fltc << '\n';
    file << fltd << '\n';
    file << '\n';
    file << dbla << '\n';
    file << dblb << '\n';
    file << dblc << '\n';
    file << dbld << '\n';
    file << '\n';

    // Close file
    file.close();*/
}
