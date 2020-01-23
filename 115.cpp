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

/*
36
467
6214
69444
458887
3948866
22460144
45100688
206156143
1101244864
3606464370
12586459805
21775907000
34908491088
153857304456
384802111280
361856321312
1687911563144
4513793233224
11933828305552
17180694335192
21620915757952
41834930521536
33422054438336
10199319583392
26444875888024
1317101446120
7946638285384
18216512774656
16034901378080
73492955154264
27965717255080
17815222396432
72883711672240
135580183633672
14770200120312
59082069217248
59088231649248
206826301204368
88674125137872
44043264000
101498880000
211335168000
26099712000
81017856000
543744000
543744000
*/