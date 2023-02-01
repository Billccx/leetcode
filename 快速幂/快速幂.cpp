typedef long long ll;
ll mod;

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