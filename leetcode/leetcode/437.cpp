#include<stdio.h>
#include<stdlib.h>
#include<iostream>

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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return 0;
        }
        int res = rootSum(root, targetSum);
        res += pathSum(root->left,targetSum);
        res += pathSum(root->right, targetSum);
        
        return res;

    }
    // 以 root 为起点 ，满足  和为 target_sum 的路径数
    int rootSum(TreeNode* root, int target_Sum)
    {
        if(root == nullptr){
            return 0;
        }
        int num = 0;
        if(root->val == target_Sum){
            num++;
        }
        num += rootSum(root->left , target_Sum - root->val);
        num += rootSum(root->right , target_Sum - root->val);
        return num;
    }
    
   
private:
   
    
};

TreeNode* creat_node(int val)
{
    TreeNode* root = new TreeNode(val);
    return root;
}

int main()
{
    Solution s1;
    
    
    return 0;
}