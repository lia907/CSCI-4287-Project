CC = gcc
CFLAGS = -std=c99
LIBS = -lm

defualt: TestPath

TestPath: pathTest.o astar.o streetmap.o
	$(CC) $(CFLAGS) -o TestPath pathTest.o astar.o streetmap.o $(LIBS)

pathTest.o: pathTest.c astar.h
	$(CC) $(CFLAGS) -c pathTest.c

astar.o: astar.c astar.h streetmap.h
	$(CC) $(CFLAGS) -c astar.c $(LIBS)

streetmap.o: streetmap.c streetmap.h
	$(CC) $(CFLAGS) -c streetmap.c

clean:
	$(RM) TestPath *.o *~