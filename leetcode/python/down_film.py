# -*-coding:utf-8-*-
 
import sys
import you_get
import os

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
    url = 'https://v.qq.com/x/cover/mzc00200gjcj7je.html'
    # 视频输出的位置
    path = 'E:/test'
    
    print(url)
    download(url, path)
       
    # modify_file_name()
    print("Good Bye")