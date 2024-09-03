// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0 ; i < 9 ; i++){
            // row check
            if(board[row][i]==c) return false;

            // col check
            if(board[i][col]==c) return false;

            // block check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        // traversing the entire board
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                // checking if any of the positions are empty
                if(board[i][j]=='.'){
                    // checking which value is valid for this position
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            // if placing this number helps solve the entire board
                            // return true
                            if(solve(board)==true) return true;
                            // else this placement doesnt yield any valid result, so
                            else board[i][j] = '.';
                        }
                    }
                    // if none of the positions are valid
                    return false;
                }
            }
        }
        // since the loop isnt executed, it means all positions are filled
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};