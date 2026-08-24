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
//     Stdlib/Console.cpp : Console management                                //
////////////////////////////////////////////////////////////////////////////////
#include "Console.h"


////////////////////////////////////////////////////////////////////////////////
//  Console global instance                                                   //
////////////////////////////////////////////////////////////////////////////////
Console GConsole = Console();


////////////////////////////////////////////////////////////////////////////////
//  Console integer left shift operator                                       //
////////////////////////////////////////////////////////////////////////////////
Console& Console::operator<<(int8_t value)
{
    // Convert integer value to buffer
    char buf[6];
    std::to_chars_result result = std::to_chars(buf, buf+5, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(uint8_t value)
{
    // Convert integer value to buffer
    char buf[6];
    std::to_chars_result result = std::to_chars(buf, buf+5, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(int16_t value)
{
    // Convert integer value to buffer
    char buf[8];
    std::to_chars_result result = std::to_chars(buf, buf+7, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(uint16_t value)
{
    // Convert integer value to buffer
    char buf[8];
    std::to_chars_result result = std::to_chars(buf, buf+7, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(int32_t value)
{
    // Convert integer value to buffer
    char buf[13];
    std::to_chars_result result = std::to_chars(buf, buf+12, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(uint32_t value)
{
    // Convert integer value to buffer
    char buf[13];
    std::to_chars_result result = std::to_chars(buf, buf+12, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(int64_t value)
{
    // Convert integer value to buffer
    char buf[22];
    std::to_chars_result result = std::to_chars(buf, buf+21, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(uint64_t value)
{
    // Convert integer value to buffer
    char buf[22];
    std::to_chars_result result = std::to_chars(buf, buf+21, value);
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}


////////////////////////////////////////////////////////////////////////////////
//  Console float left shift operator                                         //
////////////////////////////////////////////////////////////////////////////////
Console& Console::operator<<(float value)
{
    // Convert float value to buffer
    char buf[64];
    std::to_chars_result result = std::to_chars(
        buf, buf+63, value, std::chars_format::fixed
    );
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}

Console& Console::operator<<(double value)
{
    // Convert double value to buffer
    char buf[64];
    std::to_chars_result result = std::to_chars(
        buf, buf+63, value, std::chars_format::fixed
    );
    if (result.ec == std::errc())
    {
        // Write buffer
        CONSOLE_WRITE(
            CONSOLE_OUTPUT_FILEDESC, buf,
            static_cast<unsigned int>(result.ptr - buf)
        );
    }
    return *this;
}
