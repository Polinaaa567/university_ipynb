cls

g++ -c ./source/manager/main.cpp -o ./build/manager/main.o

g++ -shared ./build/manager/main.o -o ./build/manager/main.dll -Wl,--kill-at

pause