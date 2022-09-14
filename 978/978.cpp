class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len=arr.size();
        int p=0,mode=-1;
        int ans=-1,cnt=1;
        while(p<len){
            if(mode==-1 && p+1<len){
                if(arr[p]>arr[p+1]){
                    mode=0;
                    cnt++;
                    p++;
                }
                else if(arr[p]<arr[p+1]){
                    mode=1;
                    cnt++;
                    p++;
                }
                else p++;
            }
            else if(mode==0 &&p+1<len){
                if(arr[p+1]>arr[p]){
                    p++;
                    cnt++;
                    mode=1;
                }
                else{
                    if(cnt>ans) ans=cnt;
                    mode=-1;
                    cnt=1;
                }
            }
            else if(mode==1 && p+1<len){
                if(arr[p+1]<arr[p]){
                    p++;
                    cnt++;
                    mode=0;
                }
                else{
                    if(cnt>ans) ans=cnt;
                    mode=-1;
                    cnt=1;
                }
            }
            else if(p+1==len){
                if(cnt>ans) ans=cnt;
                p++;
            }
        }
        return ans;
    }
};