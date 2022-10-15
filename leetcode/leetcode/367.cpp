#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        get_data();
        if(data.find(num) != data.end()){
            return true;
        }else{
            return false;
        }

    }
private:
    unordered_set<int>data;
    void get_data()
    {
        int i = 1;
        while( i* i < INT32_MAX /2){
            data.insert(i*i);
            i++;
        }
    }
};

int main()
{
    Solution s1;
    int num = 14;
    cout << (s1.isPerfectSquare(num)? "TRUE" :"FALSE") << endl;
    return 0;
}