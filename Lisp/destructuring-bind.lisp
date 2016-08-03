;; This is a typical usage, for pulling apart a list
(destructuring-bind
      (first second)
    '(1 2)
  (format t "~%~%;;; => first:~a second:~a~&" first second))
;;; > first:1 second:2

;; You can also pull apart improper lists:
(destructuring-bind
      (first . second)
    '(1 . 2)
  (format t "~%~%;;; => first:~a second:~a~&" first second))

;;; > first:1 second:2

;; The first argument to destructuring-bind is a lambda list, but you
;; can grab the remainder by either using a dotted list:

(destructuring-bind
      (first second . stuff)
    '(1 2 3 4 5)
  (format t "~%~%;;; => first:~a second:~a rest:~a~&" first second stuff))

;;; => first:1 second:2 rest:(3 4 5)

;; or you can grab the remainder with &rest, just like you do for
;; functions that take a variable number of arguments:
(destructuring-bind
      (first second &rest stuff)
    '(1 2 3 4 5)
  (format t "~%~%;;; => first:~a second:~a rest:~a~&" first second stuff))

;;; => first:1 second:2 rest:(3 4 5)

;; It really is a lambda list, you can use default parameters:
(destructuring-bind
      (first second &optional (third 'default))
    '(1 2)
  (format t "~%~%;;; => first:~a second:~a third:~a~&" first second third))

;;; => first:1 second:2 third:DEFAULT

(destructuring-bind
      (first second &optional (third 'default))
    '(1 2 3)
  (format t "~%~%;;; => first:~a second:~a third:~a~&" first second third))

;;; => first:1 second:2 third:3

;; And you can use keyword parameters:
(destructuring-bind
      (first second &key third)
    '(1 2 :third 3)
  (format t "~%~%;;; => first:~a second:~a third:~a~&" first second third))

;;; => first:1 second:2 third:3

;; Finally, you can use it to 'unparse' trees as well, which is a
;; really great feature, since your variable declaration matches the
;; 'shape' of the data strucutre you're pulling apart.  This technique
;; is really handy for dealing with XML after it's been converted to
;; s-expressions.
(destructuring-bind
      (a (b (c d e (f g) h i j)) &rest remainder)
    '(1 (2 (3 4 5 (6 7) 8 9 10)) 11 12 13 14 15)
  (format t
          "~%~%;;; => a:~a b:~a c:~a d:~a e:~a f:~a g:~a h:~a i:~a j:~a remainder:~a ~&"
          a b c d e f g h i j remainder))

;;; => a:1 b:2 c:3 d:4 e:5 f:6 g:7 h:8 i:9 j:10 remainder:(11 12 13 14 15)
