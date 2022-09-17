class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        vector<vector<int>> v;
        for(int i=0;i<26;i++){
            vector<int> temp;
            v.push_back(temp);
        }
        int l=s.length();
        for(int i=0;i<l;i++){
            v[s[i]-'a'].push_back(i);
            int k=v[s[i]-'a'].size();
            if(k>1){
                int len=v[s[i]-'a'][k-1]-v[s[i]-'a'][0];
                if(len-1>ans) ans=len-1;
            }
        }
        return ans;
    }
};