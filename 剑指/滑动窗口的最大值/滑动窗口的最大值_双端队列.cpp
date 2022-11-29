class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        dequeue<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dp.front()]);
        int len=nums.size();
        for(int i=k;i<len;i++){
            if(dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dp.front()]);
        }
        return ans;
    }
};

/*
在滑动窗口中，如果左侧的值小于右侧，则左侧在其处于滑动窗口的过程中是永远不可能成为最大值的
因此我们只需要维护一个单调队列，储存当前在滑动窗口内部的“部分”下标
“部分”表示保持队列排序中下标对应的元素值应该是单调递减的，否则将其弹出双端队列

每次窗口右移的过程中，我们首先检查对头是否已经处于滑动窗口之外，如是，弹出之
然后准备将新元素压入队列末尾，但需要注意在压入之前需要弹出位于其前面的所有对应值小于之的下标

*/