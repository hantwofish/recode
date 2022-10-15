<!--
 * @Author: your name
 * @Date: 2021-06-24 13:26:49
 * @LastEditTime: 2021-06-24 13:52:15
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\md_readme\vscode配置c++环境.md
-->
#### 安装git 已经创建远程仓库
1. 安装 git

    1.1. 配置本机上传时候的用户名和email
    ```
    git config --global user.name "xiaoming"
    git config --global user.email "xiaoming@example.com"
    ```

    1.2. 生成 ssh 密钥
    ```
    ssh-keygen -t rsa -C "xiaoming@example.com"
    ```
    回车，存放与默认路径

    
    
2. git 与 gitee 联合使用
    2.1 gitee(github)网站创建仓库
    2.3 配置公钥与密钥用于上传
        把ssh密钥添加到码云(过程如下：)
        打开C盘–>用户–>你的用户名–>找到.ssh文件夹。
        找到id_rsa.pub，用记事本打开，复制整个文本粘贴到gitee（
        点头像，进入gitee设置面板，SSH公钥设置，
        将复制的文本粘贴到公钥，标题会自动生成，然后点击添加，根据提示输入密码就可以了。）
    2.4 测试
        `ssh -T git@gitee.com`
    
3. git 实战
   
   
    ```shell
        git pull origin master # 拉取远程仓库的与本地合并，推荐使用 git fetch + git merge
        
        git add .
        git commit -m "要添加的备注"
    	git push origin master  #上传到gitee远端分支
        git fetch origin master # 获取远程版本到本地（与git pull 有区别在于 不自动合并）
        git merge origin/master # 将远端的master分支与当前的分支进行合并
    合并冲突的方式：|
    当有冲突时候，手动解决冲突。将冲突的文件使用 git add 放入暂存区。当所有的冲突文件都放入暂存区后，需要用 git  commit 进行提交。 
    ```
    
    ```shell
    创建分支
    git checkout -b rights # 创建rights子分支，
    git branch # 查看所有分支
    git checkout 分支名 # 切换分支
    git push -u origin rights # 把本地的rights分支推送到云端并以rights名保存分
    ```
    
    ```shell
    合并多个commit
    如：
    commit 1a04d5c01549900ffe3489f7597c64ac5c5554bc
    Author: hantwofish <9217798+hantwofish@user.noreply.gitee.com>
    Date:   Mon Jul 26 12:46:46 2021 +0000
    
        one commit
        
    commit fffffc01549900ffe3489f7597c64ac5c5554bc
    Author: hantwofish <9217798+hantwofish@user.noreply.gitee.com>
    Date:   Mon Jul 26 12:46:46 2021 +0000
    
        two commit
        
    commit eeec01549900ffe3489f7597c64ac5c5554bc
    Author: hantwofish <9217798+hantwofish@user.noreply.gitee.com>
    Date:   Mon Jul 26 12:46:46 2021 +0000
    
        three commit
        
    合并前两个只需要： (意为将之后的与当前的合并--将前两个与第三个合并)(进行 rebase 之前，为防止出错先 push 到远程，后进行 push)
    git rebase -i eeec01549900ffe3489f7597c64ac5c5554bc
    
    然后将除去第一个 pick 的其他pick 改为 squash (合并注释，若不合并注释则改为f, fixup <commit> = like "squash", but discard this commit's log message
    
    git push origin +远程的分支名 #将本地的commit更新到远端  git push origin +master
    git push origin +personal分支 
    
    补充：
    git rebse --abort # 放弃
    git merge --abort # 放弃
    
    
    
    
    ```
 4. git 常用命令
    ```shell
    git cherry pick comid_ID # cherry pick
    git checkout 分支名    # 切换分支
    git checkout -b iss53  # 新建分支 并切换分支


    ```
5. 详细介绍 git 命令

    


#### vscode 配置c++环境
1. 安装 mingw64

参考[^配置]
[^配置]:[链接](https://www.cnblogs.com/hkkeryu/p/14686443.html#top)

2. 安装 vscode
    2.1 安装插件
    + c/c++
    + Chiense(Simplified) Language
    + code runner
    + Markdown Preview Enhanced

    2.2 环境配置
    + 更改默认终端
        设置图标--设置--功能--终端--Integrated › Automation Shell: Windows--点击在settings中编辑
        ```
        {
            "workbench.colorTheme": "Visual Studio Light",
            "leetcode.endpoint": "leetcode-cn",
            "code-runner.runInTerminal": true, //运行结果在终端显示
            "explorer.confirmDelete": false,
            "terminal.integrated.automationShell.windows": "D:\\SOFT\\Git\\bin\\bash.exe", //终端shell 的路径
            "leetcode.workspaceFolder": "",
            "leetcode.defaultLanguage": "cpp"

        }
        ```

3. 测试程序








## github使用
0. 在github 上新建一个仓库
1. 使用git配置本机上传时候的用户名和email

`git config --global user.name "xiaoming"`
`git config --global user.email "xiaoming@example.com"`

2. 添加公钥

如果电脑里面 有 id_rsa.pub 文件直接添加就好。没有的话执行下列操作，添加 ssh 密匙。
    `ssh-keygen -t rsa -C "xiaoming@example.com" `
把ssh密钥添加到github(过程如下:)打开C盘–>用户–>你的用户名–>找到.ssh文件夹。找到id_rsa.pub，用记事本打开，复制整个文本粘贴到gitee(点头像，进入github设置面板，SSH公钥设置，将复制的文本粘贴到公钥，标题会自动生成，然后点击添加，根据提示输入密码就可以了)

3. 下载：   
`git clone xxx`


## 命令行运行
*.sh 文件
```shell

g++ prime_test.cpp -o prime_test.exe
#g++ prime_test.o -o m_exe.exe
./prime_test.exe > prime_5.txt
```

