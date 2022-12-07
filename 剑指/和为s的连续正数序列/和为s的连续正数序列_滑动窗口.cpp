class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int p=1,q=2,sum=3;
        vector<vector<int>> ans;
        while(p<q){
            if(sum<target){
                q++;
                sum+=q;
            }
            else if(sum==target){
                vector<int> temp;
                for(int i=p;i<=q;i++) temp.push_back(i);
                ans.push_back(temp);
                sum-=p;
                p++;
            }
            else{
                sum-=p;
                p++;
            }
        }
        return ans;
    }
};