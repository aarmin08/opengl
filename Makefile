SRC_DIR = src
BUILD_DIR = build/debug
CC = clang++
OBJ_NAME = gaming
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OPENGLFILES = $(wildcard src/Opengls/*.cpp)

_FILES = $(wildcard $(SRC_DIR)/Utils/*.cpp) $(wildcard src/Rendering/*.cpp)
INCLUDE_PATHS = -Iinclude -Iusr/local/include -Iusr/local/Cellar
LIBRARY_PATHS = -Llib
COMPILER_FLAGS = --std=c++20 -Wall -O0 -g -pedantic
LINKER_FLAGS = -lsdl2 -lsdl2_Image -framework OpenGL -lglfw -lm -lglew 

all: 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(_FILES) $(OPENGLFILES) include/glad/glad.c -o $(BUILD_DIR)/$(OBJ_NAME)
clean: 
	rm -rf *.out $(OBJ_NAME) gaming
