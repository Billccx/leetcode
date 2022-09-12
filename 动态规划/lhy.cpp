#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>


#define MAXN 550
using namespace std;

int n;
int dp[MAXN][MAXN] = { 0 };

struct node {
    int id;  //最开始鹰的输入顺序作为 id
    int width, height, leg;
    vector<int> adj;
} bird[MAXN];

bool cmp(struct node x, struct node y) {
    return x.width > y.width;
}

void Init() {
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));   //初始化！

    for (int i = 1; i <= n; i++) {
        bird[i].id = i;
        scanf("%d %d %d", &bird[i].width, &bird[i].height, &bird[i].leg);
        int k, t;
        scanf("%d", &k);
        bird[i].adj.clear();
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            bird[i].adj.push_back(t);
        }
    }
    //sort(bird + 1, bird + 1 + n, cmp);   //对bird数组以width为关键字排序
}

int main() {
    int t;

    for (scanf("%d", &t); t; t--) {
        Init();
        int ans = 0;  //最终的最高高度
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                for (int j = 1; j <= n; j++) dp[i][j] = bird[j].height + bird[j].leg;
            }
            else {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i - 1][j];
                    for (auto index : bird[j].adj) {
                        if (bird[index].width < bird[j].width) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][index] - bird[index].leg + bird[j].leg + bird[j].height);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dp[n][i] > ans) ans = dp[n][i];
        }

        cout << "the answer is:" << ans << endl;
    }

}