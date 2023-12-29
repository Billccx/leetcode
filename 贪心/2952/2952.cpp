class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int sum=0,p=0,n=coins.size(),ans=0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=target;i++){
            while(sum<i){
                //cout<<sum<<"  "<<i<<"   "<<p<<endl;
                if(p<n){
                    if(coins[p]>i){
                        sum+=i;
                        ans++;
                        //cout<<"add:"<<i<<" sum:"<<sum<<endl;
                    }
                    else{
                        sum+=coins[p];
                        p++;
                    }
                }
                else{
                    sum+=i;
                    ans++;
                    //cout<<"add:"<<i<<" sum:"<<sum<<endl;
                }
            }
        }
        return ans;
    }
};