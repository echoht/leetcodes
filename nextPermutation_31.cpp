#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if(nums.size() <= 1){
        return;
    }
    int last = nums[nums.size()-1];
    int flg = 0; // is find the pos 
    int target_pos = -1;
    //find  pos who is nolonger desc order
    for(int i = nums.size() - 2; i >=0 ; i--){
        if(nums[i] >= last){
            last = nums[i];
            continue;
        }
        //find the pos  
        target_pos = i;
        //find the larger element to swap with target_pos's element 
        //after swap, [target_pos+1, end] is still a desc order 
        for(int j = nums.size()-1; j > i; j--){
            if(nums[j] > nums[i]){
                //swap 
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                break;
            }
        }
        break;
    }
    //in place to swap 
    int left = target_pos+1;
    int right = nums.size()-1;
    while(left < right){
        int tmp = nums[right];
        nums[right] = nums[left];
        nums[left] = tmp;
        left++;
        right--;
    }
    return;
}

int main(){
    int aa[] = {1,2,3};
    vector<int> a(&aa[0], &aa[3]);

    for(int i = 0; i < a.size();  i++){
        std::cout<<a[i] << " ";
    }
    std::cout << std::endl;
    nextPermutation(a);
    for(int i = 0; i < a.size();  i++){
        std::cout<<a[i] << " ";
    }
    std::cout << std::endl;
}
