default: all
all: distanceMetrics


distanceMetrics : main.o distanceMetrics.o read.o kmeans.o
	g++ -o kmeans main.o distanceMetrics.o read.o kmeans.o

main.o : app/main.cpp
	g++ -c -I./include -o main.o app/main.cpp

distanceMetrics.o : src/distanceMetrics.cpp include/distanceMetrics.hpp
	g++ -c -I./include -o distanceMetrics.o src/distanceMetrics.cpp

kmeans.o : src/kmeans.cpp include/kmeans.hpp
	g++ -c -I./include -o kmeans.o src/kmeans.cpp

read.o : src/read.cpp include/read.hpp
	g++ -c -I./include -o read.o src/read.cpp

clean:
	rm -f main.o
	rm -f kmeans.o
	rm -f distanceMetrics.o
	rm -f read.o
	rm -f test
	rm -f kmeans

test:
	g++ -o test tests/* src/* -I./include -lgtest -lgtest_main -pthread
