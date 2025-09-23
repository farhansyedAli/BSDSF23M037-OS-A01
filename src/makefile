# src/Makefile (for static library build)
CC ?= gcc
CFLAGS ?= -I../include -Wall -Wextra -std=gnu99
OBJDIR ?= ../obj
BINDIR ?= ../bin
LIBDIR ?= ../lib
TARGET ?= $(BINDIR)/client_static

SRCS := main.c myfilefunctions.c mystrfunctions.c
OBJS := $(OBJDIR)/main.o $(OBJDIR)/myfilefunctions.o $(OBJDIR)/mystrfunctions.o
LIBOBJS := $(OBJDIR)/myfilefunctions.o $(OBJDIR)/mystrfunctions.o
LIB := $(LIBDIR)/libmyutils.a

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

$(LIB): $(LIBOBJS) | $(LIBDIR)
	ar rcs $(LIB) $(LIBOBJS)

$(TARGET): $(OBJDIR)/main.o $(LIB) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(TARGET)

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/*
	rm -f $(LIBDIR)/*
