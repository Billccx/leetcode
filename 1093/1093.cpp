class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minimum=-1,maximum=-1,mode,cnt=0;
        double mean,median=0,t=0;
        long long sum=0;
        vector<int> v;
        for(int i=0;i<256;i++){
            if(count[i]){
                if(minimum<0) minimum=i;
                maximum=max(maximum,i);
                if(count[i]>t){
                    t=count[i];
                    mode=i;
                }
                v.push_back(i);
                cnt+=count[i];
                sum+=((long long)i)*((long long)count[i]);
            }
        }

        //cout<<sum<<endl;

        mean=((double)sum)/cnt;

        int l=v.size();
        int p=cnt/2+1,temp=0;
        for(int i=0;i<l;i++){
            temp+=count[v[i]];
            if(temp>=p){
                median+=(double)v[i];
                break;
            }
        }

        if(cnt%2) return {double(minimum),double(maximum),mean,median,(double)mode};
        temp=0;
        for(int i=0;i<l;i++){
            temp+=count[v[i]];
            if(temp>=(p-1)){
                median+=(double)v[i];
                median/=2;
                break;
            }
        }
        return {double(minimum),double(maximum),mean,median,(double)mode};
    }
};