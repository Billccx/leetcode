class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0,cnt=0,len=nums.size();
        unordered_map<int,int> ump;
        //0表示从数组头部开始计算
        ump[0]=0;
        //为了与0进行区分，遍历时ump索引从1开始设置
        for(int i=1;i<=len;i++){
            if(nums[i-1]) cnt++;
            int target=2*cnt-i;
            if(ump.count(target)) ans=max(ans,i-ump[target]);
            else ump[target]=i;
        }
        return ans;
    }
};