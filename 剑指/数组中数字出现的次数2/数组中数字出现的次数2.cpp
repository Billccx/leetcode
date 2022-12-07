class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size(),ans=0;
        for(int i=0;i<32;i++){
            int p=1<<i,cnt=0;
            for(int j=0;j<len;j++){
                if(nums[j]&p) cnt++;
            }
            if(cnt%3) ans|=p;
        }
        return ans;
    }
};