#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int resu = 0;
        int divitor = 0;
        for(auto i: nums){
            divitor = __gcd(divitor, i);
            if(divitor == 1){
                break;
            }
        }
        return divitor ==1 ;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {12,5,7,23};
    bool resu= s1.isGoodArray(nums);
    cout << " " << resu << endl;
    
    return 0;
}