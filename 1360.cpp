#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int dayOfMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool year(int x) {
        if((x % 4 == 0) && (x % 100 || x % 400 == 0)) return true;
        return false;
    }
    int daysBetweenDates(string date1, string date2) {
        vector<vector<int> > date(2);
        date1.push_back('-');
        date2.push_back('-');
        if(date1 > date2) swap(date1,date2);
        int l1 = date1.length(), l2 = date2.length();
        int num = 0;
        for(int i = 0;i < l1;i++) {
            if(date1[i] == '-') {
                date[0].push_back(num);
                num = 0;
            } else num = num * 10 + date1[i]-'0';
        }
        for(int i = 0;i < l2;i++) {
            if(date2[i] == '-') {
                date[1].push_back(num);
                num = 0;
            } else num = num * 10 + date2[i]-'0';
        }
        int ans = 0;
        for(int i = 1;i < date[0][1];i++)
            ans += dayOfMonth[i] + (year(date[0][0]) && i == 2);
        ans += date[0][2];
        ans = -ans;
        for(int i = date[0][0];i < date[1][0];i++)
            ans += year(i) ? 366 : 365;
        for(int i = 1;i < date[1][1];i++)
            ans += dayOfMonth[i] + (year(date[1][0]) && i == 2);
        ans += date[1][2];

        return ans;
    }
};

int main() {
    Solution sol;
    string date1 = "2020-01-15", date2 = "2019-12-31";
    cout<<sol.daysBetweenDates(date1, date2); 
    return 0;
}