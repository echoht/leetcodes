#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
	int min(int a, int b){
		return a<b? a : b;
	}
    //DP alg
	int minPathSum(vector<vector<int>>& grid) {
        // 复用grid吗？
		int m = grid.size();
		if(m <= 0){
			return 0;
		}
		int n = grid[0].size();
		if(n <= 0 ){
			return 0;
		}
		int x,y;
		for(int i = 0 ; i < m; i ++){
			for(int j = 0; j < n; j++){
				x = m-1-i;
				y = n-1-j;
				
				if(i == 0 || j == 0){
					if(i == 0 && j == 0){
						continue;
					}
					if(i > 0){  //then j == 0 in this case
						grid[x][y] += grid[x+1][y];
					}else{
						grid[x][y] += grid[x][y+1];
					}
				}else{
					grid[x][y] += min(grid[x+1][y],grid[x][y+1]);
				}
			}
		}
		return grid[0][0];
    }
    
int main(){
    vector<vector<int> > nums;
    for(int i = 0; i < 1; i++){
        vector<int> tmp(2);
        nums.push_back(tmp);
    }
    //[[0,0,1]]
    nums[0][0] = 1;
    std::cout<<uniquePathsWithObstacles(nums);
}
