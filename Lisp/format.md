##lisp中的format格式

  Directive   Interpretation
  ---------   --------------
     ~%       new line
     ~&       fresh line
     ~|       page break
     ~T       tab stop
     ~<       justification
     ~>       terminate ~<
     ~C       character
     ~(       case conversion
     ~)       terminate ~(
     ~D       decimal integer
     ~B       binary integer
     ~O       octal integer
     ~X       hexadecimal integer
     ~bR      base-b integer
     ~R       spell an integer
     ~P       plural
     ~F       floating point
     ~E       scientific notation
     ~G       ~F or ~E, depending upon magnitude
     ~$       monetary
     ~A       legibly, without escapes
     ~S       READably, with escapes
     ~~       ~
     ~{       表示下一个实参必须是列表
     
#<clisp>
    (defun dump-db ()
        (dolist (cd *db*)
            (format t "~{~a: ~10t~a~%~}~%" cd)))
    
    (format t "~a" "Dixie Chicks")
#<clisp>


1. 全局变量的设置
 - 使用如下形式来添加一个全局变量
    - *db*  -->添加了一个db的全局变量
    
#<clisp>
    (defun prompt-read (prompt)
        (format *query-io* "~a: " prompt)
        (force-output *query-io*)
        (read-line *query-io*))
#<clisp>
  - *query-io* 定义一个全局变量
  - force-output 确保lisp在打印信息之前不会等待换行
  - read-line  读取单行文本
  
#<clisp>
    (defun prompt-for-cd ()
        (make-cd
            (prompt-read "Title")
            (prompt-read "Artist")
            (or (parse-integer (prompt-read "Rating") :junk-allowed t) 0)
            (y-or-n-p "Ripped [y/n]: ")))
#<clisp>
    
 - parse-integer 的默认行为是当它无法从字符串中正确解析出整数，或者字符串里含有任何非数字的垃圾时直接报错
                    ，不过，它接受一个可选的关键字 :junk-allowed,可以适当地宽容些。
 - or            的含义和 || 很相似，由于parse-integer在没有找到整数时，返回的是NIL而不是整数，所以可以返回一个默认值 0
 - y-or-n-p      在输入了没有y、Y、n或者N的情况下将提示重新输入