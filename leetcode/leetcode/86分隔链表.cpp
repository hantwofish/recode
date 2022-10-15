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
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        // 构造两个链表
        ListNode* small_list = new ListNode(INT32_MAX,nullptr);
        ListNode* large_list = new ListNode(INT32_MAX,nullptr);
        ListNode* sma_end = small_list;
        ListNode* lar_end = large_list;
        ListNode* temp = nullptr;
        while(cur != nullptr){
            temp = new ListNode(cur->val);
            if(cur->val < x){
                sma_end ->next = temp;
                sma_end = sma_end->next;
            }else if(cur ->val >= x){
                lar_end ->next = temp;
                lar_end = lar_end ->next;
            }
            cur = cur ->next;
        }
        // 合并
        small_list ->next = large_list ->next;
        return small_list->next;
    }
};