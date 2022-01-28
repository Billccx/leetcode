#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(
            properties.begin(),
            properties.end(),
            [](const vector<int> & a, const vector<int> & b){
                return a[0] == b[0] ? (a[1] < b[1]) : (a[0] < b[0]);
            }
        );
        int highdef=0,prehighdef=0,nowattack=properties[properties.size()-1][0],i=properties.size()-1,cnt=0;
        while(i>=0){
            if(properties[i][0]!=nowattack){
                nowattack=properties[i][0];
                prehighdef=max(prehighdef,highdef);
                highdef=properties[i][1];
            }
            if(properties[i][1]<prehighdef){
                cnt++;
            }
            highdef=max(highdef,properties[i][1]);
            i--;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v={{1,5},{10,4},{4,3}};
    int result=s.numberOfWeakCharacters(v);
    cout<<result<<endl;
}