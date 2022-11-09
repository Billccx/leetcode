class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        unordered_set<char> st;
        int p=0,q=0;
        int l=s.length();
        int ans=1;
        while(p<l && q<l){
            if(!st.count(s[q])){
                st.insert(s[q]);
                q++;
            }
            else{
                ans=max(q-p,ans);
                while(s[p]!=s[q]){
                    st.erase(s[p]);
                    p++;
                }
                st.erase(s[p]);
                p++;
            }
        }
        ans=max(q-p,ans);
        return ans;
    }
};

/*
由于选择的是“最长的”无重复子串
只需用双指针p,q框定一个字串，若不重复，则q一直往前拓展
如果出现重复，则p往前收缩


没有想到动态规划的算法
无重复应当如何表示，状态转移的时候，如何判断新加入的字符与原本字符串中的其他字符不存在重复？
*/