#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include"tree.h"
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if()
        int N = data.size();
        ListNode* cur = new ListNode();
        ListNode* temp =cur;
        for(int i = 0; i < N/2 ; i++){
            cur ->next = data[i];
            cur = cur ->next;
            cur ->next = data[N-1-i];
            cur = cur ->next;
        }
        if(N % 2 == 0){ // 偶数
            cur ->next = nullptr;
        }else{
            cur ->next = data[(N-1)/2];
            cur ->next ->next = nullptr;
        }
        head = temp ->next;
        return;

    }
private:
    vector<ListNode*>data;
    void trar(ListNode* root)
    {
        ListNode* cur = root;
        while(cur != nullptr){
            data.push_back(cur);
            cur = cur ->next;
        }

    }
};