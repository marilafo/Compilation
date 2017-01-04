LEX=lex
YACC=bison
CFLAGS=-Wall $(shell pkg-config --cflags glib-2.0)
CC=gcc
LIBS=$(shell pkg-config --libs glib-2.0)

all:parse

parse:grammar.c scanner.c identificateur.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

grammar.c:grammar.y
	$(YACC) -Wconflicts-sr -t -d -o $@ --defines=grammar.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^

clean:
	rm -f grammar.c scanner.c *~
