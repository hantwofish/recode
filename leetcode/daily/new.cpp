#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void myprint( vector<vector<int>> data );
void ParseStringToVector(const string& strData, vector<vector<int>>& vecData);
void backtracing(vector<vector<int>>&MYdata,vector<vector<int>>&array ,int lenth  , int index , vector<int>&data);

void Fun(vector<vector<int>>& nums, int count, vector<vector<int>>&MYdata , vector<int>&data);
string decare(const vector<vector<string>> &sets, string add);

void test()
{
    vector<vector<string>> sets={{ "1","2","3"},{"4","5"},{"6","7"}};
    string add ,re;
   re=  decare(sets,add);
 //   cout << re <<endl;

}


int main()
{
    /*
    string str= "3,5,6;7,8;";
    vector<vector<int>> mynums = {{1,2,3},{4,5,6},{7,8,9}};
  //  ParseStringToVector(str,resu);
   // myprint(resu);
    vector<vector<int>>MYdata;
    vector<int>data;
    //backtracing(MYdata,mynums ,mynums.size()  , 0, data);
    Fun(mynums,0 ,MYdata ,data);
    myprint(MYdata);
    */

   test();
    return 0;
}


void myprint( vector<vector<string>> data )
{
    int lent1 = data.size();
    int lenth2 = data[0].size();
    cout << "*********"s
    for(int i = 0 ; i< lent1 ; i++)
    {
        for(int j= 0 ; j< data[i].size() ; j++)
        {
            cout <<data[i][j] << " ";
        }
        cout << endl;

    }   



}
/*
void ParseStringToVector(const string& strData, vector<vector<int>>& vecData)
{
    int size_lenth = strData.length();
    int left = 0;
    int right = 0;
    vector<vector<int >> nums;
    vector<int> temp;
    vector<vector<int>>MYdata; // 最后输出结果；

    while (right < size_lenth) 
    {
        if( strData[right] == ',' )
        {
            temp.push_back( stoi(strData.substr(left,right - left )  ) );
            right ++;
            left = right;
            
        }

        else if( strData[right] == ';' )
        {
            temp.push_back( stoi(strData.substr(left,right - left )  ) );
        //    cout <<" ; front = " <<  stoi(strData.substr(left,right - left )  ) << endl;
            nums.push_back(temp);

            temp.clear();
            right++;
            left = right;
            
        } 
        else if(strData[right]  >= '0' && strData[right] <= '9' )
        {
            right++;
        }
        else
        {
            cout <<"error " ;
        }
     //   cout << "right=   "<<right << endl;

    }
    myprint(nums);
    
   


}

void backtracing(vector<vector<int>>&MYdata,vector<vector<int>>&array ,int lenth  , int index , vector<int>&data)
{
    if( index == lenth   )
    {
        MYdata.push_back(data);
        // data.clear();

        return;
    }

    for(int i = 0; i < array[index].size(); i++)
    {
        data.push_back(array[index][i]);
        backtracing(MYdata, array ,lenth ,index+1 , data );
    }





}

void Fun(vector<vector<int>>& nums, int count, vector<vector<int>>&MYdata , vector<int>&data)
{
    vector<int> current =nums[count];
    for(int i = 0 ; i<current.size(); i++)
    {
        if(count + 1 < nums.size())
        {
            data.push_back( current[i] );
            Fun( nums,count + 1 , MYdata , data  );
        }
        else
        {
            data.push_back( current[i] );
         
            MYdata.push_back(data);
            data.clear();
        }
    }

}
*/
string decare(const vector<vector<string>> &sets, string add)
{
	vector<vector<string>> rs;
	int n = sets.size();
	vector<string> tmp;
	string word, result;
	for (int i = 0; i < n; ++i)
	{
		tmp.push_back(sets[i][0]);
	}
	rs.push_back(tmp);
	for (int i = n - 1; i >= 0; --i)
	{
		int nRsSize = rs.size();
		for (int k = 1; k < sets[i].size(); ++k)
		{
			for (int j = 0; j < nRsSize; ++j)
			{
				tmp = rs[j];
				tmp[i] = sets[i][k];
				rs.push_back(tmp);
			}
		}
	}
    /**/
    myprint(rs) ;





    /**/
	for (vector<vector<string> >::iterator iter = rs.begin(); iter != rs.end(); iter++)
	{
		word += add;
		for (int i = 0; i < (*iter).size(); i++)
		{
			word += (*iter)[i] + " ";//词之间添加空格
		}
		if (iter != rs.end() - 1) {
			word += "\n";//末尾不需要换行
		}
		else {
			word += "";
		}
	}
	return word;
}