#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"tree.h"

using namespace std;

class Solution {
public:
     TreeNode * result;
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        result = NULL;
        back( root ,val );
        return result;
       

    }
    void back(TreeNode* root, int val) 
    {
        if(root == NULL) return ;
        if(root -> val == val)
        {
            result = root;
            return ;
        }
        back(root -> left , val);
        back(root -> right ,val);
    }
};