#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include"tree.h"
using namespace std;


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        get_data(head);
        sort(data.begin(),data.end());
        ListNode* cur = head;
        int i = 0;
        while (cur != nullptr)
        {
            cur ->val = data[i];
            cur = cur ->next;
            i++;
        }
        return head;
    }
private:
    vector<int> data;
    void get_data(ListNode* head)
    {
        ListNode* cur = head;
        while (cur != nullptr)
        {
            data.push_back(cur->val);
            cur = cur ->next;
        }
        
    }
};

int main()
{

}