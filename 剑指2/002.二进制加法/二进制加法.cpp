class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,la=a.length(),lb=b.length();
        int l=max(la,lb);
        string ans;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<l;i++){
            if(i>=la){
                int t=carry+b[i]-'0';
                if(t==2){
                    carry=1;
                    ans+='0';
                }
                else{
                    carry=0;
                    ans+=to_string(t);
                }
            }
            else if(i>=lb){
                int t=carry+a[i]-'0';
                if(t==2){
                    carry=1;
                    ans+='0';
                }
                else{
                    carry=0;
                    ans+=to_string(t);
                }
            }
            else{
                int t=carry+a[i]-'0'+b[i]-'0';
                //cout<<"t="<<t<<endl;
                if(t>=2){
                    carry=1;
                    ans+=to_string(t%2);
                }
                else{
                    carry=0;
                    ans+=to_string(t);
                }
            }
            //cout<<ans<<endl;
        }
        if(carry) ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};