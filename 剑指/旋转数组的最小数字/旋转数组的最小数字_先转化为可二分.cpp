class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len=numbers.size();
        int l=0,r=len-1;
        while(r>=0 && numbers[l]==numbers[r]) r--;
        if(r<0) return numbers[l];
        int x=numbers[r];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(numbers[mid]>x) l=mid+1;
            else r=mid-1;  //else if numbers[mid]<=x 如果mid-1是第一个不满足numbers[mid-1]<=x的话
        }                  //之后r不会在发生变化，while退出后l=r+1正好是我们要找的位置
        return numbers[l];
    }
};