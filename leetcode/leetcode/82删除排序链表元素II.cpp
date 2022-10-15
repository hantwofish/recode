#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(head == nullptr){
           return head;
       }
       ListNode* dump = new ListNode(0);
       dump ->next = head;
       ListNode* cur = dump;
       while(cur -> next && cur->next->next){
           if(cur->next->val == cur->next->next->val){
               int cur_equ_val = cur->next->val;
               while(cur ->next && cur ->next ->val == cur_equ_val){
                   cur ->next = cur->next->next;
               }

           }else{
               cur = cur->next;
           }
       }
       return dump->next;


    }
};