class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans (n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!s.empty() && s.top()<heights[i]){
                s.pop();
                cnt++;
            }
            if(!s.empty()) cnt++;

            s.push(heights[i]);
            
            ans[i]=cnt;
        }
        return ans;
    }
};