# 参考博客园链接
# -*-coding:utf-8-*-
# 此文件必须位于所在文件夹内
'''
str_0 = "操作系统（汤小丹等第四版） (P1. 操作系统1-第一章1).flv"
str_1 = "操作系统（汤小丹等第四版） (P1. "
print(str_0)
print(str_0[len(str_1):])

str = "中科大郑烇、杨坚全套《计算机网络（自顶向下方法 第7版，James F.Kurose，Keith W.Ross）》课程 (P1. 课程目标).flv"


name = "John" # 字符串
str_len = len(name)
print (str_len)
print (name)
str1_len = len(str_1)
print(len(str_1))
print(len(str_2))
'''
str_1_front = "C--设计模式"

str_2_front = "操作系统（汤小丹等第四版） ("

str_3_front = "中科大郑烇、杨坚全套《计算机网络（自顶向下方法 第7版，James F.Kurose，Keith W.Ross）》课程 (P"


str = "P4. 操作系统4-第二章2).flv"


import os,sys
path = "E:/test/"
for file_name in os.listdir(path):
    if file_name[len("P10. "):len("P10. 操作系统")] == "操作系统":
        #new_name = ""  + file_name[len("P4. "):]
        #os.rename(file_name,new_name)
        continue
    if file_name[0:len("P")] == "P" :
        new_name = "算法"  + file_name
        os.rename(file_name,new_name)
        

 

