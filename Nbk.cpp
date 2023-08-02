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

    // Run NBK
    run();

    // NBK successfully terminated
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//  Run NBK                                                                   //
////////////////////////////////////////////////////////////////////////////////
void Nbk::run()
{
    // String test
    String str;
    String32 str32;
    String256 str256;
    String4096 str4096;

    // Display maximum array size
    std::cout << "str : " << str.maxSize() << '\n';
    std::cout << "str32 : " << str32.maxSize() << '\n';
    std::cout << "str256 : " << str256.maxSize() << '\n';
    std::cout << "str4096 : " << str4096.maxSize() << '\n' << '\n';

    // Test strings
    String test("test string");
    std::cout << test.length() << ' ' << test.data() << '\n';
    String mystr("mystr");
    std::cout << mystr.length() << ' ' << mystr.data() << '\n' << '\n';

    String concat;
    concat = test;
    std::cout << concat.length() << ' ' << concat.data() << '\n';
    concat += mystr;
    concat += "123";
    std::cout << concat.length() << ' ' << concat.data() << '\n';
    concat = "";
    std::cout << concat.length() << ' ' << concat.data() << '\n';
    concat = (test + " " + mystr);
    std::cout << "concat[2] : " << concat[2] << '\n';
    concat[3] = 3;
    std::cout << concat.length() << ' ' << concat.data() << '\n' << '\n';

    String equalop = "test";
    bool equalres = (equalop == "tes");
    bool equalres2 = (equalop == "test");
    bool equalres3 = (equalop == "testa");
    std::cout << "tes : " << (equalres?"true":"false") << '\n';
    std::cout << "test : " << (equalres2?"true":"false") << '\n';
    std::cout << "testa : " << (equalres3?"true":"false") << '\n' << '\n';

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
    std::cout << (findmatch.find(match2)) << '\n';
    std::cout << (findmatch.find(match)) << '\n';
    std::cout << (findmatch.find(match3)) << '\n';
    std::cout << (findmatch.find("tes")) << '\n';
    std::cout << (findmatch.find("test")) << '\n';
    std::cout << (findmatch.find("testa")) << '\n';
    std::cout << '\n';
    std::cout << (findmatch.match(9, match)) << '\n';
    std::cout << (findmatch.match(10, match)) << '\n';
    std::cout << (findmatch.match(11, match)) << '\n';
    std::cout << (findmatch.match(10, match2)) << '\n';
    std::cout << (findmatch.match(10, match)) << '\n';
    std::cout << (findmatch.match(10, match3)) << '\n';
    std::cout << (findmatch.match(9, "test")) << '\n';
    std::cout << (findmatch.match(10, "test")) << '\n';
    std::cout << (findmatch.match(11, "test")) << '\n';
    std::cout << (findmatch.match(10, "tes")) << '\n';
    std::cout << (findmatch.match(10, "test")) << '\n';
    std::cout << (findmatch.match(10, "testa")) << '\n';
    std::cout << '\n';

    concat = "concat ";
    concat += 123;
    concat = concat + " ";
    concat += -1381272486;
    std::cout << concat.data() << '\n';

    for (int i = 0; i < test.maxSize(); ++i)
    {
        std::cout << (int)test.data()[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < mystr.maxSize(); ++i)
    {
        std::cout << (int)mystr.data()[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < concat.maxSize(); ++i)
    {
        std::cout << (int)concat.data()[i] << ' ';
    }
    std::cout << '\n';
}
