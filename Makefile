ctenna: main.o hb9cv.o jpole.o
	gcc -o ctenna main.o hb9cv.o jpole.o

main.o: main.c
	gcc -c main.c

hb9cv.o: hb9cv.c
	gcc -c hb9cv.c

jpole.o: jpole.c
	gcc -c jpole.c
