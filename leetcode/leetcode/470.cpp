#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
using namespace std;


class Solution {
public:
    int rand10() {
        return rand7()*10/7;
    }
    int rand7()
    {
        return rand()%7;
    }
};


int main()
{
    int a = rand();
    Solution s1;
    for(int i = 0 ; i < 10 ; i++){
        cout << s1.rand10() << endl;
    }
    return 0;
}

while(true) {
    int num = (rand7() - 1) * 7 + rand7(); // 等概率生成[1,49]范围的随机数
    if(num <= 40) 
        return num % 10 + 1; // 拒绝采样，并返回[1,10]范围的随机数
}

