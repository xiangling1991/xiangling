#WF本质论

##1. WF编程模式的关键概念
[以OpenSeSame类为例，打印"Hello World!"]
###1.1 **书签**
```
[Serializable] //Bookmark 可以被序列化
public class Bookmark {
    public Bookmark(string name, BookmarkLocation continueAt);
    
    public string name {get;}
    public BookmarkLocation ContinueAt {get;}
    public object Payload{get;} //使程序恢复的输入数据(外部信号)
    
    public BookmarkManager BookmarkManager{get;} //
}

public delegate void BookmarkLocation(Bookmark resumed);

public class BookmarkManager { //用于对Bookmark进行管理
    public void Add(Bookmark bookmark);
    public void Remove(Bookmark bookmark);
    
    public void Resume(string bookmarkname, object payload);//程序会在书签的ContinueAt处恢复执行
}
```
 - 一个书签即代表已经冻结的程序的一种延续(continuation)，书签的continueAt属性指定了程序的物理恢复点。
 - 书签具有名称，可以不依赖恢复点来独立的操纵书签(多个书签可能共享一个物理恢复点)。

###1.2 **可恢复语句组件**

虚构运行时(mythical runtime):运行时管理各种类似程序的多个实例（类似C++中的多态）
```
public class MythicalRuntime {
    //starts a new program
    public ProgramHandle RunProgram(ProgramStatement program);
    
    //returns a handle to a previously started program
    public ProgramHandle GetProgramHandle(Guid programId);
    
    //passivates all in-memory programs
    public void ShutDown();
}

public class  ProgramHandle {
    //unique identifier for this program
    public Guid ProgramId {get;}
    
    //passivate the program
    public void Passivate();
    
    //resume a bookmarked program
    public void Resume(string bookmarkName, object payload);
}
```

 假设有个呵护情理的需求要求OpenSeSame作为单一语句能在较负载的多语句中使用，那么我们称其为一个**可恢复语句组件**
 
ProgramStatement类型规范了程序执行的入口点，并且作为所有可恢复语句组件的基类
```
[Serializable]
public abstract class ProgramStatement {
    public abstract void Run(BookmarkManager mgr);
}

[Serializable]
public class OpenSeSame : ProgramStatement {
    string key;
    public override void Run(BookmarkManager mgr) {
        key = DateTime.Now.Millisecond.ToString();
        Console.WriteLine("Here is your key: " + key);
        mgr.Add(new Bookmark("read", ContinueAt));
    }
    
    //ContinueAt
    ...
}
```

在虚构运行时的RunProgram方法中，作为参数提供的ProgramStatement对象时一个**可恢复程序**(Resumable Program)。
但把这样的一个对象传递给虚构运行时后，它就不在是通常情况下的CLR，它拥有了比普通的CLR更长的生命周期，因为它可以
被钝化，且可以通过GetProgramHandle来获得该对象的唯一句柄，此后可以在任意机器上继续执行，跨越了空间和时间的限制

