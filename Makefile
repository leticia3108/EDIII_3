CC = g++
# CFLAGS = -g -Wall -O0 -std=c++11
CFLAGS = -g -O0 -std=c++11 # Flag -Wall removida para funcionar no runcodes
INCLUDE = $(wildcard include/*.hpp)
SOURCES = $(wildcard src/*.cpp)
OBJ = $(SOURCES:$(SRC_DIR)/%.cpp = $(BUILD_DIR)/%.o)
# INCLUDE_OBJ = $(INCLUDE:src/%.c=src/%.o)
TARGET = $(BIN_DIR)/programaTrab

# Diretórios
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include
BUILD_DIR = build

# Criar diretórios bin e build
$(BIN_DIR):
	mkdir -p $(BIN_DIR)
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilar arquivos .c em arquivos .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ) $(BUILD_DIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

debug: $(OBJ) $(BUILD_DIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -DDEBUG

run: $(TARGET)
	$(TARGET)

.PHONY: clean

clean:
	@rm -f $(BUILD_DIR)/*.o ./*.zip $(TARGET) core

zip: 
	@rm -f *.zip
	zip -r edIII.zip $(INC_DIR)/* $(SRC_DIR)/* ./Makefile