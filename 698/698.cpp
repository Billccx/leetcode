class Solution {
public:
    int target,k_;
    vector<int> v;

    bool dfs(int level,vector<int>& nums){
        if(level==nums.size()){
            return true;
        } 

        for(int i=0;i<k_;i++){
            if(i>0 && v[i]==v[i-1]) continue;
            if(v[i]+nums[level]<=target){
                v[i]+=nums[level];
                bool canPart=dfs(level+1,nums);
                if(canPart) return true;
                v[i]-=nums[level];
            }
        }
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        k_=k;
        v.resize(k);
        int sum=0,len=nums.size(),maxnum=-1;
        for(int i=0;i<len;i++){
            if(nums[i]>maxnum) maxnum=nums[i];
            sum+=nums[i];
        } 
        target=sum/k;
        if(maxnum>target || target*k!=sum) return false;
        bool ans=dfs(0,nums);
        return ans;

    }
};