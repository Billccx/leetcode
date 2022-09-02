#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> result;
    stack<pair<int,int>> s;
    vector<int> finalPrices(vector<int>& prices) {
        int len=prices.size();
        result.resize(len,0);
        for(int i=0;i<len;i++){
            while(!s.empty() && s.top().first>=prices[i]){
                pair<int,int> temp=s.top();
                s.pop();
                result[temp.second]=temp.first-prices[i];
            }
            s.push(make_pair(prices[i],i));
        }

        while(!s.empty()){
            pair<int,int> temp=s.top();
            result[temp.second]=temp.first;
            s.pop();
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> prices={10,1,1,6};
    vector<int> result=s.finalPrices(prices);
    for(int i=0;i<result.size();i++) cout<<result[i]<<' ';
    cout<<endl;
}