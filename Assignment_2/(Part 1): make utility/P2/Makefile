CC = g++
CFLAGS = -c -Wall
objects = obj/main.o obj/function1.o obj/function2.o
USE_C = 0

ifeq ($(USE_C) , 1)
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
else
output:
	@echo "USE_C is not 1, set USE_C = 1 to compile"
endif

clean:
	rm -rf obj output
