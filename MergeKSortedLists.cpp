//
//  MergeKSortedLists.cpp
//  LeetcodeByEcho
//
//  Created by echo on 2019/4/2.
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
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge2Lists(ListNode* l1, ListNode *l2){
    ListNode* res = NULL, *tmp;
    if(l1==NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    while(l1!= NULL && l2 != NULL){
        if(l1->val <= l2->val){
            if(res == NULL){
                res = l1;
                tmp = res;
                l1 = l1->next;
            }else{
                tmp->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            }
        }else{
            if(res == NULL){
                res = l2;
                tmp = res;
                l2 = l2->next;
            }else{
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
    }
    if(l1 != NULL){
        tmp->next = l1;
    }
    if(l2 != NULL){
        tmp->next = l2;
    }
    return res;
}

vector<ListNode*> mergeKListsImp(vector<ListNode*>& lists) {
    vector<ListNode*> res;
    if(lists.size() == 1){
        res.push_back(lists[0]);
        return res;
    }
    for(int i = 0; i < lists.size(); i+=2){
        if(i+1 >= lists.size()){
            res.push_back(lists[i]);
        }else{
            ListNode* tmp = merge2Lists(lists[i], lists[i+1]);
            res.push_back(tmp);
        }
    }
    return mergeKListsImp(res);
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() <= 0){
        return NULL;
    }
    vector<ListNode *> res = mergeKListsImp(lists);
    return res[0];
}

ListNode * construct(int a[], int len){
    ListNode * res=NULL, *t ;
    for(int i = 0; i < len; i++){
        ListNode *tmp = new ListNode(a[i]);
        if (res == NULL){
            res = tmp;
            t = res;
        }
        t->next = tmp;
        t = t->next;
    }
    return res;
}
void  print(ListNode * res){
    while(res != NULL){
        std::cout<<res->val << ",";
        res = res->next;
    }
    std::cout<<std::endl;
    
}
int main(int argc, const char * argv[]) {
    vector<ListNode *> lists;
    int a[] = {1,4,5};
    ListNode * tmp = construct(a, 3);
    lists.push_back(tmp);
    print(tmp);
    print(tmp);
    int b[] = {1,3, 4};
    lists.push_back(construct(b, 3));
    int c[] = {2,6};
    lists.push_back(construct(c, 2));
    mergeKLists(lists);
}
