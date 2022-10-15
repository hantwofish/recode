#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        return 0;

    }
    // 计算两个点之间的斜率
    double cal_k(vector<int>&A, vector<int>&B)
    {
        if(A.size()!= 2 || B.size() != 2){
            return 0;
        }
        int y1 = A[1] - B[1];
        int x1 = A[0] - B[0];
        if(y1 == 0 ){
            return 0;
        }else if(x1 == 0){
            return INT32_MAX;
        }else{
            return y1 / x1;
        }

    }
    // 计算最大公约数
    int gcd(int a, int b)
    {
        cout << "a= " << a << " b= " << b << endl;
        return b ? gcd(b, a % b) : a;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>>nums = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << " " << s1.gcd(2,1) << endl;
    return 0;
}