# -*-coding:utf-8-*-
# 此文件必须位于所在文件夹内
name = "John" # 字符串
str_len = len(name)
print (str_len)
print (name)

str_1 = "人纪-③黄帝内经-倪海厦（DVD原版） (P7. 人纪-黄帝内经07-倪海厦).flv"
str_2 = "黄帝内经07-倪海厦).flv"
str1_len = len(str_1)
print(len(str_1))
print(len(str_2))

import os,sys
path = "E:/aa/"
for file in os.listdir(path):
    if file[-3:] == 'xml':
        continue
    new_name = file[-len(str_2):]
    os.rename(file,new_name)


str_2 = "辅行诀 ("
for file in os.listdir(path):
    if file[-3:] == 'xml':
        continue
    # file.replace(" ","")
    if file[0:len(str_2)] != str_2 :
        continue
    new_name = file[len(str_2):]
    new_name.replace(" ","") #删除空格
    print(file)
    print(new_name)
    os.rename(file,new_name)
    
  