CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
		 -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra \
		 -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
		 -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor \
		 -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel \
		 -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = build
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
INCLUDES := $(wildcard $(INC_DIR)/*.h)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/a

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $@

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(CC) -c $(CFLAGS) -I$(INC_DIR) $< -o $@

run: $(EXECUTABLE)
	@ ./$(EXECUTABLE)

clean_build:
	@del $(BIN_DIR)

clean_obj:
	@del $(OBJ_DIR)

clean:
	@del $(BIN_DIR)
	@del $(OBJ_DIR)
