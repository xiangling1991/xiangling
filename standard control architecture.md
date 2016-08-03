# COND

>当遇到多重分支的条件语句时,原始的IF表达式再一次变得丑陋不堪:
如果a成立那么执行x,否则如果b成立那么执行y,否则执行z.只用IF
如下:
```
(if a
    (do-x)
    (if b
        (do-y)
        (do-z)))
```

>如果要在then字句中包括多个形式,那么就使用progn,而那样的事情就会
变得更糟,因此clisp使用用于表达多重分支条件的宏cond,语法如下:
```
(cond 
    (test-1 form*)
         `
         `
         `
    (test-n form*)
```

>所以以上的式子变为
```
(cond (a (do-x))
      (b (do-y))
      (c (do-z))
```

# AND OR NOT 
>依旧遵循短路原则

# 循环
1. do 基本模板如下：
```
(do (variable-definition*)      ##变量声明
    (end-test-form result-form*)  ##测试形式和结果形式
  (statement*))
```
