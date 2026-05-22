CC=gcc
CFLAGS=-Wall

SRC=main.c \
src/fibonacci_module.c \
src/prime_analysis.c \
src/cube_operations.c \
src/quadratic_operations.c \
src/abundance_analysis.c \
src/odd_number_analysis.c \
src/performance_module.c \
src/definitions.c

TARGET=linux-task-processor

all:
	$(CC) $(CFLAGS) $(SRC) -lm -o $(TARGET)