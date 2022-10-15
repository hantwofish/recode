#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> m_map;
        for(char i : s){
            m_map[i]++;
        }
        
        int times[10] = {0};
        times[8] = m_map['g'];
        times[4] = m_map['u'];
        times[2] = m_map['w'];
        times[6] = m_map['x'];
        times[0] = m_map['z'];

        times[3] = m_map['h'] - times[8];
        times[7] = m_map['s'] - times[6];
        times[5] = m_map['v'] - times[7];

        times[1] = m_map['o'] - times[0] - times[2] - times[4];
        times[9] = m_map['i'] - times[5] - times[6] - times[8];
  

        string  ans;
        for(int i = 0 ; i< 10; i++){
            for(int j = 0 ; j < times[i]; j++){
                ans += char(i + '0');
            }
        }       
      
        return ans;     
    }
};


int main()
{
    Solution s1;
    string s = "nine";
    string resu = s1.originalDigits(s);
    cout << "resu= " << resu << endl;
    return 0;
}