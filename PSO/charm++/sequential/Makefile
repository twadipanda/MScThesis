default: all
all: pso

pso : main.o pso.o particle.o benchmark.o
	g++ main.o benchmark.o particle.o pso.o -o pso

main.o : app/main.cpp
	g++ -c -I./include -o main.o app/main.cpp

pso.o : src/pso.cpp include/pso.hpp
	g++ -c -I./include -o pso.o src/pso.cpp

particle.o : src/particle.cpp include/particle.hpp
	g++ -c -I./include -o particle.o src/particle.cpp

benchmark.o : src/benchmark.cpp include/benchmark.hpp
	g++ -c -I./include -o benchmark.o src/benchmark.cpp

clean:
	rm -f main.o pso.o particle.o benchmark.o pso