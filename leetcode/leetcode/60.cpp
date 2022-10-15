#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        backtracing(n,k);
        return data[k-1];
    }
    void backtracing(int n,int k)
    {
        if(temp.length()==n){
            
            data.push_back(temp);
            return;
        }
        if(data.size()==k){
            return;
        }
       
        for(int i = 1; i <= n ;i++){
            if(temp.find(i+'0') != temp.npos){ // 找到
               // cout << "**" << endl;
                continue;
            }
            temp+= (i+'0');
            // cout << "temp= "<< temp << endl;
            backtracing(n,k);
            temp.pop_back();
        }

    }

private:
    vector<string>data;
    string temp="";
};

int main()
{
    Solution s1;
    int n = 9;
    int k = 54494;
    string resu = s1.getPermutation(n,k);
    cout << "resu= " << resu << endl;
    return 0;
}