SRC_DIR = src
BIN_DIR = bin

CC =  gcc
CFLAGS = -I$(SRC_DIR) -Wall

TARGET = $(BIN_DIR)/depth

SRC = $(shell find $(SRC_DIR) -name *.c)
OBJ = $(SRC:%.c=%.o)

$(TARGET): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -r $(BIN_DIR)
	rm */*.o

run: $(TARGET)
	./$(TARGET)

