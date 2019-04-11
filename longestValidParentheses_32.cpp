#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//DP alg
int longestValidParentheses(string s) {
    if(s.size() <= 1){
        return 0;
    }
    int res = 0;
    int* f = new int[s.size()]; //f[n] keep the sz of longestValidParentheses which end with s[n]
    f[0] = 0;
    for(int i = 1; i < s.size(); ++i){
        int last_idx = i-1-f[i-1];
        if(last_idx < 0 || s[i] == '('){
            f[i] = 0;
            continue ;
        } 
        if(s[last_idx] == '(' && s[i] == ')'){
            int before_l_idx = i-1-f[i-1]-1;
            if(before_l_idx < 0){
                f[i] = f[i-1] + 2;
            }else{
                f[i] = f[i-1] + 2 + f[before_l_idx];
            }
        }else{
            f[i] = 0;
        }
        if(f[i] > res) {
            res = f[i];
        }
    }
    return res;
}

int main(){
    std::cout <<longestValidParentheses(")()())") << std::endl;
}
