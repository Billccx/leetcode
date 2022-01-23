#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class StockPrice {
public:
    unordered_map<int,int> ump;
    multiset<int> mts;
    int current_time;

    StockPrice() {
        current_time=-1;
    }
    
    void update(int timestamp, int price) {
        if(timestamp>current_time){
            ump[timestamp]=price;
            mts.insert(price);
            current_time=timestamp;
        }
        else{
            multiset<int>::iterator it=mts.find(ump[timestamp]);
            ump[timestamp]=price;
            if(it!=mts.end()) mts.erase(it);
            mts.insert(price);
        }

    }
    
    int current() {
        return ump[current_time];
    }
    
    int maximum() {
        return *mts.rbegin();
    }
    
    int minimum() {
        return *mts.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */


int main(){
    StockPrice* obj = new StockPrice();
    obj->update(38,2308);
    cout<<obj->maximum()<<endl;
    cout<<obj->current()<<endl;
    cout<<obj->minimum()<<endl;
    obj->update(2,5);
    
    cout<<obj->maximum()<<endl;
    obj->update(1,3);
    cout<<obj->maximum()<<endl;
    obj->update(4,2);
    cout<<obj->minimum()<<endl;
}