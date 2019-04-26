#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;

//参考了讨论区的思路
//主要思想是 缺少的最小正整数一定是在【1，nums.size()+1】范围内，所以只需要care这个范围内的数据即可
//然后利用索引下标与数组值的关系i=nums[i]-1, 获取最后结果
int firstMissingPositive(vector<int>& nums) {
    //first put nums[i] to pos nums[i]-1, if nums[i] >= 1 and nums[i] <= nums.size()
    for(int i = 0; i < nums.size(); ){
        if(nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]){
            int tmp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
            // add this judge can fast than 100%
            if(tmp <= 0 || tmp > nums.size()){
                i++;
            }
        } else {
            i++;
        }
    }

    //find the miss positive 
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == i+1){
            continue ;
        }
        return i+1;
    }
    return nums.size()+1;
}

int main(){
    int a[] = {1,2,3,4,5};
    vector<int> aa(&a[0], &a[5]);
    std::cout<<aa.size(); 
    std::cout<< firstMissingPositive(aa) << std::endl;
}
