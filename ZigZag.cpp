//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/10.
//  Copyright © 2019年 hust. All rights reserved.
//  zigzag conversion
#include <iostream>
#include <map>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
    if (s.size() <= 0){
        return "";
    }
    //pay attention to this special case
    if(numRows == 1){
        return s;
    }
    vector<string> res;
    int x = 0, y = 0;
    size_t i = 1;
    int j = 0;
    for(j = 0; j < numRows; j++ ){
        res.push_back("");
    }
    res[0] += s[0];
    while(i < s.size()){
        j = 0;
        //godown
        while(i<s.size() && j < numRows -1){
            y += 1;
            //std::cout<<"("<<y<<","<<x<<")"<<std::endl;
            res[y] += s[i];
            i++;
            j++;
        }
        j = 0;
        //go right-up
        while(i<s.size() && j < numRows -1){
            y -= 1;
            x += 1;
            //std::cout<<"("<<y<<","<<x<<")"<<std::endl;
            res[y] += s[i];
            i++;
            j++;
        }
    }
    string result = res[0] ;
    for(i = 1; i < res.size(); ++ i){
        result += res[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout<<convert("AB", 1)<<std::endl;
    
    std::cout<<convert("cb", 3)<<std::endl;
    
    std::cout<<convert("PAYPALISHIRING", 4)<<std::endl;
    
}
