class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int p=0,pre=0,l=target.size();
        vector<string> ans;
        for(int i=0;i<l;i++){
            for(int j=0;j<target[i]-pre-1;j++){
                ans.push_back("Push");
                ans.push_back("Pop");
            } 
            ans.push_back("Push");
            pre=target[i];
        }
        return ans;
    }
};