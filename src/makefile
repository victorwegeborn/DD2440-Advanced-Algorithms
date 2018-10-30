CPP = dist.cpp euler.cpp io.cpp main.cpp minWeightPerfectMatch.cpp spanning_tree.cpp twoOpt.cpp

build/main: build/cat.cpp
	g++ build/*.cpp -o build/main

build/cat.cpp: clean $(CPP) main.h
	cp main.h build/cat.cpp
	cat $(CPP) | sed 's/^#include.*//' >> build/cat.cpp
	sed -i.bak '/^$$/d' build/cat.cpp # Remove blank lines
	sed -i.bak '/^[[:blank:]]*\/\/.*/d' build/cat.cpp # Remove line comments
	rm -f build/*.bak

.PHONY: clean kattis debug asan test
clean:
	rm -f build/cat.cpp build/main

kattis: build/cat.cpp
	build/submit.py -p tsp -f build/*.cpp build/*.h build/instances.inc

debug: build/cat.cpp
	g++ build/*.cpp -o build/main -g -O0


asan: build/cat.cpp
	g++ build/*.cpp -o build/main -g -O0 -fsanitize=address

test_euler: build/cat.cpp test_euler.cpp
	cat test_euler.cpp | sed 's/^#include.*//' >> build/cat.cpp
	g++ build/*.cpp -o build/main -DTESTEULER

test_min_spanning_tree: build/cat.cpp test_min_spanning_tree.cpp
	cat test_min_spanning_tree.cpp | sed 's/^#include.*//' >> build/cat.cpp
	g++ build/*.cpp -o build/main -DTESTMINSPANNINGTREE
