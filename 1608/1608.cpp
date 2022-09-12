class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
        //cout<<endl;

        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[len-1-i]>=i+1 && (len-2-i<0|| nums[len-2-i]<i+1)){
                return i+1;
            }
        }
        return -1;
    }
};