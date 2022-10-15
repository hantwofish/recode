#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int s_len = s.length();
        vector<int>dp(s_len+1, 0); // dp[i] 个字符，i 从 1 开始
        if(s_len < 1 ||  s[0] == '0'){
            return 0;
        }
        // 初始化
        if(s[0] >= '1' && s[0] <= '9'){
            dp[1] = 1;
        }else if (s[0] == '*')
        {
            dp[1] = 9;
        }
        dp[0] = 1;
        
        for(int i =1 ; i < s_len ; i++){
            long long case_one = 0;
            long long  case_two = 0;
            int cur_index = i +1 ;  
            // 
            if(s[i] == '0'){
                case_one = 0;
            }else if(s[i] == '*'){
                case_one =(long long ) dp[cur_index-1] * 9;
            }else{
                case_one = dp[cur_index -1];
            }
            // 与前面一位组合
            string str_sub  = s.substr(i-1, 2);
            if(str_sub[0] == '0'){
                case_two = 0;
            }if( str_sub[0] >= '1' && str_sub[0] <= '9' ){
                if(str_sub[1] >= '0' && str_sub[1] <= '9'){
                    if(stoi(str_sub) <= 26 ){
                        case_two = dp[cur_index-2];
                    }else{
                        case_two  = 0;
                    }
                }else if( str_sub[1] == '*' ){
                    if(str_sub[0] == '1'){
                        case_two = (long long )dp[cur_index-2] * 9;
                    }else if(str_sub[0] == '2'){
                        case_two = (long long)dp[cur_index-2] * 6;
                    }else {
                        case_two = 0;
                    }
                }
            }else if(str_sub[0] == '*'){
                if(str_sub[1] >= '0' && str_sub[1] <= '6'){
                    case_two = dp[cur_index-2] * 2;
                }else if(str_sub[1] >= '7' && str_sub[1] <= '9'){
                    case_two = dp[cur_index-2] * 1;
                }else if(str_sub[1] == '*'){
                    case_two =  (long long)dp[cur_index-2] * 15 ;
                    
                    
                }
            }
           // cout << "i= " << i << " case_one= " << case_one << " case_two= " << case_two << endl;
            if(case_one + case_two >mod_num ){
                dp[cur_index] = (case_one + case_two) % mod_num;
            }else{
                 dp[cur_index] = (case_one + case_two);   
            }

        }
     
        return dp[s_len] ;

    }
private:
    int resul = 0;
    int mod_num = (pow(10,9)+7);
    
};
int main()
{
    Solution s1;
    string str = "7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*";
    int result = s1.numDecodings(str);
    cout << "main resu= " << result << endl;
    int a =  pow(10,9)+7;
    cout << INT32_MAX << endl;
    cout << a <<endl;
    return 0;
}
