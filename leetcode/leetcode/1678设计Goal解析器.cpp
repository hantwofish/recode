#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string resu = "";
        int front = 0;
        int behind = 0;
        while(front < command.size() ){
            if( command[front] == 'G'){
                resu += "G";
                front++;
                continue;
            }
            if( command[front] == '(' && command[front+1] == ')' ){
                resu += "o";
                front = front + 2;
                continue;
            } else if(command[front] == '(' && command[front+1] != ')'){
                front++;
                string temp = "";

                while(front < command.size() && command[front] != ')'){
                    temp += command[front];
                    front++;
                }
                resu += temp;

            } else if(command[front] == ')'){
                front++;
                continue;
            }
            cout << "while::resu= " << resu << endl;

        }
        return resu;

    }
};



int main()
{
    Solution s1;
    string command = "(al)G(al)()()G";
    cout << s1.interpret(command) << endl;
    return 0;

}