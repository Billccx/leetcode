#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> rare;
        unordered_map<string,int> ump;
        int l=0,r=0,len=s1.length();
        while(r<len){
            while(r<len && s1[r]!=' ') r++;
            ump[s1.substr(l,r-l)]++;
            l=r+1;
            r=l;
        }

        len=s2.length();
        l=r=0;
        while(r<len){
            while(r<len && s2[r]!=' ') r++;
            ump[s2.substr(l,r-l)]++;
            l=r+1;
            r=l;
        }

        for(unordered_map<string,int>::iterator p=ump.begin();p!=ump.end();p++){
            if(p->second==1){
                rare.emplace_back(p->first);
            }
        }
        return rare;
    }
};

int main(){
    Solution s;
    string s1="this apple is sweet",s2="this apple is sour";
    vector<string> result=s.uncommonFromSentences(s1,s2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}
