class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int l=s.length();
        return s.substr(n,l-n)+s.substr(0,n);
    }
};