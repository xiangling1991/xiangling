在监控软件中，一个工程可以有多个工作流实例，也就是工程和模板之间是一对多的关系：
具体的运行流程如下：
解析实例中的所添加的工程参数，运行，同时启动一个定时器(OnTimer)，不停地扫描是否有服务器端给客户端发来流程的状态信息，
此时在ProjectMonitor中的ReceiveMessageThread中实现，并调用WorkflowListener中的ListenEvent监听服务器事件，
redis是内存数据库，其get方法用于阻塞式获取服务器消息。

ListenEvent方法：构建各种类型的事件对象。