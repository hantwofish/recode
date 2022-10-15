#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main()
{
    Solution s1;
    int N = 3;
    int resu = s1.canWinNim(N);
    if(resu){
        cout << "True " << endl;
    }else{
        cout << "False " << endl;
    }

    return 0;
    
}