//
//  SumOfTwoLinkers.cpp
//  LeetcodeByEcho
//
//  Created by Echo on 2019/3/10.
//  Copyright © 2019年 hust. All rights reserved.
//  AddTwoNumbers
#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = NULL;
    ListNode* tmp = NULL;
    ListNode* l1tmp = l1;
    ListNode* l2tmp = l2;
    int last = 0;
    while(true){
        int sum = last;
        // out condition
        if(l1tmp == NULL && l2tmp == NULL && sum == 0){
            break;
        }
        
        if(l1tmp != NULL){
            sum += l1tmp->val;
            l1tmp = l1tmp->next;
        }
        if(l2tmp != NULL){
            sum += l2tmp->val;
            l2tmp = l2tmp->next;
        }
        // can use less time, compare with % and / operator
        int low = sum;
        last = 0;
        if(sum >= 10){
            low = sum - 10;
            last = 1;
        }
        if(tmp == NULL){
            tmp =new ListNode(low);
            result = tmp;
        }else{
            tmp->next = new ListNode(low);
            tmp = tmp->next;
        }
    }
    return result;
}
ListNode* linkConstruct( int* array, int arr_sz){
    ListNode * l = NULL;
    ListNode * tmp = NULL;
    for(int i = 0 ; i < arr_sz; ++ i){
        if(tmp == NULL){
            tmp = new ListNode(array[i]);
            l = tmp;
        }else{
            tmp->next = new ListNode(array[i]);
            tmp = tmp->next;
        }
    }
    return l;
}
void printLink(ListNode *l){
    while(l!=NULL){
        std::cout << l->val << " ";
        l = l->next;
    }
    std::cout<<std::endl;
}
int main(int argc, const char * argv[]) {
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    int a[1] = {0};
    int b[1] = {0};
    l1 = linkConstruct( a, 1);
    printLink(l1);
    l2 = linkConstruct( b, 1);
    printLink(l2);
    ListNode* res = addTwoNumbers(l1, l2);
    printLink(res);
}
