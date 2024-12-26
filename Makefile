################################################################################
##              ________           ______________________________________     ##
##             // .    /   _______/ . . . . . . . . . . . . . . . . .   /     ##
##            // .    /   // . . . .    _______________________________/      ##
##           // .     |  //      ______/ \\      |  // .   /_/     __/        ##
##          // .      | //    __// .   \_//     /  // .   /     __/           ##
##         // .       |//    / // .   _________/  // .       __/              ##
##        // .   /|   |/    / // .   /  \\    \  // .        \                ##
##       // .   /||        / // .    \__//    / // .   /\     \               ##
##      // .   / ||       / //  .            / // .   /  \     \              ##
##     //_____/  ||______/  \\______________/ //_____/    \____/              ##
##                                                                            ##
################################################################################
##   This is free and unencumbered software released into the public domain.  ##
##                                                                            ##
##   Anyone is free to copy, modify, publish, use, compile, sell, or          ##
##   distribute this software, either in source code form or as a compiled    ##
##   binary, for any purpose, commercial or non-commercial, and by any        ##
##   means.                                                                   ##
##                                                                            ##
##   In jurisdictions that recognize copyright laws, the author or authors    ##
##   of this software dedicate any and all copyright interest in the          ##
##   software to the public domain. We make this dedication for the benefit   ##
##   of the public at large and to the detriment of our heirs and             ##
##   successors. We intend this dedication to be an overt act of              ##
##   relinquishment in perpetuity of all present and future rights to this    ##
##   software under copyright law.                                            ##
##                                                                            ##
##   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          ##
##   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       ##
##   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   ##
##   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR        ##
##   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    ##
##   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    ##
##   OTHER DEALINGS IN THE SOFTWARE.                                          ##
##                                                                            ##
##   For more information, please refer to <https://unlicense.org>            ##
################################################################################
##    NBK : Network Backend                                                   ##
##     Makefile : Linux make compilation file                                 ##
################################################################################
CC=g++ -std=c++17 -O3 -fno-exceptions -fno-rtti \
	-fomit-frame-pointer -ffunction-sections \
	-fno-trapping-math -fno-math-errno -fno-signed-zeros
CFLAGS=-W -Wall
LDFLAGS=-pthread

all: NBK

NBK: main.o \
	Nbk.o \
	System/SysThread.o System/SysClock.o System/SysCPU.o System/SysMemory.o \
	System/Lin/SysMessage.o System/SysSettings.o \
	Stdlib/Console.o \
	Network/IPAddress.o Network/TCPSocket.o Network/UDPSocket.o \
	Physics/Physics.o \
	Physics/PhysicsTransform2.o Physics/PhysicsTransform3.o \
	Physics/Collision2.o Physics/MatrixChunk2.o Physics/MatrixStream2.o \
	Physics/BoundingSurfaces/BoundingCircle.o \
	Physics/BoundingSurfaces/BoundingAlignRect.o \
	Physics/BoundingSurfaces/BoundingRect.o \
	Resources/Resources.o Resources/MatrixColLoader.o \
	Softwares/Softwares.o

	$(CC) -o NBK \
	Nbk.o \
	System/SysThread.o System/SysClock.o System/SysCPU.o System/SysMemory.o \
	System/Lin/SysMessage.o System/SysSettings.o \
	Stdlib/Console.o \
	Network/IPAddress.o Network/TCPSocket.o Network/UDPSocket.o \
	Physics/Physics.o \
	Physics/PhysicsTransform2.o Physics/PhysicsTransform3.o \
	Physics/Collision2.o Physics/MatrixChunk2.o Physics/MatrixStream2.o \
	Physics/BoundingSurfaces/BoundingCircle.o \
	Physics/BoundingSurfaces/BoundingAlignRect.o \
	Physics/BoundingSurfaces/BoundingRect.o \
	Resources/Resources.o Resources/MatrixColLoader.o \
	Softwares/Softwares.o \
	main.o $(LDFLAGS)


main.o: main.cpp
	$(CC) -o main.o -c main.cpp $(CFLAGS)

Nbk.o: Nbk.cpp
	$(CC) -o Nbk.o -c Nbk.cpp $(CFLAGS)


System/SysThread.o: System/SysThread.cpp
	$(CC) -o System/SysThread.o -c System/SysThread.cpp $(CFLAGS)

System/SysClock.o: System/SysClock.cpp
	$(CC) -o System/SysClock.o -c System/SysClock.cpp $(CFLAGS)

System/SysCPU.o: System/SysCPU.cpp
	$(CC) -o System/SysCPU.o -c System/SysCPU.cpp $(CFLAGS)

System/SysMemory.o: System/SysMemory.cpp
	$(CC) -o System/SysMemory.o -c System/SysMemory.cpp $(CFLAGS)

System/Lin/SysMessage.o: System/Lin/SysMessage.cpp
	$(CC) -o System/Lin/SysMessage.o -c System/Lin/SysMessage.cpp $(CFLAGS)

System/SysSettings.o: System/SysSettings.cpp
	$(CC) -o System/SysSettings.o -c System/SysSettings.cpp $(CFLAGS)


Stdlib/Console.o: Stdlib/Console.cpp
	$(CC) -o Stdlib/Console.o -c Stdlib/Console.cpp $(CFLAGS)


Network/IPAddress.o: Network/IPAddress.cpp
	$(CC) -o Network/IPAddress.o -c Network/IPAddress.cpp $(CFLAGS)

Network/TCPSocket.o: Network/TCPSocket.cpp
	$(CC) -o Network/TCPSocket.o -c Network/TCPSocket.cpp $(CFLAGS)

Network/UDPSocket.o: Network/UDPSocket.cpp
	$(CC) -o Network/UDPSocket.o -c Network/UDPSocket.cpp $(CFLAGS)


Physics/Physics.o: Physics/Physics.cpp
	$(CC) -o Physics/Physics.o -c Physics/Physics.cpp $(CFLAGS)

Physics/PhysicsTransform2.o: Physics/PhysicsTransform2.cpp
	$(CC) -o Physics/PhysicsTransform2.o -c \
	Physics/PhysicsTransform2.cpp $(CFLAGS)

Physics/PhysicsTransform3.o: Physics/PhysicsTransform3.cpp
	$(CC) -o Physics/PhysicsTransform3.o -c \
	Physics/PhysicsTransform3.cpp $(CFLAGS)

Physics/Collision2.o: Physics/Collision2.cpp
	$(CC) -o Physics/Collision2.o -c Physics/Collision2.cpp $(CFLAGS)

Physics/MatrixChunk2.o: Physics/MatrixChunk2.cpp
	$(CC) -o Physics/MatrixChunk2.o -c Physics/MatrixChunk2.cpp $(CFLAGS)

Physics/MatrixStream2.o: Physics/MatrixStream2.cpp
	$(CC) -o Physics/MatrixStream2.o -c Physics/MatrixStream2.cpp $(CFLAGS)

Physics/BoundingCircle.o: Physics/BoundingCircle.cpp
	$(CC) -o Physics/BoundingCircle.o -c Physics/BoundingCircle.cpp $(CFLAGS)

Physics/BoundingAlignRect.o: Physics/BoundingAlignRect.cpp
	$(CC) -o Physics/BoundingAlignRect.o -c \
	Physics/BoundingAlignRect.cpp $(CFLAGS)

Physics/BoundingRect.o: Physics/BoundingRect.cpp
	$(CC) -o Physics/BoundingRect.o -c Physics/BoundingRect.cpp $(CFLAGS)


Resources/Resources.o: Resources/Resources.cpp
	$(CC) -o Resources/Resources.o -c Resources/Resources.cpp $(CFLAGS)

Resources/MatrixColLoader.o: Resources/MatrixColLoader.cpp
	$(CC) -o Resources/MatrixColLoader.o -c \
	Resources/MatrixColLoader.cpp $(CFLAGS)


Softwares/Softwares.o: Softwares/Softwares.cpp
	$(CC) -o Softwares/Softwares.o -c Softwares/Softwares.cpp $(CFLAGS)


clean:
	rm -rf *.o
	rm -rf System/*.o
	rm -rf System/Lin/*.o
	rm -rf Stdlib/*.o
	rm -rf Network/*.o
	rm -rf Physics/*.o
	rm -rf Physics/BoundingSurfaces/*.o
	rm -rf Resources/*.o
	rm -rf Softwares/*.o

mrproper: clean
	rm -rf NBK
