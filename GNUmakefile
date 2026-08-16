all: libcsafe.so test2 test64 testcsintstreams testbinmanip testcsint 

test: test2 test64 testbinmanip testcsint testcsintstreams
	./test2
	./test64
	./testbinmanip
	./testcsint

testcsintstreams: testcsintstreams.o csint.o
	g++ -ggdb -std=c++23 testcsintstreams.o csint.o -lboost_unit_test_framework -o testcsintstreams	

testcsintstreams.o: testcsintstreams.cpp csint.hpp
	g++ -ggdb -std=c++23 testcsintstreams.cpp -c

testbinmanip: testbinmanip.o
	g++ -ggdb -std=c++23 testbinmanip.o -lboost_unit_test_framework -o testbinmanip 

testbinmanip.o: testbinmanip.cpp accuorg_binary.hpp
	g++ -std=c++23 -o testbinmanip.o -c testbinmanip.cpp 
	
libcsafe.so: safe64.o
	g++ -shared -o libcsafe.so -fPIC safe64.o
	
test64: test64.o safe64.o
	g++  -ggdb safe64.o test64.o -lboost_unit_test_framework -o test64

test64.o: test64.cpp safe64.h
	g++ -ggdb -std=c++23 test64.cpp -c

safe64.o: safe64.cpp safe64.h
	g++ -ggdb -fPIC -std=c++23 safe64.cpp -c

test1: test1.cpp safeint1.cpp safeint2.cpp safeint.h
	g++ -ggdb -std=c++23 test1.cpp safeint1.cpp safeint2.cpp -lboost_unit_test_framework -o test1

test2: test2.cpp safeint1.cpp safeint2.cpp safeint.h
	g++ -ggdb -std=c++20 test2.cpp safeint1.cpp safeint2.cpp -o test2

csintsyn: csint.hpp
	g++ -std=c++23 -fsyntax-only csint.hpp

csint.o: csint.cpp csint.hpp
	g++  -ggdb -std=c++23 csint.cpp -c 

testcsint.o: csint.hpp testcsint.cpp
	g++  -ggdb -std=c++23 testcsint.cpp -c

testcsint: csint.o testcsint.o
	g++  -ggdb -std=c++23 testcsint.o csint.o -lboost_unit_test_framework -o testcsint	

clean: mostlyclean
	rm -f test1 test2 a.out testcsintstreams test64

mostlyclean:
	rm -f *.o

.PHONY: all clean mostlyclean test csintsyn

