class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        return a.first>b.first;
    }

    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>> v;
        int len=values.size();
        for(int i=0;i<len;i++){
            v.push_back(make_pair(values[i],labels[i]));
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=0,p=0,ans=0;
        unordered_map<int,int> ump;
        while(p<len){
            if(!ump.count(v[p].second)||ump[v[p].second]<useLimit){
                ans+=v[p].first;
                ump[v[p].second]++;
                cnt++;
                if(cnt==numWanted) break;
            }
            p++;
        }
        return ans;
    }
};