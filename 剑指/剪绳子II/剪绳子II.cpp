class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int l;
        long ans=1;
        if(n%3==0) l=n/3;
        else if(n%3==1){
            l=n/3-1;
            ans*=4;
        } 
        else{
            l=n/3;
            ans*=2;
        }

        long p=1,a=3;
        while(l){
            if(l&1) p=(p*a)%1000000007;
            a=(a*a)%1000000007;
            l=l>>1;
        }
        return (int)(ans*p%1000000007);
    }
};



//快速幂
//计算a^n % mod
ll qpow(ll a, ll n){
    ll re = 1;
    while(n) {
        if(n & 1)//判断n的最后一位是否为1
            re = (re * a) % mod;
        n >>= 1;//舍去n的最后一位
        a = (a * a) % mod;//将a平方
    }
    return re % mod;
}

//矩阵快速幂
