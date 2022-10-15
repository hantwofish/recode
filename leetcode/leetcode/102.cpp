#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> qu;
        if(root != nullptr)       qu.push(root);
        vector<vector<int>> re;
        while(!qu.empty())
        {
            int lenth = qu.size();
            vector<int> temp;
            for(int i = 0 ; i< lenth ; i++)
            {
                TreeNode* da_fromt = qu.front();
                qu.pop();
                if( da_fromt->left    ) qu.push(da_fromt->left);
                if( da_fromt -> right ) qu.push(da_fromt -> right);
                temp.push_back(da_fromt -> val);
            }
            re.push_back(temp);
            temp.clear();
            
        }

        return re;
    }
};