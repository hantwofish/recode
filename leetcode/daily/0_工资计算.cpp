#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
// ȫ�ֳ���
// ��������һ��˰�ʱ�
//       ���ϱ��գ�ҽ�Ʊ��գ�ʧҵ���գ����˱��գ��������գ����˹�����
// ��˾:  20%       10%       1%       1%        0.8%    12%
// ����:   8%       2%+3      0.2%     0%        0%      12%
const double data_1[6] = {0.08, 0.02, 0.005, 0, 0, 0.12} ; 
// ��˰���
const int data_2 = 60000;
// ��������˰˰��
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
const double data_4 = 0.05; // ��˾���ɹ��������


int main()
{   
    int base = 19000; // ��������
    int Performance = 5000; // ��Ч

    int input_1 = base + Performance; // ��н
    int input_2 = 24000*3; // ����
    
    int output_1 =  input_1 * month + input_2 ; // ˰ǰ��н

    double temp = 0; // �ۼ��籣����
    for(int i = 0 ; i< 5;i++){
        temp += data_1[i];
    }

    cout << "ÿ��" << base << "�������ʽ��ࣺ" << base * (1-(temp + data_1[5])) << endl;
    cout << "---------------------------" << endl;
    
    int output_2; // �ۼ��籣����
    output_2 = base * month * temp;

    int output_3; // �ۼƽ��ɹ���??
    output_3 = base * month * data_1[5];

    int output_4; //Ӧ��˰���ö�
    output_4 = output_1 - data_2 - output_2 - output_3;

    int output_5; // Ӧ�ɸ�˰
    for(int i = 0 ; i < 7 ; i++){
        if(output_4 <= data_3[i][0]){
            output_5 = output_4 * data_3[i][1] - data_3[i][2];
            break;
        }
    }

    int output_6; // ˰����н
    output_6 = output_1 - output_2 - output_3 - output_5;

    // ��ӡ���
    cout << "˰ǰ��н= " << output_1 << endl;
    cout << "˰����н= " << output_6 << endl;
    cout << "��˾������= " << input_1 * data_4 * month << endl;
    cout << "---------------------------" << endl;

    cout << "�籣���ɱ���= " << temp << endl;

    cout << "�ۼ��籣����= " << output_2 << endl;

    cout << "�ۼƹ��������= " << output_3 << endl;

    cout << "Ӧ��˰���ö�= " << output_4 <<endl;

    cout << "Ӧ�ɸ�˰= " << output_5 << endl;

    cout << "˰����н= " << output_6 << endl;

    cout << "˰����н= " << output_6 / 12 << endl;

    cout << "---------------------------" << endl;
    cout << "���Ԥ����ࣺ" << output_6 - (2900 + 1800 + 500)*12 << endl;
    cout << "---------------------------" << endl;
    
    //system("pause");

    return 0;

}