class Solution {
public:
    int findNthDigit(int n) {
        int sum=0,p=0;
        if(n==0) return 0;
        long long temp=n;
        while(n>0){
            long long temp=n;
            temp-=9*((long long)pow(10,p))*(p+1);
            if(temp<=0){
                p++;
                break;
            } 
            else{
                p++;
                n=temp;
            } 
            cout<<"n:"<<n<<endl;
        }
        p--;
        cout<<"n:"<<n<<" p:"<<p<<endl;
        int diff=n;
        cout<<"diff:"<<diff<<endl;
        int cnt=diff/(p+1),place=diff%(p+1);
        if(!place){
            place+=p+1;
            cnt=max(0,cnt-1);
        }
        place=(p+1)-place;
        cout<<"cnt:"<<cnt<<" place:"<<place<<endl;
        int num=pow(10,p)+cnt;
        cout<<"num:"<<num<<endl;
        int q=0;
        while(q<place){
            num=num/10;
            q++;
        } 
        return num%10;

    }
};