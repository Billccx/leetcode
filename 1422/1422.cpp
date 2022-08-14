#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> l,r;
    int maxScore(string s) {
        int len=s.length(),cnt=0;
        for(int i=0;i<len;i++){
            if(s[i]=='0') cnt++;
            l.push_back(cnt);
        }
        cnt=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]=='1') cnt++;
            r.push_back(cnt);
        }
        int ret=-1;
        for(int i=0;i<len-1;i++){
            int temp=l[i]+r[len-2-i];
            if(temp>ret) ret=temp;
        }
        return ret;
    }
};

int main(){
    Solution s;
    string str="011101";
    int result=s.maxScore(str);
    cout<<result<<endl;
}