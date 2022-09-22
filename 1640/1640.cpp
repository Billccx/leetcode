class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> ump;
        int len=pieces.size();
        for(int i=0;i<len;i++) ump[pieces[i][0]]=i;
        int p=0;
        len=arr.size();
        while(p<len){
            if(!ump.count(arr[p])) return false;
            int q=0,index=ump[arr[p]];
            while(p<len && q<pieces[index].size()){
                if(arr[p]!=pieces[index][q]) return false;
                p++;
                q++;
            }
            if(q<pieces[index].size()) return false;
        }
        return true;
    }
};