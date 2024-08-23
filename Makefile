CXX_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
		    -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra \
			-Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
			-Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor \
			-Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel \
			-Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXECUTABLE_NAME = executable.exe
OBJECTS         = main.o input_output.o tester.o terminal_calls.o testfile_check.o testfile_read.o testsystem.o solver.o

all: executable

executable: main.o input_output.o tester.o terminal_calls.o testfile_check.o testfile_read.o testsystem.o solver.o
	@g++ main.o input_output.o tester.o terminal_calls.o testfile_check.o testfile_read.o testsystem.o solver.o -o executable

main.o: main.cpp
	@g++ main.cpp -c $(CXX_FLAGS) -o main.o

input_output.o: input_output.cpp
	@g++ input_output.cpp -c $(CXX_FLAGS) -o input_output.o

tester.o: tester.cpp
	@g++ tester.cpp -c $(CXX_FLAGS) -o tester.o

terminal_calls.o: terminal_calls.cpp
	@g++ terminal_calls.cpp -c $(CXX_FLAGS) -o terminal_calls.o

testfile_check.o: testfile_check.cpp
	@g++ testfile_check.cpp -c $(CXX_FLAGS) -o testfile_check.o

testfile_read.o: testfile_read.cpp
	@g++ testfile_read.cpp -c $(CXX_FLAGS) -o testfile_read.o

testsystem.o: testsystem.cpp
	@g++ testsystem.cpp -c $(CXX_FLAGS) -o testsystem.o
	
solver.o: solver.cpp
	@g++ solver.cpp -c $(CXX_FLAGS) -o solver.o

clean_exe:
	@del *.exe

clean_o:
	@del *.o

clean_all:
	@del *.exe
	@del *.o
