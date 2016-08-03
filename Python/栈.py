#python有定义好的数据结构，比如list，tuple and dict，有的需要我们自己去定义
#比如栈、队列...


#栈：

class Stack:
    '''实现栈的功能

    该类模拟栈的相关功能，包括进栈、出栈。。。'''
    def __init__(self,size):
      self.stack = []
      self.size = size
      self.top = -1

    def push(self,content):
        if self.Full():
           print "Stack is Full"
        else:
            self.stack.append(content)
            self.top = self.top + 1
    def Full(self):
        if self.top == self.size:
            return True
        else:
            return False
    def isEmpty(self):
        if self.top == -1:
            print "Stack is Empty"
            return True
        else:
            return False

    def pop(self):
        if not self.isEmpty():
            m = self.stack[self.top]
            self.top = self.top - 1
            return m

    def Size(self):
        if not self.isEmpty():
            return self.top
        else:
#            return "It is empty"
            return -1
if __name__ == "__main__":
    stack = Stack(10)
    print stack.__doc__
    print dir(stack)
    stack.push(2)
    stack.push(4)
    stack.push(7)
#    print "size:{0}".format(stack.Size())
    print stack.pop()
    print stack.pop()
    print stack.pop()
    print stack.pop()
#    print "size:{0}".format(stack.Size())
            


    
        
