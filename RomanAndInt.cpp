//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/22.
//  Copyright © 2019年 hust. All rights reserved.
//  roman and integer

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int romanToInt(string s){
    int ret = 0;
    map<string, int> symbol2value = {
        {"M",1000}, {"CM",900}, {"D",500}, {"CD",400}, {"C",100},
        {"XC",90}, {"L",50}, {"XL",40}, {"X",10}, {"IX",9}, {"V",5}, {"IV",4}, {"I",1},
    };
    int i = 0;
    while(i < s.size()){
        if(i < s.size()-1 && (
                              (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M') )
                              || (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C') )
                              || (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X') ) )
           ){
            string sub = s.substr(i, 2);
            ret += symbol2value[sub];
            i += 2;
        }else{
            ret += symbol2value[s.substr(i,1)];
            i += 1;
        }
    }
    return ret;
}
int romanToInt2(string s){
    int ret = 0;
    int i = 0;
    while(i < s.size()){
        //string sub = s.substr(i, 2);
        switch (s[i]) {
            case 'M':
                ret += 1000;
                break;
            case 'D':
                ret += 500;
                break;
            case 'C':
                if(i<s.size()-1){
                    switch (s[i+1]) {
                        case 'D':
                            ret += 400;
                            i++;
                            break;
                        case 'M':
                            i++;
                            ret += 900;
                            break;
                        default:
                            ret += 100;
                            break;
                    }
                }else{
                    ret += 100;
                }
                break;
            case 'L':
                ret += 50;
                break;
            case 'X':
                if(i<s.size()-1){
                    switch (s[i+1]) {
                        case 'L':
                            i++;
                            ret += 40;
                            break;
                        case 'C':
                            i++;
                            ret += 90;
                            break;
                        default:
                            ret += 10;
                            break;
                    }
                }else{
                    ret += 10;
                }
                break;
            case 'V':
                ret += 5;
                break;
            case 'I':
                if(i<s.size()-1){
                    switch (s[i+1]) {
                        case 'V':
                            i++;
                            ret += 4;
                            break;
                        case 'X':
                            i++;
                            ret += 9;
                            break;
                        default:
                            ret += 1;
                            break;
                    }
                }else{
                    ret += 1;
                }
                break;
            default:
                break;
        }
        i++;
    }
    return ret;
}

string intToRoman(int num) {
    string symbols[] = {"M", "CM" , "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ret="";
    for (int i = 0; num > 0; i++) {
        while(num >= values[i]){
            ret += symbols[i];
            num -= values[i];
            //std::cout<<num<<std::endl;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    std::cout<<romanToInt2("MCMXCIV") <<std::endl;
    std::cout<<romanToInt2("III") <<std::endl;
    std::cout<<romanToInt2("IV") <<std::endl;
    std::cout<<romanToInt2("IX") <<std::endl;
    
}
