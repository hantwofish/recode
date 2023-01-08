#include"STLCOMMON.h"
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        // int firstMax = INT32_MIN;
        // int secondMax = INT32_MIN;
        for(int i = 0; i< s.length(); i++){
            if(  (s[i] >= '0') && (s[i] <= '9') ){
                int temp = s[i] -'0';
                if(find(resu.begin(),resu.end(),temp) == resu.end()){
                    resu.push_back(temp);
                }
            }
        }
        sort(resu.begin(),resu.end());
        if(resu.size() < 2){
            return -1;
        }

        return resu[resu.size()-2];
    }
public:
    vector<int>resu;
};

int main()
{
    Solution s1;
    string s = "abc1111";
    int resu = s1.secondHighest(s);
    cout << "resu= " << resu << endl;
    return 0;
}