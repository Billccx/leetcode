#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Range {
        int l, r;
        Range(int x,int y) {l=x;r=y;}
        bool operator< (const Range &W) {
            return l < W.l;
        }
    };

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){return a[0]<b[0];});
        priority_queue <struct Range> ends;
        for(int i=0;i<intervals.size();i++){
            struct Range temp{intervals[i][0],intervals[i][1]};
            if(ends.empty()|| ends.top().r >= temp.l){
                ends.push(temp);
            }
            else{
                struct Range t = ends.top();
                ends.pop();
                t.r=intervals[i][1];
                ends.push(t);
            }
            
            
        }
        return ends.size();
    }
};


int main() {
    vector<vector<int>> v = { {5,10},{6,8},{1,5},{2,3},{1,10} };
    Solution s;
    int result = s.minGroups(v);
    cout << result << endl;


}