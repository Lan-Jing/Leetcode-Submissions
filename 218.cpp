#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

/*
    The problem is to find the maximum height for every edge point, provided by left and right edges the rectangle set.
    Segment tree should be the most obvious solution. We can use heap to improve our plain scanning strategy.
    When we find the left bound of a new rectangle, push it into the heap. Otherwise right edges of visited rectangles are reached. 
    Pop them. Then the maximum height should stay at the top of the heap. Some details to handle.

    1. It is unlikely we can remove a node in a stl heap.
       We record the position information for each point, pop every obsolete point before comparasion.
    2. It is possible that a point with maximum height locates in the middle of some rectangle, instead of the leftmost location.
       Check the last point pushed into the ans vector, if that point holds the same height, throw out the current one.
    3. Multiple left edges of rectangle may appear at the same time.
       Only keep the one with largest height. Mind that this condition should be handled first then condition 2: max height first 
       determined, validaity then checked.
*/

class Solution {
public:
    struct edge {
        int pos, bInd, lOrR;
        bool operator < (const edge &other) const {
            if(pos != other.pos) return pos < other.pos;
            else return lOrR > other.lOrR;
        }
        edge(int _pos, int _ind, int _lr) : pos(_pos), bInd(_ind), lOrR(_lr) {}
    };
    struct queNode {
        int height, bInd;
        bool operator < (const queNode &other) const {
            return height < other.height;
        }
        queNode(int _h, int _ind) : height(_h), bInd(_ind) {}
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int> > ans;
        int n = buildings.size();
        if(!n) return ans;
        vector<edge> points;
        for(int i = 0;i < n;i++){
            points.push_back(edge(buildings[i][0],i,0));
            points.push_back(edge(buildings[i][1],i,1));
        }
        sort(points.begin(),points.end());
        priority_queue<queNode> que;
        vector<int> point(2);
        for(int i = 0;i < points.size();i++){
            if(!points[i].lOrR) 
                que.push(queNode(buildings[points[i].bInd][2],points[i].bInd));
            while(!que.empty() && buildings[que.top().bInd][1] <= points[i].pos)
                que.pop();
            point[0] = points[i].pos;
            point[1] = que.empty() ? 0 : que.top().height;
            if(ans.size() && ans.back()[0] == point[0])
                ans.back()[1] = max(ans.back()[1],point[1]);
            else ans.push_back(point);
            while(ans.size()>1 && ans[ans.size()-2][1] == ans[ans.size()-1][1])
                ans.pop_back();
        } 
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > buildings;
    vector<int> building;
    building = {1,2,1}; buildings.push_back(building);
    building = {2147483646,2147483647,2147483647}; buildings.push_back(building);
    vector<vector<int> > ans = sol.getSkyline(buildings);
    for(int i = 0;i < ans.size();i++) cout<<ans[i][0]<<','<<ans[i][1]<<endl;
    return 0;
}