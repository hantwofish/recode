#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;
/*
### unordered_map 的排序
题目 675
https://blog.csdn.net/qq_43404969/article/details/107694672
*/

// nums.
// nums.insert(nums.begin()+3,1); // 8 2 7 1 9 5

int main()
{
    vector<int> nums = {8,2,7,9,5};
    nums.push_back(1);
    nums.insert(nums.begin()+3,1); // 8 2 7 1 9 5
    cout << "**" << endl;
    return 0;
}