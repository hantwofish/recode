#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

    }
};

int main()
{
    Solution s1;
    vector<string>deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    int resu = s1.openLock(deadends,target);
    cout << "main resu= " << resu << endl;
}


class father{
public:
    virtual void eat() = 0;// 这是一个纯虚函数

};

