class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int sum=0,len=nums.size(),ans=0;
        ump[0]++;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            int target=sum-k;
            if(ump.count(target)) ans+=ump[target];
            //从左向右扫描的过程中加入，避免了判断target是否出现在i的左侧的问题
            ump[sum]++;
        }
        return ans;
    }
};