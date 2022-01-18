#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int parseTime(string t){
        int h=stoi(t.substr(0,2));
        int m=stoi(t.substr(3,2));
        int minutes=h*60+m;
        return minutes;
    }


    int findMinDifference(vector<string>& timePoints) {
        vector<int> t2;
        for(auto item:timePoints){
            t2.push_back(this->parseTime(item));
        }
        sort(t2.begin(),t2.end());
        int min=0x3f3f3f3f;
        for(int i=0;i<t2.size()-1;i++){
            if((t2[i+1]-t2[i])<min){
                min=t2[i+1]-t2[i];
            }
        }

        if((1440+t2[0]-t2[t2.size()-1])<min){
            min=1440+t2[0]-t2[t2.size()-1];
        }

        return min;
    }
};


int main(){
    vector<string> v={"23:59","00:00"};
    Solution s;
    int result=s.findMinDifference(v);
    cout<<result<<endl;
}