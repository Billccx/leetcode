class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> ump;
        int len=time.size();
        for(int i=0;i<60;i++) ump[i]=0;
        for(int i=0;i<len;i++){
            ump[time[i]%60]++;
        }
        int ans=((long long)ump[0])*(ump[0]-1)/2;
        for(int i=1;i<30;i++){
            ans+=ump[i]*ump[60-i];
        }
        ans+=((long long)ump[30])*(ump[30]-1)/2;
        return ans;
    }
};