class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<int>> v (n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) v[j][i]=nums[j];
                else v[j][i]=min(v[j][i-1],nums[(j+i)%n]);
            }
        }

        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long tmp=((long long)i)*((long long)x);
            for(int j=0;j<n;j++){
                tmp+=v[j][i];
            }
            ans=min(ans,tmp);
        }

        return ans;
    }
};