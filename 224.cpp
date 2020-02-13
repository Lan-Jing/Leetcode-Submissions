#include <iostream>
using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    void eval(stack<char> &opStk, stack<long long int> &numStk) {
        int a = numStk.top(); numStk.pop(); 
        int b = numStk.top(); numStk.pop();
        if(opStk.top() == '+') numStk.push(a+b);
        else numStk.push(b-a);
        opStk.pop();
    }
    int calculate(string s) {
        long long int num = -1, ls = s.length();
        stack<char> opStk;
        stack<long long int> numStk;
        for(int i = 0;i < ls;i++){
            if(s[i] == ' ') continue;
            if('0' <= s[i] && s[i] <= '9'){
                if(num == -1) num = s[i] - '0';
                else num = num * 10 + s[i] - '0';
            }else{
                if(num != -1) numStk.push(num), num = -1;
                if(s[i] == ')'){
                    while(opStk.top() != '(')
                        eval(opStk,numStk);
                    opStk.pop();
                }else{
                    if(s[i] != '(' && !opStk.empty() && opStk.top() != '(') 
                        eval(opStk,numStk);
                    opStk.push(s[i]);
                }
            }
        }
        if(num != -1) numStk.push(num);
        while(!opStk.empty()) eval(opStk,numStk);
        return numStk.top();
    }
};

int main() {
    Solution sol;
    string input = "(1+(4+5+2)-3)+(6+8)";
    cout<<sol.calculate(input)<<endl;
    return 0;
}