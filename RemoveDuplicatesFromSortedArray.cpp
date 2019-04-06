//
//  RemoveDuplicatesFromSortedArray.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/4/5.
//  Copyright © 2019 DE. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 0){
        return 0;
    }
    
    int idx1=0, idx2=1;
    while(idx2 < nums.size()){
        // 将idx2往后移动，直到遇到与idx1指向的val不同的地方
        while(idx2 < nums.size() && nums[idx2] == nums[idx1]){
            idx2++;
        }
        // 要么找到了一个新的不同值，要么就是遍历结束
        if(idx2 >= nums.size()){
            return idx1+1;
        }
        nums[++idx1] = nums[idx2++];
    }
    return idx1+1;
}

int main(int argc, const char * argv[]) {
    
}
