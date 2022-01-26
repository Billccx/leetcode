#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class DetectSquares {
public:
    unordered_map<int, unordered_map<int,int> > ump;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        ump[point[0]][point[1]]+=1;
    }
    
    int count(vector<int> point) {
        int sum=0;
        for(auto iter=ump[point[0]].begin();iter!=ump[point[0]].end();iter++){
            int y=iter->first,d=iter->first-point[1];
            if(d==0) continue;
            // cout<<point[0]<<","<<y<<endl;
            // cout<<ump[point[0]][point[1]]<<endl;
            // cout<<ump[point[0]-d].count(point[1])<<endl;
            // cout<<ump[point[0]-d].count(point[1])<<endl;
            // cout<<ump[point[0]-d].count(y)<<endl;
            // cout<<ump[point[0]+d].count(point[1])<<endl;
            // cout<<ump[point[0]+d].count(y)<<endl;

            if(ump[point[0]-d].count(point[1])&&ump[point[0]-d].count(y)){
                sum+=ump[point[0]][y]*ump[point[0]-d][point[1]]*ump[point[0]-d][y];
            }
            if(ump[point[0]+d].count(point[1])&&ump[point[0]+d].count(y)){
                sum+=ump[point[0]][y]*ump[point[0]+d][point[1]]*ump[point[0]+d][y];
            }
        }
        //cout<<sum<<endl;
        return sum;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */


int main(){
    DetectSquares* obj = new DetectSquares();
    int result;
    obj->add(vector<int>{3,10});
    obj->add(vector<int>{11,2});
    obj->add(vector<int>{3,2});
    result=obj->count(vector<int>{11,10});
    cout<<result<<endl;
    result=obj->count(vector<int>{14,8});
    cout<<result<<endl;
    obj->add(vector<int>{11,2});
    result=obj->count(vector<int>{11,10});
    cout<<result<<endl;
}