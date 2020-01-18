#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

/*
    BFS topological sort
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        int inDegree[100010];
        int cnt = 0;
        vector<vector<int> > neighbors;
        neighbors.resize(100010);
        memset(inDegree,0,sizeof(inDegree));
        for(int i = 0;i < prerequisites.size();i++){
            int in = prerequisites[i][0], out = prerequisites[i][1];
            inDegree[in]++;
            neighbors[out].push_back(in);
        } 
        queue<int> topoQue;
        for(int i = 0;i < numCourses;i++)
            if(!inDegree[i]) topoQue.push(i), cnt++;
        while(!topoQue.empty()){
            int now = topoQue.front(); topoQue.pop();
            for(int i = 0;i < neighbors[now].size();i++){
                inDegree[neighbors[now][i]]--;
                if(!inDegree[neighbors[now][i]])
                    topoQue.push(neighbors[now][i]), cnt++;
            }
        }
        if(cnt < numCourses) return false;
        else return true;
    }
};

int main() {

}