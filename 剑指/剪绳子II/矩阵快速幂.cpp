typedef long long ll;
const ll mod = 10000;
const int maxv = 2;

struct Matrix {
    ll a[maxv][maxv]; //矩阵

    Matrix operator*(const Matrix &b) const& { 
        //矩阵乘法，复杂度O(maxv^3)，也可看作常数，但maxv较大（大于5）时会使运算时间提高好几个数量级
        Matrix ans;
        for (int i = 0; i < maxv; ++i) {
            for (int j = 0; j < maxv; ++j) {
                ans.a[i][j] = 0;
                for (int k = 0; k < maxv; ++k) {
                    ans.a[i][j] += a[i][k] * b.a[k][j] % mod;
                    ans.a[i][j] %= mod;
                }
            }
        }
        return ans;
    }

    static Matrix qpow(Matrix x, ll n) {//矩阵快速幂，将乘法复杂度看作常数则复杂度为O(log n)
        Matrix ans;
        //首先将ans初始化为单位矩阵
        for (int i = 0; i < maxv; ++i) {
            for (int j = 0; j < maxv; ++j) {
                if (i == j)
                    ans.a[i][j] = 1;
                else
                    ans.a[i][j] = 0;
            }
        }//初始化为单位矩阵，参考普通数字的快速幂这里初始化为1

        while (n) {//其余细节基本相同
            if (n & 1)
                ans = ans * x;
            x = x * x;
            n >>= 1;
        }
        return ans;
    }

    Matrix(ll temp[maxv][maxv]) {//构造方法
        for (int i = 0; i < maxv; ++i) {
            for (int j = 0; j < maxv; ++j) {
                a[i][j] = temp[i][j];
            }
        }
    }
    
    Matrix() { }
};

ll fib(ll n) {//求取斐波那契数列第n项（本题取模）
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    
    ll temp[maxv][maxv] = {
        1, 1,
        1, 0
    };
    Matrix m(temp);
    m = Matrix::qpow(m, n - 2);
    return (m.a[0][1] + m.a[0][0]) % mod;
}