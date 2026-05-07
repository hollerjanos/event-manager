CC = gcc
CFLAGS = -Wall -Wextra
RM = rm -f

objects = bin/main.o\
		  bin/event.o\
		  bin/file.o\
		  bin/event-manager.o

all: bin/event-manager.out

bin/event-manager.out: $(objects)
	$(CC) $(CFLAGS) $^ -o bin/event-manager.out

# bin/event.o: src/event.c
# 	$(CC) $(CFLAGS) -c src/event.c -o bin/event.o

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) bin/event-manager.out
	$(RM) $(objects)
