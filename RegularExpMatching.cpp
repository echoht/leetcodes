//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/18.
//  Copyright © 2019年 hust. All rights reserved.
//  regular expression matching

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool isMatch(string s, string p){
    if(p.size() <= 0 && s.size()> 0){
        return false;
    }
    //存放上一个子pat可以匹配到的位置
    set<int> last_matched_idx;
    last_matched_idx.insert(-1);
    //存放当前子pat可以匹配到的位置
    set<int> cur_matched_idx;
    string cur_pat;
    int i=0, j = 0;
    int type = 0;
    while(j < p.size()){
        cur_pat = p[j];
        type = 0;
        j++;
        while(j < p.size() && p[j] == '*'){
            cur_pat += p[j];
            j++;
            type = 2;
        }
        //std::cout<<cur_pat << "\t"<<type<<std::endl;
        cur_matched_idx.clear();
        for(auto last_idx : last_matched_idx){
            if(type == 0){
                if(cur_pat[0] != '.'){
                    if(last_idx+1 < s.size() && s[last_idx+1] == cur_pat[0]){
                        cur_matched_idx.insert(last_idx+1);
                    }
                }else{
                    if(last_idx+1 < s.size()){
                        cur_matched_idx.insert(last_idx+1);
                    }
                }
            }
            if(type == 2){
                if(cur_pat[0] != '.'){
                    cur_matched_idx.insert(last_idx);
                    int n = 1;
                    while(last_idx+n < s.size() && s[last_idx+n] == cur_pat[0]){
                        cur_matched_idx.insert(last_idx+n);
                        n++;
                    }
                }else{
                    cur_matched_idx.insert(last_idx);
                    int n = 1;
                    while(last_idx+n < s.size()){
                        cur_matched_idx.insert(last_idx+n);
                        n++;
                    }
                }
            }
        }
        if(cur_matched_idx.size()<=0){
            return false;
        }
        //std::cout<<"echo:"<<cur_matched_idx.size() << "\t"<<last_matched_idx.size()<<"\t"<<j<<std::endl;
        last_matched_idx = cur_matched_idx;
        cur_matched_idx.clear();
        
    }
    if(last_matched_idx.find(s.size()-1) != last_matched_idx.end()){
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    //std::cout<<isMatch("aa", "a") <<std::endl;
    std::cout<<isMatch("aa", "a*")<<std::endl;
    std::cout<<isMatch("ab", ".*") <<std::endl;
    std::cout<<isMatch("aab", "c*a*b")<<std::endl;
    
    std::cout<<isMatch("mississippi", "mis*is*p*.")<<std::endl;
    //std::cout<<myAtoi("   -42")<<std::endl;
    //std::cout<<myAtoi("4193 with words")<<std::endl;
    //std::cout<<myAtoi("words and 987")<<std::endl;
}
