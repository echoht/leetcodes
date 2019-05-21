#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
//currently total have 
void getPermutationImp(int *arr, int *arrf, int n, int k, stringstream& str){
	//which number should be permutated currently
	if(n == 1){
        for(int j = 1; j < 10; j++){
            if(arr[j] != 0){
                str << j;
                std::cout << n << " " << j<< std::endl;
                break;
            }
        }
        return; 
    }
    int idx = 1; // 当前应该用第几个数去枚举
	while(k > idx*arrf[n-1]){
		idx++;
	}
	int i = 0; // 当前枚举的真实的数
	int cur_num = 1; 
    for(int j = 1; j < 10; j++){
        if(arr[j] != 0){
            i++;
            if(i == idx){
                cur_num = j;
                break;
            }
        }
    }
	str << cur_num;
    std::cout << n << " " << cur_num<< std::endl;
    // update 
	if(k > (idx-1)*arrf[n-1]){
		k = k- (idx-1)*arrf[n-1];
	}
	arr[cur_num] = 0;
	
	getPermutationImp(arr, arrf, n-1, k, str);
	
}
    string getPermutation(int n, int k) {
        // the set of n , 1<=n <= 9  
		int array[10] = {0};
		for(int i = 1; i <= n; i++){
			array[i] = 1;
		}
		// the factorial of each index
		int array_factorial[10] = {10};
		array_factorial[1] = 1;
		for(int i = 2; i <= n; i++){
			array_factorial[i] = i*array_factorial[i-1];
		}
		stringstream str;
		getPermutationImp(array, array_factorial, n, k, str);
		return str.str();
		
    }
	
int main(){
    std::cout<<getPermutation(4, 1);
}
