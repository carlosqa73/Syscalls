mycat: main.o
	gcc main.o -o mycat

main.o: main.c
	gcc -Wall -c main.c -o main.o

.PHONY: clean
clean:
	rm -rf mycat *.o
