#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        string resu = "";
        vector<bool>visited(str.length(),false);
        DFS(str, resu,visited);
        my_print(result_data);
        for(int i = 0 ; i < result_data.size(); i++){
            if(isValid(stoi(result_data[i]))){
                return true;
            }
        }

        return false;;
    }

    // 全排列
    void DFS(string& str , string& resu ,vector<bool>&visited)
    {
        if(resu.length() == str.length()){
            result_data.push_back(resu);
            return;
        }
        for(int i = 0 ; i< str.size(); i++){
            if(visited[i] ){
                continue;
            }
            resu += str[i];
            visited[i] = true;
            DFS(str, resu,visited);
            resu.pop_back();
            visited[i] = false;
        }

        
    }
    void my_print(vector<string>& resu)
    {
        for(auto& i : resu){
            cout << i << " ";
        }
        cout << endl;

    }

private:
    bool isValid(int num) {
        // 2的幂的二进制中只有一个1
        return (num & (num - 1)) == 0;
    }
    vector<string> result_data;
    




};

int main()
{
    Solution s1;
    int N = 16;
    cout << s1.reorderedPowerOf2(N);
    cout << endl;
    

    return 0;
}