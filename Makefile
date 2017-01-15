all: tracker test

tracker: src/main.c src/linkedList.c src/parsing.c
	gcc -Wall -std=c99 -Iinclude src/main.c src/linkedList.c src/parsing.c -o tracker

test:
	./tracker assets/test.csv

