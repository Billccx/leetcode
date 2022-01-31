#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return -1;
        int cnt=0;
        while(num){
            if(num&1) cnt+=2;
            else cnt++;
            num=num>>1;
        }
        return cnt-1;
    }
};

int main(){
    Solution s;
    int num=8;
    int result=s.numberOfSteps(num);
    cout<<result<<endl;
}