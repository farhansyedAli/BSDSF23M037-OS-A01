# Top-level recursive Makefile
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99

SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/client

.PHONY: all clean

all: $(TARGET)

$(TARGET):
	$(MAKE) -C $(SRCDIR) CC="$(CC)" CFLAGS="$(CFLAGS)" OBJDIR=../$(OBJDIR) BINDIR=../$(BINDIR) TARGET=$(TARGET)

clean:
	$(MAKE) -C $(SRCDIR) clean OBJDIR=../$(OBJDIR) BINDIR=../$(BINDIR)
	rm -f $(OBJDIR)/* $(BINDIR)/*
