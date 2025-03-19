CHARMDIR = ./charm-v7.0.0
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)

default: all
all: pso


pso : main.o pso.o particle.o benchmark.o
	$(CHARMC) -language charm++ main.o benchmark.o particle.o pso.o -o pso

main.o : app/main.cpp include/main.h main.decl.h main.def.h
	$(CHARMC) -I./include -I. -o main.o app/main.cpp

pso.o : src/pso.cpp pso.decl.h pso.def.h main.decl.h
	$(CHARMC) -I./include -I. -o pso.o src/pso.cpp

particle.o : src/particle.cpp include/particle.hpp
	$(CHARMC) -I./include -o particle.o src/particle.cpp

benchmark.o : src/benchmark.cpp
	$(CHARMC) -I./include -o benchmark.o src/benchmark.cpp

pso.decl.h pso.def.h : ci/pso.ci
	$(CHARMC) ci/pso.ci

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