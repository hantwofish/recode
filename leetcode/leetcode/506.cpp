#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>temp = score;
        sort(temp.begin(), temp.end());
        reverse(temp.begin(),temp.end());
        vector<string> resu(score.size(),"");
        for(int i = 0; i < score.size(); i++){
            int index = find_num(temp, score[i]);
            if(index == 0){
                resu[i] = "Gold Medal";
            }else if(index == 1){
                resu[i] = "Silver Medal";
            }else if(index == 2){
                resu[i] = "Bronze Medal";
            }else{
                resu[i] = to_string(index+1);
            }
        }
        return resu;

    }
    int find_num(vector<int>&score, int num)
    {
        for(int i = 0 ; i < score.size(); i++){
            if(num == score[i]){
                return i;
            }
        }
        return 0;
    }
};

int main(){
    Solution s1;
    vector<int>score= {10,3,8,9,4};
    vector<string>resu = s1.findRelativeRanks(score);
    for(auto i: resu){
        cout << i<< endl ;
    }
    cout << endl;
    return 0;
}
