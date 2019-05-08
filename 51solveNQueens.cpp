#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
// n queens problem
// the possible position that idx'th queen can put 
vector<int> possible(vector<string> &board, int idx, int n){
    vector<int> poses;
    if(idx == 0) {
        for(int i = 0; i < n; i++){
            poses.push_back(i);
        }
        return poses;
    }
    set<int> ill_pos;
    for(int i = 0; i < idx; i++){
        for(int y = 0; y <n; y++){
            if(board[i][y] == 'Q'){
                ill_pos.insert(y);
                if(y-(idx-i) >= 0)
                    ill_pos.insert(y-idx+i);
                if(idx-i+y < n)
                    ill_pos.insert(idx-i+y);
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(ill_pos.find(i) == ill_pos.end()){
            poses.push_back(i);
        }
    }
    return poses;
} 
void printboard(vector<string> board, int idx, vector<int> poses){
    std::cout << "idx is:" << idx << std::endl;
    for(int i = 0; i < board.size(); i++){
        std::cout<<board[i] << std::endl ;
    }
    std::cout << "next possible solutions: " ;
    for(int i = 0; i < poses.size(); i++){
        std::cout<< poses[i] << ",";
    }
    std::cout << std::endl;
}
void dfs(vector<string> &board, int idx, int n, vector<vector<string> > &res ){
    if(idx == n){
        res.push_back(board);
        return;
    }
    vector<int> poses = possible(board, idx, n);
    printboard(board, idx, poses);
    if(poses.size() <= 0){
        return;
    }
    for(int i = 0; i < poses.size(); i++){
        int pos = poses[i];
        board[idx][pos] = 'Q';
        dfs(board, idx+1, n, res);
        board[idx][pos] = '.';
    }
    return;
}
bool issafe(vector<string> &board, int idx, int pos, int n){
    // col 
    for(int i = 0; i < idx; i++){
        if(board[i][pos] == 'Q'){
            return false;
        }
    }
    // diag
    for(int i =idx-1, j = pos-1; i >=0 && j >=0; i--,j-- ){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    // diag
    for(int i =idx-1, j = pos+1; i >=0 && j < n; i--,j++ ){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
// second method 
void dfs2(vector<string> &board, int idx, int n, vector<vector<string> > &res ){
    if(idx == n){
        res.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!issafe(board, idx, i, n)){
            continue;
        }
        int pos = i;
        board[idx][pos] = 'Q';
        dfs(board, idx+1, n, res);
        board[idx][pos] = '.';
    }
    return;
}
vector<vector<string> > solveNQueens(int n) {
    vector<string> board;
    char *str = new char[n+1];
    for(int i = 0; i < n; i++){
        str[i] = '.';
    }
    str[n] = '\0'; 
    string line(str);
    for(int i = 0; i < n; i++){
        board.push_back(line);
        std::cout<< line << std::endl;
    }
    vector<vector<string> > res;
    dfs2(board, 0, n, res);
    return res;
} 

int main(){
    int n = 4;
    vector<vector<string> > res = solveNQueens(n);
    for(int i = 0 ; i < res.size(); i++){
        for(int j = 0; j < n; j++){
            string line = res[i][j];
            std::cout<< line << std::endl;
        } 
        std::cout<<std::endl;
    }
}
