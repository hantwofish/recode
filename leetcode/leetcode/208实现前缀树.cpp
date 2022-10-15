#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TrieNode
{
    bool isEnd; // 该结点是否是一个串的结束
    TrieNode* next[26]; // 字母映射表
};


class Trie {
public:
    Trie() {

    }
    
    void insert(string word) {

    }
    
    bool search(string word) {

    }
    
    bool startsWith(string prefix) {

    }
};