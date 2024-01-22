# Git使用教程
## 安装
安装地址：https://git-scm.com/<br>
选择对应系统版本，然后按照默认选项安装
## 基本配置
设置用户名与邮箱
1. 右键打开Git Bash
2. 设置名字(字符串为名字)```git config --global user.name “name”```
3. 设置邮箱(字符串为邮箱)```git config --global user.email “name@name.com”```
## Git基本概念
1. 工作区(workspace)
   * 未暂存:修改后文件
   * 未跟踪:新建的文件
   ```git add```可将工作区提交到暂存区
2. 暂存区(index)
   ```git commit```可将暂存区提交到仓库
3. 仓库(repository)
## 常用命令
```git init```在当前位置创建本地仓库(Git Bash打开位置)
```git status```查看当前文件状态(分别是在哪个区)
```git add 文件名```把指定文件添加到暂存区
```git add .```添加所有文件到暂存区
```git commit -m "注释"```提交到仓库(字符串内写提交信息)
```git log [option]```查看提交记录
   * -- all 显示所有分支
   * --pretty=oneline 将提交信息显示为一行
   * --abbrev-commit 使得输出的commitId更简短
   * --graph 以图的形式显示
   * 为了优化显示，一般输入这行```git log --pretty=oneline --all --graph --abbrev-commit```

```git reset --hard commitID```回退版本
```git reflog```查看已经删除的提交记录
```git branch```查看全部分支
```git branch 分支名```从当前位置创建分支
```git checkout 分支名```切换分支
```git checkout -b 分支名```从当前位置创建并且切换到新创建分支
```git merge 分支名```把"分支名"的分支合并到当前分支上(Esc :wq可退出编辑)
```git branch -d 分支名```删除分支
```ssh-keygen -t rsa```配置钥对
```cat ~/.ssh/id_rsa.pub```查看公钥
```git remote origin 远程仓库地址```添加远程仓库(地址选用ssh的)
```git push origin 本地分支名:远端分支名```推送到远程仓库(一样名字可只写一个)
```git clone```克隆远端仓库
```git fetch```抓取远端仓库
```git pull```拉取远端仓库