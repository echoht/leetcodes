//
//  strStr_28.cpp
//  LeetcodeByEcho
//
//  Created by Dylan326 on 2019/4/7.
//  Copyright © 2019 DE. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
//O(n*m)
int strStr(string haystack, string needle) {
    //base situation
    if(needle.size() <= 0){
        return 0;
    }
    if(haystack.size() < needle.size()){
        return -1;
    }
    for(int i = 0; i <= haystack.size()-needle.size(); ++i){
        int fast = i;
        for(int j = 0; j < needle.size(); ++j){
            if(fast >= haystack.size() || haystack[fast] != needle[j]){
                break;
            }
            fast++;
        }
        //matched
        if(fast - i == needle.size()){
            return i;
        }
        
    }
    return -1;
}

// KMP
int* nextImp(string needle){
    int *next = new int[needle.size()];
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < needle.size()-1){
        if(k == -1 || needle[j] == needle[k]){
            next[++j] = ++k;
        }else{
            k = next[k];
        }
    }
    return next;
}
int strStr2(string haystack, string needle) {
    //base situation
    if(needle.size() <= 0){
        return 0;
    }
    if(haystack.size() < needle.size()){
        return -1;
    }
    int * next = nextImp(needle);
    int j = 0;
    int i = 0;
    int lenp = needle.size();
    int lenS = haystack.size();
    while(j<lenp&& i < lenS){
        if(j == -1 || needle[j] == haystack[i]){
            ++j;
            ++i;
            if(j == needle.size()){
                return i-j;
            }
        }else{
            j = next[j];
        }
        
    }
    return -1;
}



int main(int argc, const char * argv[]) {
    int a[] = {0,1,2,2,3,0,4,2};
    vector<int> A(&a[0], &a[8]);
    int * n = nextImp("issi");
    for(int i = 0; i < 4; i++){
        std::cout<<n[i]<<" ";
    }
    std::cout<<endl;
    std::cout<<strStr2("mississippi","issi");
}
