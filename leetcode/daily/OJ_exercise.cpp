#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace  std;

// OJ 7
/*
输入描述:
    链接：https://ac.nowcoder.com/acm/contest/5657/G
    来源：牛客网

    输入数据有多组, 每行表示一组输入数据。

    每行不定有n个整数，空格隔开。(1 <= n <= 100)。
输出描述:
    每组数据输出求和的结果
intput:
    1 2 3
    4 5
    0 0 0 0 0
output:
    6
    9
    0
*/

int Oj_7()
{
    int data;
    while(cin >> data){
        int sum = data;
        while(cin.get() != '\n'){
            int a;
            cin >> a;
            sum += a;

        }
        cout << sum << endl;
    }
    return 0;
}

// oj9
/*
输入描述:
    多个测试用例，每个测试用例一行。

    每行通过空格隔开，有n个字符，n＜100


输出描述:
    对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
示例1
intput:
    a c bb
    f dddd
    nowcoder
output:
    a bb c
    dddd f
    nowcoder
*/

int OJ9()
{

    string tmp;
    vector<string> vec;
     
    while(cin >> tmp) {
        vec.push_back(tmp);
         
        if(getchar() == '\n') {
            sort(vec.begin(), vec.end());
            for(int i=0; i<vec.size()-1; i++){
                cout << vec[i] << " ";
            }
            cout << vec.back() << endl;
            vec.clear();
        }
    }
    return 0;
}

// oj10
/*
链接：https://ac.nowcoder.com/acm/contest/5657/J
来源：牛客网

输入描述:
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输出描述:
对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格

a,c,bb
f,dddd
nowcoder

a,bb,c
dddd,f
nowcoder


*/

int OJ10()
{
    string temp;
    while(cin>>temp)
    {
        stringstream ss(temp);
        string word;
        vector<string> list;
        while(getline(ss,word,','))
        {
            list.emplace_back(word);
        }
        sort(list.begin(), list.end());
        cout<<list[0];
        for(int i=1;i<list.size();i++)
        {
            cout<<','<<list[i];
        }
        cout<<endl;
        
        temp.clear();
    }
    return 0;
}



void test()
{
    string resu;
    while(cin >> resu){
        cout << "string= " << resu << endl;
        if(cin.get() == ' '){
            cout << " space= "<< endl;
        }else if(cin.get() == '\n'){
            cout << " end " << endl;

        }

    }

}
int main()
{
   // OJ9();
   test();
    
    return 0;
}

