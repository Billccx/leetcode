class Solution {
public:
    bool isMatch(string s, string p) {
        vector<pair<char,int>> v;
        for(int i=0;i<p.length();){
            if(p[i]>='a' && p[i]<='z'){
                if(i+1<p.length()&& p[i+1]=='*'){
                    v.push_back(make_pair(p[i],-1));
                    i+=2;
                }
                else{
                    v.push_back(make_pair(p[i],1));
                    i++;
                } 
            }
            else if(p[i]=='.'){
                v.push_back(make_pair('X',0));
                i++;
            }
        }

        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        return true;
    }
};