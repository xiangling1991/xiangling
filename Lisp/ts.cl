(defun test-cl ()
	(format t "~A ~%" "Hello")
	)

;(test-cl)

;(format t "~A ~%" (member 'a '((a b) (c d)) :key #'car))
;(format t "~A ~%" (member-if #'oddp '(2 3 4)))
;(format t "~A ~%" (adjoin 'm '(a b c)))
;(format t "~A ~%" (union '(a b c) '(d b c a)))
;(format t "~A ~%" (intersection '(a b c) '(a b d a)))
;(format t "~A ~%" (set-difference '(a b d) '(b d e d)))
;(format t "~A ~%" (subseq '(a b c d) 1 3))
;(format t "~A ~%" (reverse '(a b c d)))


(defun mirror? (s)
	(let ((len (length s)))
		(and (evenp len) 
			(let ((mid (/ len 2)))
				(equal (subseq s 0 mid)
					(reverse (subseq s mid)))))))

; (format t "~A ~%" (mirror? '(a b c c b a)))

; (defun nthmost (n x)
; 	(nth (- n 1)
; 		(sort (copy-list x) #'>)))

; (format t "~A ~%" (nthmost 2 '(4 5 2 6 8)))

; (format t "~A ~%" (null 1))

; (defun enigma (x)
; 	(and (not (null x))
; 		(or (null (car x))
; 			(enigma (cdr x)))))

; (format t "~A ~%" (enigma '(a)))

; (defun mystery (x y)
; 	(if (null y)
; 		nil
; 		(if (eql (car y) x)
; 			0
; 			(let ((z (mystery x (cdr y))))
; 				(and z (+ z 1))))))

; (format t "~A ~%" (mystery 2 '(2 2 3 4 2)))
; (format t "~A ~%" (or nil nil nil nil))

(defun islist (x)
	(if (or (null (listp x)) (null x))
		nil
		(islist (cdr x))))

(format t "~A ~%" (islist '(3 (3 3))))

(defun pri (x)
	(format t "~A " "*")
	(if (> x 1)
		(pri (- x 1))))


(defun new-union (x y)
	(dolist (obj y)
		(if (not (not-in obj x))
			(append x obj)))
	x)

(defun not-in (m x)
	(if (null x)
		nil
		(if (equal (car x) m)
			nil
			(not-in m (cdr x)))))

(format t "	~A ~%" (new-union '(a b c) '(a d b)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun occurrence (lst)
	(let ((res nil))
		(dolist (obj lst)
			(let ((n 0))
				(ti obj n lst)
				(append res (cons obj n))))
		res))

(defun ti (obj n lst)
	(if (null lst)
		nil
		(if (equal obj (car lst))
			(+ n 1)
			(ti obj n (cdr lst))))
	n)

(format t "~A ~%" (occurrence '(a a)))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun showdots (x)
	(reverse x)
	(let ((res nil))
		()))

(format t " ~A ~%" (cond ((eq 'a 'b) 'first)
	((atom 'a) 'second)
	((> 4 6) (+ (* 2 3) 7))))


(format t "~D ~B ~O ~X ~R ~%" 12 12 12 12 8)

(defun x2 (x)
	(let ((b nil))
		(do ((i 0 (1+ i)))
			((> i (length x)) b)
			(setf b (cons (* i i) b)))))

(format t "~A ~%" (x2 '(1 2 3 4 5 max(3 4))))

(defun shortest-path (start end net)
	(bfs end (list (list start)) net))

(defun bfs (end queue net)
	(if (null queue)
		nil
		(let ((path (car queue)))
			(let ((node (car path)))
				(if (eql node end)
					(reverse path)
					(bfs end
						(append (cdr queue)
							(new-path path node net))
						net))))))

(defun new-path (path node net)
	(mapcar #'(lambda (n)
		(cons n path))
	(cdr (assoc node net))))

(setf min '((a b c) (b c) (c d)))
(format t "~A ~%" (cdr (assoc 'a min)))
(format t "~A ~%" (shortest-path 'a 'd min))