#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lx=0,rx=0,lval=0,rval=0;
    int preop=1,side=0;
    string solveEquation(string equation) {
        int i=0,len=equation.length(),tempval=0,hastimes=0;
        while (i<len){
            if(equation[i]=='x'){
                if(side==0){
                    if(hastimes) lx+=preop*tempval;
                    else lx+=preop;
                } 
                else{
                    if(hastimes) rx+=preop*tempval;
                    else rx+=preop;
                }
                tempval=0;
            }
            else if(equation[i]=='+'){
                if(side==0) lval+=preop*tempval;
                else rval+=preop*tempval;
                tempval=0;
                preop=1;
                hastimes=0;
            }
            else if(equation[i]=='-'){
                if(side==0) lval+=preop*tempval;
                else rval+=preop*tempval;
                tempval=0;
                preop=-1;
                hastimes=0;
            }
            else if(equation[i]=='='){
                lval+=preop*tempval;
                tempval=0;
                preop=1;
                side=1;
                hastimes=0;
            }
            else{
                tempval=tempval*10+equation[i]-'0';
                hastimes=1;
            }
            i++;
        }

        rval+=preop*tempval;

        cout<<lx<<' '<<lval<<' '<<rx<<' '<<rval<<endl;

        int xcnt=lx-rx;
        int val=rval-lval;
        if(xcnt){
            string ans="x="+to_string(val/xcnt);
            return ans;
        }
        else if(val==0){
            return "Infinite solutions";
        }
        else{
            return "No solution";
        }
    }
};

int main(){
    string str="2x+3x-6x=x+2";
    Solution s;
    string result=s.solveEquation(str);
    cout<<result<<endl;

}