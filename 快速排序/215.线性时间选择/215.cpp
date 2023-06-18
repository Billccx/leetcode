class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition3(a, l, r);
    }

    //题解的划分方式
    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    inline int partition2(vector<int>& a,int l,int r){
        int i=l,j=r-1,x=a[r];
        //此处必须为i<=j
        while(i<=j){
            if(a[i]>x){
                swap(a[i],a[j]);
                j--;
            }
            else i++;
        }
        swap(a[i],a[r]);
        return i;
    }

    inline int partition3(vector<int>& a,int l,int r){
        int i=l,j=r-1,x=a[r];
        while(i<=j){
            while(a[i]<x && i<=j){
                i++;
                if(i>=r) break;
            } 
            while(a[j]>=x && j>=i){
                j--;
                if(j<0) break;
            }
            if(i<=j) swap(a[i],a[j]);
        }
        swap(a[i],a[r]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};