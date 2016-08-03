#*-* coding:utf-8 *-*

class Queue():
    ''' queue

    实现队列的入队、出队等操作'''

    def __init__(self,size):
        self.front = -1
        self.end = -1
        self.queue = []
        self.Size = size

    def InQueue(self,data):
        if not self.isFull():
            self.queue.append(data)
            self.end = self.end + 1
            return 0
        else:
            print "The Queue is Full"
            return -1
            
    def OutQueue(self):
        if not self.isEmpty():
            m = self.queue[self.front]
            self.front = self.front + 1
            return m
        else:
            return "Empty"

    def isEmpty(self):
        if self.front == self.end:
            return True
        else:
            return False

    def isFull(self):
        if self.end - self.front == self.Size:
            return True
        else:
            return False

if __name__ == "__main__":
    queue = Queue(4)
    queue.InQueue(4)
    queue.InQueue(4)
    queue.InQueue(6)
    print queue.OutQueue()
    print queue.OutQueue()
    print queue.OutQueue()
    print queue.OutQueue()
    print dir(queue)
    
