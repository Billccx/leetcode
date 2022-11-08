class Solution {
public:
    int findMin(vector<int>& nums) {
        int len=nums.size();
        int l=0,r=len-1;
        while(l<r){ //为什么边界条件是l<r?
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else if(nums[mid]<nums[r]) r=mid; //此处认为，最小值也会满足<nums[r]，因此我们不可以排除mid位置
            else r--;
        }
        return nums[r];
    }
};

/*
没有理解这种写法
*/