class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i,j,k,l=nums.size();
        i=j=k=0;
        vector<vector<int>> ans;
        while(i<l){
            if(nums[i]>0) break;
            //对i进行去重
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }

            j=i+1;
            k=l-1;
            while(j<k){
                //cout<<i<<' '<<j<<' '<<k<<endl;
                //对j进行去重
                if(j!=i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }

                if(nums[j]+nums[k]<-nums[i]) j++;
                else if(nums[j]+nums[k]>-nums[i]) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                } 
            }
            i++;            
        }
        return ans;
    }
};

/*
本题目难点为将时间复杂度优化为n^2
同时还需要考虑去重
*/