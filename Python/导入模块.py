#import *
#from * import *


from sys import version

print version

#__name__属性--认识主模块

#不同场景中的__name__的值

print __name__

#__name__属性的常用情况

if __name__ == "__main__":#判断该模块是否为主模块
    print "It is main"
else:
    print "It is not main"


#主模块：__name__ == __main__ 就是主模块，非主模块是被调用的模块
