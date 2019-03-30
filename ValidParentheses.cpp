//
//  ValidParentheses.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/3/30.
//  Copyright © 2019 DE. All rights reserved.
//
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool isValid(string s){
    vector<char> stack;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(' || s[i] == '{' || s[i]== '['){
            stack.push_back(s[i]);
        }
        else{
            if(s[i] == ')'){
                if(stack.size() > 0 && stack[stack.size()-1] == '('){
                    stack.pop_back();
                }else{
                    return false;
                }
            }
            if(s[i] == '}'){
                if(stack.size() > 0 && stack[stack.size()-1] == '{'){
                    stack.pop_back();
                }else{
                    return false;
                }
            }
            if(s[i] == ']'){
                if(stack.size() > 0 && stack[stack.size()-1] == '['){
                    stack.pop_back();
                }else{
                    return false;
                }
            }
        }
    }
    if (stack.size()>0){
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::cout<<isValid("()")<<std::endl;
    std::cout<<isValid("()[]{}")<<std::endl;
    std::cout<<isValid("(]")<<std::endl;
    std::cout<<isValid("([)]")<<std::endl;
    
}
