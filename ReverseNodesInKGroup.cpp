#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k <= 1 || head == NULL ){
        return head;
    }
    ListNode* newHead = NULL, *tmp, *t, *t1;
    vector<ListNode*> sk;
    t1 = head;
    int flg = 0;
    while(true){
        //push cur k node into vector
        int i = 0;
        sk.clear();
        while(i < k ){
            if (t1 != NULL){
                
                sk.push_back(t1);
                t1 = t1->next;
                i++;
            }else{
                break;
            }
        }
        if(i < k){
           if(sk.size() > 0){ //the left out nodes 
               if(newHead == NULL){
                  newHead = sk[0];
                  t = newHead;
               }else{
                   t->next = sk[0];
               }
               flg = 1;
           } 
           break; 
        }
        //reverse 
        for(i = k-1; i >= 0; --i ){
            if(newHead == NULL){
                newHead = sk[i];
                t = newHead;
            }else{
                t->next = sk[i];
                t = t->next;
            }
        }
    }
	//这个地方需要注意，很容易出现无限链表
    if(flg == 0) {
        t->next = NULL;
    }
    if(newHead == NULL){
        return head;
    }
    return newHead;    
}
ListNode* construct(int a[], int len ){
    ListNode* res = NULL, *tmp = NULL;
    for(int i = 0; i < len; ++i){
        ListNode* t = new ListNode(i);
        if(res == NULL){
            res = t;
            tmp = t;
        }else{
            tmp->next = t;
            tmp = tmp->next;
        }
    }
    return res;
}
void print(ListNode * a){
    while(a != NULL){
        std::cout<<a->val<< ",";
        a = a->next;
    }
    std::cout<<std::endl;
}
int main(){
    int a[] = {1,2};
    ListNode *head = construct(a, 2);
    print(head);
    ListNode * res=reverseKGroup(head, 2);
    print(res);
}
