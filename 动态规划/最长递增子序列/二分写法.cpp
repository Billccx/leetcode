class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        vector<int> v(len);
        v[0]=nums[0];
        int p=0;
        for(int i=0;i<len;i++){
            if(nums[i]>v[p]){
                p++;
                v[p]=nums[i];
            }
            else{
                //cout<<"insert:"<<nums[i]<<endl;
                int x=lower_bound(v.begin(),v.begin()+p+1,nums[i])-v.begin();
                //cout<<"x:"<<x<<endl;
                v[x]=nums[i];
            }
        }
        return p+1;
    }
};

/*
dp[i]=j 表示长度为i的单增子序列的最后一个值为j
我们贪心地想让dp[i]的值越小越好

从1开始枚举p，表示当前考虑了长度为p的单增序列（实现时其实从0计数）
如果数组中的下一个值>dp[p]，则把该值压入dp数组的最后一个，p++
否则在dp数组中找到>=该值的位置，用该值进行替换，表示用更小的值达到单增的效果

*/