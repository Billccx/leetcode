#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> vchar,vint;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9') vint.push_back(s[i]);
            else vchar.push_back(s[i]);
        }
        if(abs((int)vint.size()-(int)vchar.size())>1) return "";
        string ans="";
        int cl=vchar.size(),il=vint.size();
        for(int i=0;i<cl+il;i++){
            if(cl>=il){
                if(i%2==0) ans+=vchar[i/2];
                else ans+=vint[i/2];
            }
            else{
                if(i%2==0) ans+=vint[i/2];
                else ans+=vchar[i/2];

            }

        }
        return ans;
    }
};

int main(){
    Solution s;
    string str="12431543125";
    string result=s.reformat(str);
    cout<<result<<endl;
}