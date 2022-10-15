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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head ->next == nullptr || k == 0){
            return head;
        }
        // 计算链表长度；
        int len = 0;
        ListNode* front = head;
        ListNode* right = nullptr ; //  与 left 相差 n+1 
        ListNode* end =nullptr;
        while(front != nullptr){
            len++;
            if(front ->next == nullptr){
                end = front;
            }
            front = front->next;
        }
        int move_times = k % len;
        if(move_times == 0 ){
            return head;
        }
        
        right = head;
        for(int i = 0 ; i < move_times +1  ; i++){
            right = right->next;
        }

        //
        ListNode* left = head;
        while(left != nullptr && right != nullptr){
            left = left ->next;
            right = right->next;
        }
        front = left ->next;
        end ->next = head;
        left ->next = nullptr;

        return front;
    }
};