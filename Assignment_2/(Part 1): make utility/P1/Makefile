CC = g++
CFLAGS = -c -Wall
objects = obj/main.o obj/function1.o obj/function2.o

all: directory output

directory:
	mkdir -p obj

output: $(objects)
	$(CC) $(objects) -o output
	
obj/main.o: main.cpp functions.h
	$(CC) $(CFLAGS) main.cpp -o obj/main.o
	
obj/function1.o: function1.cpp
	$(CC) $(CFLAGS) function1.cpp -o obj/function1.o
	
obj/function2.o: function2.cpp
	$(CC) $(CFLAGS) function2.cpp -o obj/function2.o
	
clean:
	rm -rf output obj
