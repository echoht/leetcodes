#include <iostream>
#define INT_MIN -2^31
#define INT_MAX 2^31
using namespace std;

//利用减法做除法
int divide(int dividend, int divisor) {
    long res = 0;
    int flg = 1;  
    long dividend_long = dividend;
    long divisor_long = divisor;
    if(dividend == 0){
        return 0;
    }
    if(dividend > 0 && divisor < 0 ){
        divisor_long = 0-divisor_long;
        flg = -1;
    }
    if(dividend < 0 && divisor > 0 ){
        dividend_long = 0-dividend_long;
        flg = -1;
    }
    if(dividend < 0 && divisor < 0 ){
        dividend_long = 0-dividend_long;
        divisor_long = 0-divisor_long;
    }
    std::cout<<dividend_long <<","<<divisor_long<<std::endl; 
    while(dividend_long-divisor_long >= 0){
        long tmp = divisor_long;
        //<< tmp until larger divisor 
        long i = 1;
        while(true){
            tmp = tmp << 1;
            if(tmp > dividend_long){
                tmp = tmp >> 1;
                break;
            }
            i = i<<1;
        }
        res += i;
        std::cout<<dividend_long<<","<<tmp<<","<<i<<std::endl;
        dividend_long = dividend_long -tmp;
    }    
    if(flg == -1){
        return 0-res;
    }
    if (res >= 2147483648){
        res = 2147483647;
    }
    return res;
}

int main(){
    std::cout<<divide(-1,-1);
}
