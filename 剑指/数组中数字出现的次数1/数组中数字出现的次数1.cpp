class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ab=0,len=nums.size();
        for(int i=0;i<len;i++) ab^=nums[i];
        int p=1;
        while(!(ab&p)) p=p<<1;
        int left=ab,right=ab;
        for(int i=0;i<len;i++){
            if(nums[i]&p) left^=nums[i];
            else right^=nums[i];
        }
        return {left,right};
    }
};