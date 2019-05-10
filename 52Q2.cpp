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
bool issafe(vector<int> &board, int idx, int pos, int n){
    // col 
    std::cout << "idx :" << idx << ", pos :" << pos << "\n   board info : ";
    for(int i = 0; i < idx; i++){
        std::cout<< board[i] << ",";
        if(board[i] == pos){
            std::cout<<" false"<<std::endl;
            return false;
        }
		if(abs(board[i] - pos) == idx-i)
		{
            std::cout<<" false"<<std::endl;
			return false;
		}
    }
    std::cout<<" true"<<std::endl;
    
    return true;
}
// second method 
void dfs2(vector<int> &board, int idx, int n, int &res ){
    if(idx == n){
        res++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!issafe(board, idx, i, n)){
            continue;
        }
        
        board.push_back(i);
        dfs2(board, idx+1, n, res);
        board.pop_back();
    }
    return;
}
int solveNQueens(int n) {
    vector<int> board;
    int res=0;
    dfs2(board, 0, n, res);
    return res;
} 

int main(){
    int n = 4;
    int res = solveNQueens(n);
    
    std::cout<<res<<std::endl;
  
}
