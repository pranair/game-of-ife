@echo off
mkdir build
pushd build
gcc -Wall -Werror -g -O0 ..\src\game.c -I..\sdl\include\  -L..\sdl\lib -lmingw32 -lSDL2main -lSDL2  -o game.exe 
echo done
popd
