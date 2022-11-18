class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> ump;
        int len=s.length();
        for(int i=0;i<len;i++){
            ump[s[i]]++;
        }
        for(int i=0;i<len;i++){
            if(ump[s[i]]==1) return s[i];
        }
        return ' ';
    }
};