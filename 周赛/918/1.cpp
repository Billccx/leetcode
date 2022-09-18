#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len=s.size();
        int p=0,cnt=1,ans=1;
        while(p<len){
            cnt=1;
            while(p+1<len && s[p+1]==s[p]+1){
                p++;
                cnt++;
            }
            if(cnt>ans) ans=cnt;
            p++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str="abcde";
    int result=s.longestContinuousSubstring(str);
    cout<<result<<endl;

}