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
	Nbk.o

	$(CC) -o NBK \
	Nbk.o \
	main.o $(LDFLAGS)


main.o: main.cpp
	$(CC) -o main.o -c main.cpp $(CFLAGS)

Nbk.o: Nbk.cpp
	$(CC) -o Nbk.o -c Nbk.cpp $(CFLAGS)


clean:
	rm -rf *.o

mrproper: clean
	rm -rf NBK
