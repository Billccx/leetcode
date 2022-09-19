#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<int,int>& a,const pair<int,int>& b){
        if(a.second<b.second) return true;
        else if(a.second>b.second) return false;
        else{
            return a.first>b.first;
        }
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;
        int len=nums.size();
        for(int i=0;i<len;i++){
            ump[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto iter=ump.begin();iter!=ump.end();iter++){
            v.push_back(make_pair(iter->first,iter->second));
        }

        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            int temp=v[i].first;
            int cnt=v[i].second;
            //cout<<"temp:"<<temp<<" cnt:"<<cnt<<endl;
            for(int j=0;j<cnt;j++) ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v={1,1,2,2,2,3};
    vector<int> ans=s.frequencySort(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}