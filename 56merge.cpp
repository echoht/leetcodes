#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
	return a[0] < b[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if(invervals.size() <= 1){
			return intervals;
		}
		vector<vector<int> > res;
		
		sort(intervals.begin(), intervals.end(), cmp);
		for (int i = 0; i < intervals.size(); ){
			int start = intervals[i][0];
			int end = intervals[i][1];
			int j = i + 1;
			while(j < intervals.size()){
				if(intervals[j][0] <= end){
					if(intervals[j][1] > end){
						end = intervals[j][1] ;
					}
					j++;
				}else{
					break;
				}
			}
			vector<int> r;
			r.push_back(start);
			r.push_back(end);
			res.push_back(r);
			
			//update
			i = j;
		}
		return res;
    }
	
int main(){
    //TreeNode* root = new TreeNode(2);
    //vector<vector<int> > resstd::cout<<isSymmetrical(root);
	vector<vector<int> > num;
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	num.push_back(a);
	vector<int> b;
	b.push_back(2);
	b.push_back(6);
	num.push_back(b);
	vector<int> c;
	c.push_back(15);
	c.push_back(18);
	num.push_back(c);
	vector<int> d;
	d.push_back(8);
	d.push_back(10);
	num.push_back(d);
	vector<vector<int> > res= merge(num);
    for(int i = 0; i < res.size(); i++){
        for(int j =0; j < res[i].size(); j++){
            std::cout<<res[i][j]<<",";
        }
        std::cout<<std::endl;
	}
}
