#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

string cal_str(string str)
{
    string data_num = "";
    string char_num = "";
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            data_num += str[i];
        }else if(  (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            char_num += str[i];
        }
    }
    sort(data_num.begin(),data_num.end());
    reverse(data_num.begin(),data_num.end());
    sort(char_num.begin(),char_num.end());
    int i = 0 ;
    int j = 0;
    for(int k = 0 ; k < str.length() ;k++){
        if(str[k] == '?'){
            continue;
        }else if(str[k] >= '0' && str[k] <= '9'){
            str[k] = data_num[i];
            i++;
        }else {
            str[k] = char_num[j];
            j++;

        }
    }
    return str;
}
string cal_str2S(string str)
{
    vector<int>data_num;
    vector<char>data_char;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            data_num.push_back(str[i] - '0');
        }else if(  (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            data_char.push_back(str[i]);
        }
    }
    sort(data_num.begin(),data_num.end());
    reverse(data_num.begin(),data_num.end());
    sort(data_char.begin(),data_char.end());

    int i = 0 ;
    int j = 0;
    for(int k = 0 ; k < str.length() ;k++){
        if(str[k] == '?'){
            continue;
        }else if(str[k] >= '0' && str[k] <= '9'){
            str[k] = (char)(data_num[i] + '0');
            i++;
        }else if(  (str[k] >= 'a' && str[k] <= 'z') || (str[k] >= 'A' && str[k] <= 'Z')){
            str[k] = data_char[j];
            j++;

        }
    }
    return str;
}


int main()
{
    string str = "1243??Asdfs?xzaa";
    string resu = cal_str2S(str);
    cout << resu << endl;
    return 0;
}