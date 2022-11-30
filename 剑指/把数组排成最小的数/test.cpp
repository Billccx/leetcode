#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int cmp(int a, int b){
    return a<b;
}

int main(){
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}