class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=s1.length(),len=s2.length();
        if(l>len) return false;
        vector<int> a(26),b(26);
        for(int i=0;i<l;i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        } 
        for(int i=l-1;i<len;i++){
            if(i>l-1){
                b[s2[i]-'a']++;
                b[s2[i-l]-'a']--;
            }
            bool isIdentical=true;
            for(int i=0;i<26;i++){
                if(a[i]!=b[i]){
                    isIdentical=false;
                    break;
                }
            }
            if(isIdentical) return true;
        }
        return false;
    }
};