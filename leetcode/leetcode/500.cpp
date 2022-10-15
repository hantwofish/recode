#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        vector<string>resu;
        for(auto i: words){
            if(isvaild(i)){
                resu.push_back(i);
            }
        }
        return resu;

    }
    bool isvaild(string str)
    {
        if(str.length()== 1){
            return true;
        }
        int cur = 1;
        int res = 1;
        for(int j = 0; j < str.size(); j++){
            if(str[j] >= 'A' && str[j] <= 'Z'){
                str[j] = str[j] - 'A' + 'a';
            }
        }

        for(int j = 0 ; j < str.size(); j++){

            if(data_1.find(str[j]) != data_1.npos){
                cur = 1;
            }else if(data_2.find(str[j]) != data_2.npos){
                cur = 2;
            }else if(data_3.find(str[j] != data_3.npos)){
                cur = 3;
            }
            if(j == 0){
                res = cur;
            }else{
                if(cur != res){
                    return false;
                }
            }
        }
        return true;


    }
private:
    string data_1 = "qwertyuiop";
    string data_2 = "asdfghjkl";
    string data_3 = "zxcvbnm";
    


};

int main()
{
    Solution s1;
    vector<string>nums = {"Qwq","se","xc","cde"};
    vector<string> resu = s1.findWords(nums);
    for(auto& i : resu){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}