#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans;
        char ch[2];
        if(A > B) ch[0] = 'a', ch[1] = 'b';
        else      ch[0] = 'b', ch[1] = 'a', swap(A, B);

        while(A || B) {
            if(A) ans.push_back(ch[0]), A--;
            if(A && A >= B) ans.push_back(ch[0]), A--;
            if(B) ans.push_back(ch[1]), B--;
        }
       
        return ans;
    }
};