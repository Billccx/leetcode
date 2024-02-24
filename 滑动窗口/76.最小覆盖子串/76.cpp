class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> ump;
        for(int i=0;i<t.length();i++){
            ump[t[i]]++;
        }
        int pfast=-1,pslow=0;
        string ans="";
        int anslen=INT_MAX;
        //cout<<"pfast:"<<pfast<<" s.length:"<<s.length()<<endl;
        int n=s.length();
        while(pfast<n){
            //cout<<"pfast:"<<pfast<<" pslow:"<<pslow<<endl;
            // for(auto kv:ump){
            //     cout<<kv.first<<" "<<kv.second<<endl;
            // }
            bool isFill=true;
            for(auto kv : ump){
                if(kv.second>0){
                    isFill=false;
                    break;
                }
            }
            if(isFill){
                while(true){
                    if(ump.count(s[pslow])){
                        if(ump[s[pslow]]==0){
                            if((pfast-pslow+1)<anslen){
                                anslen=pfast-pslow+1;
                                ans=s.substr(pslow,anslen);
                            }
                            
                            ump[s[pslow]]++;
                            pslow++;
                            break;
                        }
                        else{
                            ump[s[pslow]]++;
                            pslow++;
                        }
                    }
                    else{
                        pslow++;
                    }
                }
            }
            else{
                pfast++;
                if(pfast>=s.length()) break;
                if(ump.count(s[pfast])) ump[s[pfast]]--;
            }
        }
        return ans;
    }
};