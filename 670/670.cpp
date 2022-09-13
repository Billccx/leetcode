class Solution {
public:
    int maximumSwap(int num) {
        int temp=num;
        vector<int> v;
        while(temp>0){
            int t=temp%10;
            v.push_back(t);
            temp=temp/10;
        }

        vector<int> v2=v;
        sort(v2.begin(),v2.end(),greater<int>());
        int p=v.size()-1,q=0;
        bool isSwap=false;
        while(p>=0&&q<v.size()){
            if(v[p]<v2[q]){
                for(int j=0;j<v.size();j++){
                    if(v[j]==v2[q]){
                        swap(v[j],v[p]);
                        int ans=0;
                        for(int i=v.size()-1;i>=0;i--){
                            ans*=10;
                            ans+=v[i];
                        }
                        return ans;
                    }
                }
            }
            else if(v[p]==v2[q]){
                p--;
                q++;
            }
        }

        return num;
    }
};