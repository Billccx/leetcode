class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rlen=mat.size(),clen=mat[0].size(),cnt=0;
        vector<int> rowcnt(rlen);
        vector<int> colcnt(clen);
        vector<vector<int>> v;
        for(int i=0;i<rlen;i++){
            for(int j=0;j<clen;j++){
                if(mat[i][j]){
                    rowcnt[i]++;
                    colcnt[j]++;
                    vector<int> temp={i,j};
                    v.push_back(temp);
                }
            }
        }

        for(auto item: v){
            if(rowcnt[item[0]]==1 && colcnt[item[1]]==1) cnt++;
        }

        return cnt;




    }
};