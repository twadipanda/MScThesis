CHARMDIR = ./charm-v7.0.0
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)


default: all
all: distanceMetrics


distanceMetrics : main.o distanceMetrics.o read.o kmeans.o
	$(CHARMC) -language charm++ -o hello main.o distanceMetrics.o read.o kmeans.o

main.o : app/main.cpp include/main.h main.decl.h main.def.h kmeans.decl.h
	$(CHARMC) -I./include -I. -o main.o app/main.cpp

distanceMetrics.o : src/distanceMetrics.cpp include/distanceMetrics.h
	$(CHARMC) -I./include -I. -o distanceMetrics.o src/distanceMetrics.cpp

kmeans.o : src/kmeans.cpp include/kmeans.h kmeans.decl.h kmeans.def.h main.decl.h
	$(CHARMC) -I./include -I. -o kmeans.o src/kmeans.cpp

read.o : src/read.cpp include/read.h
	$(CHARMC) -I./include -o read.o src/read.cpp

# distanceMetrics.decl.h distanceMetrics.def.h : ci/distanceMetrics.ci
# 	$(CHARMC) ci/distanceMetrics.ci

kmeans.decl.h kmeans.def.h : ci/kmeans.ci
	$(CHARMC) ci/kmeans.ci

main.decl.h main.def.h : ci/main.ci
	$(CHARMC) ci/main.ci

clean:
	rm -f main.decl.h main.def.h main.o
	rm -f kmeans.decl.h kmeans.def.h kmeans.o
	rm -f read.o
	rm -f hello charmrun

run:
	$(CHARMDIR)/bin/charmrun +p10 ./hello
