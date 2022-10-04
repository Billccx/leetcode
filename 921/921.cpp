class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int len=s.length(),ans=0;
        for(int i=0;i<len;i++){
            if(s[i]==')'){
                if(st.empty() || st.top()!='(') ans++;
                else st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        ans+=st.size();
        return ans;
    }
};