#include"STLCOMMON.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        dpVec.resize(amount+1,0);
        if(amount == 0){
            return 1;
        }
        PrintVec();
        dpVec[0] = 1;
        for(int moneyNumber = 1; moneyNumber <= amount; moneyNumber++){
            int choiceNumber  = 0;
            for(int j = 0; j < coins.size(); j++){
                if(moneyNumber - coins[j] < 0){
                    continue;
                }
                // else if(moneyNumber - coins[j] == 0){
                //     choiceNumber = 1;
                // }
                else{
                    dpVec[moneyNumber] += dpVec[moneyNumber - coins[j]];
                }
            }
            //dpVec[moneyNumber] = choiceNumber;
        }
        PrintVec();
        return dpVec[amount];

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
    int amount = 3;
    vector<int>coins = {1,2};
    int resukt = s1.change(amount,coins);
    cout << "resu= " << resukt << endl;

    return 0;
}