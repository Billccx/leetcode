class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="") return "";
        int len=s.size();
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0;i<len;i++){
            dp[i][i]=1;
        }

        int maxlen=1;
        string ans=s.substr(0,1);
        for(int l=2;l<=len;l++){
            for(int i=0;i+l-1<len;i++){
                int end=i+l-1;
                if(s[i]==s[end]){
                    if(l==2) dp[i][end]=2;
                    else if(dp[i+1][end-1]>0) dp[i][end]=dp[i+1][end-1]+2;
                }
                if(dp[i][end]>maxlen){
                    maxlen=dp[i][end];
                    ans=s.substr(i,maxlen);
                }
            }
        }
        return ans;
    }
};