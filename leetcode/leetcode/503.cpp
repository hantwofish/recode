#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int>resu(N,0);
        stack<int> stk; // 存放索引
        for(int i = (2*N-1) ;i >= 0 ; i--){
            while(!stk.empty() && nums[stk.top() % N] <= nums[i % N] ){
                stk.pop();
            }
            resu[i % N] = stk.empty() ? -1 : nums[stk.top()%N];
            stk.push(i % N);

        }
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,2,1};
    vector<int>resu = s1.nextGreaterElements(nums);
    for(auto& i : resu){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}