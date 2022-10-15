#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        if(calString(word1) == calString(word2)){
            return true;
        }else{
            return false;
        }
    }
    string calString(vector<string>& word)
    {
        string resu = "";
        for(int i =0 ; i < word.size(); i++){
            resu +=word[i];
        }
        return resu;

    }
};

int main()
{

}