class Solution {
public:
    int lastRemaining(int n, int m) {
        int p=0,cnt=0,ans=-1,temp=n;
        vector<int> v;
        for(int i=0;i<n;i++) v.push_back(i);
        while(temp>0){
            if(v[p]>=0){
                cnt++;
                if(cnt==m){
                    ans=v[p];
                    //cout<<v[p]<<endl;
                    v[p]=-1;
                    cnt=0;
                    temp--;    
                }
            }
            p=(p+1)%n;
        }
        return ans;
    }
};