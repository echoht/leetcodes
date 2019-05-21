#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
 ListNode* rotateRight(ListNode* head, int k) {
    if(k <= 0 || head == NULL){
		return head;
	}    
	
	int n = 1; // total list sz 
	ListNode *tmp = head;
	while(tmp->next != NULL){
		n++;
		tmp = tmp->next;
	}
	k = k % n;
	//tmp is the last one 
	tmp->next = head; // a circle 
	int stp = n-k;
	while(step>0){
		tmp = tmp->next;
		step--;
	}
	head = tmp->next;
	tmp->next = NULL;
	return head;
	
}
