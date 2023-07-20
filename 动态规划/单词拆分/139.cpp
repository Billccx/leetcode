class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(310);
        dp[0]=1;
        int len=s.length(),n=wordDict.size();
        for(int i=1;i<=len;i++){
            for(int j=0;j<n;j++){
                int l=wordDict[j].length();
                if(i<l) continue;
                else if(s.substr(i-l,l)!=wordDict[j]) continue;
                else if(dp[i-l]) dp[i]=1;
            }
        }
        return dp[len];
    }
};

/*
复杂度更低的写法
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

*/