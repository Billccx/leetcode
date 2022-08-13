#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> fmax,bmin;
    int maxChunksToSorted(vector<int>& arr) {
        int l=arr.size();
        vector<vector<int>> maxmin(2,vector<int>(l));
        int tempmax=-1,tempmin=100000001,cnt=0;
        for(int i=0;i<l;i++){
            if(tempmax<arr[i]) tempmax=arr[i];
            maxmin[0][i]=tempmax;
        }
        for(int i=l-1;i>=0;i--){
            if(tempmin>arr[i]) tempmin=arr[i];
            maxmin[1][i]=tempmin;
        }
        for(int i=0;i<l-1;i++){
            if(maxmin[0][i]<=maxmin[1][i+1]) cnt++;
        }
        // for(int i=0;i<maxmin.size();i++){
        //     for(int j=0;j<maxmin[i].size();j++){
        //         cout<<maxmin[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        return cnt+1;

    }
};

int main(){
    Solution s;
    vector<int> arr={2,1,3,4,4};
    int result=s.maxChunksToSorted(arr);
    cout<<result<<endl;
}