//
//  SearchInsertPosition_35.cpp
//  LeetcodeByEcho
//
//  Created by Dylan326 on 2019/4/14.
//  Copyright © 2019 DE. All rights reserved.
//



#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
// 利用二分查找 注意边界处理
int binarySearch(vector<int>& nums, int target, int left, int right){
    if(left > right){
        if(left>=0 && left < nums.size()){
            return left;
        }
        return right;
    }
    if(left == right){
        if(nums[left] == target){
            return left;
        }
        if(nums[left] < target){
            return left+1;
        }
        return left; // the insert position
    }
    int mid = left + (right-left)/2;
    if(target < nums[mid]){
        return binarySearch(nums, target, left, mid-1);
    }
    else if(target > nums[mid]){
        return binarySearch(nums, target, mid+1, right);
    }
    return mid;
}

int searchInsert(vector<int>& nums, int target) {
    
    return binarySearch(nums, target, 0, nums.size()-1);
}

int main(int argc, const char * argv[]) {
    int a[] = {1,3};
    vector<int> A(&a[0], &a[2]);
    
    std::cout<<searchInsert(A, 4);
}
