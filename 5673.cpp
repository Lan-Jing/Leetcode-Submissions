#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> vec;
        vec.push_back(a), vec.push_back(b), vec.push_back(c);

        sort(vec.begin(), vec.end());

        int score = 0;
        if(vec[0]+vec[1] <= vec[2]) {
            return vec[0]+vec[1];
        } else {
            score += vec[1]-vec[0];
            vec[1] -= score, vec[2] -= score;
            
            int a = vec[2]/2, b = vec[2]-a;
            score += vec[2];
            vec[0] -= a, vec[1] -= b;
            score += min(vec[0], vec[1]);
        }
        return score;
    }
};