class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(1700);
        f[1]=1;
        int i,j,k; 
        i=j=k=1;
        for(int p=2;p<=n;p++){
            int m=min(min(f[i]*2,f[j]*3),f[k]*5);
            f[p]=m;
            if(m==f[i]*2) i++;
            if(m==f[j]*3) j++;
            if(m==f[k]*5) k++;
        }
        return f[n];
    }
};

/*
三指针
对于当前生成到第p个数字
f[i-1],f[j-1],f[k-1]必然都要小于等于这第p个数字
所以下一个数字必然会产生于f[i],f[j],f[k]中，准确来说是三者的最小值
但是f[i],f[j],f[k]可能会有相等，因此我们需要同时对i,j,k指针更新，而不知只更新其中的一个
*/