class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> step={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,cnt=0;
        vector<int> ans;
        int m=matrix.size();
        if(m==0) return ans;
        int n=matrix[0].size();
        if(n==0) return ans;
        while(true){
            ans.push_back(matrix[x][y]);
            matrix[x][y]=-200;
            int nx=x+step[cnt][0],ny=y+step[cnt][1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && matrix[nx][ny]>=-100){
                x=nx;
                y=ny;
            }
            else{
                cnt=(cnt+1)%4;
                nx=x+step[cnt][0],ny=y+step[cnt][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && matrix[nx][ny]>=-100){
                    x=nx;
                    y=ny;
                }
                else break;
            }
        }
        return ans;
    }
};