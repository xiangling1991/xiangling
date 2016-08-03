#函数形参与实参

#参数的概念

#print len()#无参，运行失败，len需要参数

a = "adsfd"
print len(a)

#什么是形参

def function1(a,b):
    if a > b:
        print a
    else:
        print b
    

#什么是实参

def function2(a,b):
    if a > b:
        print a
    else:
        print b

function2(2,3)


#全局变量
def fun():
    global i
    i = 7
    print i

#i = 9
fun()
#i = 9
print i
