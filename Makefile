CC = gcc
CFLAGS = -Wall -Wextra -g

build: src/main.c
	$(CC) $(CFLAGS) $^ -o tinogea

check: build
	$(CC) $(CFLAGS) $^ -o $@

%.h:

main.c: src/tag.h

.PHONY: build check clean

clean:
	rm -rf *.o