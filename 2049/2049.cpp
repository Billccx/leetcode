#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, vector<long long int>> ump;
    vector<long long int> score;
    vector<long long int> size;
    vector<long long int> par;
    int sum;

    long long int getSize(int x) {
        long long int size_ = 1;
        if (ump.count(x)) {
            for (int i = 0; i < ump[x].size(); i++) {
                size_ += getSize(ump[x][i]);
            }
        }
        size[x] = size_;
        return size_;
    }

    int getRoot(int x_) {
        int x = x_;
        while (par[x] >= 0) x = par[x];
        return x;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int l = parents.size();
        sum = l;
        for (int i = 0; i < l; i++) {
            score.push_back(1);
            size.push_back(1);
            if (parents[i] >= 0) {
                ump[parents[i]].push_back(i);
            }
            par.push_back(parents[i]);
        }
        getSize(0);

        long long int maxScore = 0;

        for (int i = 0; i < l; i++) {

            if (parents[i] >= 0) {
                //score[i] *= (size[getRoot(par[i])]-size[i]);
                score[i] *= (sum - size[i]);
            }
            if (ump.count(i)) {
                for (int j = 0; j < ump[i].size(); j++) {
                    score[i] *= size[ump[i][j]];
                }
            }
            if (score[i] > maxScore) maxScore = score[i];
        }

        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (score[i] == maxScore) cnt++;
        }

        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> v = { -1,2,0,2,0 };
    int result = s.countHighestScoreNodes(v);
    cout << result << endl;
}