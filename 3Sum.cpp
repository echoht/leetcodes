//
//  main.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/9.
//  Copyright © 2019年 hust. All rights reserved.
//  三数和为0

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector< vector<int> > ThreeNumSum(vector<int> array){
    vector< vector<int> > result;
    if(array.size() < 3){
        return result;
    }
    sort(array.begin(), array.end());
    for (int i = 0; i< array.size()-2; ++i){
        //去重
        if(i > 0 && array[i] == array[i-1]){
            continue;
        }
        int low = i+1;
        int high = array.size()-1;
        while(low < high){
            if(array[i] + array[low] + array[high] == 0){
                result.push_back({array[i], array[low], array[high]});
                low ++;
                high --;
                while(low < array.size()-1 && array[low] == array[low-1]){
                    low ++ ;
                }
                while(high > 0 && array[high] == array[high+1]){
                    high--;
                }
            }else if(array[i] + array[low] + array[high] > 0){
                high --;
                while(high > low && array[high] == array[high+1]){
                    high --;
                }
            }else{
                low ++;
                while(low < high && array[low] == array[low-1]){
                    low ++;
                }
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    auto res = ThreeNumSum({-2,0,1,1,2});
    for(vector<int> r : res){
        for(int e: r){
            std::cout<< e << " ";
        }
        std::cout<< endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
