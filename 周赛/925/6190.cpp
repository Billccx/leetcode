#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int p=0,len=nums.size();
        vector<int> dec(len,1);
        vector<int> asc(len,1);
        vector<int> ans;
        while(p<len){
            if(p-1>=0 && nums[p]<=nums[p-1]) dec[p]=dec[p-1]+1;
            if(p-1>=0 && nums[p]>=nums[p-1]) asc[p]=asc[p-1]+1;
            p++;
        }
        for(int i=0;i<len;i++){
            if(i+k<len && i>=k && dec[i-1]>=k && asc[i+k]>=k) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v={878724,201541,179099,98437,35765,327555,475851,598885,849470,943442};
    int k=4;
    vector<int> ans=s.goodIndices(v,k);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
    cout<<endl;
}