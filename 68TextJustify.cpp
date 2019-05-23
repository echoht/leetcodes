#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start=-1, end=-1, word_sz=0; // current line's start word's idx, end word's idx, and total words_sz 
		int tmp = 0;
		vector<string> res;
		for(int i = 0; i < words.size(); i++){
			if(start == -1){
				start = i;
				end = i;
				word_sz = words[i].size();
				tmp = word_sz;
				continue;
			}
			if(tmp + 1 + words[i].size() <= maxWidth){ // still can pad 
				end = i;
				word_sz += words[i].size();
				tmp += 1 + words[i].size();
			}else{ // get a line 
				int restspacenum = maxWidth - word_sz;
				int evalspacenum = end-start == 0 ? restspacenum : restspacenum/(end-start);
				int addspacenum = end-start == 0 ? 0 : restspacenum%(end-start);
				int wordsnum = end-start+1;
				
				string s;
				for(int j = start; j <= end; j++){
					s += words[j];
					if(j == end && wordsnum > 1){ // left and right justified
						continue;
					}
					if(j-start < addspacenum){
						s+= " ";
					}
					for(int x = 0; x <evalspacenum; x++ ){
						s+=" ";
					}
				}
				res.push_back(s);
				// update state
				start = i;
				end = i;
				word_sz = words[i].size();
				tmp = word_sz;
			}
		}
		// the last one 
		string s;
		int restspacenum = maxWidth - word_sz;
		
		for(int j = start; j <= end; j++){
			s += words[j];
			if(restspacenum > 0){
                s+= " ";
                restspacenum--;
            }
		}
		for(int x = 0; x <restspacenum; x++ ){
			s+=" ";
		}
		res.push_back(s);
		return res;
    }
    
int main(){
    string ax[] = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    vector<string> a(&ax[0], &ax[17]);
    vector<string> tmp = fullJustify(a, 16);
    for(int i = 0; i < tmp.size(); i++){
        std::cout<<"\""<<tmp[i] << "\"\n";
    }
}
