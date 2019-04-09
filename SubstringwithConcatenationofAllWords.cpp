#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct WordApp{
    string word;
    int idx;
    bool operator<(const WordApp& rhs) const {
        return idx < rhs.idx;
    }
};
void getNext(string word, int* next){
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j<word.size()-1){
        if(k == -1 || word[j] == word[k]){
            next[++j] = ++k;
        }else{
            k = next[k];
        }
    }
    return;
}
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    //first find each words appear idx 
    vector<WordApp> allWordsApp;
    map<string, int> word_cnt;
    map<int, string> idx_word;
    int total_concate_len = 0;
    for(int i = 0; i < words.size(); ++i){
        string word = words[i];
        if(word_cnt.find(word) == word_cnt.end()){
            word_cnt[word] = 1;
            total_concate_len += word.size();
        }else{
            total_concate_len += word.size();
            word_cnt[word] += 1;
            continue;
        }

        //KMP here
        int* next = new int[word.size()];
        getNext(word, next);
        for(int k = 0; k < word.size(); k++){
            std::cout<<next[k] << " ";
        }
        std::cout<<std::endl;
        //match s and the word 
        int slen = s.size();
        int wordlen = word.size();
        int m =0, n =0;
        while(m<slen){
            if(n == -1 || s[m] == word[n]){
                m++;
                n++;
                if(n == word.size()){
                    WordApp t;
                    t.word = word;
                    t.idx = m-n;
                    allWordsApp.push_back(t);
                    idx_word[m-n] = word;

                    n = next[n-1]; //keep looking next appear idx
                    m--;
                    /*
                    if (n == -1){
                        n = 0;
                    }*/
                }
            }else{
                n = next[n];
            }
        }
    
        delete []next;
    }
    //sort and then check is a concate words str in the s
    sort(allWordsApp.begin(), allWordsApp.end());
    //print info 
    for(int i = 0; i < allWordsApp.size(); ++i){
        WordApp t = allWordsApp[i];
        std::cout<<t.word << " app in " << t.idx << ", idx word" << idx_word[t.idx] <<std::endl;
    }
    std::cout<<idx_word.size() << "idx_word size"<<std::endl; 
    //check is an OK idx 
    map<string, int> word_cnt_2;
    for(int i = 0; i < allWordsApp.size(); ++i){
        // check each idx 
        // put into word_cnt_2
        // is concate 
        word_cnt_2.clear();    
        int cnt = 0;
        int next_idx = allWordsApp[i].idx;
        if(next_idx + total_concate_len > s.size()){
            break;
        }
        while(cnt < words.size()){ //still not enough word 
            if(idx_word.find(next_idx) == idx_word.end()){
                break;
            }
            // keep the appear times
            if(word_cnt_2.find(idx_word[next_idx]) == word_cnt_2.end()){
                word_cnt_2[idx_word[next_idx]] = 0;
            }
            word_cnt_2[idx_word[next_idx]] += 1;
            if(word_cnt_2[idx_word[next_idx]] > word_cnt[idx_word[next_idx]]){
                break;
            }
            next_idx = next_idx += idx_word[next_idx].size();
            cnt += 1;
        }
        if(cnt == words.size()){
            res.push_back(allWordsApp[i].idx);
        }  
    }
    return res;
}

int main(){
    string s="aaa";
    vector<string> words;
    words.push_back("a");
    words.push_back("a");
    //words.push_back("best");
    //words.push_back("good");

    vector<int> a = findSubstring(s, words);
    for(int i = 0; i < a.size();  i++){
        std::cout<<a[i] << " ";
    }
    std::cout << std::endl;
}
