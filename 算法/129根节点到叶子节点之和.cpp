#include"STLCOMMON.h"
#include"TREE_LIST.h"

using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        resuOut.clear();
        resu.clear();
        // resu += to_string(root->val);
        // if(root->left != nullptr){
        //     BackTracing(root->left,resu);
        // }
        // if(root->right != nullptr){
        //     BackTracing(root->right,resu);
        // }
        BackTracing(root,resu);
        PrintVec();
        cout << "resultOut.size()= " << resuOut.size() << endl;
        // int number= CalVec();
        // cout << "number= " << number;
        return CalVec();
    }

    void BackTracing(TreeNode* curNode, string &curStr)
    {
        //cout << "BackTring:: start curStr= " << curStr << endl;
        // 为叶子节点
        if(curNode->left == nullptr && curNode->right == nullptr){
            curStr += to_string(curNode->val);
            resuOut.push_back(curStr);
            cout << "BackTring:: curStr= " << curStr << endl;
            return;
        }
        string temp = to_string(curNode->val);
        curStr += temp;
        if(curNode->left != nullptr){
            BackTracing(curNode->left,curStr);
            // 回溯
            curStr = curStr.substr(0,curStr.length()-temp.size());
        }
        if(curNode->right != nullptr){
            BackTracing(curNode->right,curStr);
            // 回溯
            curStr = curStr.substr(0,curStr.length()-temp.size());
        }   
        
    }
    void PrintVec()
    {
        for(auto i: resuOut){
            cout << i << " ";
        }
        cout << endl;
    }
    int CalVec()
    {
        int resu  = 0;
        for(auto i : resuOut){
            resu += stoi(i);
        }
        return resu;
    }
public:
    string resu = "";
    vector<string> resuOut;
};

int main()
{
    Solution s1;
    TreeNode *root1 = new TreeNode;
    TreeNode *root2 = new TreeNode(); // 初始化为 0
    TreeNode *root = new TreeNode(1); // 初始化为 1
    // cout << root1->val << endl;
    // cout << root2->val << endl;
    // cout << root->val << endl;
    TreeNode *two_1 = new TreeNode(2); // 第二层第一个
    TreeNode *two_2 = new TreeNode(3);

    root -> left = two_1;
    root -> right = two_2;

    int resu = s1.sumNumbers(root);
    cout << "main:: resu= " << resu << endl;

    return 0;

}