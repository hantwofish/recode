#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stk.push(asteroids[0]);
        for(int i = 1; i < asteroids.size(); i++){
            int cur_num = asteroids[i];
            cout << "cur_num= " << cur_num << endl;
            if(!stk.empty() && stk.top() > 0  && cur_num < 0  ){
                bool disappear = false; // 当前数字要不要消失
                while(!stk.empty() && stk.top() > 0 && cur_num < 0){
                    if( abs(cur_num) == stk.top() ){
                        disappear = true;
                        stk.pop();
                        break;
                    }else if( abs(cur_num) < stk.top() ){
                        disappear = true;
                        break;
                    }else if( abs(cur_num ) > stk.top()){
                        stk.pop();
                    }
                }
                if(disappear == false){
                    stk.push(cur_num);
                }
                
            }else{
                stk.push(cur_num);
            }

            
        }
        cout << "stk.size()= " << stk.size() << endl;
        
        while(!stk.empty()){
            nums.push_back(stk.top());
            stk.pop();
        }
        reverse(nums.begin(),nums.end());
        return nums;


    }

private:
    stack<int>stk;
    vector<int>nums;
};
int main()
{
    Solution s1;
    vector<int> asteroids= {-2,1,-2,-2};
    vector<int>resu = s1.asteroidCollision(asteroids);
    for(auto&i : resu){
        cout << " " << i;
    }
    cout << endl;
    return 0;
}