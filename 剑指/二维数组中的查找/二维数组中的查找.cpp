class Solution {
public:
    bool binarySEarch(vector<int>& v,int target){
        int len=v.size();
        int l=0,r=len-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]==target) return true;
            else if(v[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            bool result=binarySEarch(matrix[i],target);
            if(result) return true;
        }
        return false;
    }
};