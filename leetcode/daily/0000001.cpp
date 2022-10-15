#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std; 
int step(vector<vector<char>>&data, string target);

int main()
{
    int n , m , x, y, z;
    cin >> n >> m >> x >> y >> z;
    vector<vector<char>>data(n,vector<char>(n,' '));
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char temp;
            cin >> temp;
            data[i][j] = temp;
        }
    }
    string target;
    cin >> target;
    int resu = step(data,target);
    cout << resu << endl;
    return 0;
}


int step(vector<vector<char>>&data, string target)
{
    int str_lenth = target.length();

    return 0;


}