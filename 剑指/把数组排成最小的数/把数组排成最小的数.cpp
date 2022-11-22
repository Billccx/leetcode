class Solution {
public:

    static bool cmp(const int& x,const int& y){
        string a=to_string(x),b=to_string(y);
        string ab=a+b,ba=b+a;
        if(ab<ba) return true;
        else return false;
    }


    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        int l=nums.size();
        for(int i=0;i<l;i++){
            ans+=to_string(nums[i]);
        }
        return ans;
    }
};