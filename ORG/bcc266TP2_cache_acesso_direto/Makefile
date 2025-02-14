# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -O2 -lm

# Source files
SRCS = programa.c cpu.c ram.c mmu.c geradorInstrucoes.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HDRS = blocoMemoria.h cpu.h endereco.h instrucao.h mmu.h ram.h

# Executable name
TARGET = toy_simulator

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable
run:
	./$(TARGET)

# Phony targets
.PHONY: all clean run