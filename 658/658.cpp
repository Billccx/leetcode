class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int p=0,len=arr.size();
        vector<int> ans;
        while(p<len && arr[p]<x) p++;
        // if(p==0){
        //     for(int i=0;i<k;i++) ans.push_back(arr[i]);
        //     return ans;
        // }
        p--;
        int q=p+1;
        cout<<p<<','<<q<<endl;
        while(k>0){
            if(p>=0 && q<len){
                if(x-arr[p]<=arr[q]-x){
                    ans.push_back(arr[p]);
                    p--;
                } 
                else{
                    ans.push_back(arr[q]);
                    q++;
                } 
                k--;
            }
            else if(p>=0 && q>=len){
                ans.push_back(arr[p]);
                p--;
                k--;
            }
            else if(p<0 && q<len){
                ans.push_back(arr[q]);
                q++;
                k--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};