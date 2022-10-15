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
vector<vector<int>> decare(const vector<vector<int>> &sets);

void test()
{
    vector<vector<int>> sets={{1,2,3},{4,5},{7,8,9}};
    vector<vector<int>> re;
    re=  decare(sets);
    myprint(re);

}


int main()
{


   test();
    return 0;
}


void myprint( vector<vector<int>> data )
{
    int lent1 = data.size();
    int lenth2 = data[0].size();
    cout << "*********" <<endl;
    for(int i = 0 ; i< lent1 ; i++)
    {
        for(int j= 0 ; j< data[i].size() ; j++)
        {
            cout <<data[i][j] << " ";
        }
        cout << endl;

    } 
     cout << "*********" <<endl;  



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



