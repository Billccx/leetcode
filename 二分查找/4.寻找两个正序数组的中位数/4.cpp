class Solution {
public:
    int getKmin(vector<int>& a,vector<int>& b, int k){
        //cout<<"find new"<<endl;

        int p=0,q=0,la=a.size(),lb=b.size();
        while(k>1){
            //cout<<k<<'p'<<p<<'q'<<q<<endl;
            if(p>la-1) return b[q+k-1];
            else if(q>lb-1) return a[p+k-1];

            int dp=min(k/2,la-p);
            int dq=min(k/2,lb-q);
            if(a[p+dp-1]<=b[q+dq-1]){
                p+=dp;
                k-=dp;
            }
            else if(a[p+dp-1]>b[q+dq-1]){
                q+=dq;
                k-=dq;
            }
        }
        if(p>=la) return b[q];
        else if(q>=lb) return a[p];
        else return min(a[p],b[q]);
    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=nums1.size()+nums2.size();
        if(l%2==0){
            double x=getKmin(nums1,nums2,l/2+1);
            double y=getKmin(nums1,nums2,l/2);
            return (x+y)/2;
        }
        else{
            return getKmin(nums1,nums2,l/2+1);
        }
    }
};