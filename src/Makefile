CC = gcc
CFLAGS = -Wall -Wextra -g

exec: main.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: exec clean

clean:
	rm -rf *.o