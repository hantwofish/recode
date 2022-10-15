#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
// 全局常量
// 个人五险一金税率表
//       养老保险，医疗保险，失业保险，工伤保险，生育保险，个人公积金
// 公司:  20%       10%       1%       1%        0.8%    12%
// 个人:   8%       2%+3      0.2%     0%        0%      12%
const double data_1[6] = {0.08, 0.02, 0.005, 0, 0, 0.12} ; 
// 免税金额
const int data_2 = 60000;
// 个人所得税税率
const double data_3[7][3]= {
    {36000,        0.03,    0},
    {144000,       0.1,    2520},
    {300000,       0.2,    16920},
    {420000,       0.25,   31920},
    {660000,       0.3,    52920},
    {960000,       0.35,   85920},
    {INT32_MAX,    0.45,   181920}

};
const int month =12;
const double data_4 = 0.05; // 公司缴纳公积金比率


int main()
{   
    int base = 19000; // 基本工资
    int Performance = 5000; // 绩效

    int input_1 = base + Performance; // 月薪
    int input_2 = 24000*3; // 年终
    
    int output_1 =  input_1 * month + input_2 ; // 税前年薪

    double temp = 0; // 累计社保比例
    for(int i = 0 ; i< 5;i++){
        temp += data_1[i];
    }

    cout << "每月" << base << "基本工资结余：" << base * (1-(temp + data_1[5])) << endl;
    cout << "---------------------------" << endl;
    
    int output_2; // 累计社保缴纳
    output_2 = base * month * temp;

    int output_3; // 累计缴纳公积??
    output_3 = base * month * data_1[5];

    int output_4; //应纳税所得额
    output_4 = output_1 - data_2 - output_2 - output_3;

    int output_5; // 应纳个税
    for(int i = 0 ; i < 7 ; i++){
        if(output_4 <= data_3[i][0]){
            output_5 = output_4 * data_3[i][1] - data_3[i][2];
            break;
        }
    }

    int output_6; // 税后年薪
    output_6 = output_1 - output_2 - output_3 - output_5;

    // 打印输出
    cout << "税前年薪= " << output_1 << endl;
    cout << "税后年薪= " << output_6 << endl;
    cout << "公司公积金= " << input_1 * data_4 * month << endl;
    cout << "---------------------------" << endl;

    cout << "社保缴纳比例= " << temp << endl;

    cout << "累计社保缴纳= " << output_2 << endl;

    cout << "累计公积金缴纳= " << output_3 << endl;

    cout << "应纳税所得额= " << output_4 <<endl;

    cout << "应纳个税= " << output_5 << endl;

    cout << "税后年薪= " << output_6 << endl;

    cout << "税后月薪= " << output_6 / 12 << endl;

    cout << "---------------------------" << endl;
    cout << "年底预算结余：" << output_6 - (2900 + 1800 + 500)*12 << endl;
    cout << "---------------------------" << endl;
    
    //system("pause");

    return 0;

}