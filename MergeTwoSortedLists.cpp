//
//  MergeTwoSortedLists.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/3/30.
//  Copyright © 2019 DE. All rights reserved.
//
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //边界条件
    if(l1==NULL ){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    ListNode *tmp1=l1, *tmp2=l2;
    ListNode *head, *tmp;
    if(tmp1->val <= tmp2->val){
        head = tmp1;
        tmp1 = tmp1->next;
    }else{
        head = tmp2;
        tmp2 = tmp2->next;
    }
    tmp = head;
    while(true){
        if(tmp1 == NULL){
            tmp->next = tmp2;
            break;
        }
        if(tmp2 == NULL){
            tmp->next = tmp1;
            break;
        }
        if(tmp1->val <= tmp2->val){
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        }else{
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return head;
}
