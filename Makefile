SRCS		= $(wildcard src/*.c)
RELEASE_TARGET	= $(patsubst src/%.c,release/%.bin,$(SRCS))
DEBUG_TARGET	= $(patsubst src/%.c,debug/%.debug,$(SRCS))

all: $(RELEASE_TARGET) $(DEBUG_TARGET)

release/%.bin: src/%.c
	mkdir -p release
	gcc -o $@ -O2 $^

debug/%.debug: src/%.c
	mkdir -p debug
	gcc -o $@ -g $^

clean:
	rm $(RELEASE_TARGET) $(DEBUG_TARGET)
