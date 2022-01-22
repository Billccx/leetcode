#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int l=s.length();
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-1-i]) return 2;
        }
        return 1;
    }
};


int main(){
    Solution s;
    string str="baabb";
    int result=s.removePalindromeSub(str);
    cout<<result<<endl;
}