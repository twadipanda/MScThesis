default: all
all: ga

ga : main.o benchmark.o crossover.o ga.o mutation.o selection.o
	g++ main.o benchmark.o crossover.o ga.o mutation.o selection.o -o ga

main.o : app/main.cpp
	g++ -c -static-libstdc++ -I./include -o main.o app/main.cpp

benchmark.o : src/benchmark.cpp
	g++ -c -static-libstdc++ -I./include -o benchmark.o src/benchmark.cpp

crossover.o : src/crossoverHeuristic.cpp
	g++ -c -static-libstdc++ -I./include -o crossover.o src/crossoverHeuristic.cpp

ga.o : src/ga.cpp
	g++ -c -static-libstdc++ -I./include -o ga.o src/ga.cpp

mutation.o : src/mutationHeuristic.cpp
	g++ -c -static-libstdc++ -I./include -o mutation.o src/mutationHeuristic.cpp

selection.o : src/selectionHeuristic.cpp
	g++ -c -static-libstdc++ -I./include -o selection.o src/selectionHeuristic.cpp

clean:
	rm -f main.o benchmark.o crossover.o ga.o mutation.o selection.o ga
