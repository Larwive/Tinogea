CC = gcc
CFLAGS = -g -I/opt/homebrew/Cellar/sdl2_image/2.8.2_1/include -I/opt/homebrew/Cellar/sdl2/2.30.3/include
LIBS = -L/opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib -L/opt/homebrew/Cellar/sdl2/2.30.3/lib -lSDL2_image  -lSDL2

build: src/main.o src/engine/window.o assets/obj/obj.o
	$(CC) $(CFLAGS) $^ -o tinogea $(LIBS)

check: tst/test.c
	$(CC) $(CFLAGS) $^ -o $@
	./check

%.h:

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.c: src/tag.h src/engine/windows.h

test.c: tst/test_tag.h

.PHONY: build check clean

clean:
	find . -type f -name '*.o' -delete