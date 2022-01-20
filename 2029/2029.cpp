#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int remain1=0,remain2=0,remain0=0;
        for(auto item:stones){
            if(item%3==0) remain0++;
            else if(item%3==1) remain1++;
            else remain2++;
        }
        int cnt=0,diff=0,sum=(remain1*1+remain2*2)%3;

        if(remain1==0 && remain2==0){
            return false;
        }

        if(min(remain1,remain2)>0){
            if(remain0%2==0) return true;
            else return false;
        }
        else{
            diff=abs(remain1-remain2);
            if(diff<3){
                if(sum!=0) return false;
                else return true;
            }
            else{
                if(remain0%2==0) return false;
                else return true;
            }
        }
    }
};
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int remain1=0,remain2=0,remain0=0;
        for(auto item:stones){
            if(item%3==0) remain0++;
            else if(item%3==1) remain1++;
            else remain2++;
        }
        //局势转换器，先后手之间必胜转换
        //没有局势转换器
        if(remain0%2==0){
            if(min(remain1,remain2)>0) return true; //只要0，1都有，就必然进入先手必胜的局势
            else return false; //倘若任一个数量为零，各种情况（数量凑到3成为倍数输掉，或小于3拿完凑不成倍数输掉）
        }
        //有局势转换器
        //没有好的理解办法，枚举分析
        else{
            if(abs(remain1-remain2)>2) return true;
            else return false;
        }
    }
};



int main(){
    Solution s;
    vector<int> v={2,1};
    auto result=s.stoneGameIX(v);
    cout<<result<<endl;
}