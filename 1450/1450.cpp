class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n=startTime.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(startTime[i]<=queryTime[i] && quaryTime[i]<=endTime[i]) cnt++;
        }
        return cnt;

    }
};


/*
class Solution {
public: 
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int lessStart = upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
        int lessEnd = lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();
        return lessStart - lessEnd;
    }
};


upper_bound()
C++中的upper_bound 和lower_bound比较容易弄混。
记住的方法是根据名字记住其功能，
如upper_bound表示以某个数为上限，这个数应该放在哪个位置；
lower_bound表示以某个数为下限，这个数应该放在哪个位置。同时注意数组应该提前拍好序。

 
#include<bits/stdc++.h>
using namespace std;
int main() {
  int a[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
 
  cout << (lower_bound(a, a + 12, 4) - a) << endl; //输出 9
  cout << (upper_bound(a, a + 12, 4) - a) << endl; //输出 12
  cout << (lower_bound(a, a + 12, 1) - a) << endl; //输出 0
  cout << (upper_bound(a, a + 12, 1) - a) << endl; //输出 3
  cout << (lower_bound(a, a + 12, 3) - a) << endl; //输出 6
  cout << (upper_bound(a, a + 12, 3) - a) << endl; //输出 9
  cout << (lower_bound(a, a + 12, 5) - a) << endl; //输出 12
  cout << (upper_bound(a, a + 12, 5) - a) << endl; //输出 12
  cout << (lower_bound(a, a + 12, 0) - a) << endl; //输出 0
  cout << (upper_bound(a, a + 12, 0) - a) << endl; //输出 0
 
  return 0;
}
*/