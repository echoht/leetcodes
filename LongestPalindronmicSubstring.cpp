//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/10.
//  Copyright © 2019年 hust. All rights reserved.
//  longestPalindrome

#include <iostream>
#include <map>
using namespace std;
string longestPalindrome(string s) {
    if (s.size() <= 0){
        return "";
    }
    int array[s.size()][s.size()]; //存放从i到j子串的最长回文串
    int max_len = 0;
    int max_pos = 0;
    int max_s = 0;
    int max_e = 0;
    // DP
    for(int i = s.size()-1 ; i >= 0; --i){
        for(int j = i; j < s.size() ; ++j){
            if(i == j){
                array[i][j] = 1;
            }
            else if(j == i + 1 && s[j] == s[i]){
                array[i][j] = 2;
            }
            else if(j-i>1 && array[i+1][j-1] > 0 && s[j] == s[i]){
                array[i][j] = array[i+1][j-1] + 2;
            }else {
                array[i][j] = 0;
            }
            if(array[i][j] > max_len){
                max_s = i;
                max_e = j;
                max_len = array[i][j];
            }
        }
    }
    return s.substr(max_s, max_e-max_s+1);
}

int main(int argc, const char * argv[]) {
    std::cout<<longestPalindrome("babad")<<std::endl;
    
    std::cout<<longestPalindrome("cbbd")<<std::endl;
    
    std::cout<<longestPalindrome("abba")<<std::endl;
    
}
