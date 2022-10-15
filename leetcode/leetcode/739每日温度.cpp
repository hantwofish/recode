#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        stack<int> stk; // 存储下标索引
        vector<int>resu(N,0);
        for(int i = N-1; i >=0 ; i--){
           
            while(!stk.empty() &&  temperatures[ stk.top() ] <= temperatures[i]){
                stk.pop();
            }
            resu[i] = stk.empty() ? 0 : (stk.top() - i);
            stk.push(i);
        }
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>tempures = {73,74,75,71,69,72,76,73};
    vector<int>resu= s1.dailyTemperatures(tempures);
    for(auto& i : resu){
        cout << i << " ";
    }
    return 0;
}