#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

string nextSeq(string seq){
    int cnt = 1;
    char last = seq[0];
    stringstream next ;
    for(int i= 1; i < seq.size(); i++){
        if(seq[i] == seq[i-1]){
            cnt ++;
        }else{
            next << cnt << last ;
            cnt = 1;
            last = seq[i]; 
        }
    }
    if(cnt > 0){
        next << cnt << last ;
    }
    return next.str();
}

string countAndSay(int n) {
    string start = "1";  
    if(n <= 0){
        return "";
    }
    for(int i = 2; i <=n; i++){
        // generate next seq 
        start = nextSeq(start);
    }
    return start;
}

int main(){
    for(int i = 0; i < 10; i++){
        std::cout << countAndSay(i) << std::endl;
    }
}
