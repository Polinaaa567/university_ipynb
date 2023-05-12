cls

g++ -c ./source/server/server.cpp -o ./build/server/simple/components.o
g++ -c ./source/server/main.cpp -o ./build/server/simple/main.o

g++ -c ./source/server_2/server.cpp -o ./build/server/super/components.o
g++ -c ./source/server_2/main.cpp -o ./build/server/super/main.o


g++ -shared ./build/server/simple/components.o ./build/server/simple/main.o -o ./build/server/simple.dll -Wl,--kill-at

g++ -shared ./build/server/super/components.o ./build/server/super/main.o -o ./build/server/super.dll -Wl,--kill-at -lole32 -loleaut32 -luser32