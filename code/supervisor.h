//
// Created by Madalena Ye on 11/03/2023.
//

#ifndef DA_SUPERVISOR_H
#define DA_SUPERVISOR_H

#include "graph.h"
#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include "station.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Supervisor{
public:
    Supervisor();

    unordered_map<string, int> getId();
private:

    void createStations();
    void createGraph();

    Station::StationH stations;
    unordered_map<string, int> idStations;
    Graph graph = Graph(532);
};


#endif //DA_SUPERVISOR_H