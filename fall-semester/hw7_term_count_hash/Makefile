CFLAGS = -Wall -Werror -Wextra

all: hw7 Hash
		gcc hw7.o Hash.o -o hw7

hw7: hw7.c
		gcc -c hw7.c

Hash: Hash.c
		gcc -c Hash.c

clean:
		-rm *.o hw7
