#include"STLCOMMON.h"

using namespace std;

void test_map()
{
    auto i = make_pair(3,"2");
    unordered_map<int,pair<int,string>> unor_map;
    unor_map.insert( {1, make_pair(3,"-")}  );
    unor_map.insert(  pair<int,pair<int,string>>(3,i)      );
    unor_map.insert(  pair<int,pair<int,string>>(0,   pair<int,string>(2,"2")   )   );

    unor_map.erase(2);

    for(auto it = unor_map.begin(); it != unor_map.end(); it++){
        cout << "first= " << it->first << endl;
    }



}

int main()
{
    test_map();
    return 0;
}