#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string print(string s, int numRows, int mode, int pos) {
        int l = s.length();
        string res;
        if(mode == 0){
            int ptr = pos - 1;
            do{
                res += s[ptr];
                ptr += numRows != 1 ? 2 * numRows - 2 : 1;
//                cout<<res<<endl;
            }while(ptr < l);
        }else{
            int ptr = pos - 1;
            int iter = 0;
            do{
                res += s[ptr];
                ptr += iter == 0 ? 2 * numRows - 2 - 2 * (pos - 1) : 2 * (pos - 1);
                iter = 1 - iter;
//                cout<<res<<endl;
            }while(ptr < l);
        }
        return res;
    }
    string convert(string s, int numRows) {
        string ans;
        for(int i = 1;i <= numRows;i++){
            if(i == 1 || i == numRows) ans += print(s,numRows,0,i);
            else ans += print(s,numRows,1,i);
        }
        return ans;
    }
};

int main() {
    string input = "PAYPALISHIRING";
    Solution sol;
    cout<<sol.convert(input,4)<<endl;
    input = "A";
    cout<<sol.convert(input,1)<<endl;
    return 0;
}