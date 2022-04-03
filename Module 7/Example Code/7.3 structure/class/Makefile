FLAGS = -pedantic-errors -std=c++11

point.o: point.cpp point.h
			g++ $(FLAGS) -c $<

main.o: main.cpp point.h
			g++ $(FLAGS) -c $<

main: point.o main.o
			g++ $(FLAGS) $^ -o $@

clean:
			rm -f main main.o point.o

.PHONY: clean
