CHARMDIR = ./charm-v7.0.0
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)


default: all
all: distanceMetrics


distanceMetrics : main.o distanceMetrics.o read.o
	$(CHARMC) -language charm++ -o hello main.o distanceMetrics.o read.o

main.o : app/main.cpp include/main.h main.decl.h main.def.h distanceMetrics.decl.h
	$(CHARMC) -I./include -o main.o app/main.cpp

distanceMetrics.o : src/distanceMetrics.cpp include/distanceMetrics.h distanceMetrics.decl.h distanceMetrics.def.h main.decl.h
	$(CHARMC) -I./include -o distanceMetrics.o src/distanceMetrics.cpp

read.o : src/read.cpp include/read.h
	$(CHARMC) -I./include -o read.o src/read.cpp

distanceMetrics.decl.h distanceMetrics.def.h : ci/distanceMetrics.ci
	$(CHARMC) ci/distanceMetrics.ci

main.decl.h main.def.h : ci/main.ci
	$(CHARMC) ci/main.ci

clean:
	rm -f main.decl.h main.def.h main.o
	rm -f hello.decl.h hello.def.h hello.o
	rm -f hello charmrun
