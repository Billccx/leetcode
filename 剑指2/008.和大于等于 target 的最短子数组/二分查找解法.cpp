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
        for(int i=0;i<len;i++){
            int t=presum[i]+target-nums[i];
            auto p=lower_bound(presum.begin(),presum.end(),t);
            if(p==presum.end()) break;

            if(ans==0) ans=(int)(p-presum.begin())-i+1;
            else ans=min(ans,(int)(p-presum.begin())-i+1);
        }
        return ans;
    }
};