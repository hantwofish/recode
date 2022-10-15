# -*-coding:utf-8-*-
 
import sys
import you_get
import os
 

    
   
# 中科大郑烇、杨坚全套《计算机网络（自顶向下方法 第7版    
add_vec = [ ]         
str_base = 'https://www.bilibili.com/video/BV1JV411t7ow?p=1'
for index in range(65):
   add_vec.append(str_base + str(index+1))
   
   
# 数据结构与算法 严蔚敏 王卓   
add_vec_2 = [] 
str_base = 'https://www.bilibili.com/video/BV1Fy4y1v7S8?p='
for index in range(173):
   add_vec_2.append(str_base + str(index+1))
 
# 操作系统（汤小丹等第四版）
add_vec_3 = [] 
str_base = 'https://www.bilibili.com/video/BV1th41147T7?p='
for index in range(27):
   add_vec_3.append(str_base + str(index+1))

add_vec_4 = [] 
str_base = 'https://www.bilibili.com/video/BV1Lr4y1S7GM?p='
for index in range(23):
   add_vec_4.append(str_base + str(index+1))

# 人纪-针灸   
add_vec_5 = [] 
str_base = 'https://www.bilibili.com/video/BV1Sb4y1B7zk/?p='
for index in range(81):
   add_vec_5.append(str_base + str(index+1))   


str_1_front = "C--设计模式"

str_2_front = "操作系统（汤小丹等第四版） ("

str_3_front = "中科大郑烇、杨坚全套《计算机网络（自顶向下方法 第7版，James F.Kurose，Keith W.Ross）》课程 (P"

str_4_front = "数据结构与算法 严蔚敏 王卓 ("



def modify_file_name() :
    path = "E:/test/"
    for file_name in os.listdir(path):
        if file_name[-3:] == 'xml':
            continue
        if file_name[0:len(str_1_front)] == str_1_front :
            continue
            
        if file_name[0:len(str_2_front)] == str_2_front :
            new_name = file_name[len(str_2_front):]
            os.rename(file_name,new_name)
            
        if file_name[0:len(str_3_front)] == str_3_front :
            new_name = "中科大_计网"  + file_name[len(str_3_front):]
            os.rename(file_name,new_name)
        if file_name[0:len(str_4_front)] == str_4_front :
            new_name = ""  + file_name[len(str_4_front):]
            os.rename(file_name,new_name)

def download(url, path):
    sys.argv = ['you-get' , '-o' ,path, url]
    you_get.main()
 
if __name__ == '__main__':
    # 视频网站的地址
    #url = 'https://www.bilibili.com/video/BV1DT4y1R7sA?spm_id_from=333.999.0.0'
    # 视频输出的位置
    path = 'E:/films'
    for url in add_vec_5:
        print(url)
        download(url, path)
        print("\n")
    # modify_file_name()
    print("Good Bye")