#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<list>
using namespace std;
// 自定义排序规则
bool my_sort(pair<int,int>&A, pair<int,int>&B)
{
    return A.first > B.first;
}

void test_string()
{
    string s = "abcsdd" ;
    string str = s.substr(3, 2);
    if(s.find(str) == s.npos){
        cout << "not found" << endl;
    }else{
        cout << "found " << s.find(str) << endl;
    }
    
}

void test_set()
{
    set<int>m_set;
    multiset<int>a;
    unordered_multiset<int>b;
    int nums[] = {11,3,5,4,20,4};
    for(int i = 0 ; i < sizeof(nums)/sizeof(int) ; i++){
        m_set.insert(nums[i]);
    }
    set<int>::iterator it = m_set.begin();
    for(int i = 0 ; i < m_set.size() ; i++){
       //  cout << m_set[i] << endl; //  error
       cout << *(it++)<< " ";
    }
    it = m_set.begin();
    while(it != m_set.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;

}

void test_unorder_set()
{
    unordered_set<int>m_set;
    int nums[] = {11,3,5,4,20,4,3};
    for(int i = 0 ; i < sizeof(nums)/sizeof(int) ; i++){
        m_set.insert(nums[i]);
    }
    unordered_set<int>::iterator it = m_set.begin();
    for(int i = 0 ; i < m_set.size() ; i++){
       //  cout << m_set[i] << endl; //  error
      // cout << *(it++)<< " ";
    }
    it = m_set.begin();
    while(it != m_set.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;

}

void test_list()
{
    list<int>m_list;
    m_list.push_back(1);
    m_list.push_back(2);
    m_list.push_front(3);
    //
    list<int>::iterator it = m_list.begin();
    while(it != m_list.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;
    cout << " count= " << m_list.size() ;


}

int main()
{
    //test_string();
    //test_set();
    //test_unorder_set();
    test_list();
    return 0;
}

/*
1. list
https://www.cnblogs.com/qi09/archive/2011/01/21/1941065.html

*/