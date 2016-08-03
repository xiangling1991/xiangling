1 备份cp /etc/samba/smb.conf /etc/samba/smb.conf.bak

2 在smb.conf最后加上(若当前用户为xl):
	[xl]
		comment=xl
		path=/home/xl
		writable=yes

3 在root下输入命令:smbpasswd -a xl #添加用户xl到smaba用户数据库

4 配置iptables和selinux
4.1 命令
	service iptables stop
或	
	iptables -I RH-Firewall-1-INPUT 5 -m state --state NEW -m tcp --dport 129 -j ACCEPT
	iptables -I RH-Firewall-1-INPUT 5 -m state --state NEW -m tcp -p tcp --dport 445 -j ACCEPT
	iptables -I RH-Firewall-1-INPUT 5 -p udp -m udp --dport 137 -j ACCEPT

        iptables -I RH-Firewall-1-INPUT 5 -p udp -m udp --dport 138-j ACCEPT

        iptables-save

        service iptables  restart

4.2 命令
	setenforce 0
	vim /etc/selinux/config 将SELINUX=enforce 改为SELINUX=disabled
或
	setsebool -Psamba_enable_home_dirs on
	setsebool -Psamba_export_all_rw on

最后命令
	getsebool -a | grep samba	查看所有samba到值
