class NumMatrix {
public:
    vector<vector<int>> presum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        presum.resize(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
                presum[i+1][j+1]=presum[i][j+1]+sum;
            }
        }

        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<presum[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2+1][col2+1]-presum[row2+1][col1]-presum[row1][col2+1]+presum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */