#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <cmath>

/*
    conversion. Try to consider all situations.    
*/

class Solution {
public:
    int myAtoi(string str) {
        int lstr = str.length();
        int side = 0;
        int flag = 0;
        int ans = 0;
        for(int i = 0;i < lstr;i++){
            if(!flag && str[i] == ' ') continue;
            else if((str[i] < '0' || str[i] > '9') && (flag || (!flag && str[i] != '-' && str[i] != '+'))) return ans;
            else if(str[i] == '-' || str[i] == '+'){
                flag = 1;
                side = str[i] == '+' ? 0 : 1;
            }else if('0' <= str[i] && str[i] <= '9'){
                flag = 1;
                if(((-1)*pow(2,31) + (str[i]-'0'))/10 > ans)
                    ans = (-1)*pow(2,31);
                else if((pow(2,31)-1 - (str[i]-'0'))/10 < ans)
                    ans = pow(2,31) - 1;
                else ans = 10 * ans + pow(-1,side) * (str[i]-'0');
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.myAtoi("42")<<endl;
    cout<<sol.myAtoi("+-2")<<endl;
    cout<<sol.myAtoi("+18234sdf   ")<<endl;
    cout<<sol.myAtoi("    -42")<<endl;
    cout<<sol.myAtoi("4193 with words")<<endl;
    cout<<sol.myAtoi("words and 987")<<endl;
    cout<<sol.myAtoi("-91283472332")<<endl;
}