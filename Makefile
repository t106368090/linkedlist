CC = gcc

.PHONY:all clean

all:

	@$(CC) -o a1 a1.c

clean:

	@rm -f *.o a1  


