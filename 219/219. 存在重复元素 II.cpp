#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int s=nums.size();
        for(int i=0;i<k+1&&i<s;i++){
            if(!ump.count(nums[i])){
                ump[nums[i]]=i;
            }
            else return true;
        }
        for(int i=k+1;i<s;i++){
            ump.erase(nums[i-k-1]);
            if(ump.count(nums[i])) return true;
            else{
                ump[nums[i]]=i;
            }
        }

        return false;

    }
};

int main(){
    vector<int> v={1,2,3,1,2,3};
    int k=2;
    Solution s;
    bool result=s.containsNearbyDuplicate(v,k);
    cout<<result<<endl;
}