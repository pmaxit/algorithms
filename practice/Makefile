CC=g++
CFLAGS=
LFLAGS=

OBJDIR = obj
TARGET = a.out
SRCDIR = src

SOURCES = knights.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

.phony: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

