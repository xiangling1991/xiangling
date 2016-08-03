##存取
1. 使用car和cdr定义的存取函数:
 - nth:查找特定位置的元素
 - nthcdr:查找第n个cdr
 - last:返回列表的最后一个Cons对象
```
(nth 0 '(a b c)) -->A
(nthcdr 2 '(a b c))  -->(C)
```
2. 没有检查错误的情况下，nthcdr定义：
```
(defun our-nthcdr (n lst)
    (if zerop n)
        lst
        (our-nthcdr (- n 1) (cdr lst)))
```

##映射函数
 - mapcar:接受一个函数以及一个或多个列表，返回把函数应用至每个列表的元素的结果
 - maplist:接受和mapcar相同的参数，将列表的渐进的下一个cdr传入函数
 - mapc

```
(mapcar #'(lambda (x) (+ x 10))
            '(1 2 3))                    -->(11 12 13)

(mapcar #'list '(a b c) '(1 2 3 4))      -->((A 1) (B 2) (C 3))

(maplist #'(lambda (x) x) '(a b c))      -->((A  B C) (B C) (C))
```

##集合
 - member:使用eql来比较每一个元素,可带参数如下(选择性添加)
 - test:传入某个函数作为:test参数，那么那个函数就会被用来比较是否相等，而不是用eql，
 - key:提供这个参数，可在比较之前，指定一个函数运用在每一个元素

```
(member '(a) '((a) (z)) :test #'equal)   -->((A) (Z))
(member 'a '((a b) (c d)) :key #'car)    -->((A B) (C D))

(member 2 '((1) (2)) :key #'car :test #'equal)  -->((2))
(member 2 '((1) (2)) :test #'equal :key #'car)  -->((2))
```

- member-if:member的判断式

```
;判断是否为奇数
(member-if #'oddp '(2 3 4)) -->(3 4)
```

- adjoin:接受一个对象和一个列表，如果该对象存在列表，则跳过，否则将该对象构建到列表上
- union:并
- intersection:交
- set-difference:差

```
(adjoin 'b '(a b c)) -->(A B C)
(adjoin 'z '(a b c)) -->(Z A B C)
(union '(a b c) '(d c e)) -->(A D B C E)
(intersection '(a b c) '(d b e)) -->(B)
(set-difference '(a b e d) '(a b e)) -->(D)
```

##序列
 - length:序列长度
 - subseq:子序列
 - reverse:序列反转
 - every:满足每一个
 - some:满足部分
```
(length '(a b c)) -->3
;第一个参数表示序列，第二个参数是包含子序列的位置，第三个参数表示不包含子序列的位置
(subseq '(a b c d) 1 2) -->(B)
(subseq '(a b c d) 2)   -->(B C D)
(every #'oddp '(1 3 5)) -->T
(some #'evenp '(1 2 3)) -->T
```

##note
 - and:如果第一个参数为nil，就返回nil，否则返回右边的值
 - or:找到第一个非nil的值并返回
 ```
 (and A (or b c)) ->if a is nil(not 0,0 also is value,not nil),return nil,else return (or b c)
 (or nil nil c d f) ->c
 ```

##栈
 - push:将元素放进列表,使用cons实现
 - pop:弹出列表的第一个元素
 - pushnew:push变种，使用adjoin实现

```
(defun our-reverse (lst)
    (let ((acc nil))
        (dolist (obj lst)
            (push obj acc))
        acc))

(let ((x '(a b)))
    (pushnew 'c x)
    (pushnew 'a x))  -->(C A B);c被加入列表，而a没有
```

##点状列表
 - 由cons创建，与list创建的列表不同之处在于，list最后元素为nil，而cons创建的尾元素非空
 在使用append时，list可以正常被加入，而点状列表就会失败，因为nil为空表
 ```
 (cons 'a (cons 'b (cons 'c 'd))) ;(A B C . D)
 ```

###总结
1. 一个 Cons 是一个含两部分的数据结构。列表用链结在一起的 Cons 组成。
2. 判断式 equal 比 eql 来得不严谨。基本上，如果传入参数印出来的值一样时，返回真。
3. 所有 Lisp 对象表现得像指针。你永远不需要显式操作指针。
4. 你可以使用 copy-list 复制列表，并使用 append 来连接它们的元素。
5. 游程编码是一个餐厅中使用的简单压缩演算法。
6. Common Lisp 有由 car 与 cdr 定义的多种存取函数。
7. 映成函数应用函数至逐项的元素，或逐项的列表尾端。
8. 嵌套列表的操作有时被考虑为树的操作。
9. 要判断一个递归函数是否 正确，你只需要考虑是否包含了所有情况。
10. 列表可以用集合表示。数个内置函数把列表当作集合。
11. 关键字参数是选择性的，并不是由位置所识别，是用符号前面的特殊标签来识别。
12. 列表是序列的子类型。 Common Lisp 有大量的序列函数。
13. 一个不是正规列表的 Cons 称之为点状列表。
14. 用 cons 对象作为元素的列表，可以拿来表示对应关系。这样的列表称为关联列表(assoc-lists)。
15. 自动内存管理拯救你处理内存配置的烦恼，但制造过多的垃圾会使程序变慢。


##文件操作
-fresh-line [stream] :输出到文件换行
-princ object [stream] :输出到流


- (declare (dynamic-extent arg)):为参数在栈上动态分配空间，出作用域时释放



-member item list &key key test test-not => tail