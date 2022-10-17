class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ump;
        int p = 0, q = 0, l = fruits.size(), ans = 1, sum = 0;
        while (p < l) {
            if (ump.size() == 2 && !ump.count(fruits[p])) {
                while (ump.size() == 2) {
                    ump[fruits[q]]--;
                    sum--;
                    if (!ump[fruits[q]]) ump.erase(fruits[q]);
                    q++;
                }
                ump[fruits[p]]++;
                sum++;
                p++;
            }
            else {
                ump[fruits[p]]++;
                sum++;
                if (sum > ans) ans = sum;
                p++;
            }
        }
        return ans;
    }
};
