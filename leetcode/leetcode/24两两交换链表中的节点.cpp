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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* output = head ->next;
        ListNode* left = head;
        ListNode* right = head ->next;
        while(left != nullptr && right != nullptr){
            ListNode* front = right -> next;
            if(front == nullptr){
                right ->next = left;
                left -> next = nullptr;
                left = front;
            }else if(front != nullptr && front->next == nullptr){
                right ->next = left;
                left -> next = front;
                left = front;
                right = front ->next;
            }
            else if(front != nullptr){
                right -> next = left;
                left ->next = front ->next;
                left = front;
                right = front ->next;

            }
        }
        return output;

    }
};