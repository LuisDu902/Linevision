
#ifndef DA_SUPERVISOR_H
#define DA_SUPERVISOR_H


#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>


#include "Graph.h"
#include "Station.h"
using namespace std;

class Supervisor{
public:
    Supervisor();

    Station::StationH getStations() const;
    unordered_map<string, int> getId() const;
    unordered_map<string, int> getSubGraphStations() const;
    unordered_map<string, Station::StationH> getMunicipalityStations();
    unordered_map<string, Station::StationH> getDistrictStations();

    Graph getGraph() const;
    Graph getSubGraph() const;

    bool isStation(const string& station);
    bool isLine(const string& line);

    void createSubgraph(const unordered_set<string>& failedLines);
    void createSubgraph(const vector<pair<string, string>>& failedSegments);
    void createSubgraph(const Station::StationH& failedStations);
    vector<pair<string, int>> topBudget(int type);

private:

    void createStations();
    void createGraph();

    void checkField(istringstream &iss, string &field);
    string removeQuotes(istringstream &iss, string field);

    int makeVertex(Graph &_graph, unordered_map<string, int> &ids, const string &name, int &id);

    //void removeUnusedStations();

    bool segmentFailure(const vector<pair<string, string>>& failedSegments, const string& source, const string& target);
    bool lineFailure(unordered_set<string> failedLines, const string &source, const string &target);
    bool stationFailure(Station::StationH failedStations, const string &source, const string &target);

    Station::StationH stations;

    unordered_map<string, int> idStations;
    unordered_map<string, Station::StationH> municipalityStations;
    unordered_map<string, Station::StationH> districtStations;

    unordered_map<string, int> subGraphStations;

    unordered_set<string> lines;
    unordered_map<string, Station::StationH> stationsPerLine;

    Graph graph;
    Graph subGraph;

};


#endif //DA_SUPERVISOR_H
