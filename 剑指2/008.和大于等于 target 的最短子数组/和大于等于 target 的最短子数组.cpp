class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
        int l=0,r=0,len=nums.size(),sum=0;
        vector<int> presum;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            presum.push_back(sum);
        }
        while(r<len){
            int s=presum[r]-presum[l]+nums[l];
            if(s>=target){
                if(ans==0) ans=r-l+1;
                else ans=min(ans,r-l+1);
                l++;
                if(l>r) r=l;
            }
            else r++;
        }
        return ans;
    }
};


/*
更好的写法，在线计算前缀和


*/