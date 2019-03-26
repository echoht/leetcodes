//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/10.
//  Copyright © 2019年 hust. All rights reserved.
//  string to integer(atoi)

#include <iostream>
#include <map>
#include <vector>
using namespace std;
//#define INT_MAX 2147483647
//#define INT_MIN INT_MAX*(-1)+1

int myAtoi(string s) {
    //去掉空格
    size_t i = 0;
    while(i < s.size() && s[i] == ' '){
        i++;
    }
    //判断正负
    int isPos = 1;
    if(i < s.size() && (s[i] == '-' || s[i] == '+')){
        if(s[i] == '-'){
            isPos = 0;
        }
        i++;
    }
    //数值部分
    if(i < s.size() && (s[i] < '0' || s[i] > '9')){
        return 0;
    }
    long number = 0;
    int dig = 0;
    while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
        //判断是否越界
        dig = s[i] - '0';
        if(isPos == 0){
            dig *= (-1);
        }
        number = number*10 + dig;
        std::cout<<number << " " << isPos << std::endl;
        if(number > INT_MAX){
            return INT_MAX;
        }
        if(isPos == 0 && number < INT_MIN){
            return INT_MIN;
        }
        i++;
    }
    
    return (int)number;
}
//this solution is faster
int myAtoi2(string s) {
    //去掉空格
    size_t i = 0;
    while(i < s.size() && s[i] == ' '){
        i++;
    }
    //判断正负
    int isPos = 1;
    if(i < s.size() && (s[i] == '-' || s[i] == '+')){
        if(s[i] == '-'){
            isPos = 0;
        }
        i++;
    }
    //数值部分
    if(i < s.size() && (s[i] < '0' || s[i] > '9')){
        return 0;
    }
    int number = 0;
    int dig = 0;
    while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
        //判断是否越界
        dig = s[i] - '0';
        if(isPos == 0){
            dig *= (-1);
        }
        //std::cout<<number << " " << dig<<" "<<INT_MIN/10 << std::endl;
        if(number >= INT_MAX/10){
            //std::cout<< "> INT_MAX" << std::endl;
            if(number == INT_MAX/10 && dig <= 7){
                return number*10+dig;
            }
            return INT_MAX;
        }
        if(number <= INT_MIN/10){
            if(number == INT_MIN/10 && dig >= -8){
                return number*10 + dig;
            }
            return INT_MIN;
        }
        number = number*10 + dig;
        i++;
    }
    return number;
}

int main(int argc, const char * argv[]) {
    std::cout<<INT_MAX<<std::endl;
    std::cout<<myAtoi2("-2147483647")<<std::endl;
    //std::cout<<myAtoi("   -42")<<std::endl;
    //std::cout<<myAtoi("4193 with words")<<std::endl;
    //std::cout<<myAtoi("words and 987")<<std::endl;
}
