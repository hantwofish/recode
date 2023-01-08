#include"STLCOMMON.h"

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        return 0;
    }
    int beauNumber(string s)
    {
        unordered_map<char,int> unMap;
        for(int i = 0; i< s.length(); i++ ){
            unMap[s[i]]++;
        }
        int maxNumber = INT32_MIN;
        int minNumber = INT32_MAX;
        auto it = unMap.begin();
        while (it != unMap.end())
        {
            if(it->second > maxNumber){
                maxNumber = it->second;
            }
            if(it->second < minNumber){
                minNumber = it->second;
            }
            it++;
        }
        cout << "maxNumber= " << maxNumber << " minNumber= " << minNumber << endl;
        return maxNumber-minNumber;
        

    }
};

int main()
{
    Solution s1;
    string s  = "abaacc";
    s1.beauNumber(s);
    return 0;

}

