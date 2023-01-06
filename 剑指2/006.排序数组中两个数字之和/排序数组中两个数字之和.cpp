class Solution {
public:

    int binarySearch(int start,int end,int target,vector<int>& v){
        int l=start,r=end;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]==target) return mid;
            else if(v[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        for(int i=0;i<len;i++){
 
            int temp=target-numbers[i];
            if(temp<numbers[i]){
                int index=binarySearch(0,i-1,temp,numbers);
                if(index!=-1) return {index,i};
            }
            else if(temp>numbers[i]){
                int index=binarySearch(i+1,len-1,temp,numbers);
                if(index!=-1) return {i,index};
            }
            else{
                if(i-1>=0 && numbers[i-1]==numbers[i]) return {i-1,i};
                else if(i+1<len && numbers[i+1]==numbers[i]) return {i,i+1};
            }

        }
        return {-1,-1};
    }
};

/*
该解法可以进一步优化，只考虑i的右侧数字即可，数组是升序的，再考虑左边就重复了，没有必要
*/