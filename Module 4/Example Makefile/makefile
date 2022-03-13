FLAGS = -pedantic-errors -std=c++11

gcd.o: gcd.cpp gcd.h
	g++ $(FLAGS) -c $<
gcd_main.o: gcd_main.cpp gcd.h
	g++ $(FLAGS) -c $<
gcd: gcd.o gcd_main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f gcd gcd.o gcd_main.o gcd.tgz
tar:
	tar -czvf gcd.tgz *.cpp *.h

.PHONY: clean tar

