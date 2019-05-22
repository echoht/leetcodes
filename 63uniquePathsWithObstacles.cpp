#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
    //DP alg
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		int m = obstacleGrid.size();
		if(m <= 0){
			return 0;
		}
		int n = obstacleGrid[0].size();
		if(n <= 0 ){
			return 0;
		}
		long a[100][100]; // 最大不超过100 
		for(int i = 0 ; i < m; i ++){
			for(int j = 0; j < n; j++){
				if(obstacleGrid[m-1-i][n-1-j] == 1){
					a[i][j] = 0;
					continue;
				}
				if(i == 0 || j== 0){
                    if(i == 0 && j == 0){
                        a[i][j] = 1;
                    }
					else if( (i >= 1 && (a[i-1][j] == 0 || obstacleGrid[m-1-(i-1)][n-1-j] == 1) )  || ( j >= 1 && (a[i][j-1] == 0 || obstacleGrid[m-1-i][n-1-(j-1)] == 1)) ){
						a[i][j] = 0;
					}else{
						a[i][j] = 1;
					}
				}else{
					if( (obstacleGrid[m-1-(i-1)][n-1-j] == 1 && obstacleGrid[m-1-i][n-1-(j-1)])){
						a[i][j] = 0;
					}else if(obstacleGrid[m-1-(i-1)][n-1-j] == 1 ){
						a[i][j] = a[i][j-1];
					}else if(obstacleGrid[m-1-i][n-1-(j-1)] == 1 ){
						a[i][j] = a[i-1][j];
					}else{
						a[i][j] = a[i-1][j] + a[i][j-1];
					}
				}
			}
		}
		return a[m-1][n-1];
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
