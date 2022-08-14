#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> cap;
    vector<vector<int>> r;
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        for(int index=0;index<groupSizes.size();index++){
            bool hascap=false;
            for(int i=0;i<cap.size();i++){
                if(cap[i]==groupSizes[index] && r[i].size()<cap[i]){
                    r[i].push_back(index);
                    hascap=true;
                    break;
                } 
            }
            if(!hascap){
                cap.push_back(groupSizes[index]);
                vector<int> g;
                g.push_back(index);
                r.push_back(g);
            }
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<int> gpS={3,3,3,3,3,1,3};
    vector<vector<int>> result=s.groupThePeople(gpS);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }

}