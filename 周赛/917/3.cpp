#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int len=nums.size();
        vector<int> r;
        for(int i=0;i<nums.size();i++){
            r.push_back(~nums[i]);
        }
        vector<int> sum(len);
        int s=0;
        for(int i=0;i<len;i++){
            s=s|nums[len-1-i];
            sum[len-1-i]=s;
        }
        vector<int> ans(len);
        int p=len-1,q=len-1,temp=sum[p];
        while(p>=0){
            if((temp|r[q])<sum[p]){
                ans[p]=q-p+1;
                p--;
                temp=temp|nums[p];
            } 
            else if((temp|r[q])==sum[p]){
                temp=temp|r[q];
                q--;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,0,2,1,3};
    vector<int> result=s.smallestSubarrays(nums);
    for(int i=0;i<result.size();i++) cout<<result[i]<<' ';
    cout<<endl;
}