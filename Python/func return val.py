#返回单值

def test():
    i = 7
    return i

print test()

#多返回值

def test2(i,j):
    k = i*j
    return [i,j,k]#可返回list，tuple，和dict

x = test2(4,4)
print x

x,y,z = test2(5,6)
print x
print y
print z


i = 6
j = 7
i,j = j,i #交换i和j的值

print i
print j
