#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

/*
    fast check on Nqueens-style chessboard.
    a TlE solution used binary_search to find coreesponding record.
    It could be better to use STL map to implement a O(logn) search manner
*/

class Solution {
public:
    int gox[9]={-1,0,1,-1,0,1,-1,0,1}, goy[9]={-1,-1,-1,0,0,0,1,1,1};
    vector<int> gridIllumination(int N, vector<vector<int> > &lamps, vector<vector<int> > &queries) {
        map<pair<int,int>,int> pos, ldiagMap, rdiagMap;
        map<int,int> xMap, yMap;
        for(int i = 0;i < lamps.size();i++){
            pos[make_pair(lamps[i][0],lamps[i][1])] = i;
            xMap[lamps[i][0]]++, yMap[lamps[i][1]]++;
            int x = lamps[i][0] - min(lamps[i][0],lamps[i][1]),
                y = lamps[i][1] - min(lamps[i][0],lamps[i][1]);
            ldiagMap[make_pair(x,y)]++;
            x = lamps[i][0] + min(N-lamps[i][0]-1,lamps[i][1]);
            y = lamps[i][1] - min(N-lamps[i][0]-1,lamps[i][1]);
            rdiagMap[make_pair(x,y)]++;
        }
        vector<int> res;
        for(int i = 0;i < queries.size();i++){
            int x = queries[i][0], y = queries[i][1];
            int t1 = min(x,y), t2 = min(N-x-1,y);
            if(!xMap[x] && !yMap[y] && !ldiagMap[make_pair(x-t1,y-t1)] && !rdiagMap[make_pair(x+t2,y-t2)])
                res.push_back(0);
            else res.push_back(1);

            for(int i = 0;i < 9;i++){
                int nx = x + gox[i], ny = y + goy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(!pos.count(make_pair(nx,ny))) continue;
                int index = pos[make_pair(nx,ny)];
                pos.erase(make_pair(nx,ny));
                xMap[lamps[index][0]]--, yMap[lamps[index][1]]--;
                x = lamps[index][0], y = lamps[index][1];
                t1 = min(x,y), t2 = min(N-x-1,y);
                ldiagMap[make_pair(x-t1,y-t1)]--, rdiagMap[make_pair(x+t2,y-t2)]--;
            }
        }
        return res;
    }
};


int main() {

}