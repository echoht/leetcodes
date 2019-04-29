#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;

//42 trapping rain water
int computeArea(vector<int>& height, int left, int mid, int right){
    if(height[mid]>= height[left] || height[mid] >= height[right]){
        return 0;
    }
    int res = 0;
    int minb = left;
    if(height[right] < height[left]){
        minb = right;
    }
    for(int i = left+1; i < right; i++){
        if(height[i] < height[minb]){
            res += height[minb] - height[i];
        }
    }
    return res;
} 
int trap(vector<int>& height) {
    if(height.size() < 3){
        return 0;
    }
    // first part: asc , so can't trap rain 
    int i = 1;
    int res = 0;

    while(i< height.size() && height[i] >= height[i-1]){
        i++;
    }
    for(i; i < height.size(); ){
        int left = i-1;
        while(i < height.size() && height[i] <= height[i-1]){
            i++;
        }
        int mid = i-1;
        while(i < height.size() && height[i] >= height[i-1]){
            i++;
        }
        int right = i-1;
        // find next higher height
        for(int j = right+1; j < height.size(); j++){
            if(height[right] >= height[left]){
                break;
            }
            if(height[j] > height[right]){
                right = j;
            }
        }
        res += computeArea(height, left, mid, right);
        i = right+1;
    } 
    return res;   
}

int main(){
    int a[] = {5,4,1,2};
    //int a[] = {0,1,0,2,1,0,1,3,2,1,2,1, 3,0};
    vector<int> aa(&a[0], &a[4]);
    std::cout<<trap(aa)<<std::endl;
}
