#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
	return a[0] < b[0];
}
	//NEW INTERVAL 
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
		int start = -1; 
		int end = -1;
		int new_start = 0;
		
		for(int i =0; i < intervals.size(); i++){
			if(start == -1 ){ // still not find a approprate pos for newInterval, so newInterval[0] is larger then before intervals'end
				
				if(newInterval[0] <= intervals[i][1]){  
					start = i;
					//case 1 not overlap with intervals[i]
					if(newInterval[1] < intervals[i][0]){
						res.push_back(newInterval);
						res.push_back(intervals[i]); //current interval 
					}else{ // case2 overlap with intervals[i] 
						new_start = newInterval[0] > intervals[i][0] ? intervals[i][0] : newInterval[0];
						if(newInterval[1] <= intervals[i][1]){
							end = i;
							intervals[i][0] = new_start;
							res.push_back(intervals[i]);
                            continue;
						}else{// end is not found;  
							;
						}
					}
				}
			}
			if(start != -1 && end == -1){ // start is found but not end 
				if(newInterval[1] <= intervals[i][1]) {
					end = i;
					if(newInterval[1] < intervals[i][0]) { // case 1 the end is not overlap with intervals[i]
						vector<int> r;
						r.push_back(new_start);
						r.push_back(newInterval[1]);
						res.push_back(r);
						res.push_back(intervals[i]); // current
					} else { // case 2 overlap
						intervals[i][0] = new_start;
						res.push_back(intervals[i]);	
					}
					continue;
				}
			}
			if(start == -1) { // not found start, so push the interval
				res.push_back(intervals[i]);
			}	
			if(start != -1 && end != -1){
				res.push_back(intervals[i]);
			}
		}
		if(start == -1 ){
			res.push_back(newInterval);
		}
        if(start != -1 && end == -1){ // start is found but not end 
        {
            newInterval[0]= new_start;
			res.push_back(newInterval);
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
	vector<int> d;
	d.push_back(8);
	d.push_back(10);
	num.push_back(d);
	vector<int> c;
	c.push_back(15);
	c.push_back(18);
	num.push_back(c);
	vector<int> dd;
	dd.push_back(0);
	dd.push_back(2);
   
	vector<vector<int> > res= insert(num, dd);
    for(int i = 0; i < res.size(); i++){
        for(int j =0; j < res[i].size(); j++){
            std::cout<<res[i][j]<<",";
        }
        std::cout<<std::endl;
	}
}
