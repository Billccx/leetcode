class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> lr,rl;
        int len=a.size();
        int temp=1;
        for(int i=0;i<len;i++){
            temp=temp*a[i];
            lr.push_back(temp);
        }
        temp=1;
        for(int i=len-1;i>=0;i--){
            temp*=a[i];
            rl.push_back(temp);
        }
        vector<int> ans;
        for(int i=0;i<len;i++){
            int t=1;
            if(i-1>=0) t*=lr[i-1];
            if(i+1<len) t*=rl[len-i-2];
            ans.push_back(t);
        }
        return ans;
    }
};

/*
可以采用
vector<int> L(length, 0), R(length, 0);
的方式初始化数组
*/