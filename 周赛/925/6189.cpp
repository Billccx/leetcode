#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxnum=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxnum) maxnum=nums[i];
        }
        int ans=1;
        vector<int> c(nums.size(),0);
        for(int i=0;i<c.size();i++){
            if(nums[i]==maxnum){
                if(i==0) c[i]=1;
                else c[i]=c[i-1]+1;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(c[i]>ans) ans=c[i];
        }
        return ans;
        
    }
};

int main(){
    Solution s;
    vector<int> v={1,2,3,3,2,2};
    int ans=s.longestSubarray(v);
    cout<<ans<<endl;
}