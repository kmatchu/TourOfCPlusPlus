Using minGW compiler (downloaded)
- posix threads, windows 64 bit, ucrt (universal)


`g++ -c ../src/*.cpp`
- compiles object files into folder where i am running command from

`g++ -c Chapter1/src/file1.cpp -o Chapter1/build/file1.o`
- compiles a single src. -o is destination (nothing to do with .o)

`g++ Chapter01/build/main.o -o Chapter01/bin/ch1_program`
- links a single object file into a .exe file (ch1_program)

`g++ Chapter01/build/*.o -o Chapter01/bin/ch1_program`
- links all object files into the .exe file