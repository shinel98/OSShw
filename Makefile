CC = gcc
#CFLAGS = -W -Wall
TARGET = manager_user
DTARGET = manager_debug
OBJECTS = main.c manager.o
all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) -DDEBUG -o $@ $^
clean:
	rm *.o product_user
	rm *.o product_debug


