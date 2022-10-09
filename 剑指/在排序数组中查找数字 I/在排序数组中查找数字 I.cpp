class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        int l=0,r=len-1;
        while(l<=r){ //l<r 无法处理长度为1的数组
            int mid=(l+r)>>1;
            if(nums[mid]==target){
                int i=mid+1,cnt=1;
                while(i<len && nums[i]==nums[mid]){
                    cnt++;
                    i++;
                } 
                i=mid-1;
                while(i>=0 && nums[i]==nums[mid]){
                    cnt++;
                    i--;
                } 
                return cnt;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else l=mid+1;
        }
        return 0;
    }
};