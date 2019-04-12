#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int searchImp(vector<int>& nums, int target, int left, int right){
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
    //mid in which position
    if( nums[mid] >= nums[left]) { //in first part
       if(target > nums[mid]){
           return searchImp(nums, target, mid+1, right);
       }else if (target < nums[mid]){
           if(target >= nums[left]){
               return searchImp(nums, target, left, mid-1);
           } 
           else{
               return searchImp(nums, target, mid+1, right);
           }
       }else{
           return mid;
       }
    }else{ //in second part 
        if(target < nums[mid]){
            return searchImp(nums, target, left, mid-1);
        }else if (target > nums[mid]){
            if(target <= nums[right]) {
                return searchImp(nums, target, mid+1, right);
            }else{
                return searchImp(nums, target, left, mid-1);
            }
        }else{
            return mid;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    if (nums.size() <= 0){
        return -1;
    }
    return searchImp(nums, target, 0, nums.size()-1);    
}

int main(){
    int aa[7] = {4,5,6,7,0,1,2};
    vector<int> a(&aa[0], &aa[7]);
    std::cout <<search(a, 3)<< std::endl;
}
