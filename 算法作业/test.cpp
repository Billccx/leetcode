#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int>& v){
    for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
    cout<<endl;
}

void dfs(vector<int>& v, int n){
    if(n==1) print(v);
    else{
        for(int i=0;i<n;i++){
            dfs(v,n-1);
            if(n%2==1){
                swap(v[0],v[n-1]);
            }
            else{
                swap(v[i],v[n-1]);
            }
        }
    }
}


int main(){
    vector<int> v={1,2,3,4,5};
    dfs(v,5);
}