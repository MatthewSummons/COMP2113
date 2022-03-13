# Makefile
# Created by Shaheer Ziya on UTC+08 19:05

FLAGS = -pedantic-errors -std=c++11

gcd.o: gcd.cpp gcd.h
	g++ $(FLAGS) -c $<
lcm.o: lcm.cpp lcm.h
	g++ $(FLAGS) -c $<
calc.o: calc.cpp gcd.h lcm.h 
	g++ $(FLAGS) -c $<
calc: gcd.o lcm.o calc.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o calc

.PHONY: clean
