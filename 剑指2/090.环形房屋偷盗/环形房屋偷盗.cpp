class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==1) return nums[0];
        //0~len-2
        int x=0,y=nums[0],ans=0;
        int temp=0;
        for(int i=0;i<len-1;i++){
            if(i==0) temp=y;
            else{
                temp=max(y,x+nums[i]);
                x=y;
                y=temp;
            }
        }

        ans=temp;
        temp=0;
        x=0;
        y=nums[1];
        for(int i=1;i<len;i++){
            if(i==1) temp=y;
            else{
                temp=max(y,x+nums[i]);
                x=y;
                y=temp;
            }
        }
        ans=max(ans,temp);
        return ans;
    }
};