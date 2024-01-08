class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        vector<int> s;
        s.push_back(0);
        for(int i=1;i<word.length();i++){
            if(word[i-1]-word[i]>2 || word[i]-word[i-1]>2) s.push_back(i);
        }
        s.push_back(word.length());
        for(int i=0;i<s.size();i++) cout<<s[i]<<' ';
        cout<<endl;

        int ans=0;
        for(int i=1;i<s.size();i++){
            int start=s[i-1],end=s[i];
            int len=end-start;

            for(int m=1;m<=26 && m*k<=len; m++){
                unordered_map<char,int> ump;
                for(int p=start;p<end;p++){
                    ump[word[p]]++;
                    if(p-m*k+1>=start){
                        bool flag=true;
                        for(int q=0;q<26;q++){
                            if(ump[q+'a']!=0 && ump[q+'a']!=k){
                                flag=false;
                                break;
                            }
                        }
                        if(flag){
                            ans++;
                        } 
                        ump[word[p-m*k+1]]--;
                    }
                    
                }
            }
        }
        return ans;
    }
};