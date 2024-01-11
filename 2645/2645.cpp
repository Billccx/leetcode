class Solution {
public:
    int addMinimum(string word) {
        stack<char> s;
        int n=word.length();
        int p=0,cnt=0;
        s.push(word[p]);
        cnt+=(word[p]-'a');
        p++;
        while(p<n){
            int dif=word[p]-s.top()-1;
            if(dif<0) dif+=3;
            cnt+=dif;
            s.push(word[p]);
            p++;
        }
        if(s.top()!='c') cnt+=('c'-s.top());
        return cnt;
    }
};