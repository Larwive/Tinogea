CC = gcc
CFLAGS = -Wall -Wextra -g -I/opt/homebrew/Cellar/sdl2/2.30.3/include
LIBS = -L/opt/homebrew/Cellar/sdl2/2.30.3/lib -lSDL2

build: src/main.c src/engine/window.c
	$(CC) $(CFLAGS) $^ -o tinogea $(LIBS)

check: tst/test.c
	$(CC) $(CFLAGS) $^ -o $@
	./check

%.h:

main.c: src/tag.h src/engine/windows.h

test.c: tst/test_tag.h

.PHONY: build check clean

clean:
	rm -rf *.o