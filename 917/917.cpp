#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<int> v;
        queue<char> q;
        stack<char> st;
        int sl=s.length();
        for(int i=0;i<sl;i++){
            if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z'){
                st.push(s[i]);
            }
            else{
                v.push_back(i);
                q.push(s[i]);
            }
        }
        string result;
        int j=0;
        for(int i=0;i<v.size();i++){
            int index=v[i];
            while(j<index){
                result.push_back(st.top());
                st.pop();
                j++;
            }
            result.push_back(q.front());
            q.pop();
            j++;
        }
        while (!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main(){
    Solution so;
    string s="test1ng-Leet=code-Q!";
    string result=so.reverseOnlyLetters(s);
    cout<<result<<endl;
}


/*

//双指针解法
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) { // 判断左边是否扫描到字母
                left++;
            }
            while (right > left && !isalpha(s[right])) { // 判断右边是否扫描到字母
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/reverse-only-letters/solution/jin-jin-fan-zhuan-zi-mu-by-leetcode-solu-db20/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/