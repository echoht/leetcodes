//
//  RemoveElement_27.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/4/6.
//  Copyright © 2019 DE. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
//first sort and then remove the target val,nlog(n)
int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(), nums.end());
    if(nums.size() <=0){
        return 0;
    }
    int idx1=0, idx2=-1;
    //int i = 0;
    //find the first val index
    while(idx1<nums.size() && nums[idx1] != val){
        idx1++;
    }
    if(idx1>= nums.size()){
        return nums.size();
    }
    idx2 = idx1+1;
    //find the first v that != val, and after val
    while(idx2<nums.size() && nums[idx2] == val){
        idx2++;
    }
    // put v and left values forward
    for(idx2; idx2<nums.size(); idx2++){
        nums[idx1++] = nums[idx2];
    }
    return nums.size() - (idx2-idx1);
}
//swap O(n)
int removeElement2(vector<int>& nums, int val) {
    int times = 0;
    int lastIndex = nums.size()-1;
    for(int i = 0; i < nums.size(); i++){
        //no need to check again
        if(i >= nums.size() - times){
            break;
        }
        if(nums[i] == val){
            //swap with the last not val
            while(lastIndex>=0 && nums[lastIndex] == val){
                lastIndex--;
                times++;
            }
            if(lastIndex > i){
                nums[i] = nums[lastIndex--];
                times++;
            }
        }
    }
    return nums.size()-times;
}
int main(int argc, const char * argv[]) {
    int a[] = {0,1,2,2,3,0,4,2};
    vector<int> A(&a[0], &a[8]);
    std::cout<<removeElement2(A, 2);
}
