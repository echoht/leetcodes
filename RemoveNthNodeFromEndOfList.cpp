//
//  RemoveNthNodeFromEndOfList.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/3/27.
//  Copyright © 2019 hust. All rights reserved.


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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *idx1 = head;
    ListNode *root = new ListNode(-1);
    root->next = head;
    ListNode *idx2=root;
    //第一个指针先移动N步
    for(int i = 0;i < n; ++i){
        idx1 = idx1->next;
    }
    while(true){
        if(idx1 == NULL){
            idx2->next = idx2->next->next;
            break;
        }
        idx1 = idx1->next;
        idx2 = idx2->next;
    }
    return root->next;
}
int main(int argc, const char * argv[]) {
    
}
