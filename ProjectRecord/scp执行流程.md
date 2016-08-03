#scp执行流程


1. 监控模式下，当连接服务器的时候，就会通过LoginClusterSystem来获取一个ClusterSystem
的对象指针，创建一个会话，同时创建一个线程组，使用tbb的并发队列，来接收来自（local、
cluster...）的task，并开启对应的进程csfproc（进程模式）开始执行，或直接在线程中执行。
tbb::concurrent_bounded_queue<T> tbb的并发队列，在这里用来存储每个所要处理的任务。


2. 在开始执行时，startInstance->Start->Run，在Scheduler的Run方法中实现对活动的执行，
每个计算活动执行Execute->DoExecute,在DoExecute中的SubmitCompute调用具体的活动中的
SubmitCompute，再调用JobSession中的SubmitJob，再根据具体的job类型执行
LocalBatchJobExecutor或LocalDAGExecutor,这两个类重写了operator()这个方法，在创建的
时候就执行operator()中的代码。
在LocalBatchJobExecutor或LocalDAGExecutor方法中，主要将每个Actor中获取的tasks进行重组
成为可执行的task，并放进tbb的任务队列，供开始创建的线程调用。
在调用处理进程，该进程将进度信息保存在message_queue中，在处理完成后，监控端获取该队列中
的信息并处理（消息队列名为当前执行任务的id，只有名称相同，队列中的内容就是共享的）

3. 在开始本地执行时，根据是否存在临时的pid文件来确定该实例是否已经运行。OverViewPanel中的
LocalExecProject方法。


在集群模式下，对界面的操作，主要是对流程实例的操作，包括开始，暂停，继续等，Asio都会发送一条
信息到服务器端，具体的执行代码在Workflowinstance中。


projectmonitor中：
在连接数据库时，创建一个线程ReceiveMessageThread来接收各类事件，并放进notify的
容器中，OnTimer中定时处理容器中的数据。而从线程中接受的事件是由wflistener中的redis获取的。

在服务器端，UserConnection的OnSetMatchineAttr中redis将发送消息到监控端。