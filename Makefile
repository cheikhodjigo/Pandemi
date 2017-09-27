.PHONY: all tests clean

all: bin/generator

bin/generator: src/generator.c
	mkdir -p bin
	gcc -std=c11 -o bin/generator src/generator.c

check:
	./tests.sh

clean:
	rm -rf bin/
	rm -rf tests_out/
