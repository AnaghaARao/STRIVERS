/*  Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix. */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrix(vector<vector<int>>& matrix){
    int col = 1;

    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j < matrix[i].size() ; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j==0) col = 0;
                else matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1 ; i < matrix.size() ; i++){
        for(int j = 1 ; j < matrix[i].size() ; j++){
            if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j] = 0;
        }
    }

    if(matrix[0][0]==0){
        for(int i = 0 ; i < matrix[0].size() ; i++) matrix[0][i] = 0;
    }

    if(col==0){
        for(int i = 0 ; i < matrix.size() ; i++) matrix[i][0] = 0;
    }

    return matrix;
}