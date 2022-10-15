#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        traver(root);
        TreeNode* cur = root;
        for(int i = 1; i< data.size(); i++){
            cur ->left = nullptr;
            cur ->right = data[i];
            cur = cur ->right;
        }

    }
    void traver(TreeNode* root)
    {
        if(root == nullptr){
            return;
        }
        data.push_back(root);
        if(root ->left){
            traver(root->left);
        }
        if(root ->right){
            traver(root->right);
        }

    }
private:
    vector<TreeNode*> data;
};

int main()
{

}
