#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
// -100.0 < x < 100.0
//n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
double powImp(double x, long n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return x;
	}
	double tmp = powImp(x, n/2);
	if(n & 1 == 1){
		return tmp*tmp*x;
	}
	return tmp*tmp;
}

double myPow(double x, int n) {
    if(n<0){
		long l = (long)n*(-1);  //这里需要注意有最小负数int*（-1）后大于最大正数int
		double tmp = powImp(x,l);
		return 1/tmp;
	} 
	return powImp(x, n);
}
