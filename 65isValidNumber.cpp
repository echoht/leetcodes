#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
	bool isInt(string s, int start, int end){
	
		if(s[start] == '+' || s[start] == '-'){
			start ++;
		}
		if(start > end){
			return false;
		}
		for(int i = start; i <= end; i++){
			if(s[i] < '0' || s[i] > '9'){
				return false;
			}
		}
		return true;
	}
	
	bool isNumber(string s) {
        //remove the space @start and @tail 
		int start = 0, end=s.size()-1;
		while(s[start] == ' '){
			start++;
		}
		while(s[end] == ' '){
			end--;
		}
		//only check [start, end]
		if(s[start] == '+' || s[start] == '-'){
			start++;
		}
		if(start > end){
			return false;
		}
		bool isDecimal = false;
        bool isDigitBefore = false;
		for(int i = start; i <= end; i++){
			if(i== start && (s[start] == '+' || s[start] == '-')){
				return false;
			}
			if(s[i] >= '0' && s[i] <= '9'){
                isDigitBefore = true;
				continue;
			}
			if(isDigitBefore && s[i] == 'e'){
				return isInt(s, i+1, end);
			}
			if(s[i] == '.' && isDecimal == false ){ //assume . can be the last one char and first one
				//has problem here !!! 
				isDecimal = true;
				continue;
			}
			return false;
		}
		if(isDecimal && isDigitBefore== false){
			return false;
		}
		return true;
    }
