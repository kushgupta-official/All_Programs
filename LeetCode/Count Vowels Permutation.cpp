class Solution {
public:
    const int MOD=1e9+7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} },
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
    unordered_map <char,vector <int> > dp;
    int solve(int n,char ch){
        if (n==0)
            return 1;
        if (dp[ch][n])
            return dp[ch][n];
        for (auto i:mappings.at(ch)){
            dp[ch][n]=(dp[ch][n]+solve(n-1,i))%MOD;
        }
        return dp[ch][n];
    }
    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return solve(n,'s');
    }
};