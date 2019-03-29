#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//echo by 20190329 
//the nums is the original vector, start used to point the start pos for 3sum 
//nums is already sorted
vector< vector<int> > ThreeSum(vector<int> &nums, int start, int target){
    vector< vector<int> > res;
    for(int i = start; i < nums.size(); ++i){
        if(i>start && nums[i] == nums[i-1]){
            continue;
        }
        int left = i+1;
        int right = nums.size() - 1;
        while(left < right){
        int sum_tmp = nums[i] + nums[left] + nums[right];
        if(sum_tmp == target){
            vector<int> tmp ;
            tmp.push_back(nums[i]);
            tmp.push_back(nums[left]);
            tmp.push_back(nums[right]);
            res.push_back(tmp);
            while(left+1 < nums.size() && nums[left+1] == nums[left]){
                left++;
            }
            left ++;
            while(right-1 >= 0 && nums[right-1] == nums[right]){
                right--;
            }
            right --;
        }else if(sum_tmp < target){
            while(left+1 < nums.size() && nums[left+1] == nums[left]){
                left++;
            }
            left++;
        }else{
            while(right-1 >= 0 && nums[right-1] == nums[right]){
                right--;
            }
            right--;
        }
        }
    }
    std::cout<<res.size()<<std::endl;
    return res;
}
vector< vector<int> > fourSum(vector<int> nums, int target){
    vector< vector<int> > res ;
    if(nums.size() < 4){
        return res;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-3; ++i){
        if(i>0 && nums[i-1] == nums[i]){
            continue;
        }
        vector< vector<int> > sub_res = ThreeSum(nums, i+1, target-nums[i]);
        for(int j = 0; j < sub_res.size(); ++j){
            vector<int> r = sub_res[j];
            r.push_back(nums[i]);
            res.push_back(r);
        }
    }
    return res;
}

int main(){
    int a[]= {5,0,2,-5,-5,4,-5,1,-1};
    vector<int> nums(a, a+9);
    vector< vector<int> >res = fourSum(nums, -5);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); ++j){
            std::cout<<res[i][j] << ",";
        }
        std::cout<<std::endl;
    }
}
