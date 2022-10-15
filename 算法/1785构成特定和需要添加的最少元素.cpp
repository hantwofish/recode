#include"STLCOMMON.h"
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int sumNum  = 0;
        for(auto i : nums){
            sumNum += i;
        }
        int diffNumber = abs(goal - sumNum);
        if(diffNumber % limit == 0){
            return diffNumber / limit;
        }
        return diffNumber / limit + 1;
    }
};


class Solution2 {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int sumNum  = 0;
        for(auto i : nums){
            sumNum += i;
        }
        int diffNumber = abs(goal - sumNum);
        cout << "sumNum= " << sumNum  << " goal= " << goal << " diffNUmber= " << diffNumber << endl;
        dpVec.resize(diffNumber+1, INT32_MAX);
        //PrintVec();
        for(int i = 0; i <= diffNumber; i++){
            if(i == 0){
                dpVec[i] = 0;
                continue;
            }
            if(i <= limit){
                dpVec[i]=1;
                continue;
            }
            int temp = INT32_MAX;
            for(int j = 1; j <= limit; j++){
                temp = ( temp < dpVec[i-j] )? temp : (dpVec[i-j]); 
            }
            dpVec[i] = temp + 1;

        }
        //PrintVec();
        return dpVec[diffNumber];
    }
    void PrintVec()
    {
        for(auto i : dpVec){
            cout << i << " ";
        }
        cout << endl;
    }
public:
    vector<int> dpVec;
};

int main()
{
    Solution s1;
    Solution2 s2;
    vector<int>nums = {2,2,2,5,1,-2};
    int limit = 5;
    int goal = 126614243;
    int resu1 = s1.minElements(nums,limit,goal);
    int resu2 = s2.minElements(nums,limit,goal);
    cout << "s1:: resu= " << resu1  << endl;
    cout << "s2:: resu= " << resu2  << endl;
    return 0;
}