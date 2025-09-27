# Makefile for mtool library

# Compiler and flags
CC = gcc
CFLAGS = -Wall -fPIC

# Project name
TARGET = mtool

# Source files
SRC = src/$(TARGET).c
OBJ = $(TARGET).o

# OS-specific settings
UNAME_S := $(shell uname -s)

# Default install locations
PREFIX ?= /usr/local
INCLUDEDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

# Library names
STATIC_LIB = lib$(TARGET).a
ifeq ($(UNAME_S), Darwin)
    # macOS
    SHARED_LIB = lib$(TARGET).dylib
    SHARED_FLAGS = -dynamiclib -install_name $(LIBDIR)/$(SHARED_LIB)
else
    # Linux
    SHARED_LIB = lib$(TARGET).so
    SHARED_FLAGS = -shared -Wl,-soname,$(SHARED_LIB)
endif

# Default target: build all libraries
all: $(STATIC_LIB) $(SHARED_LIB)

# Create object file
$(OBJ): $(SRC) src/$(TARGET).h
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Create static library
$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

# Create shared library
$(SHARED_LIB): $(OBJ)
	$(CC) $(SHARED_FLAGS) -o $@ $^

# Installation
install: all
	@mkdir -p $(INCLUDEDIR)
	@mkdir -p $(LIBDIR)
	cp src/$(TARGET).h $(INCLUDEDIR)
	cp $(STATIC_LIB) $(LIBDIR)
	cp $(SHARED_LIB) $(LIBDIR)
	@echo "mtool library installed successfully!"
	@echo "Header in: $(INCLUDEDIR)"
	@echo "Libraries in: $(LIBDIR)"

# Uninstallation
uninstall: 
	rm -f $(INCLUDEDIR)/$(TARGET).h
	rm -f $(LIBDIR)/$(STATIC_LIB)
	rm -f $(LIBDIR)/$(SHARED_LIB)
	@echo "mtool library uninstalled."

# Clean up build files
clean:
	rm -f $(OBJ) $(STATIC_LIB) $(SHARED_LIB) test_program

# Build the test program
test: test.c all
	$(CC) test.c -Isrc -L. -l$(TARGET) -o test_program
	@echo "Test program 'test_program' created. Run it with ./test_program"
