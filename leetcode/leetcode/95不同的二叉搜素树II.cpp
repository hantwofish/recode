#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;


 // Definition for a binary tree node.
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
    int numTrees(int n) {
      int resu =  generateTrees(1,n);
        return resu;
    }
    int generateTrees(int start, int end)
    {
        if(start > end){
            return 1;
        }
        int mid= 0;
        for(int i = start ; i <= end; i++){
            int left_Trees = generateTrees(start, i-1);
            int right_Tess = generateTrees(i+1, end);
            
            mid += left_Trees * right_Tess;
           
        }
        return mid;   
    }  
};