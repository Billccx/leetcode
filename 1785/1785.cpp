class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int len=nums.size();
        long long int sum=0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
        }
        long long int diff=goal-sum;
        if(!diff) return 0;
        diff=abs(diff);
        int cnt=0;
        cnt+=diff/limit;
        if(diff%limit) cnt++;
        return cnt;
    }
};

/*
面对情况
若 diff整除goal 答案为diff/goal
若不整除 则为 diff/goal+1
上取整公式可以避免ifelse判断

ans=(diff+goal-1)/goal


*/