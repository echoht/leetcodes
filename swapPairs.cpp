#include<iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* swapPairs(ListNode* head){
    //base situation
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* newHead = NULL, *tmp = NULL, *t1, *t, *nt=NULL;
    newHead = head->next;
    t = newHead;
    t1 = head; //t1 is a moving idx 
    while(true){
        tmp = t1->next->next;
        t->next = t1;
        t1->next = tmp;
        //nt = t1;  //keep the last node 
        if(nt != NULL){
            nt->next = t;
        }
        nt = t1;
        //idx moving to next swap pair
        t1 = t1->next;
        if(t1 == NULL || t1->next == NULL){
            break; //no need to swap 
        }
        t = t1->next;
    }
    return newHead;
}
int main(){}
