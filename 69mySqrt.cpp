#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
int mySqrt(int x) {
        if(x <= 1){
			return x;
		}
		//binary search 
		int left = 1, right = x;
		int mid ;
		while(left < right ){
			mid = left + (right-left)/2;
			if(x/mid >= mid){
                left = mid+1;
			}else{
				right = mid;
			}
		}
		return right-1;
    }
	//牛顿法
    int mySqrt2(int x) {
        if(x <= 1){
			return x;
		}
		double pre = 0, res = 1;
		while(abs(pre-res) > 1e-6){
			pre = res;
			res = 0.5*(res + x/res);
		}
		return int(res);	
    }
	
int main(){
    std::cout<<mySqrt(3);
    std::cout<<mySqrt(2);
}
