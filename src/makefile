# src/makefile.

CC ?= gcc
CFLAGS ?= -I../include -Wall -Wextra -std=gnu99
OBJDIR ?= ../obj
BINDIR ?= ../bin
LIBDIR ?= ../lib
TARGET ?= $(BINDIR)/client_static

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
LIB := $(LIBDIR)/libmyutils.a

.PHONY: all clean

all: $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

# Compile .c into .o inside ../obj
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build static library from string + file functions
$(LIB): $(OBJDIR)/myfilefunctions.o $(OBJDIR)/mystrfunctions.o | $(LIBDIR)
	ar rcs $@ $^

# Link final executable with static library
$(TARGET): $(OBJDIR)/main.o $(LIB) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(TARGET)

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET)
	rm -f $(LIB)
