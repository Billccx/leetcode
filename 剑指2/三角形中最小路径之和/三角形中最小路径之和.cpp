class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> v(n+1);
        v[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                v[j]=min(
                    (j-1>=0 ? v[j-1]:INT_MAX),
                    (j==i ? INT_MAX: v[j])
                )+triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,v[i]);
        return ans;
    }
};