#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 1){
            result = to_string(numerator);
        }

        return result;
    }
private:
    string result = "";    
};

int main()
{
    Solution s1;
    int numerator = 1;
    int denominator = 2;
    string resu = s1.fractionToDecimal(numerator, denominator);
    cout << "resu= " << resu << endl;
    return 0;
}