class Solution {
public:
    int solve(vector<int>&nums,int l,int r){
        vector<int> temp;
        if(l>=r) return 0;
        int mid=l+(r-l)/2;
        int ans=0;
        ans+=solve(nums,l,mid)+solve(nums,mid+1,r);
        int p=l,q=mid+1;
        while(p<=mid && q<=r){
            if(nums[p]<=nums[q]){
                temp.push_back(nums[p]);
                p++;
                ans+=q-mid-1;
            }
            else if(nums[p]>nums[q]){
                temp.push_back(nums[q]);
                q++;
            }
        }

        while(p<=mid){
            temp.push_back(nums[p]);
            p++;
            ans+=q-mid-1;
        }

        while(q<=r){
            temp.push_back(nums[q]);
            q++;
        }

        copy(temp.begin(),temp.end(),nums.begin()+l);
        return ans;

    }

    int reversePairs(vector<int>& nums) {
        int len=nums.size();
        int ans=solve(nums,0,len-1);
        return ans;
    }
};



/*
对于归并双指针移动的写法
while(p<=x&& q<=y){
    if(a[p]<a[q]){
        p++;
    }
    else if(a[p]>=a[q]){
        q++;
    }
}

for(i=p;p<mid;p++)

for(i=q;q<r;q++)


在while循环中用if,一次while只移动一次指针，这样的写法比较优雅
不要在while中再嵌套一层while,这样对于边界的判断很不好写
*/