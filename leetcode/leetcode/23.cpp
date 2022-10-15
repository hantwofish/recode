#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* creat_Node(int val)
{
    ListNode* cur = new ListNode;
    cur->val = val;
    cur ->next = nullptr;
    return cur;
}

ListNode* creat_List(vector<int>&nums)
{
    ListNode* head  = new ListNode;
    head -> val = nums[0];
    head -> next = nullptr;

    ListNode* cur = head;
    for(int i = 1; i < nums.size(); i++){
        cur ->next = creat_Node(nums[i]);
        cur = cur->next;
    }
    return head;
    
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return nullptr;
    }
};


int main()
{
    vector<int>nums = {1,2,3,4,5};
    ListNode* head = creat_List(nums);
    ListNode* cur = head;
    while(cur != nullptr){
        cout << cur ->val << " ";
        cur = cur ->next;
    }
    
    return 0;
}


