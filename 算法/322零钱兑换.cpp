#include"STLCOMMON.h"

using namespace std;

// 递归解法--超时
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        return DpCal(coins,amount);
    }
    int DpCal(vector<int>& coins,int number)
    {
        if(number == 0){
            return 0;
        }
        if(number < 0){
            return -1;
        }
        cout << "number= " << number << endl;
        for(int i = 0; i < coins.size(); i++){
            if(number == coins[i]){
                return 1;
            }
        }
        int min_number = INT32_MAX;
        for(int i = 0; i < coins.size(); i++){
            int subProblem = DpCal(coins, number- coins[i]);
            if( subProblem == -1){
                continue;
            }
            min_number =  min(min_number, 1 + subProblem );
            cout << "min_number= " << min_number << endl;
        }
        if(min_number == INT32_MAX){
            return -1;
        }
        return min_number;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //PrintVec();
        if(amount == 0){
            return 0;
        }
        dpVec.resize(amount+1, 0);
        //PrintVec();
        dpVec[0] = 0;
        for(int i = 0; i< coins.size(); i++){
            if( coins[i] > amount-1 ){
                continue;
            }
            dpVec[coins[i]] = 1;
        }
        //PrintVec();


        for(int moneyNumber = 1; moneyNumber<= amount ; moneyNumber++){
            if(dpVec[moneyNumber] != 0){
                continue;
            }
            // 求出最小值
            int resuMin  = INT32_MAX;
            for(int j  = 0; j < coins.size(); j++){
                if(moneyNumber - coins[j] < 0){
                    continue;
                }
                int resulytTemp = dpVec[moneyNumber- coins[j]];
                if(resulytTemp != -1){
                    resuMin = min(resuMin, 1+ resulytTemp);
                }
                
            }
            if(resuMin != INT32_MAX){
                dpVec[moneyNumber] = resuMin;
            }else{
                dpVec[moneyNumber] = -1;
            }
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
    vector<int>dpVec;
};


int main()
{
    Solution s1;
    vector<int>coins = {1}; 
    int amount = 0;
    int resu = s1.coinChange(coins,amount);
    cout << "resu= " << resu << endl;
    return 0;
}
