#condor的描述文件*.sub
eg:exp.sub/exp.sh
```
universe = vanilla
initialdir = /home/example
error = exp$(Process).error
log = exp$(Process).log
output = exp$(Process).out
executable = exp.sh
+AccountingGroup = "group_rutgers.condor"
Notiffication=never
queue 5

#universe :代表工作提交模式，condor一般有多种，如:standard,java...
#initialdir:代表执行开始的目录
#error,log,output:利用$(Process)宏，来为每个任务根据进程号来将文件标号
#executable:可执行文件的名字
#arguments:执行文件需要传递的参数，或者依赖的输入文件等，如input1.txt...
#+AccountingGroup:用你的用户名取代condor
Notification:如果不包括此项，condor将会在完成每个任务后发送邮件提醒您
queue：代表执行多次任务。这里的$(Process)将会设置为0-29
```

