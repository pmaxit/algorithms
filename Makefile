# Makefile

CC= clang++
CFLAGS= -g -std=c++11 -pedantic -Wno-c++11-extensions

# typing 'make' will invoke the first target entry in the file
TARGET= test
LIBTARGET = lib$(TARGET).a

# Project files
INCLUDES= -I./include
SRCDIR= src
OBJDIR= obj
BINDIR= bin

# Define the library paths in addition to /usr/lib
SOURCES =
MAIN_SOURCE = test.cpp

# Create Object files
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
MAIN_OBJ = $(MAIN_SOURCE:%.cpp=$(OBJDIR)/%.o)
rm= rm -f

all: $(TARGET)

$(TARGET): $(OBJECTS) $(MAIN_OBJ)
	$(CC) -o $@ $(LFLAGS) $^
	@echo "Linking complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $^"
	$(CC) $(CFLAGS) $(INCLUDES) -c $? -o $@
	@echo "Compiled $< successfully"

.PHONEY: clean static

static: $(LIBTARGET)

$(LIBTARGET): $(OBJECTS)
	ar rcs $@ $^

clean:
	@$(rm) $(OBJECTS) $(MAIN_OBJ) $(TARGET) $(LIBTARGET)
	@echo "Cleanup complete"

remove: clean
	@$(rm) $(TARGET) $(LIBTARGET)
	@echo "Executable removed"
