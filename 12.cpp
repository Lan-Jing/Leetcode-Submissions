#include <iostream>
using namespace std;
#include <string>
#include <cstring>

/*
    easy conversion.
*/

class Solution {
public:
    string intToRoman(int num) {
        string Roman;
        int nums[20] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string chars[20] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int ptr = 0;
        while(num){
            ptr = 0;
            while(num < nums[ptr]) ptr++;
            num -= nums[ptr];
            Roman += chars[ptr];
        }
        return Roman;
    }
};

int main(){
    Solution sol;
    cout<<sol.intToRoman(3)<<endl;
    cout<<sol.intToRoman(4)<<endl;
    cout<<sol.intToRoman(9)<<endl;
    cout<<sol.intToRoman(58)<<endl;
    cout<<sol.intToRoman(1994)<<endl;
    return 0;
}