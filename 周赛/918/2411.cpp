class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int len=nums.size();
        vector<int> v(30,-1);
        //cout<<v.size()<<endl;
        vector<int> ans(len);
        for(int i=len-1;i>=0;i--){
            int temp=nums[i];
            int result=i;

            for(int j=0;j<30;j++){
                if((temp>>j)&1) v[j]=i;
                else if(((temp>>j)&1)==0 && v[j]!=-1) result=max(result,v[j]);

            }
            ans[i]=result-i+1;
        }
        return ans;
    }
};