class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        vector<vector<int>> v(len,vector<int>(2));
        int cnt=1;
        v[0][0]=1;
        for(int i=1;i<len;i++){
            if(ratings[i]>ratings[i-1]){
                cnt++;
                v[i][0]=cnt;
            }
            else{
                cnt=1;
                v[i][0]=1;
            }
        }

        cnt=1;
        v[len-1][1]=1;
        for(int i=len-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                cnt++;
                v[i][1]=cnt;
            }
            else{
                cnt=1;
                v[i][1]=1;
            }
        }

        int ans=0;
        for(int i=0;i<len;i++){
            ans+=max(v[i][0],v[i][1]);
        }
        return ans;
    }
};