1. 保存和读取
#<clisp>
    (defun save-db (filename)
        (with-open-file (out filename
		                  :direction :output
		                  :if-exists :supersede)
           (with-standard-io-syntax
	           (print *db* out))))
#<clisp>

 - with-open-file   :宏会打开一个文件，将文件流绑定到一个变量上，执行一组表达式，然后在关闭这个文件。它还可以保证即便在表达式
    求值出错时也可以正确关闭文件，紧跟着with-open-file的列表并非函数调用而是with-open-file语法的一部分，
    它含有用来保存要在with-open-file主体中写入的文件流的变量名，这个值必须是文件名，紧随其后是一些控制如
    何打开文件的选项。这里用:direction :output 指定了正在打开一个用于写入的文件，以及用:if-exists 
    :supersede说明当存在同名的文件时想要覆盖已存在的文件。
 - with-standard-io-syntax   :确保那些影响print行为的特定变量可以被设置成它们的标准值。当把数据读回来时，你将使用同样的宏来确
    保读取器和打印器的操作彼此兼容。
 
#<clisp>
    (defun load-db (filename)
        (with-open-file (in filename)
            (with-standard-io-syntax
	           (setf *db* (read in))))
#<clisp>                              

 - 此时with-open-file不需要带可选参数,read in 读取filename中的内容
 - setf 最主要的赋值操作，将其第一个参数设置成其第二个参数的求值结果，这里将读取的内容放进*db*全局变量中。
    会破坏db中已有的数据。
        
2. 查询

 - 目标
    - (select :artist "Dixie Checks")

 - 函数remove-if-not接受一个谓词和一个原始列表，然后返回一个仅包含原始列表中匹配该谓词的所有元素的新列表。
    - (remove-if-not #'evenp '(1 2 3 4 5 6 7 8 9))  #获取列表中的偶数
        - 这里的谓词是函数evenp，当其参数是偶数时返回真
        - \#' 记号是“获取函数，其名如下”的简称。没有#'的话，Lisp将把evenp作为一个变量名来对待并查找该变量的值，而不是将其看作函数。
    - 也可以向remove-if-not传递一个匿名函数，如下：
        - (remove-if-not #'(lambda (x) (= 0 (mod x 2))) '(1 2 3 4 5 6 7 8 9))
        - 此时，谓词是  (lambda (x) (= 0 (mod x 2)))
        
#<lisp>
    (select #'(lambda (cd) (equal (getf cd :artist) "Dixie Chicks")))
    (defun select (selector-fn)     ;传入的是一个函数，可以匹配artist,title,rating等查找方式。
        (remove-if-not selector-fn *db*))
    (defun artist-selector (artist)
        #'(lambda (cd) (equal (getf cd :artist) artist)))
#<lisp>

- artist-selector 是一个返回函数的函数，     