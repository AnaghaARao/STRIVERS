// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. 
// You may return the answer in any order.Each solution contains a distinct board configuration of the n-queens' placement, 
// where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include<bits/stdc++.h>
using namespace std;

void solve(int col, vector<string>& board, vector<int>& rowCheck, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, vector<vector<string>>& res, int n){
    if(col == n){
        res.push_back(board);
        return;
    }

    for(int row = 0 ; row < n ; row++){
        if(rowCheck[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            rowCheck[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row] = 1;
            board[row][col] ='Q';
            solve(col+1, board, rowCheck, upperDiagonal,lowerDiagonal,res,n);
            rowCheck[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row] = 0;
            board[row][col] ='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    string s(n,'.');
    vector<string> board(n,s);
    vector<int> rowCheck(n,0);
    vector<int>upperDiagonal(2*n-1,0);
    vector<int>lowerDiagonal(2*n-1,0);
    solve(0, board, rowCheck, upperDiagonal, lowerDiagonal, res,n);
    return res;
    // cout<<board[0]<<endl;
    return res;
}

// UNOPTIMIZED SOLUTION

// bool isSafe(int row, int col, vector<string> board, int n){
//     int r = row, c = col;

//     while(r>=0 && c>=0){
//         if(board[r--][c--]=='Q') return false;
//     }

//     r = row, c = col;
//     while(c>=0){
//         if(board[r][c--]=='Q') return false;
//     }

//     r = row, c = col;
//     while(r<n && c>=0){
//         if(board[r++][c--]=='Q') return false;
//     }

//     return true;
// }

// void solve(int row, int col,vector<string>&board, vector<vector<string>>& res, int n){
//     if(col == n){
//         res.push_back(board);
//         return;
//     }

//     for(int i = 0 ; i < row ; i++){
//         if(isSafe(i,col,board,n)){
//             board[row][col] = 'Q';
//             solve(row,col+1,board,res,n);
//             board[row][col] = '.';
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n){
//     vector<vector<string>> res;
//     vector<string>board;
//     string s(n,'.');
//     for(int i = 0 ; i < n ; i++) board.push_back(s);
//     solve(0,0,board,res,n);
//     return res;
// }