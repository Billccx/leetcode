class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len=hours.size(),sum=0;
        stack<pair<int,int>> s;
        for(int i=0;i<len;i++){
            sum+=(hours[i]>8?1:-1);
            if(s.empty()||s.top().first>sum) s.push(make_pair(sum,i));
        }
        int ans=0;
        for(int i=len-1;i>=0;i--){
            if(sum>0) ans=max(ans,i+1);
            while(!s.empty()&&s.top().first<sum){
                ans=max(ans,i-s.top().second);
                s.pop();
            }
            if(s.empty()) break;
            if(i==s.top().second){
                s.pop();
            }
            sum-=(hours[i]>8?1:-1);
        }
        return ans;
    }
};