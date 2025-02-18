#include "main.decl.h"

#include "main.h"
#include "distanceMetrics.decl.h"

#include<vector>
#include<iostream>
#include <chrono>
#include "read.h"

/* readonly */ CProxy_Main mainProxy;
// int indexCount;


// Entry point of Charm++ application
Main::Main(CkArgMsg* msg) {
    mainProxy = thisProxy;
    int k = 2;
    KmeansParser::Reader reader("letter.txt");
    std::vector<std::vector<double>> points = reader.readAndParse();
    std::vector<std::vector<double>> centers;
    for (int i = 0; i < k; i++) {
        centers.push_back(points[i]);
    }
    CProxy_DistanceMetrics distanceMetricsArray = CProxy_DistanceMetrics::ckNew(1000);
    distanceMetricsArray[0].euclideanDistance(points[0], centers[0]);
}


// Constructor needed for chare object migration (ignore for now)
// NOTE: This constructor does not need to appear in the ".ci" file
Main::Main(CkMigrateMessage* msg) { }

void Main::finished(double value, int index) {
    CkPrintf("Got value from index %d on processor %d" index, CkMyPe());
    if (index == 0) {
        done();
    }
}


// When called, the "done()" entry method will cause the program
//   to exit.
void Main::done() {
  CkExit();
}


#include "main.def.h"
