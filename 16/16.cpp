class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX,mindiff=INT_MAX;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len;i++){
            int j=i+1,k=len-1;
            for(;j<k;j++){
                while(k>j){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==target) return sum;
                    else if(sum>target){
                        int diff=sum-target;
                        if(diff<mindiff){
                            mindiff=diff;
                            ans=sum;
                        }
                        k--;
                    }
                    /*
                    如果sum<target并不是二重循环的第一个：
                    则已知上一步循环中nums[i]+nums[j]+nums[k]>target
                    到了这一步发现nums[i]+nums[j]+nums[k]<target
                    比较后即可break

                    如果是二重循环的第一个的话：
                    那么 
                    nums[i]+nums[j]+nums[k+1]>nums[i]+nums[j-1]+nums[k+1]
                    已知nums[i]+nums[j-1]+nums[k]<0
                        nums[i]+nums[j-1]+nums[k]>0
                    而nums[i]+nums[j-1]+nums[k]与target的差值已经被比较过了
                    所以我们不用在做额外的回退k指针了
                    */
                    else{
                        int diff=target-sum;
                        if(diff<mindiff){
                            mindiff=diff;
                            ans=sum;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};