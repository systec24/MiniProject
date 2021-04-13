CC = gcc
CFLAGS = -W -Wall
TARGET = Product
OBJECTS = main.c manager.o product.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

clean : 
	rm Product *.o
