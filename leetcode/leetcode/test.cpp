#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<math.h>
#include<vector>

using namespace std;



int main()
{
   // signed char x = 0xFFFE;
   // printf("%d \n",(x-1));
   // cout  << (x--) << endl;
   // return 0;

   unsigned int a = 20;
   int b = 13;
   int k = b - a ;
   printf("%x \n",(-a+b));


   printf("%d \n", (unsigned int)b +a );
   printf("%d \n", (int)( b +a) );
   printf("%d \n", b + (int)a );
   
}

