#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"tree.h"

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        ListNode* cur = head;
        ListNode* m_next = head ->next;
        ListNode* start_1 =cur;
        ListNode* start_2 = cur ->next;
        while((cur != nullptr) && (m_next != nullptr)){
            if((cur ->next == nullptr)  || (cur ->next ->next == nullptr)){
                break;
            }

            cur ->next = cur ->next ->next;
            cur = cur ->next ->next;
            cout << "cur= " << cur->val << endl;
            if((m_next ->next == nullptr) || (m_next ->next -> next == nullptr)){
                break;
            }
            m_next ->next = m_next ->next ->next;
            m_next = m_next ->next ->next;
        }
        
        cur ->next = start_2;
        return head;

    }
};