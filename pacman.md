安装包
```
# pacman -S package_name
# pacman -S $(pacman -Ssq package_regex) //利用正则表达式安装包
# pacman -S extra/package_name   //选择不同版本的包
```
安装包组
```
# pacman -S gnome
 Enter a selection (default=all):1-10 12
 Enter a selection (default=all):^5-8 ^12
 //查看哪些包属于gnome组
# pacman -Sg gnome
```

删除软件包
```
pacman -R package_name
pacman -Rs package_name //删除指定包以及没有被其他软件包使用的依赖关系
pacman -Rsc package_name //删除软件包和所有以来这个软件的包
pacman -Rdd package_name //删除软件包,但不删除依赖这个软件包的其他程序
pacman -Rn package_name //删除软件包以及该软件备份的重要配置文件,在其后面加上*.pacsave
pacman -Rsn package_name

pacman -Rs $(pacman -Qtdq) //删除孤立的安装包,递归形式
```

升级软件包
```
# pacman -Syu //pacman 输出记录到/var/log/pacman.log
```

查询数据库
```
pacman -Q --help
pacman -S --help
pacman -Ss string //查询描述的string
pacman -Qs string //查询已安装的软件包
pacman -Si package_name //显示软件包的详尽信息
pacman -Qi package_name //查询本地安装包的详细信息
pacman -Qii package_name //同时显示备份文件和修改状态
pacman -Ql package_name //获取已安装软件包所包含文件的列表
pacman -Qk package_name //检查 软件安装的文件是否都存在
pacman -Qo /path/to/file_name //查询数据库获取某个文件属于哪个包
pacman -Qdt //罗列所有不再作为依赖的软件包(孤立orphans)
pacman -Qet //罗列所有明确安装而且不被其它包依赖的软件包
pactree package_name //显示软件包的依赖树
pactree -r package_name //检查一个安装包的软件包被哪些包依赖
```

清理软件包缓存
```
pacman -Sc
# paccache -r //删除近3个版本前的软件包
# paccache -ruk0 
```

其他
```
# pacman -Syu package_name ... //升级系统
# pacman -Sw package_name //下载而不安装
# pacman -U /path/to/package/package_name-version.pkg.tar.xz //安装本地包
# pacman -U http://www.xxx.com/repo/example.pkg.tar.xz
```

配置
pacman 的配置位于/etc/pacman.conf
```
IgnorePkg = package_name //不升级该软件包,可用","隔开
```

详细请见https://wiki.archlinux.org/index.php/Pacman_%28%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87%29