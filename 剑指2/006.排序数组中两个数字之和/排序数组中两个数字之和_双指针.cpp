/*
        xi      xj
x0  x1      ...       xn-1 xn

如果xi+xj=target
我们的两个指针分别从0和n出发，向中间移动
如果x[l]+x[r]>target, r--
x[l]+x[r]<target, l++
这样l，r必然有一个先触碰到i或j（l碰i,r碰j）
这样的话，剩余的移动过程只会单方面地移动另一个指针，不会错过解
该解法时间复杂度为On，比二分查找更好
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        int l=0,r=len-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target) return {l,r};
            else if(numbers[l]+numbers[r]<target) l++;
            else r--;
        }
        return {-1,-1};
    }
};