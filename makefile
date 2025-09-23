# Top-level recursive Makefile
CC = gcc

CFLAGS = -Iinclude -Wall -Wextra -std=c99

CFLAGS = -Iinclude -Wall -Wextra -std=gnu99


SRCDIR = src
OBJDIR = obj
BINDIR = bin

TARGET = $(BINDIR)/client

LIBDIR = lib
TARGET = ../$(BINDIR)/client_static


.PHONY: all clean

all: $(TARGET)

$(TARGET):

	$(MAKE) -C $(SRCDIR) CC="$(CC)" CFLAGS="$(CFLAGS)" OBJDIR=../$(OBJDIR) BINDIR=../$(BINDIR) TARGET=$(TARGET)

clean:
	$(MAKE) -C $(SRCDIR) clean OBJDIR=../$(OBJDIR) BINDIR=../$(BINDIR)
	rm -f $(OBJDIR)/* $(BINDIR)/*

	$(MAKE) -C $(SRCDIR) CC="$(CC)" CFLAGS="$(CFLAGS)" OBJDIR=../$(OBJDIR) BINDIR=../$(BINDIR) LIBDIR=../$(LIBDIR) TARGET=$(TARGET)

clean:
	$(MAKE) -C $(SRCDIR) clean OBJDIR=../$(OBJDIR) BINDIR=../$(BINDIR) LIBDIR=../$(LIBDIR)
	rm -f $(OBJDIR)/* $(BINDIR)/* $(LIBDIR)/*

