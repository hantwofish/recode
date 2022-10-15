#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void myprint( vector<vector<int>> data )
{
    int lent1 = data.size();
    int lenth2 = data[0].size();
    cout << "*********" <<endl;
    for(int i = 0 ; i< lent1 ; i++)
    {
        for(int j= 0 ; j< data[i].size()- 1; j++)
        {
            cout <<data[i][j] << ",";
        }
        cout << data[i][data[i].size()- 1];
        cout << endl;

    } 
     cout << "*********" <<endl;  



}
vector<vector<int>> decare(const vector<vector<int>> &sets);
//vector<vector<int>> dele(string& strData);



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
    vecData = decare(nums);
    myprint(vecData);
    
   


}



int main()
{
    string str= "3,5,6;7,8;";
    vector<vector<int>> vecData;
    ParseStringToVector(str,  vecData);

    return 0;
}



vector<vector<int>> decare(const vector<vector<int>> &sets)
{
	vector<vector<int>> rs;
	int n = sets.size();
	vector<int> tmp;
//	string word, result;
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





   
    return rs;
}



