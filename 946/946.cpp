#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> mp;
    stack<int> s;
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        mp.resize(1001, 0);
        int len = pushed.size();
        int p = 0, q = 0;
        while (p < len || q < len) {
            while (p < len && q < len && mp[popped[q]] == 0) {
                s.push(pushed[p]);
                mp[pushed[p]] = 1;
                p++;
            }
            if (mp[popped[q]]) {
                int temp = s.top();
                if (temp == popped[q]) {
                    s.pop();
                    q++;
                }
                else return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> poped = { 4,3,5,1,2 };
    bool result = s.validateStackSequences(pushed, poped);
    cout << result << endl;

}