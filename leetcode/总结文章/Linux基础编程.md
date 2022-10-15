
#### Linux常用命令

```shell
sudo apt-get updata #系统自检更新
sudo apt-get upgrade #软件包更新
sudo apt-get dist-upgrade #大版本(内核更新) 系统更新

pwd #列出当前在哪个目录
man pwd # 查看 pwd命令的使用手册
ls #
ls / # 文件目录信息
ls /usr/ # 列出 usr 下目录

cd # 进入目录
cd .#当前目录
cd .. #上一级目录
cd ../..
ls -l #当前目录下文件详细信息
ls a* # 正则匹配，列出a 开头的文件
cp aaa.txt aaaa.bak #拷贝文件
rm #删除
rmdir #删除目录

wget -c http...  #从 ...源下载
mv #文件重命名
mv xxx  xxx 

tail 文件名 #查看文件尾部
tail -f -n 3 文件名 #实时以尾3 行输出显示

#系统方面的命令
ps #查看系统进程的命令
ps -ef #显示所有的进程 ps al

kill # 给另外一个程序发信息
df -h # 磁盘使用情况


```
```shell
# 给上面的两个文件加权限
chmod u+x ./start.sh
chmod u+x ./shut.sh

#在服务器上启动服务
./start.sh
```
#### shell

```shell
#!/bin/bash
gcc main.c -c -Wall -g -o main.o
gcc main.o -o m_exe

```
```shell
# 给上面的两个文件加权限
chmod u+x ./start.sh
```


后台运行
root@vmali:~/code# ./prit.sh 
61466
61467
61468
root@vmali:~/code# nohup ./m_exe > i_5.txt &
