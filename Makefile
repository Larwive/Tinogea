CC = gcc
CFLAGS = -Wall -Wextra -g

build: src/main.c
	$(CC) $(CFLAGS) $^ -o tinogea

check: tst/test.c
	$(CC) $(CFLAGS) $^ -o $@
	./check

%.h:

main.c: src/tag.h

test.c: tst/test_tag.h

.PHONY: build check clean

clean:
	rm -rf *.o