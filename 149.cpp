#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

class Solution {
public:
    struct line {
        double a, b, c;
        line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
        bool onLine(vector<int> &point) {
            return abs(a*(double)point[0] + b*(double)point[1] + c) < 1e-10 ;
        }
        bool operator < (const line &other) const {
            if(a != other.a) return a < other.a;
            else if(b != other.b) return b < other.b;
            else return c < other.c;
        }
    };
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 2) return points.size();
        set<line> lineSet;
        int ans = 2;
        map<vector<int>,int> pointMap;
        for(int i = 0;i < points.size();i++){
            pointMap[points[i]]++;
            ans = max(ans,pointMap[points[i]]);
        }
        double a = 0, b = 0, c = 0;
        for(int i = 0;i < points.size();i++)
            for(int j = i+1;j < points.size();j++){
                long long int delta = (long long)points[i][0]*(long long)points[j][1] - (long long)points[i][1]*(long long)points[j][0];
                if(!delta){
                    if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) continue;
                    c = 0;
                    if(points[i][0] == 0 && points[j][0] == 0) a = 1, b = 0;
                    else if(points[i][1] == 0 && points[j][1] == 0) a = 0, b = 1;
                    else a = -1, b = 1;
                }else{
                    c = 1;
                    a = (double)(points[i][1]-points[j][1]) / (double)delta;
                    b = (double)(points[j][0]-points[i][0]) / (double)delta;
                }
                line nowLine = line(a,b,c);
                if(lineSet.count(nowLine)) continue; else lineSet.insert(nowLine);
                int tmp = 2;
                for(int k = 0;k < points.size();k++){
                    if(k == i || k == j) continue;
                    if(nowLine.onLine(points[k])) tmp++;
                }
                ans = max(ans,tmp);
            }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> point;
    vector<vector<int> > points;
    point = {0,0}; points.push_back(point);
    point = {-1,-1}; points.push_back(point);
    point = {2,2}; points.push_back(point);
    cout<<sol.maxPoints(points)<<endl;
    return 0;
}