#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <utility>

class UndergroundSystem {
public:
    map<pair<string,string>, pair<int,int> > stationMap;
    map<int, pair<string,int> > idMap;
    UndergroundSystem() {
        stationMap.clear();
        idMap.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        idMap[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int travelTime = t - idMap[id].second;
        if(stationMap.count(make_pair(idMap[id].first, stationName))) {
            stationMap[make_pair(idMap[id].first, stationName)].first += travelTime;
        } else {
            stationMap[make_pair(idMap[id].first, stationName)].first = travelTime;
        }
        stationMap[make_pair(idMap[id].first, stationName)].second ++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> target = make_pair(startStation, endStation);
        return (double)stationMap[target].first/(double)stationMap[target].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main() {
    
}