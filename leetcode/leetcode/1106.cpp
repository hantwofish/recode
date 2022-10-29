#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stackStr;
        
        stackStr.push(expression[0]);
        int index= 1;
        while(index < expression.size()){
            cout << "stackStr.size()= " << stackStr.size() << endl;
            cout << "index= " << index << endl;
            char temp = expression[index];
            if(temp == ','){
                index++;
                continue;
            }else if(temp == ')'){
                vector<bool> vecStr;
                while( stackStr.top() != '&' && stackStr.top() != '!' && stackStr.top()!= '|' ){
                   
                    if(stackStr.top() == 't'){
                        vecStr.push_back(true);
                    }else if(stackStr.top() == 'f'){
                        vecStr.push_back(false);
                    }
                    
                    stackStr.pop();
                }
                if(stackStr.top() == '&'){
                    stackStr.pop();
                    bool temp = true;
                    for(int i = 0 ; i < vecStr.size(); i++){
                        temp &= vecStr[i];
                    }
                    stackStr.push(boolTochar(temp));

                }else if(stackStr.top() == '|'){
                    stackStr.pop();
                    bool temp = false;
                    for(int i = 0 ; i < vecStr.size(); i++){
                        temp |= vecStr[i];
                    }
                    stackStr.push(boolTochar(temp));

                }else if(stackStr.top() == '!'){
                    stackStr.pop();
                    stackStr.push(boolTochar(!vecStr[0]));

                }

                

            }else{
                stackStr.push(temp);
            }



            index++;
        }
        bool resu = stackStr.top() == 't' ? true : false;
        return resu;



    }
    char boolTochar(bool num)
    {
        if(num){
            return 't';
        }else{
            return 'f';
        }
    }
};


class Solution2 {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == ',') {
                continue;
            } else if (c != ')') {
                stk.push(c);
            } else {
                int t = 0, f = 0;
                while (stk.top() != '(') {     
                    char val = stk.top();
                    stk.pop();
                    if (val == 't') {
                        t++;
                    } else {
                        f++;
                    }
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                switch (op) {
                case '!':
                    stk.push(f == 1 ? 't' : 'f');
                    break;
                case '&':
                    stk.push(f == 0 ? 't' : 'f');
                    break;
                case '|':
                    stk.push(t > 0 ? 't' : 'f');
                    break;
                default:
                    break;
                }
            }
        }
        return stk.top() == 't';
    }
};



int main()
{
    Solution s1;
    string expression = "&(|(f))";
   
    if(s1.parseBoolExpr(expression)){
        cout << "True";
    }else{
        cout << "False";
    }
    cout << endl;                                                                                           
    return 0;

}