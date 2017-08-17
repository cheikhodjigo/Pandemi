.PHONY: all tests clean

all: bin/generator

bin/generator:
	mkdir -p bin
	gcc -o bin/generator src/generator.c

check:
	./tests.sh

clean:
	rm -rf bin/
	rm -rf tests_out/
