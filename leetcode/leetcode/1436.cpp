#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> data;
        for(int i= 0; i < paths.size(); i++){
            data.insert(paths[i][0]);
        }
        for(int i = 0 ; i< paths.size(); i++){
            if(data.find(paths[i][1] ) == data.end()){
                return paths[i][1];
            }
        }
        return "";
    }
};

int main()
{
    Solution s1;
    vector<vector<string>>paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    string resu = s1.destCity(paths);
    cout << "resu= " << resu << endl;
    return 0; 
}