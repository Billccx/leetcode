class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> s0;
        stack<int> s1;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(s[i]=='('){
                s0.push('(');
                s1.push(-1);
            }
            if(s[i]==')'){
                s0.pop();
                if(s1.top()==-1){
                    s1.pop();
                    s1.push(1);
                }
                else{
                    int sum=0;
                    while(s1.top()!=-1){
                        sum+=s1.top();
                        s1.pop();
                    }
                    s1.pop();
                    s1.push(sum*2);
                }
            }
        }
        int ans=0;
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        return ans;
    }
};