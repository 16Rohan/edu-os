CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = edu-os.exe

.PHONY: all clean

all: $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) 2>nul || mkdir $(OBJ_DIR) 2>nul || exit 0

clean:
	rm -rf $(OBJ_DIR) $(TARGET) 2>nul || rmdir /s /q $(OBJ_DIR) 2>nul || exit 0
	del /q $(TARGET) 2>nul || exit 0
