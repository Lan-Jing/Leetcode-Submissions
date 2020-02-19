#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    Manacher's algorithm. Take advantage of symmetry of palindromes.
    First insert helper char, for instance, '#' in intervals between each char of the original string.
    This will turn even palindromes into odd ones, easiler to handle. 
    When there are two symmetrical positions in a palindrome, we can in O(1) time transit information of 
    the sub-palindrome from left to right.
    1. if current palindrome doesn't reach position i, no information we can get from before: len[i] = 1
    2. if position i is within the range of the current palindrome, first we ensure len[i] = min(len[j],right-i+1).
       That is to say, we can determine the minimum length of palindrome centered at position i. And part outside the 
       current palidrome should be checked one by one.

    Be careful of the relation between numbers in p table and the final length:
    1. L = p[i] - 1
    2. leftPos = (i - p[i])/2
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans, t = "<";
        int ls = s.length();
        if(!ls) return ans;
        for(int i = 0;i < ls;i++)
            t += '#', t += s[i];
        t += "#>";
        int lt = t.length();
        vector<int> p(lt);
        int center = 0, right = 0, maxL = 0;
        for(int i = 1;i < lt-1;i++){
            if(i > right) p[i] = 1;
            // no information we can get.
            else p[i] = min(p[2*center-i],right-i+1);
            // the mimimum length we get immediately determine.
            while(t[i-p[i]] == t[i+p[i]]) p[i]++;
            // try to extend the right boundary for palindrome centered at i.
            if(i+p[i]-1 > right){
            // maintain the rightmost boundary we have so far.
                right = i+p[i]-1;
                center = i;
                if(p[i]-1 > maxL){
                    maxL = p[i]-1;
                    ans = s.substr((i-p[i])/2,p[i]-1);
                }
            }
            // replace the current palindrome if necessary.
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "abcbabcba";
    cout<<sol.longestPalindrome(input)<<endl;
    return 0;
}