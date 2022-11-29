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