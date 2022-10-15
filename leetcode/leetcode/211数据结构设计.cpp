#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class TrieNode{
public:
    vector<TrieNode*>child;
    bool isWord;
    TrieNode():child(26,nullptr),isWord(false){};
    ~TrieNode(){
        for(auto c: child){
            delete c;
        }
    }

};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary(){
        delete root;
    }
    
    void addWord(string word) {
        TrieNode*p = root;
        for(char c : word){
            int i = c - 'a';
            if( ! p->child[i] ){
                p ->child[i] = new TrieNode();
            }
            p = p ->child[i];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
       
    }
private:
    TrieNode* root;

};

int main()
{
    WordDictionary* obj = new WordDictionary();
    obj->addWord("a");
    vector<string> data={".","a","aa","a",".a","a."};
    for(int i = 0 ; i < data.size(); i++){
        bool param_2 = obj->search(data[i]);
        if(param_2){
            cout << "True " ; 
        }else{
            cout << "False ";
        }
    }
    return 0;
}