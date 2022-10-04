#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool has0inCol0=false;
        bool has0inRow0=false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                has0inCol0=true;
                break;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                has0inRow0=true;
                break;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                cout<<matrix[i][j]<<' ';
            }
            cout<<endl;
        }



        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                   matrix[i][j]=0;
                }
            }
        }

        // for(int i=0;i<matrix[0].size();i++){
        //     if(matrix[0][i]==0){
        //         for(int j=0;j<matrix[0].size();j++) matrix[0][j]=0;
        //         break;
        //     }
        // }

        if(has0inCol0){
            for(int i=0;i<matrix.size();i++) matrix[i][0]=0;
        }
        if(has0inRow0){
            for(int i=0;i<matrix[0].size();i++) matrix[0][i]=0;
        }

    }
};

int main(){
    Solution s;
    vector<vector<int>> v={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(v);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}