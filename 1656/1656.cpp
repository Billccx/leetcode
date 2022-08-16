#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class OrderedStream {
public:
    vector<string> v;
    int ptr,n_;
    OrderedStream(int n):v(n+1),ptr(1),n_(n) {
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey]=value;
        vector<string> temp;
        if(this->ptr==idKey){
            while(this->ptr<=n_ && v[this->ptr]!=""){
                temp.push_back(v[this->ptr]);
                this->ptr++;
            }
        }
        return temp;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

// class vec{
// public:
//     vector<string> s;
//     vec(int n):s(n){

//     }


// };


// int main(){
//     vector<string> v(10);
//     string s="dfvfv";
//     s="dcdscvdsv";
    
//     vec v2(10);
//     for(int i=0;i<v2.s.size();i++){
//         if(v2.s[i]=="") cout<<'y'<<endl;
//     }

// }