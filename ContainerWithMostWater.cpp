//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/22.
//  Copyright © 2019年 hust. All rights reserved.
//  container with most water

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int area = 0;
    while(left < right){
        int short_height;
        int short_index;
        if (height[left] < height[right]){
            short_height = height[left];
            short_index = left;
        }else{
            short_height = height[right];
            short_index = right;
        }
        int area_tmp = short_height*(right-left);
        if(area_tmp > area){
            area = area_tmp;
        }
        //这里移动时，用较短的那个line去移动，才有可能获得更大的面积
        if(short_index < right){
            left++;
            while(left < right && height[left] < height[short_index]){
                left++;
            }
        }else{
            right--;
            while(right > left && height[right] < height[short_index]){
                right--;
            }
        }
    }
    return area;
}
