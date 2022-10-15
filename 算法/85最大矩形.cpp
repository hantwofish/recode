#include"STLCOMMON.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        cout << matrix.size() << " " << matrix[0].size() << endl;
        int resu = 0;
        for(int rowStart = 0; rowStart < matrix.size(); rowStart++){
            for(int rowEnd = rowStart ;rowEnd < matrix.size(); rowEnd++){
                for(int colStart = 0; colStart < matrix[0].size(); colStart++){
                    for(int colEnd  = colStart; colEnd < matrix[0].size(); colEnd++){
                        //cout << "rowStart= " << rowStart << " rowEnd= " << rowEnd << " colStart= " << colStart << " colEnd= " << colEnd <<endl;
                        if(isFillOne(rowStart, rowEnd, colStart, colEnd,matrix)){
                            //cout << "rowStart= " << rowStart << " rowEnd= " << rowEnd << " colStart= " << colStart << " colEnd= " << colEnd <<endl;
                            int temp = (rowEnd- rowStart +1)*(colEnd - colStart +1);
                            //cout << "temp = " << temp << endl;
                            resu = max(resu,temp);
                        }
                    }

                }
            }
        }
        
        return resu;
    }
    bool isFillOne(int rowStart, int rowEnd, int colStart, int colEnd, vector<vector<char>> matrix)
    {
        for(int i = rowStart; i <= rowEnd ; i++){
            for(int j = colStart; j <= colEnd; j++){
                if(matrix[i][j] == '0'){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    // vector<vector<char>> matrix = 
    //     {{'1','0','1','0','0'},{'1','0','1','1','1'},
    //     {'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> matrix = {{'0'}};
    int resu = s1.maximalRectangle(matrix);
    cout << "resu= " << resu << endl;
    return 0;

}