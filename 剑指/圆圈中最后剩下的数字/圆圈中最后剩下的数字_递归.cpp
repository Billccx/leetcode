class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n==1) return 0;
        int next=lastRemaining(n-1,m);
        return (m%n+next)%n;
    }
};