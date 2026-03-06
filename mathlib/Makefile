CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lcheck -lm -lpthread

LIB_SRC = mathlib.c
TEST_SRC = test_mathlib.c
TARGET = testy

.PHONY: all test clean run

all: $(TARGET)

$(TARGET): $(LIB_SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test: $(TARGET)
	./$(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)