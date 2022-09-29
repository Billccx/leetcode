#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double sum=0.0;
    for(int i=1;i<=50000000;i++){
        sum+=pow(-1,i+1)/(2*i-i);
    }
    cout<<sum<<endl;
}