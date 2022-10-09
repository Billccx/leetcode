class Solution {
public:
    //寻找第一个=target的位置
    int SearchfirstBE(vector<int>& nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target) r=mid-1;
            else l=mid+1;
        }
        if(l<nums.size() && nums[l]==target) return l;
        else return -1;
    }

    //寻找最后一个=target的位置
    int SearchLastLE(vector<int>& nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) l=mid+1;
            else r=mid-1;
        }
        if(r>=0 && nums[r]==target) return r;
        else return -1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int start=SearchfirstBE(nums,target);
        int end=SearchLastLE(nums,target);
        if(start==-1) return vector<int>{-1,-1};
        return vector<int>{start,end};
    }
};