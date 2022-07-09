#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,int> ump;
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1));
        for(int i=0;i<arr.size();i++){
            ump[arr[i]]=i;
        }

        int res=0;
        for(int i=2;i<arr.size();i++){
            for(int j=i-1;j>0;j--){
                int temp=arr[i]-arr[j];
                if(ump.count(temp) && ump[temp] <j){
                    dp[i][j]=max(3,dp[j][ump[temp]]+1);
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v={2,4,7,8,9,10,14,15,18,23,32,50};
    int result=s.lenLongestFibSubseq(v);
    cout<<result<<endl;
}