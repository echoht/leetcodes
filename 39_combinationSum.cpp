#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


using namespace std;

vector<vector<int> > csimp(vector<int>& candidates, int target, int idx){
    vector<vector<int> > result;
    if(target == 0) {
        vector<int> tmp;
        result.push_back(tmp);
        return result;
    }
    if(target < candidates[0]){
        return result;
    }
    if(idx >= candidates.size()){
        return result;
    }

    //for(int i = idx; i < candidates.size(); i++){
    {    
        int cur = candidates[idx];
        int max_appear_cnt = target/cur;
        for(int j = 0; j <= max_appear_cnt; j++){
            vector<vector<int > > res = csimp(candidates, target-j*cur, idx+1);
            for(int n = 0; n < res.size(); n++){
                for(int k = 0; k < j ; k++){
                    res[n].push_back(cur);
                }
                result.push_back(res[n]);
            }
        }
    }
    return result;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    // first sort by asc
    sort(candidates.begin(), candidates.end());
    int flg = 0;
    vector<vector<int> > res = csimp(candidates, target, flg);
    return res;
}

int main(){
    int a[] = {2,3,6,7};
    vector<int> aa(&a[0], &a[4]);

    vector<vector<int> > r= combinationSum(aa, 7);
    for(int i = 0;i <r.size(); i++){
        for(int j =0 ; j < r[i].size(); j++){
            std::cout<<r[i][j] << ",";
        }
        std::cout<<std::endl;
    }
}
