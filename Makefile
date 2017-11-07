.PHONY: all tests clean
FILENAME= bin/pandemic
$(FILENAME): src/pandemi.o
	mkdir -p bin
	gcc -o $(FILENAME) src/pandemi.c
src/pandemi.o: src/pandemi.c
	gcc -c src/pandemi.c

all: bin/generator

bin/generator: src/generator.c
	mkdir -p bin
	gcc -std=c11 -o bin/generator src/generator.c

check:
	./tests.sh

clean:
	rm -rf bin/
	rm -rf tests_out/
