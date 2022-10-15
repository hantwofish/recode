git 常用命令的使用

```
$ 将工作区文件放到暂存区
git add . 
$ 将暂存区文件回退到工作区
git reset HEAD filename // 或者 git reset filename
```

## git 命令详细解说
###  git cherry-pick 

1.基本用法

git cherry-pick命令的作用，就是将指定的提(commit)应用于其他分支。
`$ git cherry-pick <commitHash>`
上面命令就会将指定的提交commitHash，应用于当前分支。这会在当前分支产生一个新的提交，当然它们的哈希值会不一样。

举例来说，代码仓库有master和feature两个分支。
```
 a - b - c - d   Master
         \
           e - f - g Feature
```
现在将提交f应用到master分支。

```
# 切换到 master 分支
$ git checkout master

# Cherry pick 操作
$ git cherry-pick f
```

上面的操作完成以后，代码库就变成了下面的样子。

```
a - b - c - d - f   Master 
        \
        e - f - g Feature
```
从上面可以看到，master分支的末尾增加了一个提交f。

git cherry-pick命令的参数，不一定是提交的哈希值，分支名也是可以的，表示转移该分支的最新提交。

`$ git cherry-pick feature`
上面代码表示将feature分支的最近一次提交，转移到当前分支。

2.转移多个提交
Cherry pick 支持一次转移多个提交。
`$ git cherry-pick <HashA> <HashB>`
上面的命令将 A 和 B 两个提交应用到当前分支。这会在当前分支生成两个对应的新提交。
如果想要转移一系列的连续提交，可以使用下面的简便语法。


`$ git cherry-pick A..B` 
上面的命令可以转移从 A 到 B 的所有提交。它们必须按照正确的顺序放置：提交 A 必须早于提交 B，否则命令将失败，但不会报错。

注意，使用上面的命令，提交 A 将不会包含在 Cherry pick 中。如果要包含提交 A，可以使用下面的语法。


`$ git cherry-pick A^..B `

参考链接：
[1]:http://www.ruanyifeng.com/blog/2020/04/git-cherry-pick.html


### 解决冲突

如果操作过程中发生代码冲突，Cherry pick 会停下来，让用户决定如何继续操作。

（1）--continue
用户解决代码冲突后，第一步将修改的文件重新加入暂存区（git add .），第二步使用下面的命令，让 Cherry pick 过程继续执行。
`$ git cherry-pick --continue`

（2）--abort
发生代码冲突后，放弃合并，回到操作前的样子。

（3）--quit
发生代码冲突后，退出 Cherry pick，但是不回到操作前的样子。

### git rebase

### git pull 与 git fetch , git merge

分支合并
```shell
git merge 源分支 目标分支 #分支合并
git reset commit_id #回退到某一个版本


```

### git基本命令
#### 分支
```shell
git branch #查看所有分支名称，带*为当前分支
git branch -r #查看远端分支
git branch -a #查看本地以及远端所有分支
git checkout -b xxx #新建分支并切换分支
```

删除分支
`git branch -d xxx #删除本地分支`

删除远程分支：
```shell
git branch -d -r xxx 
git push origin :分支名 #推送到远端
```

```shell
git diff 本地分支 origin/分支名 #查看本地分支与远程分支差异
git fetch orgin 远程分支名 #将远程分支保存至本地
```

本地分支合并中冲突管理
```shell
状态（master|merge）
打开冲突文件 vim xxx.txt
手动修改后
git add 文件名
git commit -m "xxx"
```

撤销操作
```shell
文件被修改但未进行git add
使用 git checkout 文件名 #回到原来状态
git checkout . #修改但未提交的文件全部回退
```

git reflog #查看提交过命令

```shell
git commit --amend #修改最后一次提交信息
```