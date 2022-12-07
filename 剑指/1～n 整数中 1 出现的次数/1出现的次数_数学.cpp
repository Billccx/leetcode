class Solution {
public:
    int countDigitOne(int n) {
        int ans=0;
        for(int i=0;i<=10;i++){
            long long p=pow(10,i),temp=n;
            ans+=(int)(temp/(10*p)*p+max(0LL,min(temp%(10*p)-p+1,(long long)p)));
        }
        return ans;
    }
};