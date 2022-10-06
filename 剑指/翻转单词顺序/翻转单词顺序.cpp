class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int start=0,l=s.length(),p=0;
        for(;start<l;start++){
            if(s[start]!=' '){
                if(p){
                    s[p]=' ';
                    p++;
                }
                int end=start;
                while(end<l && s[end]!=' '){
                    s[p]=s[end];
                    p++;
                    end++;
                }
                reverse(s.begin()+p-(end-start),s.begin()+p);
                start=end;
            }
        }
        return s.substr(0,p);
    }
};