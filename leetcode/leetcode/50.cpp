#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Solution2 {
public:
    double myPow(double x, int n) {
        long long N  = n;
        if(x == 1){
            return 1.0;
        }
        return n>=0 ? cal(x,N) : 1.0/cal(x,-N);

    }
    double cal(double x , long long N ){
        
        if(N == 0){
            return 1.0;
        }
        double y = cal(x , N /2);
        return N % 2 == 0 ? y*y : y*y*x; 

    }
};

class Solution {
public:
    double myPow(double x, int n) {
        
        return 1.0;
    }
    double cal_pow(double x , long long N)
    {
        return 0.0;
    }
};
int main()
{
    Solution s1;
    int n  = 2;
    int N  = INT32_MAX;
    int resu = s1.myPow(n,N);
    cout << "resu= " << resu << endl;
    return 0;
}



