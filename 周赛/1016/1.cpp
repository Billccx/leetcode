#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            queue<int> q;
            int temp=i;
            while(temp>0){
                q.push(temp%10);
                temp/=10;
            }
            int rev=0;
            while(!q.empty()){
                rev*=10;
                rev+=q.front();
                q.pop();
            }
            if(i+rev==num){
                return true;
            } 
        }
        return false;
    }
};

int main(){
    for(int j=0;j<100000;j++){
        bool isFound=false;
        for(int i=0;i<=j;i++){
            queue<int> q;
            int temp=i;
            while(temp>0){
                q.push(temp%10);
                temp/=10;
            }
            int rev=0;
            while(!q.empty()){
                rev*=10;
                rev+=q.front();
                q.pop();
            }
            if(i+rev==j){
                cout<<j<<endl;
                isFound=true;
                break;
            } 
        }
        if(isFound) continue;
        //else cout<<0;
    }
}