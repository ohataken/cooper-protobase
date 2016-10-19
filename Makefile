.c.o:
	$(CC) -Wall -Wextra -g -c $<

cooper-protobase.o: main.o
	$(CC) $^ -o cooper-protobase.o

run: cooper-protobase.o
	./$<
