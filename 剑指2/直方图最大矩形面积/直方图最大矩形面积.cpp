class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int len=heights.size();
        stack<int> q;
        q.emplace(-1);
        int ans=0;
        for(int i=0;i<len;i++){
            int p=q.top();
            if(p==-1 || heights[i]>=heights[p]){
                q.emplace(i);
            }
            else{
                while(p!=-1 && heights[p]>heights[i]){
                    int now=p;
                    q.pop();
                    p=q.top();
                    int temp=heights[now]*(i-p-1);
                    //cout<<heights[now]<<" "<<i-p-1<<" "<<i<<" "<<p<<endl;
                    ans=max(ans,temp);
                }
                q.emplace(i);
            }
        }
        return ans;
    }
};