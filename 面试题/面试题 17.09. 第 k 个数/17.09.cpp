class Solution {
public:
    int getKthMagicNumber(int k) {
        int i=0,j=0,l=0;
        vector<int> dp;
        dp.push_back(1);
        for(int p=0;p<k;p++){
            int p3=dp[i]*3;
            int p5=dp[j]*5;
            int p7=dp[l]*7;
            int now=min(p3,min(p5,p7));
            dp.push_back(now);
            if(now==p3){
                i++;
            } 
            if(now==p5){
                j++;
            } 
            if(now==p7){
                l++;
            } 
        }

        //for(int i=0;i<k;i++) cout<<dp[i]<<' ';
        //cout<<endl;
        return dp[k-1];
    }
};