# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -O2  level 2 compilation optimizations
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -O2 -Wall

# the build target executable:
TARGET = server

all: $(TARGET)

$(TARGET): server.o server_api.o gpio.o
	$(CC) $(CFLAGS) -o $(TARGET) server.o server_api.o gpio.o

server.o: server.c server_api.h
	$(CC) $(CFLAGS) -c server.c

server_api.o: server_api.c
	$(CC) $(CFLAGS) -c server_api.c

gpio.o: gpio.c gpio.h
	$(CC) $(CFLAGS) -c gpio.c
clean:
	rm $(TARGET) *.o
