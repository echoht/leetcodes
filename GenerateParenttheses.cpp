//
//  GenerateParenttheses.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/4/1.
//  Copyright © 2019 DE. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

void genParImp(string cur, int left, int right, vector<string> &res){
    
    if(left == right && left ==0){
        res.push_back(cur);
        return;
    }
    if(left > 0){
        genParImp(cur + "(", left-1, right, res);
    }
    if(right > left){
        genParImp(cur+")", left, right -1, res);
    }
    return ;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    genParImp("", n, n, res);
    for (auto r : res){
        std::cout<<r<<std::endl;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    generateParenthesis(4);
}
