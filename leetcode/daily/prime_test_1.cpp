#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
#include<map>
#include<unordered_set>
#include<algorithm>
// 计算单位 素元
using namespace std;


//vector<int> prime_list={2,3,5,7,11,13,17};
//int p = 2;
//int q = 3; 
//int  m_i =801;
vector<int> R_i; //  全部集族
vector<int> unit; // 单位
vector<int> prime_ele; // 素元



void print_vec(vector<int>& unit);
void print_set(unordered_set<int>& unit);
void print_vec_string(vector<string>& unit);



// 计算R_i;
void cal_R_i(int m_i)
{
    R_i.clear();
    cout << "m_i= " <<  m_i << endl;
    for(int k = 0 ; k< m_i ; k++){
        R_i.push_back(k);
    }
}




// 计算单位
void cal_unit(int m_i)
{
    unit.clear();
    for(int i = 0 ; i < R_i.size() ; i++){
        int cur_num = R_i[i];
        for(int j = 0 ; j < R_i.size(); j++ ){
            if((cur_num * R_i[j])%m_i == 1){
//                cout << cur_num << "*" << R_i[j] << "= 1" <<  endl;
                unit.push_back(cur_num);
            }
        }
    }
    cout << "danwei " << unit.size() << endl;
}

bool is_unit(int test_num){
    if( find(unit.begin(),unit.end(),test_num) != unit.end() ){
        return true;
    }
    else{
        return false;
    }

}
// 是否存在真分解
bool exists_fenjie(int test_num,int m_i)
{
    // 所有分解的形式 不存在真分解
    for(int  m = 0; m < R_i.size() ; m++){
        for(int n = 0 ; n < R_i.size(); n++){
            if( (R_i[m]*R_i[n])%m_i == test_num ){
                if( (!is_unit(R_i[m]))&& (!is_unit(R_i[n]))  ){
//                    cout << test_num << " = " << R_i[m] << " * " << R_i[n] <<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

// 计算素元。
void cal_prime(int m_i)
{
    prime_ele.clear();
    for(int i = 0 ; i < R_i.size(); i++){
        int cur_num = R_i[i];
        if(cur_num == 0){
            continue;
        }
        // 单位
        if( find(unit.begin(),unit.end(),cur_num) !=unit.end() ){
            continue;
        }
        if( exists_fenjie(cur_num,m_i) ){
            continue;
        }else{
            prime_ele.push_back(cur_num);
        }

    }
    cout << "suyuan "<< prime_ele.size() << endl;
}

// 验证G
bool is_fit_G(vector<int>& R_i)
{
   return false;
}




void print_vec(vector<int>& unit)
{
    for(auto i : unit){
        cout << i <<  " ";
    }
    cout << endl;
}
int main()
{
    int m_i = 5*5*5;
 
    for(int num = m_i; num <= m_i ; num++){
        m_i = num;
        cal_R_i(m_i);
        print_vec(R_i);
        cal_unit(m_i);
        print_vec(unit);
        cal_prime(m_i);
        print_vec(prime_ele);

        if(is_fit_G(R_i)){
            cout << "mi= " << m_i << "  fit" << endl;
            break;
        }
    }
    return 0;
        
}