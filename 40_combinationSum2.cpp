#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;

//vector<vector<int> > csimp(vector<int>& candidates, map<int, int> &appear_cnt, int target, int idx){
// 正真的dfs
void csimp(vector<int>& candidates, int target, int idx, vector<int> &path, vector<vector<int> > &res){
    if(target == 0) {
        res.push_back(path);
        return;
    }
    if(target < 0) {
        return;
    }
    {    
        for(int i = idx; i < candidates.size(); i++)
        {
			//注意这里可以去重
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            csimp(candidates, target-candidates[i], i+1, path, res);
            path.pop_back();
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    int flg = 0;
    sort(candidates.begin(), candidates.end());
    vector< vector<int> > res;
    vector<int>  tmp;
    csimp(candidates, target, flg, tmp , res);
    return res;
}

int main(){
    int a[] = {10,1,2,7,6,1,5};
    vector<int> aa(&a[0], &a[7]);
    
        for(int j =0 ; j < aa.size(); j++){
            std::cout<<aa[j] << ",";
        }
        std::cout<<std::endl;
    vector<vector<int> > r = combinationSum(aa, 8);
    for(int i = 0;i <r.size(); i++){
        for(int j =0 ; j < r[i].size(); j++){
            std::cout<<r[i][j] << ",";
        }
        std::cout<<std::endl;
    }
}
