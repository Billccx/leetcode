class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int mul=1,l=0,r=0,ans=0,len=nums.size();
        if(k==0) return 0;
        while(r<len){
            if(mul*nums[r]<k){
                mul*=nums[r];
                ans+=r-l+1;
                r++;
            }
            else{
                mul/=nums[l];
                l++;
                if(r<l) r=l;
            }
        }
        return ans;
    }
};


/*
更好的写法
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        int prod = 1, i = 0;
        for (int j = 0; j < n; j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            ret += j - i + 1;
        }
        return ret;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/ZVAVXX/solutions/1463528/cheng-ji-xiao-yu-k-de-zi-shu-zu-by-leetc-xqx8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/