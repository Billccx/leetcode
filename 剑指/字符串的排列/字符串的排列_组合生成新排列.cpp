class Solution {
public:
    vector<string> ans;
    void dfs(string s){
        //cout<<"s:"<<s<<endl;
        int len=s.length();
        int p=-1,q=-1;
        for(int i=len-2;i>=0;i--){
            if(s[i]<s[i+1]){
                p=i;
                break;
            } 
        }
        if(p==-1) return;
        int temp=INT_MAX;
        for(int i=len-1;i>p;i--){
            if(s[i]>s[p] && s[i]<temp){
                temp=s[i];
                q=i;
            }
        }
        //cout<<"p:"<<s[p]<<" q:"<<s[q]<<endl;
        swap(s[p],s[q]);
        reverse(s.begin()+p+1,s.end());
        ans.push_back(s);
        dfs(s);
    }

    vector<string> permutation(string s) {
        vector<int> vis(8);
        sort(s.begin(),s.end());
        ans.push_back(s);
        dfs(s);
        return ans;
    }
};

/*


*/