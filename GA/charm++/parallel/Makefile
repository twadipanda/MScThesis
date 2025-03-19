CHARMDIR = ./charm-v7.0.0
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)

default: all
all: ga


ga : main.o benchmark.o crossover.o ga.o mutation.o selection.o
	$(CHARMC) -language charm++ -o ga main.o benchmark.o crossover.o ga.o mutation.o selection.o

main.o : app/main.cpp include/main.h main.decl.h main.def.h ga.decl.h
	$(CHARMC) -I./include -I. -o main.o app/main.cpp

ga.o : src/ga.cpp ga.decl.h ga.def.h main.decl.h
	$(CHARMC) -I./include -I. -o ga.o src/ga.cpp

benchmark.o : src/benchmark.cpp
	$(CHARMC) -I./include -o benchmark.o src/benchmark.cpp

crossover.o : src/crossoverHeuristic.cpp
	$(CHARMC) -I./include -o crossover.o src/crossoverHeuristic.cpp

mutation.o : src/mutationHeuristic.cpp
	$(CHARMC) -I./include -o mutation.o src/mutationHeuristic.cpp

selection.o : src/selectionHeuristic.cpp
	$(CHARMC) -I./include -o selection.o src/selectionHeuristic.cpp

ga.decl.h ga.def.h : ci/ga.ci
	$(CHARMC) ci/ga.ci

main.decl.h main.def.h : ci/main.ci
	$(CHARMC) ci/main.ci

clean:
	rm -f main.decl.h main.def.h
	rm -f main.o benchmark.o crossover.o ga.o mutation.o selection.o ga
	rm -f ga.decl.h ga.def.h
	rm -f charmrun

run-quiet:
	$(CHARMDIR)/bin/charmrun +p7 ./ga ++quiet

run:
	$(CHARMDIR)/bin/charmrun +p7 ./ga
