#include"STLCOMMON.h"
using namespace std;

//找出所有子串，判断是否为回文子串
class Solution2{

};

class Solution {
public:
    int countSubstrings(string s) {
        int lengh = s.length();
        int result = 0;
        dpVec.resize(lengh, vector<bool>(lengh,0));
        for(int row = lengh - 1; row >= 0; row--){
            for(int col = row ; col < lengh; col++){
                if(row == col){
                    dpVec[row][col] = true;
                    result++;
                    continue;
                }
                if( (col - row == 1) && (s[row] == s[col])){ // 两个字符
                    dpVec[row][col] =  true;
                    result++;
                    continue;
                }
                if( (col - row > 1 )&& (s[row] == s[col])  &&  (dpVec[row+1][col-1])  ){
                    // 从 dpVec[row+1][col-1] 到  dpVec[row][col]  、
                    // 方向 从下到上，从左到右
                    dpVec[row][col] = true;
                    result++;
                }

            }
        }



        return result;
    }
public:
    vector<vector<bool>>dpVec;
};

int main()
{
    Solution2 s2;
    Solution s1;
    string s = "abc";
    int resu = s1.countSubstrings(s);
    cout << "resu= " << resu << endl;
    return 0;
}