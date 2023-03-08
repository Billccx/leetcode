class Solution {
public:
    int minimumDeletions(string s) {
        int len=s.length(),acnt=0,bcnt=0;
        vector<int> a,b;
        a.push_back(0);
        b.push_back(0);
        for(int i=0;i<len;i++){
            if(s[i]=='a') acnt++; 
            a.push_back(acnt);
        }
        for(int i=len-1;i>=0;i--){
            if(s[i]=='b') bcnt++;
            b.push_back(bcnt);
        }

        int ans=INT_MAX;
        for(int i=0;i<=len;i++){
            //cout<<(i-a[i])<<"\t"<<(len-i-b[len-i])<<endl;
            int temp=(i-a[i])+(len-i-b[len-i]);
            ans=min(ans,temp);
        }
        return ans;
    }
};