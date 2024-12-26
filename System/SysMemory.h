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
//     System/SysMemory.h : System memory management                          //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_SYSTEM_SYSMEMORY_HEADER
#define NBK_SYSTEM_SYSMEMORY_HEADER

    #include "System.h"
    #include "SysMessage.h"

    #include <cstddef>
    #include <cstdlib>

    //#include <iostream>
    //#include <iomanip>


    ////////////////////////////////////////////////////////////////////////////
    //  SysMemory settings                                                    //
    ////////////////////////////////////////////////////////////////////////////
    const size_t SysMemoryDefaultAlignment = 0x100;


    ////////////////////////////////////////////////////////////////////////////
    //  System memory pool enumeration                                        //
    ////////////////////////////////////////////////////////////////////////////
    enum SysMemoryPool
    {
        SYSMEMORY_MATRICES = 0,

        SYSMEMORY_POOLSCOUNT = 1
    };


    ////////////////////////////////////////////////////////////////////////////
    //  SysMemoryList structure                                               //
    ////////////////////////////////////////////////////////////////////////////
    struct SysMemoryList
    {
        SysMemoryPool pool;
        size_t size;
    };


    ////////////////////////////////////////////////////////////////////////////
    //  SysMemoryArray : Memory pools and sizes                               //
    ////////////////////////////////////////////////////////////////////////////
    const SysMemoryList SysMemoryArray[SYSMEMORY_POOLSCOUNT] =
    {
        SYSMEMORY_MATRICES, 0x8000
    };


    ////////////////////////////////////////////////////////////////////////////
    //  SysMemory class definition                                            //
    ////////////////////////////////////////////////////////////////////////////
    class SysMemory
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  SysMemory default constructor                                 //
            ////////////////////////////////////////////////////////////////////
            SysMemory();

            ////////////////////////////////////////////////////////////////////
            //  SysMemory destructor                                          //
            ////////////////////////////////////////////////////////////////////
            ~SysMemory();


            ////////////////////////////////////////////////////////////////////
            //  Init system memory                                            //
            //  return : True if system memory is ready                       //
            ////////////////////////////////////////////////////////////////////
            bool init();

            ////////////////////////////////////////////////////////////////////
            //  Reset system memory pool                                      //
            ////////////////////////////////////////////////////////////////////
            void resetMemory(SysMemoryPool memoryPool)
            {
                m_offset[memoryPool] = 0;
            }

            ////////////////////////////////////////////////////////////////////
            //  Destroy system memory                                         //
            ////////////////////////////////////////////////////////////////////
            void destroySysMemory();


            ////////////////////////////////////////////////////////////////////
            //  Allocate memory                                               //
            ////////////////////////////////////////////////////////////////////
            template<typename T> T* alloc(size_t size, SysMemoryPool memoryPool,
                size_t alignment = SysMemoryDefaultAlignment)
            {
                // Check memory size
                if (size == 0) { return 0; }

                // Adjust memory size according to type
                size *= sizeof(T);

                // Adjust memory size according to alignment
                size_t sizeOffset = (size % alignment);
                if (sizeOffset != 0) { size += (alignment - sizeOffset); }

                // Adjust memory start offset according to alignment
                size_t offset = m_offset[memoryPool];
                size_t startOffset = (
                    (((size_t)m_memory[memoryPool]) + offset) % alignment
                );
                if (startOffset != 0) { offset += (alignment - startOffset); }

                // Check remaining memory in pool
                if ((offset + size) > SysMemoryArray[memoryPool].size)
                {
                    // Not enough remaining memory in pool
                    return 0;
                }

                // Get memory pointer
                T* data = (T*)(((size_t)m_memory[memoryPool]) + offset);

                // Update current memory offset
                m_offset[memoryPool] = (offset + size);

                // Update current memory usage
                if (m_offset[memoryPool] >= m_usage[memoryPool])
                {
                    m_usage[memoryPool] = m_offset[memoryPool];
                }

                // Return memory pointer
                return data;
            }


            ////////////////////////////////////////////////////////////////////
            //  Dump system memory usage                                      //
            ////////////////////////////////////////////////////////////////////
            /*void dumpMemory()
            {
                std::cout << "Memory dump\n";
                for (int i = 0; i < SYSMEMORY_POOLSCOUNT; ++i)
                {
                    std::cout << std::hex << m_usage[i] << " ( ";
                    std::cout << std::dec << (
                        (m_usage[i]*1.0)/(SysMemoryArray[i].size*1.0)
                    )*100.0;
                    std::cout << " % )\n";
                }
                std::cout << '\n';
            }*/


        private:
            ////////////////////////////////////////////////////////////////////
            //  SysMemory private copy constructor : Not copyable             //
            ////////////////////////////////////////////////////////////////////
            SysMemory(const SysMemory&) = delete;

            ////////////////////////////////////////////////////////////////////
            //  SysMemory private copy operator : Not copyable                //
            ////////////////////////////////////////////////////////////////////
            SysMemory& operator=(const SysMemory&) = delete;


        private:
            void*       m_memory[SYSMEMORY_POOLSCOUNT];     // Memory
            size_t      m_offset[SYSMEMORY_POOLSCOUNT];     // Offset
            size_t      m_usage[SYSMEMORY_POOLSCOUNT];      // Usage
    };


    ////////////////////////////////////////////////////////////////////////////
    //  SysMemory global instance                                             //
    ////////////////////////////////////////////////////////////////////////////
    extern SysMemory GSysMemory;


#endif // NBK_SYSTEM_SYSMEMORY_HEADER
