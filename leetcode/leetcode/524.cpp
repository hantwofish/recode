#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        for(int k = 0 ;  k < n ; k++){
            string diff = dictionary[k];
            int i = 0;
            int j = 0;
           // cout << "i= " << i << "j= " << j << endl;
            while (i < s.length() && j < diff.length()) 
            {
                cout << "i= " << i << "j= " << j << endl;
                while(s[i] != diff[j] && i < s.length()){
                    i++;
                }
                if(s[i] == diff[j]){
                    i++;
                    j++;
                }
            }
           if(j >= diff.length()){
                result = result.length() > diff.length() ? result : diff;
                cout << "result== " << result << endl;
            }else if( i >= s.length() ){ // 未匹配
                continue;
            }
            
        }

        return result;
    }
private:
    string result ="";
};


int main()
{
    Solution s1;
    string s = "abce";
    vector<string>dictionary = {"abe","abc"};
    string resu= s1.findLongestWord(s,dictionary);
    cout << "reu= " << resu << endl;
    return 0;

}