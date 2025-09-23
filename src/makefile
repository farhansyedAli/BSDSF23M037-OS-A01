# src/Makefile
CC ?= gcc
CFLAGS ?= -I../include -Wall -Wextra -std=gnu99
OBJDIR ?= ../obj
BINDIR ?= ../bin
LIBDIR ?= ../lib
TARGET ?= $(BINDIR)/client

SRCS := $(filter-out main.c, $(wildcard *.c))
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
MAIN := $(OBJDIR)/main.o
STATICLIB := $(LIBDIR)/libmyutils.a

.PHONY: all clean

all: $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build the static library
$(STATICLIB): $(OBJS) | $(LIBDIR)
	ar rcs $@ $(OBJS)

# Build the executable by linking main.o with the static library
$(TARGET): $(MAIN) $(STATICLIB) | $(BINDIR)
	$(CC) $(CFLAGS) $(MAIN) -L$(LIBDIR) -lmyutils -o $(TARGET)

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET)
	rm -f $(STATICLIB)
