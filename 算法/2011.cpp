#include"STLCOMMON.h"
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int resu = 0;
        for(auto str : operations){
            if(IsAdd(str)){
                resu++;
            }else{
                resu--;
            }
        }
        return resu;

    }
public:
    bool IsAdd(string str)
    {
        if(str == "X++" || str == "++X"){
            return true;
        }
        return false;

    }
};