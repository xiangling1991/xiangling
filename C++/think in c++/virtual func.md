# 虚拟规格中const的存在

>決定一個virutal function是否需要const,似乎是件琐屑的事情,但当你真正面对一个
abstract base class时,却不容易做决定,做这件事,意味着得假设subclass实体可能被
无穷次地使用,不把函数声明为const,意味着该函数不能够获得一个const reference或
const pointer,比较令人头大的是,声明一个函数为const,然后才发现实际上其derived
intance必须修改某一个data member,我不知道有没有一致的解决办法,因此,最好的办法
就是不使用const.