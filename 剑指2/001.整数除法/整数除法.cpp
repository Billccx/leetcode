class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MIN){
            if(b==-1) return INT_MAX;
            else if(b==1) return INT_MIN;
        }
        if(b==INT_MIN){
            if(a==INT_MIN) return 1;
            else return 0;
        }
        if(a==0) return 0;

        bool isNeg=false;
        if(a>0){
            a=-a;
            isNeg=!isNeg;
        }
        if(b>0){
            b=-b;
            isNeg=!isNeg;
        }

        int l=1,r=INT_MAX,ans=0;
        while(l<=r){
            int mid=l+((r-l)>>1);
            //b*mid>=a
            bool flag=quickMulti(b,mid,a);
            if(flag){
                ans=mid;
                if(mid==INT_MAX) break;
                l=mid+1;
            }
            else r=mid-1;
        }

        return isNeg? -r:r;
    }

    bool quickMulti(int y,int z,int x){
        int result=0,add=y;
        while(z){
            if(z&1){
                if(result<x-add) return false;
                result+=add;
            }
            if(z!=1){
                if(add<x-add) return false;
                add+=add;
            }
            z=z>>1;
        }
        return true;
    }
};