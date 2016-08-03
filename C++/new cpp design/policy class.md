#基于Policy的Class设计

1. 多重继承产生的问题：
    - 关于技术（Mechanics）。目前没有一成不变即可套用的代码，可以在某种受控情况下将继承而来的classes组合起来。
        大多数时候你得小心协调继承而来的classes的运转，让它们得到所需的行为。
    - 关于型别信息（Type information）。Based classes并没有足够的型别信息来继续完成它们的工作。比如：
        你正试着籍由继承一个DeepCopy class来为你的smart pointer实作出深层拷贝，但DeepCopy应该具有怎样的接口呢：
        它必须产生一个对象，而其型别未知。
    - 关于状态处理（State manipulation）。base classes实作的各种行为必须操作相同的state。这意味着它们必须虚继
        承一个持有该state的base class。由于总是由user classes继承library classes，这会使得设计更加复杂而且变得没有弹性。
        
