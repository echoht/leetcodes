//
//  SudokuSolver_37.cpp
//  LeetcodeByEcho
//
//  Created by Dylan326 on 2019/4/21.
//  Copyright © 2019 DE. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
//find the possible num at(r, c), default is 1-9, remove those number appear at row r and col c and sub 3x3
vector< char > possibleSul(vector<vector<char>>& board, int r, int c){
    vector<char> res;
    set<char> appeared;
    for(int i = 0; i < 9; i++){
        if(board[r][i] != '.'){
            appeared.insert(board[r][i]);
        }
        
        if(board[i][c] != '.'){
            appeared.insert(board[i][c]);
        }
    }
    //sub 3x3
    int r_ = r/3*3;
    int c_ = c/3*3;
    for(int i = r_ ; i < r_ + 3; i++){
        for(int j= c_; j < c_+3; j++){
            if(i == r || j == c || board[i][j] == '.'){
                continue ;
            }
            appeared.insert(board[i][j]);
        }
    }
    for (int i = 1; i < 10; i++){
        char x = i+'0';
        if(appeared.find(x) != appeared.end()){
            continue;
        }
        res.push_back(x);
    }
    return res;
}
bool solveSudokuImp(vector<vector<char>>& board, vector<std::pair<int, int>> &cooards, int idx){
    if(idx >= cooards.size()){
        return true;
    }
    pair<int, int> p = cooards[idx];
    vector<char> solus = possibleSul(board, p.first, p.second);
    
    
    for(auto s : solus){
        board[p.first][p.second] = s;
        bool ret = solveSudokuImp(board, cooards, idx+1);
        if(ret ){
            return true;
        }
    }
    board[p.first][p.second] = '.';
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<std::pair<int, int> > cooards;
    for(int i =0 ;i < 9; i++){
        for(int j = 0; j < 9; j++){
            if( board[i][j] == '.' ){
                cooards.push_back(make_pair(i, j));
            }
        }
    }
    solveSudokuImp(board, cooards, 0);
}

int main(){
    char a[9][9] =
      { {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    vector<vector<char>> board;
    for(int i = 0; i < 9; i ++){
        vector<char> aa;
        for(int j = 0; j < 9; j++){
            aa.push_back(a[i][j]);
        }
        board.push_back(aa);
    }
    solveSudoku(board);
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j++){
            std::cout<< board[i][j] << ",";
        }
        std::cout<<std::endl;
    }
}
