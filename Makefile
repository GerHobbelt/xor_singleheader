all: unit unit2 bench

unit : tests/unit.c include/xorfilter.h include/fusefilter.h
	cc -std=c99 -O3 -o unit tests/unit.c -Iinclude -Wall -Wextra -Wshadow  -Wcast-qual

unit2 : tests/unit2.cpp include/xorfilter.h include/fusefilter.h
	gcc -O3 -o unit2 tests/unit2.cpp -Iinclude -Wall -Wextra -Wshadow  -Wcast-qual -lc++

bench : benchmarks/bench.c include/xorfilter.h include/fusefilter.h
	cc -std=c99 -O3 -o bench benchmarks/bench.c -Iinclude -Wall -Wextra -Wshadow  -Wcast-qual

test: unit
	./unit
	./unit2

clean: 
	rm -f unit unit2 bench
