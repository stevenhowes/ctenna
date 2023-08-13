clean:
	rm -f *.o ctenna
	
ctenna: main.o hb9cv.o jpole.o groundplane.o
	cc -o ctenna main.o hb9cv.o jpole.o groundplane.o

main.o: main.c
	cc -c main.c

hb9cv.o: hb9cv.c
	cc -c hb9cv.c

jpole.o: jpole.c
	cc -c jpole.c

groundplane.o: groundplane.c
	cc -c groundplane.c
