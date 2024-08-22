CXX_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
		    -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXECUTABLE_NAME = a.exe

all:
	@g++ .\main.cpp           -c $(CXX_FLAGS)
	@g++ .\terminal_calls.cpp -c $(CXX_FLAGS)
	@g++ .\input_output.cpp   -c $(CXX_FLAGS)
	@g++ .\testfile_check.cpp -c $(CXX_FLAGS)
	@g++ .\testfile_read.cpp  -c $(CXX_FLAGS)
	@g++ .\testsystem.cpp     -c $(CXX_FLAGS)
	@g++ .\tester.cpp         -c $(CXX_FLAGS)
	@g++ .\solver.cpp         -c $(CXX_FLAGS)

	@g++ .\main.o .\input_output.o .\tester.o .\terminal_calls.o .\testfile_check.o .\testfile_read.o .\testsystem.o .\solver.o -o a

run:
	@.\$(EXECUTABLE_NAME)

run_h:
	@.\$(EXECUTABLE_NAME) -h

run_t:
	@.\$(EXECUTABLE_NAME) -t

run_s:
	@.\$(EXECUTABLE_NAME) -s

clean_exe:
	@del *.exe

clean_o:
	@del *.o

clean_all:
	@del *.exe
	@del *.o
