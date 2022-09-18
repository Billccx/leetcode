#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> v={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int AliceStartMonth=stoi(arriveAlice.substr(0,2));
        int AliceStartDay=stoi(arriveAlice.substr(3,2));

        int BobStartMonth=stoi(arriveBob.substr(0,2));
        int BobStartDay=stoi(arriveBob.substr(3,2));

        int AliceLeaveMonth=stoi(leaveAlice.substr(0,2));
        int AliceLeaveDay=stoi(leaveAlice.substr(3,2));

        int BobLeaveMonth=stoi(leaveBob.substr(0,2));
        int BobLeaveDay=stoi(leaveBob.substr(3,2));

        int As=0;
        for(int i=1;i<AliceStartMonth;i++) As+=v[i];
        As+=AliceStartDay;

        int Bs=0;
        for(int i=1;i<BobStartMonth;i++) Bs+=v[i];
        Bs+=BobStartDay;

        int Ae=0;
        for(int i=1;i<AliceLeaveMonth;i++) Ae+=v[i];
        Ae+=AliceLeaveDay;

        int Be=0;
        for(int i=1;i<BobLeaveMonth;i++) Be+=v[i];
        Be+=BobLeaveDay;
        cout<<As<<' '<<Ae<<' '<<Bs<<' '<<Be<<endl;

        if(Ae<Bs || As>Be) return 0;
        else if(As<=Bs && Ae>=Be){
            return Be-Bs+1;

        }
        else if(Bs<=As&& Be>=Ae){
            return Ae-As+1;
        }
        else if(Ae>=Bs && As<Bs){
            return Ae-Bs+1;
        }
        else if(Be>As && Bs<As){
            return Be-As+1;
        }
        
        return 0;
    }
};

int main(){
    Solution s;
    string arriveAlice = "08-06 ", leaveAlice = "12-08", arriveBob = "02-04", leaveBob = "09-01";
    int result=s.countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob);
    cout<<result<<endl;
}