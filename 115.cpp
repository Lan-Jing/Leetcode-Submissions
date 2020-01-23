#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

/*
    a TLE(O(N*M^2)) solution was once designed, but was straight forward.
    Consider dp[i][j] representing all possibilities of s[0-j] matching t[0-i],
    each time we determine a partition s[0-j](which matches t[0-(i-1)]), we can find an additional matching 
    char s[k](k > j) == t[i] so that possibilities (from dp[i-1][j]) carries to t[i], which is represented by dp[i][k]. 
    dp[i][j] is the sum of all these carries.

    However, dp[i][j] mandates that s[j] has to be matched so that additional loops are required.
    We can remove the restriction and sum up all dp[i][k](0 <= k < j) to dp[i][j]. Now dp[i][j]
    represents all possibilities that all substrings from [0,j](instead of the single one ends in s[j]) matching substing t[0-i]. 
    Each time a match (t[i] == s[j]) occurs, possibilities from t[0-(i-1)] goes to dp[i][j], otherwise possibilities 
    from t[0-i] with smaller range s[0-(j-1)] is carried.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        if(!t.length() || s.length() < t.length()) return 0;
        int ls = s.length(), lt = t.length();
        vector<vector<long long int> > dp;
        dp.resize(lt);
        for(int i = 0;i < lt;i++) dp[i].resize(ls);
        for(int i = 0;i < ls;i++)
            if(t[0] == s[i]) dp[0][i] = i ? dp[0][i-1] + 1 : 1;
            else dp[0][i] = i ? dp[0][i-1] : 0;
        for(int i = 1;i < lt;i++)
            for(int j = 0;j < ls;j++){
                dp[i][j] += j ? dp[i][j-1] : 0;
                if(t[i] == s[j])
                    dp[i][j] += j ? dp[i-1][j-1] : 0;
            }
/*        for(int i = 0;i < lt;i++){
            for(int j = 0;j < ls;j++) cout<<dp[i][j]<<' '; cout<<endl;
        }
*/        return dp[lt-1][ls-1];
    }
};

int main(){
    Solution sol;
    string s = "rababbit", t = "rabbit";
    cout<<sol.numDistinct(s,t)<<endl;
    s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    cout<<sol.numDistinct(s,t)<<endl;
    return 0;
}
