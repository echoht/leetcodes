#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;

string sort_str(string s){
	int cs[26] = {0};
	for(int i = 0; i < a.size(); i++){
		cs[a[i]-'a'] += 1;
	}
	stringstream res;
	for(int i = 0; i < 26; i++){
		res << cs[i]+'a';
	} 
	return res.str();
}

vector<vector<string> > anagrams(vector<string> a){
	map<string, vector<string> > hmap;
	for(int i = 0; i < a.size(); i++){
		//string tmp = sort_str(a[i]);
		string tmp = a[i];
		sort(tmp.begin(), tmp.end());
		if(hmap.find(tmp) == hmap.end()){
			vector<string> empty;
			hmap[tmp] = empty;
		}
		hmap[tmp].push_back(a[i]);
	}
	vector<vector<string> > res;
	for(auto vec : hmap){
		res.push_back(vec.second);
	}
	return res;
}
