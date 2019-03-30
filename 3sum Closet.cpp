//
//  3sum Closet.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/27.
//  Copyright © 2019年 hust. All rights reserved.
//  3Sum Closest

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    int tmp = INT_MAX; //记录与taget的距离
    int ret=0;  //记录真实三数和
    int tmp1 = 0, tmp2 = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; i++){
        int left = i+1;
        int right = nums.size()-1;
        while(left < right){
            tmp1 = nums[i] + nums[left] + nums[right] - target;
            tmp2 = abs(tmp1);
            if (tmp2 < tmp){
                tmp = tmp2;
                ret = nums[i] + nums[left] + nums[right];
            }
            if(tmp1 < 0 ){
                //与当前的left位置上数字相同的话，计算出的加和相同，所以直接跳过
                while(left < nums.size()-1 && nums[left] == nums[left+1]){
                    left++;
                }
                left++;
            }else if(tmp1 == 0){
                return ret;
            }else{
                while(right > 0 && nums[right] == nums[right-1]){
                    right--;
                }
                right--;
            }
        }
    }
    return ret;
}
