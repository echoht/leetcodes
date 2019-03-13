//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/10.
//  Copyright © 2019年 hust. All rights reserved.
//  AddTwoNumbers
#include <iostream>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s){
    map<char, int> char_latest_position;
    int max_len = 0;
    
    int last_repeated_pos = -1;
    for(int i = 0; i < s.size(); i ++){
        char curr = s.at(i);
        if(char_latest_position.find(curr) != char_latest_position.end() &&
           char_latest_position[curr] > last_repeated_pos){
            last_repeated_pos = char_latest_position[curr];
        }
        std::cout<<curr << " last pos:" << last_repeated_pos << std::endl;
        if(i - last_repeated_pos > max_len){
            max_len = i - last_repeated_pos;
        }
        char_latest_position[curr] = i;
    }
    return max_len;
}

int main(int argc, const char * argv[]) {
    std::cout<<lengthOfLongestSubstring("abcabcbb")<<std::endl;
    
    std::cout<<lengthOfLongestSubstring("bbbbb")<<std::endl;
    
    std::cout<<lengthOfLongestSubstring("abba")<<std::endl;
    
}
