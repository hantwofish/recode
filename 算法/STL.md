### MAP

https://blog.csdn.net/wsp_1138886114/article/details/106794899

```c++
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //向 umap 容器添加新键值对
    umap.emplace("Python教程", "http://c.biancheng.net/python/");
    umap.emplace("Java教程", "http://c.biancheng.net/java/");
    umap.emplace("Linux教程", "http://c.biancheng.net/linux/");

    //输出 umap 存储键值对的数量
    cout << "umap size = " << umap.size() << endl;
    //使用迭代器输出 umap 容器存储的所有键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
```
