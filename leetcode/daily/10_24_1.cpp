#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace  std;
string cal_resu(vector<string>&first,vector<string>&second,vector<string>&third,vector<string>&resu);

int main()
{                                                            
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    vector<string>first(n1,"");
    vector<string>second(n2,"");
    vector<string>third(n3,"");
    string temp = "";
    for(int i = 0 ; i < n1;i ++){
        cin >> temp;
        first[i] = temp;
    }
    for(int i = 0 ; i< n2; i++){
        cin >> temp;
        second[i] = temp;
    }
    for(int i = 0 ; i< n3; i++){
        cin >> temp;
        third[i] = temp;
    }
    int N ;
    cin >> N;
    vector<string> resu_panduan;
    for(int i = 0 ; i < N ; i++){
        resu_panduan.clear();
        string temp2;
        while(cin >> temp2){
            if(temp2 == "\n"){
                break;
            }
           // cout << "temp2= " << temp2 << endl;
            resu_panduan.push_back(temp2);
            cout << "++=" << resu_panduan.size() <<endl;
        }
        // 进行判断
        cout << "**" << resu_panduan.size() <<endl;
        cout << cal_resu(first,second,third,resu_panduan) << endl;
    }

    return 0;


}

string cal_resu(vector<string>&first,vector<string>&second,vector<string>&third,vector<string>&resu)
{
    int weici_num = 0;
    vector<int>str_num(resu.size(),0);
    for(int j = 0; j < resu.size(); j++ ){
        if(find(first.begin(),first.end(),resu[j]) != first.begin() ){
            str_num[j] = 0;
        }else if(find(second.begin(),second.end(),resu[j]) != second.begin() ){
            str_num[j] = 1;
        }else if(find(third.begin(),third.end(),resu[j]) != third.begin() ){
            str_num[j] = 2;
        }
    
    }
    
    if(str_num[0] == 1 || str_num[0] == 2){
        return "NO";
    }
    vector<int>beifen(str_num);
    sort(str_num.begin(),str_num.end());
    if(str_num != beifen){
        return "NO";
    }
    return "YES";
}

