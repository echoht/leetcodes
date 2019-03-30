//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/28.
//  Copyright © 2019年 hust. All rights reserved.
//  longestCommonPrefix

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() <= 0){
        return "";
    }
    if (strs.size()== 1){
        return strs[0];
    }
    string ret="";
    for(int i = 0; ; i++){
        char cur_char;
        if(i < strs[0].size() ){
            cur_char = strs[0][i];
        }else{
            return ret;
        }
        for(int j = 1; j < strs.size(); ++j){
            if (strs[j][i] != cur_char){
                return ret;
            }
        }
        ret += cur_char;
    }
    return ret;
}
