#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l=height.size();
        int p=0,q=1,sum=0;
        while(p<l){
            q=p+1;
            while(q<l && height[p]>=height[q]) q++;
            //cout<<q<<endl;
            if(q==l) p=q;
            else{
                for(int i=p+1;i<q;i++){
                    sum+=(height[p]-height[i]);
                    //cout<<"sum+"<<(height[p]-height[i])<<endl;
                }
                p=q;
            }
        }

        p=l-1;

        while(p>=0){
            q=p-1;
            while(q>=0 && height[p]>height[q]) q--;
            //cout<<q<<endl;
            if(q<0) p=q;
            else{
                for(int i=p-1;i>q;i--){
                    sum+=(height[p]-height[i]);
                    //cout<<"sum+"<<(height[p]-height[i])<<endl;
                }
                p=q;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> height ={4,2,0,3,2,5};
    int result=s.trap(height);
    cout<<result<<endl;
}