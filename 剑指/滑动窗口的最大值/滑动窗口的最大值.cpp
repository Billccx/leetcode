class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int,greater<int>> s;
        for(int i=0;i<k;i++) s.insert(nums[i]);
        ans.push_back(*s.begin());
        int len=nums.size();
        for(int i=k;i<len;i++){
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back(*s.begin());
        }
        return ans;
    }
};