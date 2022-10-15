#include"STLCOMMON.h"
using namespace std;



class Solution {
public:
    string largestMerge(string word1, string word2) {
        int lent1 = word1.length();
        int lent2 = word2.length();
        int i = 0;
        int j = 0;
        while((i < lent1) &&( j < lent2)){
            string subString1 = word1.substr(i,lent1-i);
            string subString2 = word2.substr(j,lent2 - j);
            if(subString1 > subString2){
                resu += word1[i];
                i++;
            }else{
                resu += word2[j];
                j++;
            }
        }
        // 判断是否指向最后
        if(i  < lent1){
            resu += word1.substr(i, lent1 - i);
        }
        if(j < lent2){
            resu += word2.substr(j, lent2 - j);
        }



        return resu;
    }
public:
    string resu = "";
};


int main()
{
    Solution s1;
    string word1 = "abcabc";
    string word2 = "abdcaba";

    string resu = s1.largestMerge(word1, word2);
    cout << "resu= " << resu << endl;
    return 0;
}