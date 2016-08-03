# git解决本地和远程文件冲突

>1. 如果希望保留生产服务器上所做的改动,仅仅并入新配置项,处理如下:
 - git stash
 - git pull
 - git stash pop
 然后使用git diff -w +filename 确认代码自动合并的情况
 
>2. 如果希望用代码库中的文件完全覆盖本地工作版本,处理如下:
  - git reset --hard
  - git pull
  其中git reset 是针对版本,如果想针对文件回退本地修改,使用
  - git checkout HEAD file/to/restore
 

> git pull origin master //将远程的主分支拉取到本地