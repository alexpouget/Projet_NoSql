CC=gcc

all: MySqlLite

MySqlLite: str.o map.o main.o
	gcc -o MySqlLite main.o map.o str.o
main.o: main.c map.h str.h
	gcc -o main.o -c main.c
map.o: map.c
	gcc -o map.o -c map.c
str.o: str.c
	gcc -o str.o -c str.c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf hello
