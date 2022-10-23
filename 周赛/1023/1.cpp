class Solution {
public:
    int gcd(int a, int b){
        if (a % b == 0) return b;
        else return gcd(b, a % b);
    }
    
    int subarrayGCD(vector<int>& nums, int k) {
        vector<int> temp(nums);
        int ans=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==k) ans++;
            if(temp[i]%k==0) temp[i]/=k;
            else temp[i]=-1;
        }
        
        int l=temp.size();
        
        int p=0,q=0;
        while(p<l && q<l){
            while(q<l && temp[q]==-1) q++;
            p=q;
            while(p<l && temp[p]!=-1) p++;
            
            for(int i=q;i<p;i++){
                for(int j=i+1;j<p;j++){
                    bool can=true;
                    int m = temp[i];
                    for(int k=i;k<=j;k++){
                        if(temp[p]==1){
                            ans++;
                            can=false;
                            break;
                        }
                        int a=m,b=temp[k];
                        while(a%b!=0){
                            int temp=b;
                            b=a%b;
                            a=temp;
                        }
                        m=b;
                    }
                    if(!can) continue;
                    if(m==1) ans+=1;
                }
            }
            q=p;
        }
        
        return ans;
    }
};