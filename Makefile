prog: main.o hb9cv.o
	gcc -o prog main.o hb9cv.o

main.o: main.c
	gcc -c main.c

hb9cv.o: hb9cv.c
	gcc -c hb9cv.c
