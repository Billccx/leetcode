class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int len=intervals.size();
        int begin=intervals[0][0],end=intervals[0][1];
        for(int i=0;i<len;i++){
            if(intervals[i][0]>end){
                ans.push_back({begin,end});
                begin=intervals[i][0];
                end=intervals[i][1];
            }
            else if(intervals[i][1]>end) end=intervals[i][1];
        }
        ans.push_back({begin,end});
        return ans;
    }
};