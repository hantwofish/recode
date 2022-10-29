#include"STLCOMMON.h"


using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.size()/2;
        int leftNumber =0 ;
        int rightNumber =0 ;
        cout << "s.size()= " << s.size() << " half= " << half << endl;
        for(int i = 0 ; i< half; i++){
            if( s[i] >= 'a' && s[i] <= 'z'){
                s[i] =s[i] - 32;
            }
             // 小写转大写
            if((s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U')){
                left[s[i]]++;
                leftNumber ++;
            }
        }
        for(int i = half ; i< s.size(); i++){
            if( s[i] >= 'a' && s[i] <= 'z'){
                // 小写转大写
                s[i] =s[i] - 32;
               
            }
            if((s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U')){
                right[s[i]]++;
                rightNumber++;
            }
        }
        cout << "**" << endl;
        // if((left['A'] == right['A'])&&(left['E'] == right['E'])&&(left['I'] == right['I'])&&(left['O'] == right['O'])&&(left['U'] == right['U'])){
               
        //         cout << "true" << endl;
        //          return true;
        // }else{
        //     cout << "false" << endl;
        // }
        if(leftNumber == rightNumber){
            return true;
        }
        return false;
    }
public:
    unordered_map<char,int>left;
    unordered_map<char,int>right;
};

int main()
{
    Solution s1;
    string s = "AbCdEfGh";
    s1.halvesAreAlike(s);
    return 0;

}