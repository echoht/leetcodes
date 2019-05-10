#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

//Example:

//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//Follow up:

//If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//DP
int maxSubArray(vector<int>& nums) {
    int res = 0;
    if(nums.size() <=0){
      return res;
    }
    int last = nums[0];
    res = last;
    for(int i = 1; i < nums.size(); i++ ){
        if(last > 0){
            last += nums[i];
        } else{
            last = nums[i];
        }
        if(last > res){
            res = last;
        }
    }
    return res;
}
int crossmaxl(vector<int>& nums, int left, int right, int mid){
    int sum = nums[mid];
    int i = mid-1;
    int tmp=0, lsum=0, rsum=0;
    
    while(i >= left){
        tmp += nums[i];
        if(tmp > lsum){
            lsum = tmp;
        }
        i--;
    }
    i = mid + 1;
    tmp = 0;
    while(i <= right){
        tmp += nums[i];
        if(tmp > rsum){
            rsum = tmp;
        }
        i++;
    }
    return sum + lsum + rsum;
}
int maxl(int a, int b, int c){
    int res = a > b ? a : b;
    return res > c ? res : c;
}
int subProblem(vector<int>& nums, int left, int right){
    if(left==right){
        return nums[left];
    }
    if(left > right){
        return -2147483648;
    }
    int mid = left + (right-left)/2;
    int leftmax = subProblem(nums, left, mid);
    int rightmax = subProblem(nums,mid+1, right);
    int crossmax = crossmaxl(nums, left, right, mid);
    return maxl(leftmax, rightmax, crossmax);
}
//divide and conquer
int maxSubArray2(vector<int>& nums){
    return subProblem(nums, 0, nums.size()-1);
}
int main(){
    int n = 4;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(&a[0], &a[9]);
    std::cout<<maxSubArray2(nums)<<std::endl;
}
