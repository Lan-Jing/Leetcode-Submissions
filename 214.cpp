#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
    Find the shortest palindrome in O(n) time.
    The basic idea of the O(n^2) solution is determining the longest sub-palindrome as prefix of s.
    Interestingly with the palindrome property we make use of KMP. Concretely, if a prefix of s is
    a palindrome, its reverse matches itself. Then we may reverse s and concatenate with itself, such as 
    "abbacd dcabba". Therefore, the sub-palindrome on the left matches itself on the right, which is exactly 
    what KMP is looking for. 
    Mind special cases like "aabba", when KMP run on s+rev(s), which is "aabbaabbaa", it cross over the middle of two 
    strings. To prevent this we can insert a space " " in the middle, making it "aabba abbaa". Then the algorithm will
    perform perfectly.
*/

class Solution {
public:
    int getNext(string s) {
        vector<int> next(s.length());
        next[0] = -1;
        int l = -1;
        for(int r = 1;r < s.length();r++){
            while(s[l+1] != s[r] && l > -1) l = next[l];
            next[r] = s[l+1] == s[r] ? ++l : l;
        }
        return next.back();
    }
    string shortestPalindrome(string s) {
        if(!s.length()) return s;
        string t = s; reverse(t.begin(),t.end());

        for(int i = getNext(s+" "+t)+1;i < s.length();i++) t += s[i];
        reverse(t.begin(),t.end());
        return t;
    }
};

int main() {
    Solution sol;
    string input = "abbacd";
    cout<<sol.shortestPalindrome(input)<<endl;
    return 0;
}