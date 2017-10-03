.PHONY: all tests clean
FILENAME= bin/pandemi
$(FILENAME): src/pandemi.o
	mkdir -p bin
	gcc -o $(FILENAME) src/pandemi.c

all: bin/generator

bin/generator: src/generator.c
	mkdir -p bin
	gcc -std=c11 -o bin/generator src/generator.c

check:
	./tests.sh

clean:
	rm -rf bin/
	rm -rf tests_out/
