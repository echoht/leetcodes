#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > res;
		if(n <= 0){
			return res;
		}
		int cicle = n/2 + 1;
		int num = 1;
		int x, y;
		//initialize
		for(int i = 0; i < n; i++){
			vector<int> tmp(n);
			res.push_back(tmp);
		}
		for(int i = 0; i < cicle; i++){
			//->
			x = i;
			for(y = i; y < n-i; y++){
				res[x][y] = num++;
			}
			//|
			y = n-i-1;
			for(x=i+1; x < n-i; x++){
				res[x][y] = num++;
			}
			//<-
			x = n-i-1;
			for(y = n-i-2; y >= i; y--){
				res[x][y] = num++;
			}
			// |
			y = i;
			for(x = n-i-2; x > i ; x--){
				res[x][y] = num++;
			}
		}
		return res;
    }
	
int main(){
    vector<vector<int> > res =generateMatrix(5)  ;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout<<res[i][j] << ",";
        }
        std::cout << std::endl;
    }
}
