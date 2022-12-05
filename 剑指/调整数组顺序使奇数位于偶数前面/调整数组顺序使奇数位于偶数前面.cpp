class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len=nums.size();
        int p=0,q=len-1;
        while(p<q){
            while(p<len && nums[p]%2==1) p++;
            while(q>=0 && nums[q]%2==0) q--;
            if(p<q){
                swap(nums[p],nums[q]);
                p++;
                q--;
            }
        }
        return nums;
    }
};

/*
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right and nums[left] % 2 == 1) {
                left++;
            }
            while (left < right and nums[right] % 2 == 0) {
                right--;
            }
            if (left < right) {
                swap(nums[left++], nums[right--]);
            }
        }
        return nums;
    }
};
*/