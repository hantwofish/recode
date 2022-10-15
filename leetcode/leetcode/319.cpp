#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

/*

这个题的题眼是“每 i 个灯泡就切换一个灯泡的开关” 这个意思
就是第i轮，“改变位置在第i的倍数上的那个灯泡”。所以叫每i个灯泡
切换一个灯泡的开关，举个例子，有6个灯泡，第2轮，改变的是第2个、第4个、第
6个灯泡的位置，都是2的倍数
*/
class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0 ||  n == 1){
            return n;
        }
        vector<bool>data(n+1,0);
        for(int i =1 ; i <= n ; i++){
            trans(data, i);
        }
        int sum = 0;
        for(int i = 1 ; i< data.size(); i++){
            if(data[i]){
                sum++;
            }
        }
        return sum;

    }
    void trans(vector<bool>&data, int times)
    {
        for(int i = 1 ; i < data.size() ; i++){
            if(i % times == 0){
                data[i] = !data[i];
            }
        }
    }
};

int main()
{
    Solution s1;
    int n  = 10000;
    int resu = s1.bulbSwitch(n);
    cout << "resu= " << resu << endl;
    return 0;
}