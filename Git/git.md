# git安装心得(archlinux)

 - 1.sudo pacman -S git
 - 2.git init //初始化当前文件夹为仓库
 - 3.git config user.name "user-name"  //添加用户名
 - 4.git config user.mail "user_mail@example.com"//添加链接的git邮箱

 - 5.sudo pacman -S openssh  //ssh-keygen 需要这个安全协议
 - 6.ssh-keygen -t rsa -C "user_mail@example.com" //生成密钥,将公共密钥添加到git官网的ssh

 - git remote add <name> <git address> //关联git的仓库
 - git remote remove <name> //删除已关联的仓库
 - git push -u origin master //将添加到本地仓库的文件同步到网络仓库