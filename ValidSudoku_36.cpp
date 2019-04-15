//
//  ValidSudoku_36.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/4/15.
//  Copyright © 2019 DE. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for(int k = 0; k < 3; ++k){
        for(int i = 0; i < 9; i++){
            int a[9] = {0};
            for(int j= 0; j < 9; j ++){
                char ele;
                if (k == 0){
                    ele = board[i][j];
                }else if(k == 1) {
                    ele = board[j][i];
                }else{
                    int i_ = i/3*3+j/3;
                    int j_ = i%3*3+j%3;
                    std::cout<<"("<<i<<","<<j<<"), (" << i_ << "," << j_<<")"<<std::endl;
                    ele = board[i_][j_];
                }
                if(ele != '.'){
                    int x = ele - '0'-1;
                    a[x] += 1;
                    if (a[x] != 1){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int a[9][9] = {{'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    vector< vector<char> > A ;
    for(int i = 0; i < 9; ++i){
        vector<char> aa;
        
        for(int j = 0; j < 9; j++){
            aa.push_back(a[i][j]);
        }
        A.push_back(aa);
    }
    std::cout<<A.size();
    std::cout<<isValidSudoku(A);
}
