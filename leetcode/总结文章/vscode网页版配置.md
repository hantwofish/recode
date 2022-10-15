### code-server
[参考^]
[参考^]:[参考](https://blog.csdn.net/weixin_43988498/article/details/110305091)
1. 软件
链接：https://pan.baidu.com/s/1rSLwyAdl41aTNNG8XR8Dzg 
提取码：xnqz
2. 安装

安装软件：
```
# 创建文件夹下载code server安装包 或者 从百度云中下载
wget https://github.com/cdr/code-server/releases/download/3.2.0/code-server-3.2.0-linux-x86_64.tar.gz 



# 解压到一个你想放置的地方
tar -xvzf code-server-3.2.0-linux-x86_64.tar.gz

# 进入解压文件夹，改一下名字吧
cd ..
mv code-server-3.2.0-linux-x86_64 code-server

# 进去，写两个脚本文件，一个启动，一个关闭   见下方
cd code-server 
vim ./start.sh
vim ./shut.sh

```

软件目录如下：
```
root@vmali:~/han/code-server/code_server# cd ..
root@vmali:~/han/code-server# ls
code_server                            code-server.log  shut.sh
code-server-3.11.1-linux-amd64.tar.gz  save_pid.txt     start.sh
root@vmali:~/han/code-server# 

```

start.sh
```
export PASSWORD="xxx12346789xxxx"			# 写你的code-server登录密码
nohup ./code-server --port 9999 --host 0.0.0.0 --auth password > run.log 2>&1 & 		# 端口可以自己指定，其他不改，后台运行
echo $! > save_pid.txt		
```

shut.sh
```
kill -9 'cat save_pid.txt'  # 关闭这个进程，关闭code-server服务
```
下一步: 启动服务与打开服务器端口
```
# 给上面的两个文件加权限
chmod u+x ./start.sh
chmod u+x ./shut.sh

#在服务器上启动服务
./start.sh
```

服务器中需要打开端口；
阿里云-> 控制台-> 配置安全组规则-> 配置规则-> 入方向 -> 加入配置的端口号

#### 测试
浏览器 公网ip:端口号
