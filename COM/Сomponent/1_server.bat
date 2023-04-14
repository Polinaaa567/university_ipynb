cls

g++ -c ./source/server/server.cpp -o ./build/server/components.o
g++ -c ./source/server/main.cpp -o ./build/server/main.o

g++ -shared ./build/server/components.o ./build/server/main.o -o ./build/server/main.dll -Wl,--kill-at

pause