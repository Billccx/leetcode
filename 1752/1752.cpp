class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans="";
        int l1=word1.length(),l2=word2.length();
        int p=0,q=0;

        while(p<l1 && q<l2){
            if(word1[p]>word2[q]) ans+=word1[p++];
            else if(word1[p]<word2[q]) ans+=word2[q++];
            else{
                if(word1.substr(p,l1-p)>=word2.substr(q,l2-q)) ans+=word1[p++];
                else ans+=word2[q++];
            }
        }

        if(p<l1) ans+=word1.substr(p,l1-p);
        if(q<l2) ans+=word2.substr(q,l2-q);
        
        return ans;
    }
};