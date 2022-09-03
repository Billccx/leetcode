#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(
            pairs.begin(),
            pairs.end(),
            [](const vector<int>& a,const vector<int>& b){
                return a[1]<b[1];
            }
        );

        int cnt=0,len=pairs.size(),pre=-1;
        for(int i=0;i<len;i++){
            if(pairs[i][0]>pre){
                cnt++;
                pre=pairs[i][1];
            }
        }
        return cnt;
    }
};

int main(){

}