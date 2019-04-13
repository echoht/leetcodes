//
//  searchRange_34.cpp
//  LeetcodeByEcho
//
//  Created by Dylan326 on 2019/4/13.
//  Copyright © 2019 DE. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int binarySearch(vector<int>& nums, int target, int left, int right){
    if(left > right){
        return -1;
    }
    if(left == right){
        if(nums[left] == target){
            return left;
        }
        return -1;
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

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    if(nums.size()<=0){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    int target_idx = binarySearch(nums, target, 0, nums.size()-1);
    if(target_idx == -1){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    int i = target_idx-1;
    while(i>=0 && nums[i]==target){
        i--;
    }
    res.push_back(i+1);
    i = target_idx+1;
    while(i<nums.size() && nums[i] == target){
        i++;
    }
    res.push_back(i-1);
    return res;
}

