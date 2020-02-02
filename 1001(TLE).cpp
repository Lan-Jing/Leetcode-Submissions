#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

class Solution {
public:
    struct xFirstCmp {
        bool operator () (const vector<int> &n1, const vector<int> &n2) {
            if(n1[0] != n2[0]) return n1[0] < n2[0];
            else return n1[1] < n2[1];
        }
    };
    struct yFirstCmp {
        bool operator () (const vector<int> &n1, const vector<int> &n2) {
            if(n1[1] != n2[1]) return n1[1] < n2[1];
            else return n1[0] < n2[0];
        }
    };
    int binarySearch(vector<pair<int,int> > arr, int target) {
        if(!arr.size()) return -1;
        int l = 0, r = arr.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(arr[mid].first < target) l = mid + 1;
            else r = mid;
        }
        if(target == arr[l].first) return l;
        else return -1;
    }
    int gox[9]={-1,0,1,-1,0,1,-1,0,1}, goy[9]={-1,-1,-1,0,0,0,1,1,1};
    vector<int> gridIllumination(int N, vector<vector<int> > &lamps,
                                 vector<vector<int> > &queries) {
        vector<vector<int> > xLamps, yLamps;
        xLamps = yLamps = lamps;
        sort(xLamps.begin(),xLamps.end(),xFirstCmp());
        sort(yLamps.begin(),yLamps.end(),yFirstCmp());
        vector<pair<int,int> > X, Y, diagX, diagY, diagX1, diagY1;
        int last = -1;
        for(int i = 0;i < xLamps.size();i++){
            if(xLamps[i][0] == last){
                X[X.size()-1].second++;
            }else{
                last = xLamps[i][0]; 
                X.push_back(make_pair(last,1));
            }
        }
        last = -1;
        for(int i = 0;i < yLamps.size();i++){
            if(yLamps[i][1] == last){
                Y[Y.size()-1].second++;
            }else{
                last = yLamps[i][1];
                Y.push_back(make_pair(last,1));
            }
        }
        map<int,int> Xmap, Ymap, Xmap1, Ymap1;
        set<pair<int,int>> nodeSet;
        for(int i = 0;i < lamps.size();i++){
            int nx = lamps[i][0], ny = lamps[i][1];
            nx -= min(lamps[i][0],lamps[i][1]);
            ny -= min(lamps[i][0],lamps[i][1]);
            if(nx) Xmap[nx]++; else Ymap[ny]++;

            nx = lamps[i][0], ny = lamps[i][1];
            nx += min(N-lamps[i][0]-1,lamps[i][1]);
            ny -= min(N-lamps[i][0]-1,lamps[i][1]);
            if(ny) Ymap1[ny]++; else Xmap1[nx]++; 

            nodeSet.insert(make_pair(lamps[i][0],lamps[i][1]));
        }
        for(map<int,int>::iterator iter = Xmap.begin();iter != Xmap.end();iter++)
            diagX.push_back(make_pair(iter->first,iter->second));
        for(map<int,int>::iterator iter = Ymap.begin();iter != Ymap.end();iter++)
            diagY.push_back(make_pair(iter->first,iter->second));
        for(map<int,int>::iterator iter = Xmap1.begin();iter != Xmap1.end();iter++)
            diagX1.push_back(make_pair(iter->first,iter->second));
        for(map<int,int>::iterator iter = Ymap1.begin();iter != Ymap1.end();iter++)
            diagY1.push_back(make_pair(iter->first,iter->second));

        vector<int> res;
        for(int i = 0;i < queries.size();i++) {
            int xPos = binarySearch(X,queries[i][0]);
            int yPos = binarySearch(Y,queries[i][1]);
            int nx = queries[i][0] - min(queries[i][0],queries[i][1]);
            int ny = queries[i][1] - min(queries[i][0],queries[i][1]);
            int nx1 = queries[i][0] + min(N-queries[i][0]-1,queries[i][1]);
            int ny1 = queries[i][1] - min(N-queries[i][0]-1,queries[i][1]);
            int diagPos = nx ? binarySearch(diagX,nx) : binarySearch(diagY,ny);
            int diagPos1 = ny1 ? binarySearch(diagY1,ny1) : binarySearch(diagX1,nx1);
            if((xPos == -1 || !X[xPos].second) && (yPos == -1 || !Y[yPos].second) && 
               (diagPos == -1 || !(nx ? diagX[diagPos].second : diagY[diagPos].second)) && 
               (diagPos1 == -1 || !(ny1 ? diagY1[diagPos1].second : diagX1[diagPos1].second))) res.push_back(0);
            else res.push_back(1);

            for(int j = 0;j < 9;j++){
                int x = queries[i][0] + gox[j];
                int y = queries[i][1] + goy[j];
                if(y < 0 || x < 0 || y >= N || x >= N) continue;
                if(!nodeSet.count(make_pair(x,y))) continue; else nodeSet.erase(make_pair(x,y));
                xPos = binarySearch(X,x), yPos = binarySearch(Y,y);
                X[xPos].second--; Y[yPos].second--;

                nx = x - min(x,y), ny = y - min(x,y);
                diagPos = nx ? binarySearch(diagX,nx) : binarySearch(diagY,ny);
                nx ? diagX[diagPos].second-- : diagY[diagPos].second--;
                
                nx = x + min(N-x-1,y), ny = y - min(N-x-1,y);
                diagPos = ny ? binarySearch(diagY1,ny) : binarySearch(diagX1,nx);
                ny ? diagY1[diagPos].second-- : diagX1[diagPos].second--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > lamps, queries;
    int N = 5;
    vector<int> node;
    node = {0,0}; lamps.push_back(node);
    node = {4,4}; lamps.push_back(node);
    node = {3,2}; lamps.push_back(node);
    node = {1,2}; lamps.push_back(node);
    node = {3,3}; lamps.push_back(node);
    node = {1,1}; queries.push_back(node);
    node = {1,0}; queries.push_back(node);
    node = {3,2}; queries.push_back(node);
    node = {1,0}; queries.push_back(node);
    vector<int> output = sol.gridIllumination(N,lamps,queries);
    for(int i = 0;i < output.size();i++) cout<<output[i]<<' '; cout<<endl;
    return 0;
}
