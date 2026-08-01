all: test1 test2

test: test1 test2
	./test1
	./test2
	

test1: test1.cpp safeint1.cpp safeint2.cpp safeint.h
	g++ -ggdb -std=c++20 test1.cpp safeint1.cpp safeint2.cpp -o test1

test2: test2.cpp safeint1.cpp safeint2.cpp safeint.h
	g++ -ggdb -std=c++20 test2.cpp safeint1.cpp safeint2.cpp -o test2

clean: mostlyclean
	rm -f test1 test2 a.out

mostlyclean:
	true

.PHONY: all clean mostlyclean test