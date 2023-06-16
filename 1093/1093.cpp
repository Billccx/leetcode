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

//更好的写法

/*
class Solution {
public:    
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int total = accumulate(count.begin(), count.end(), 0);
        double mean = 0.0;
        double median = 0.0;
        int minnum = 256;
        int maxnum = 0;
        int mode = 0;

        int left = (total + 1) / 2;
        int right = (total + 2) / 2;
        int cnt = 0;
        int maxfreq = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)count[i] * i;  //ll转换写法
            if (count[i] > maxfreq) {
                maxfreq = count[i];
                mode = i;
            }
            if (count[i] > 0) {
                if (minnum == 256) {
                    minnum = i;
                }
                maxnum = i;
            }
            if (cnt < right && cnt + count[i] >= right) {
                median += i;
            }
            if (cnt < left && cnt + count[i] >= left) {
                median += i;
            }
            cnt += count[i];
        }
        mean = (double) sum / total;
        median = median / 2.0;
        return {(double)minnum, (double)maxnum, mean, median, (double)mode};
    }
};
*/