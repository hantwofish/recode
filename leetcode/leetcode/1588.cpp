#include"STLCOMMON.h"

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int length = arr.size();
        int resu = 0;
        int temp = 0;
        for(int i = 0; i< arr.size(); i++){
            for(int len = 1; len <= length; len++){
                if(len % 2 == 0){
                    continue;
                }
                if(i + len - 1 >= arr.size()){
                    continue;
                }
                temp = calSum(arr, i, i+ len-1);
                cout << " temp = " << temp << endl;
                resu += calSum(arr, i, i+ len-1);

            }
        }


        return resu;
    }
    int calSum(vector<int>&arr, int i, int j){
        int sum = 0;
        for(int start = i; start <= j; start++){
            sum = sum+ arr[start];
        }
        return sum;
    }
};

int main()
{
    Solution s1;
    vector<int> grid = {1,4,2,5,3};
    int resu = s1.sumOddLengthSubarrays(grid);
    cout << "resu= " << resu << endl;
    return 0;
}