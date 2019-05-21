#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
    //DP alg
	int uniquePaths(int m, int n) {
		if(m <= 0 || n <= 0){
			return 0;
		}
        int a[100][100]; // 最大不超过100 
		for(int i = 0 ; i < m; i ++){
			for(int j = 0; j < n; j++){
				if(i == 0 || j== 0){
					a[i][j] = 1;
				}else{
					a[i][j] = a[i-1][j] + a[i][j-1];
				}
			}
		}
		return a[m-1][n-1];
    }
