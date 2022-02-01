#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        string result="";
        int len=s.length();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                vector<vector<int>> v(26,vector<int>(2));
                
                for(int k=i;k<=j;k++){
                    if(s[k]>='A' && s[k]<='Z'){
                        v[s[k]-'A'][0]+=1;
                    }
                    else{
                        v[s[k]-'a'][1]+=1;
                    }
                }
                int flag=1;
                for(int i=0;i<26;i++){
                    if((v[i][0]&&!v[i][1])||(!v[i][0]&&v[i][1])){
                        flag=0;
                        break;
                    }
                }
                if(flag && j-i+1>result.length()){
                    result=s.substr(i,j-i+1);
                }
            }
        }
        return result;
    }
};

int main(){
    string str="dDzeE";
    Solution s;
    string result=s.longestNiceSubstring(str);
    cout<<result<<endl;
}