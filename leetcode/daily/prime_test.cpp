#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
#include<map>
#include<unordered_set>
#include<algorithm>

using namespace std;


//vector<int> prime_list={2,3,5,7,11,13,17};
int p = 3;
int q = 2; 
int  m_i = p*p*q;
vector<int> R_i; // 
vector<int> unit; // 单位
vector<int> prime_ele; // 素元
vector<bool> is_find(m_i, false); 


void print_vec(vector<int>& unit);
void print_set(unordered_set<int>& unit);
void print_vec_string(vector<string>& unit);

// 计算R_i;
void cal_R_i()
{
    for(int k = 0 ; k< m_i ; k++){
        R_i.push_back(k);
    }
}

// 计算最大公因数
int gcd(int x,int y)
{
    int t;
    while (y) t=x, x=y, y=t%y;
    return x;
}

// 计算单位(与m_i在 I 中互素)
void cal_p()
{
    for(int i = 1; i <= m_i ; i++){
        if(gcd(i,m_i) == 1){
            unit.push_back(i);
        }

    }
    cout << "danwei= " << unit.size() << " (p^2-p)(q-1)= " << (p*p -p)*(q-1) << endl;
}

// 计算素元 [p][u]形式
void cal_prime_ele()
{
    unordered_set<int> temp;
    
    for(int m = 0 ; m < unit.size(); m++){
        temp.insert(( p * unit[m])  % m_i);
    }
    
    auto it = temp.begin();
    while (it != temp.end())
    {
        prime_ele.push_back(*it);
        it++;
    }
    

    sort(prime_ele.begin(),prime_ele.end());
    cout << "suyuan = " << prime_ele.size() << " (p-1)(q-1)= " << (p-1)*(q-1) << endl;
}

void cal_prime_ele2()
{
    vector<int> temp;
    
    for(int m = 0 ; m < unit.size(); m++){
        temp.push_back(( p * unit[m])  % m_i);
    }
    
    auto it = temp.begin();
    while (it != temp.end())
    {
        prime_ele.push_back(*it);
        it++;
    }
    

  //  sort(prime_ele.begin(),prime_ele.end());
    cout << "suyuan = " << prime_ele.size() << " (p-1)(q-1)= " << (p-1)*(q-1) << endl;
}


bool is_Prime_ele(int M)
{
    if( find( prime_ele.begin(),prime_ele.end(),M) != prime_ele.end()  ){
        return true;
    }
    return false;
}
/*
// 求得差值为2的素数对
void cal_pri_2(vector<int>&prime_ele , vector<string>& prime_ele_0_2, vector<string>& prime_ele_0_2_4, vector<string>& prime_ele_0_4_6)
{
    
    for(int i = 0 ; i < prime_ele.size() ; i ++){
       int base  = prime_ele[i];
       //cout << "base= " << base << endl;
        if( is_Prime_ele(base + 2 ) ){
            prime_ele_0_2.push_back(to_string( base  ) + " " + to_string(base + 2));
            if( is_Prime_ele(base + 6 )){
                prime_ele_0_2_6.push_back(to_string( base  ) + " " + to_string(base + 2) + " " + to_string(base + 6));
            }
        }

        if( is_Prime_ele(base+4) && is_Prime_ele(base + 6)  ){
            prime_ele_0_4_6.push_back(to_string( base  ) + " " + to_string(base + 4) + " " + to_string(base + 6));
        }


    }
    return ;
}

*/

// 对于不同的形状进行计算
void cal_circle(int A, int B , int C, int U)
{
    cout << "[" << A<<"U" << "]= " << (A*U)%m_i << endl; 
    cout << "[" << B<<"U" << "]= " << (B*U)%m_i << endl; 
    cout << "[" << C<<"U" << "]= " << (C*U)%m_i << endl; 
}



// 验证 pr(x ) /\ pr(y)
vector<string> cal_pr_pr2()
{
    vector<string> resu;
    string temp  = "";
    for(int m = 0 ; m < m_i ; m++){
        // 为 零元
        if(R_i[m] == 0){
            continue;
        }
        // 为单位
        if((find(unit.begin(),unit.end(),R_i[m]))!= unit.end() ){
            continue;
        }
        // 为素元
        if((find(prime_ele.begin(),prime_ele.end(),R_i[m]))!= prime_ele.end() ){
            continue;
        } 
        // 已经找到过
        if(is_find[m]){
            continue;
        }

        for(int n = 0 ; n < prime_ele.size(); n++){
            if(is_find[m]){
                break;
            }
            for(int k = 0 ; k < prime_ele.size(); k++){
                if( ((R_i[m]+R_i[m])%m_i) == ( prime_ele[n] + prime_ele[k])%m_i  ){
                    temp = to_string(R_i[m]) +"+"+ to_string(R_i[m]) + " = " + to_string(prime_ele[n]) + " " + to_string(prime_ele[k]);
                    resu.push_back(temp);
                    is_find[m] = true;
                    break;
                }
            }
        }
    }
    cout << "resu.size()= " << resu.size() << endl;
    return resu;


}

int main()
{


    vector<string> resu;
    cout << "p=  " << p << " q= " << q << endl;
    cal_R_i();
    print_vec(R_i);
    cout << endl;

    cal_p();
    print_vec(unit);
    cout << endl;

    cal_prime_ele();
    print_vec(prime_ele);
    cout << endl;

    resu = cal_pr_pr2();
    print_vec_string(resu);
    


    return 0;
}


void print_vec(vector<int>& unit)
{
    for(auto i : unit){
        cout << i <<  " ";
    }
    cout << endl;
}
void print_set(unordered_set<int>& unit)
{
    for(auto i : unit){
        cout << i <<  " ";
    }
    cout << endl;
}
void print_vec_string(vector<string>& unit)
{
    for(auto i : unit){
        cout << i <<  " " << endl;
    }
    cout << endl;
}