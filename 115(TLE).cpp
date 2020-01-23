#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

class Solution {
public:
    int numDistinct(string s, string t) {
        if(!t.length() || s.length() < t.length()) return 0;
        int ls = s.length(), lt = t.length();
        cout<<lt<<' '<<ls<<endl;
        vector<vector<long long int> > dp;
        dp.resize(lt);
        for(int i = 0;i < lt;i++) dp[i].resize(ls);
        for(int j = 0;j < ls;j++)
            if(t[0] == s[j]) dp[0][j] = 1;
        for(int i = 1;i < lt;i++)
            for(int j = 0;j < ls-1;j++)
                for(int k = j+1;k < ls;k++)
                    if(t[i] == s[k])
                        dp[i][k] += dp[i-1][j];
        for(int i = 0;i < lt;i++){
            for(int j = 0;j < ls;j++) cout<<dp[i][j]<<' '; cout<<endl;
        }
        long long int ans = 0;
        for(int i = 0;i < ls;i++) ans += dp[lt-1][i];
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "rabbbit", t = "rabbit";
    cout<<sol.numDistinct(s,t)<<endl;
//    s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
//    t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
//    cout<<sol.numDistinct(s,t)<<endl;
    return 0;
}