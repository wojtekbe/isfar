CC = g++
CFLAGS = `pkg-config opencv --cflags` -g -c -Wall
LDFLAGS = `pkg-config opencv --libs`

readfifo: readfifo.o

r: readfifo
	./$^

clean:
	-rm -f *.o readfifo
