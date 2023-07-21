class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> v(10005);
        vector<int> p(10005);
        vector<vector<int>> ans;

        int len=intervals.size();
        for(int i=0;i<len;i++){
            v[intervals[i][0]]++;
            v[intervals[i][1]]--;
            if(intervals[i][0]==intervals[i][1]) p[intervals[i][0]]=1;
        }
        int sum=0;
        vector<int> temp={-1,-1};
        
        bool flag=false;
        for(int i=0;i<10005;i++){
            sum+=v[i];
            if(sum>0 && !flag){
                flag=true;
                temp[0]=i;
            } 
            else if(sum==0 && flag){
                temp[1]=i;
                ans.push_back(temp);
                flag=false;
            }
            else if(p[i]&& !flag){
                ans.push_back({i,i});
            }
        }
        return ans;
    }
};