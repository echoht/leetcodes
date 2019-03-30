//
//  LetterCombinationsOfAPhoneNum.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/3/27.
//  Copyright © 2019 hust. All rights reserved.
//  Letter Combinations of a Phone Number


#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if (digits.size() <= 0){
        return res;
    }
    //第0个位置
    int last_end_idx = 0;
    int idx = digits[0] - '0' - 2;
    for(int j = 0; j < dict[idx].size(); ++j){
        res.push_back(dict[idx].substr(j,1));
    }
    
    for(int i = 1; i < digits.size(); ++i){
        idx = digits[i] - '0' - 2;
        int cur_res_end_idx = res.size()-1;
        for(int k = last_end_idx; k <= cur_res_end_idx; ++k){
            string sub = res[k];
            for(int j = 0; j < dict[idx].size(); ++j){
                string sub = res[k];
                sub+=dict[idx].substr(j,1);
                res.push_back(sub);
            }
        }
        last_end_idx = cur_res_end_idx+1;
    }
    vector<string> result(res.begin()+last_end_idx, res.end());
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> res = letterCombinations("23");
    for(auto r: res){
        std::cout<<r<<std::endl;
    }
}
