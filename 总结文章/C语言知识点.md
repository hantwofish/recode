
#### 数据存储

|       字节数       | 32位系统 | 64位系统 |
| :----------------: | :------: | :------: |
|        char        |    1     |          |
|   unsigned char    |    1     |          |
|       short        |    2     |          |
|   unsigned short   |    2     |          |
|        int         |    4     |          |
|    unsigned int    |    4     |          |
|        long        |    4     |    8     |
|   unsigned long    |    4     |    8     |
|       float        |    4     |          |
|       double       |    8     |          |
|     long long      |    8     |          |
| unsigned long long |    8     |          |

+ 负数的存储

负数的存储以补码形式存储（正数的反码加一）


#### 表达式 类型自动转换

```c++
1.参与运算的类型不同，先转换成相同类型再运算
2.数据类型向数据长度增长的方向转换，char -> short -> int -> unsinged int -> long
3.所有float都会先转成double进行运算，哪怕只有一个float
4.赋值运算时候，赋值号右边类型向左面的类型转换
5.浮点数和整形数，整型数向浮点数转换
6.在表达式中，如果char和short 类型的值进行运算，无论char和short有无符号，结果都会自动转换成int
7.如果 char 或 short 与 int 类型计算，结果和int类型相同。(即：如果int是有符号的，结果则是带符号的，如果int是无符号的，结果就是无符号的)。
8.同一类型，有符号数和无符号数运算，有符号数向无符号数转变
https://blog.csdn.net/wangjiaweiwei/article/details/106316474

```

```c++
char(1) short(2) int(4) long(4) float(4) double(8)
```

```c++
int main2()
{
   int i = -1;
   for( ; i < sizeof(int) ; i++){
      printf("%d\n", i);
   }

   unsigned int a = 6;
   int b = -20;
   int c = a + b;

   printf("a+b= %u\n",(a+b));

   if(a+b >0 ){
      printf("a+b>0 \n");
      cout << a+ b << endl;
   }else{
      printf("a+b<=0 \n");
   }


   cout << c << endl;
   return 0;
}
```

#### 宏

#### 枚举
+ 枚举类型大小
枚举的大小和编译器，编译选项有关系，具体大小无法统一确定。

+ 枚举的值
规则：
```
1.枚举的第一个值如果没有定义，则从0开始
2.枚举的值如果指定，那么就是指定值
3.枚举的值如果未指定，则为上一个值加一
4.同一个枚举下面的值可以相同。
```

#### 结构体
+ 结构体对齐

+ 为什么结构体对齐

+ 结构体大小计算
规则如下：
1. 结构体成员对齐，第一个结构体成员的应该放在偏移地址为0 的地方，往后的每个结构体成员需要从最小长度min_L的整数倍的地方开始存放。min_L通过是该数据类型的长度和计算机默认存储模式长度取最小值确定（比如32位机器中int型占4个字节，机器默认存储是8个字节，那么存储是按照4的整数倍进行，如果机器默认存储是2个字节，那么存储是按照2的整数倍进行）

2. 结构体的总大小，即sizeof()的计算结果，是结构体内部占用最大字节的数据类型长度和机器默认存储模式字节长度的最小值的整数倍，不足需要补齐。

```c++
//假设默认存储8个字节// #pragma pack (8)
typedef struct_STUDENT1{
int a ;// 从4的倍数开始，0-3
char b://从1的倍数开始，4（实际占用4-7）
double c;//从8的倍数开始，8-15
float d;//从4的倍数开始，16（16-19）
}Student1；
//结构体内部对齐后大小20个字节（0-19）；整体对齐，要满足最大字节类型的整数倍，即8的整数倍，故为24，即sizeof（student）=24
————————————————
//假设默认存储8个字节//
typedef struct_STUDENT1{
int a ;// 从4的倍数开始，0-3
char b://从1的倍数开始，4（实际占用4-7）
int add; // 从4的倍数开始，8-11
double c;//从8的倍数开始，16-23
float d;//从4的倍数开始，24（24-27）
}Student1；
//结构体内部对齐后大小28个字节（0-27）；整体对齐，要满足最大字节类型的整数倍，即8的整数倍，故为32，即sizeof（student）=32
```
3. 结构体嵌套时，如果结构体M中包含结构体N，还是按照最大字节成员类型大小对齐，但是结构体N的起点为N内部最大字节成员的整数倍（如，结构体M中嵌套结构体N，N中有int char 和double ，那么N应该从8的整数倍开始）

```c++
typedef struct_STUDENT2{
char a ;// 从1的倍数开始，0（0-7）
Student b://从内部成员最大字节整倍数开始，即从8开始存储，（占用第8-31字节）
double c;//从8的倍数开始，即32-39
}Student2；
//结构体内部对齐后大小40个字节（0-19）；整体对齐，要满足最大字节类型的整数倍，即8的整数倍，故为40，即sizeof（student）=40
————————————————
版权声明：本文为CSDN博主「小重拌豆腐」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_41535111/article/details/120772706
```

#### 联合体

结构体和共用体的区别在于：结构体的各个成员会占用不同的内存，互相之间没有影响；而共用体的所有成员占用同一段内存，修改一个成员会影响其余所有成员。

结构体占用的内存大于等于所有成员占用的内存的总和（成员之间可能会存在缝隙），共用体占用的内存等于最长的成员占用的内存。共用体使用了内存覆盖技术，同一时刻只能保存一个成员的值，如果对新的成员赋值，就会把原来成员的值覆盖掉。
————————————————
版权声明：本文为CSDN博主「徐昊Xiho」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u011974987/article/details/52305364

```c++
union 共用体名{
    成员列表
};
```

+ 小端模式与大端模式
大端序：数据是以高位数据放到低位地址。
小端序：数据是以高位数据放大高位地址，低位数据放到低位地址。
注意：现在一般使用的主机都是小端序，内存存储数据都是从低位开始对低位数据先存储。

如何使用代码去验证主机的大小端序：

原理：从上面的联合体中可以知道所有成员都使用同一块内存，所以只要将数据存入到内存中再从低位读出数据就可以知道数据的存储的端序。
————————————————
版权声明：本文为CSDN博主「小Armand」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_37552254/article/details/106169378

```c++
union num
{
   int a;
   unsigned char b;
}
int main(int argc,const char **argv)
{
     union num aaa;
     aaa.a = 0x12345678;
     printf("0x%x",aaa.b);
}
```
如果打印结果是0x78则是小端序机
如果打印结果是0x12则是大端序机

+ sizeof()

#### 精简习题

```c++
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <typeinfo>
#include <cstring>
using namespace std;
// 定义一个类型 这种类型是指针类型，指针指向数组，数组中三个int元素
typedef int(*ptr_array_three)[3]; 

#pragma pack (2)

struct Student {
        short int num;
        char sex;
        short int data;
        char aaa;
};


void test02()
{
    signed char x = 0xFFFE;
    printf("%d \n" ,x--); // -2
}
void test03()
{
    unsigned short i = 65535;
    printf("%d \n", i); // 65535

    unsigned short j = 65535;
    printf("%d \n", j); // -1

    char p[20] = {'a','b','c','d',0};
    char q[] = "abc";
    char r[] = "abcde";
    strcat(p,r);
    strcpy(p+strlen(q), q);
    printf("%d \n",sizeof(p));

    unsigned int a = 20;
    int b = 13;
    int k = b - a;
    k < (unsigned int)b + a; // false
    k < (int)(b + a); // true
    k < b + (int) a ; // true;
}

void test06()
{
    struct tagSmart
    {
        char flag1;
        int (*left_tree)[3];
        struct  tagSmart* right_tree[2];
        char flag3;
        char flag4;   
    }SmartFlag[4];
    cout << sizeof(SmartFlag) << endl;

    // 四字节对齐，二字节对齐，一字节对齐，结构体大小为 8 8 6
    struct student {
        short int num;
        char sex;
        short int data;
        char aaa;
    };
    
}

int main()
{
   char str[] = "\\\\";
   cout << sizeof(str) << endl; // \为转义字符，一共两个斜杠，加一个"\0"

    cout << "Student = " << sizeof(Student) << endl;
    return 0;

}
```

#### 关键字以及关键点

#### 指针


#### const
C++ const 允许指定一个语义约束，编译器会强制实施这个约束，允许程序员告诉编译器某值是保持不变的。如果在编程中确实有某个值保持不变，就应该明确使用const，这样可以获得编译器的帮助。
##### 1. 修饰普通变量
```c++
const int a = 7;
int  b = a; // 正确
a = 8;       // 错误，不能改变
```
a 被定义为一个常量，并且可以将 a 赋值给 b，但是不能给 a 再次赋值。对一个常量赋值是违法的事情，因为 a 被编译器认为是一个常量，其值不允许修改。

```c++
#include<iostream>
 
using namespace std;
 
int main(void)
{
    const int  a = 7;
    int  *p = (int*)&a;
    *p = 8;
    cout<<a;
    system("pause");
    return 0;
}
```

##### 2.修饰指针变量
`左定值，右定向，const修饰不变量`

##### 3.const参数传递和函数返回值
+ const修饰函数参数情况

A.

B. 修饰指针
```c++
void Cpf1(int const *a)
{
    cout<<*a<<" ";
    *a = 9;// error 左定值，值不可修改
    a = nullptr;
    
}

void Cpf1(int * const a)
{
    cout<<*a<<" ";
    *a = 9;
    int b = 0;
    a = &b; // 右定向，指向不可修改
    
}
```

C.

+ const修饰函数返回值


##### 4.const修饰类成员函数


参考：https://www.runoob.com/w3cnote/cpp-const-keyword.html

#### static

#### typedef

```cpp

/*
typedef 与  #define 的区别 

*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int* pint;
#define PINT int *

int i1= 1;
int i2 =2;

const pint p1 = &i1; // int * const p; 指针是一个常量，不可以修改
const PINT p2 = &i2; // const int* p2; 无法通过指针改变，所指向的值

pint s1 , s2; // s1 和 s2 都是 int 型指针  int * s1 和 int* s2;
PINT s3 , s4; //相当于int * s3，s4；只有一个是指针

void testPointer()
{
    cout << "p1:  " <<p1 << "  *p1 " << *p1 <<endl;
    // p1 = &i2; // erroe;
    *p1 = 5;
    cout << "p1:  " <<p1 << "  *p1 " << *p1 <<endl;

    cout << "p2:  " <<p2 << "  *p2 " << *p2 <<endl;
    //*p2 = 10 ; // error
    p2 = &i1;
    cout << "p2:  " <<p2 << "  *p2 " << *p2 <<endl;



}





void test()
{
    int a[5] ={0,1,2,3,4};
    int b[5] ={0,1,2,3,4};
    // a = b; // error; 数组名是地址，并且 是一个不可以修改的指针 

}




int main()
{

   // test();
    testPointer();
    cout <<"hello555 " << endl;
    return  0;
}


/*
/////////////////////////
判断 const 后面的内容

const 与 星号有两种关系：
1： 指针不可修改。（指针与变量之间的指向关系固定）
2： 不可以通过指针对变量进行修改


const 在一个变量前面，则这个变量不能被修改。
const int a = 12;

当带有星号时候，判断依据是  const 在 * 前面还是后面。
* 号前面
常量指针： p 指向的内容不能通过 p 来修改（但可以修改，只是不能通过 P 来修改）
（理解： *p 是一个变量， 属于不能通过指针修改变量）
const char * p;
char const * p;


* 后面
指针常量：p 是一个指针，不可以被修改。
（理解： p  是一个指针变量，加上 const 之后，就是指针变量变成常量，不可以修改）
char * const p;


//////////////// 
函数中带 const 参数,无法修改，形参的值，形参引用 的值，以及形参指针所指向的值

void fs(const int &i);
void fs(const int* p);



*/
```

+ typedef 重新定义类型

```c++
// typedef 判断时候，将typedf 暂时去掉
typedef unsigned char BYTE;

typedef int NUM[100]; // 定义NUM 为整型数组类型
NUM n; // 定义n 为整型数组变量，原先需要定义为： int n[100];

typedef char *PSTRING; // 定义 PSTRING 为字符指针类型
PSTRING p , q; // char * p; char *q;

typedef int (*POINTER)(); // 定义 POINTER为 指向函数的指针类型，函数返回值为整数型
POINTER p1,p2;

typedef void (*V_FP_CHARP)(char *);

// 函数数组指针混合
typedef char (* FRPTC()) [5]; // FRPTC声明为一个函数类型，该函数返回一个指针
// 该指针指向内含5 个char 类型元素的数组

typedef int (*testCases[10])(); // 定义了数组，testCases[10],数组中的元素是函数指针，
// 函数指针的类型是 int (*)(),函数参数为空，返回值为int

int (*pt1)(void);
//pt1 = nullptr; // error
double (*pdf)(double);
//pdf = sin;// error函数体外只能进行如变量或函数定义声明等，不能执行语句或调用函数！！！


int func_1()
{
    return 1;
}
int func_2(void)
{
    return 2;
}
double func3 (double a)
{
    return 3.0;
}


void func(int (*pt1)(), int (*pt2)())
{
    p1 = nullptr;
    p1 = pt1;
    
    int resu = (*p1)(); // 函数调用
    resu = p1();
    resu += (*pt2)();
    cout << resu<< endl;
    cout << "hello" << endl;
}

void test( int(* pt1)(), double (*pt2)(double) )
{
    pt1 = func_1;
    pt2 = func3;

}

int main()
{
    func(func_1, func_2);
  return 0;

}

```

+  `* () [] ` 优先级问题

这三者优先级有低到高：`* < () = []`，而且他们与变量名的结合是从左到右的

```c++

int foo[12][24]; // 一个数组12*24
int *p; // 一个指针，指向 int 类型
int **ptr; // 一个指针，指向一个指针(指向int类型)
int * strings[5]; // 一个数组，数组中元素为指针，指向int类型
int (* pointer)[5]; // 一个指针，指向一个int(*)[5]类型数组
int * bar[12][14]; // 一个数组，数组中元素均为指针，指向int类型
int (* pp)[12][24]; // 一个指针，指向int(*)[12][24]数组
int (* ppp[3])[4]; // 一个数组，每个数组中元素均为指针，指向int(*)[4]类型数组

char *func(); //函数声明，返回值为char*
char (* funcp) ();//一个指针，该指针指向一个返回类型为char的函数
char (* funcps[3]) ();//一个数组，共3个元素，每个元素是一个指针，指针指向一个返回值为char的函数


typedef int array5[5];
typedef array5 * p_to_array5;
typedef p_to_array5 arrayp[10];

array5 foo;//foo是一个int[5]数组
p_to_array5 p;//p是一个指向int[5]数组的指针
arrayp array;//array是一个数组，共10个元素，每个元素是一个p_to_array5指针

```


+ 函数与指针

指针可以指向函数。指向函数的指针保存着函数代码起始处的地址。当声明一个函数指针时，必须声明它指向的函数类型，即指定函数的返回类型以及函数的参量类型。
void eat(char * food);声明了一个形式参量为字符指针的的函数，要声明一个指向这样类型函数的指针，需要这样做：
void (* pointer) (char *);

声明一个指向特定函数类型的指针，首先声明一个该类型的函数，然后用(* pf)形式的表达式替换函数名称，pf就成为了可指向那种类型函数的指针了。

声明了指针之后，还需对指针进行赋值，赋值给指针的函数必须拥有与指针声明中一致的形参和返回值。

函数指针作为参数
有了函数的指针，可以利用指针来访问函数：

通过 (*pf) (参数)的方式访问函数
通过 pf (参数)的方式访问函数

```c++
#include <stdio.h>

void toUpper(char *);
void toLower(char *);
void foo( void (*pf)(char *),char * string);
int main() {
    void (*pf) (char *);
    
    char test[] = "I love you";
    
    pf = toUpper;
    
    (* pf)(test);//1
    
    pf = toLower;
    
    pf(test);//2
    
    foo(pf,test);//foo函数调用
}
/*
 * foo接受一个函数指针与char指针
 */
void foo( void (*pf)(char *),char * string){
    pf(string);
    puts(string);
}

```

+ 数组名与指针
```c++
int B [3][12][24];
// B : int(*)[12][24] 类型指针
// B[0] : int(*)[24] 类型指针
// B[0][0] : int* 指针

```

```c++
int func1()
{
    int array[2][3][4];
    int num = 0;
    // for(int num = 0 ; num< 24 ; num ++){
    //     array[i/2][i/3][i/4] = num;
    //     i++;
    // }
    for(int i = 0; i< 2 ;i++){
        for(int j = 0 ; j < 3; j ++){
            for(int k = 0; k < 4; k++){
                array[i][j][k] = num  ;
                num++;
            }
        }
        cout << endl;
    }
    for(int i = 0; i< 2 ;i++){
        for(int j = 0 ; j < 3; j ++){
            for(int k = 0; k < 4; k++){
                cout << array[i][j][k] << " " ;
            }
        }
        cout << endl;
    }
    cout << endl;

    int (* pp)[3][4]; // 一个指针，指向int(*)[3][4]数组
    pp = array;
    cout << *(*(*(pp+1)+2)+2) << endl; // array[1][2][2]

    int (* ptr)[4];
    ptr = array[1];
    cout << *(*(ptr + 1)+ 3) << endl; // array[1][1][3];

    int * ptr1 = nullptr;
    ptr1 = array[1][2];
    cout<< *(ptr1 + 2) << endl;// array[1][1][2]

    return 0;

}

int main()
{
    func1();    
    return 0;
}
```


参考：https://www.cnblogs.com/bobliao/p/9932197.html#%E5%87%BD%E6%95%B0%E4%B8%8E%E6%8C%87%E9%92%88



