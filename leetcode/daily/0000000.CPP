#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

void test()
{
    vector<int>nums = {1,2,2};
    int tot = accumulate(nums.begin(),nums.end(),1);
    cout << "tot= " << tot << endl;
}

int main()
{
    test();
    return 0;
}

