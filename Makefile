.c.o:
	$(CC) -Wall -Wextra -g -c $<

cooper-protobase.o: cooper_object.o main.o
	$(CC) $^ -o cooper-protobase.o

run: cooper-protobase.o
	./$<
