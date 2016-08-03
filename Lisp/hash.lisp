;create hash table grammar
;(~%-%~)
;;;make-hash-table &key :test :size :rehash-size :rehash-threadhold

;;;The key argument provides the key.

;;;The :test argument determines how keys are compared - it should have one of three values #'eq, #'eql, 
;;;or #'equal, or one of the three symbols eq, eql, or equal. If not specified, eql is assumed.

;;;The :size argument sets the initial size of the hash table. This should be an integer greater than zero.

;;;The :rehash-size argument specifies how much to increase the size of the hash table when it becomes full.
;;; This can be an integer greater than zero, which is the number of entries to add, or it can be a floating-point 
;;;number greater than 1, which is the ratio of the new size to the old size.Thedefault value for this 
;;;argument is implementation-dependent.

;;;The :rehash-threshold argument specifies how full the hash table can get before it must grow. This can be 
;;;an integer greater than zero and less than the :rehash-size (in which case it will be scaled whenever the
;;; table is grown), or it can be a floating-point number between zero and 1. The default value for this 
;;;argument is implementation-dependent.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;retrive item from table
;(~%-%~)
;;gethash key hash-table &optional default

;;;key: is the associated key

;;;hash-table: is the hash-table to be searched

;;;default: is the value to be returned, if the entry is not found, which is nil, if not specified.

;example

>(seq emplist (make-hash-table))
>(setf (gethash '001 emplist) '(Charlie Brown))
>(setf (gethash '002 emplist) '(Freddie Seal))
>(setf (gethash '003 emplist) '(Mark Mongoose))

>(write (gethash '001 emplist))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;maphash function
;;;The maphash function allows you to apply a specified function on each key-value pair on a hash table
;;;it has two arguments

;;;example
>(maphash #'(lambda (k v) (format t "~a => ~a~%" k v)) emplist)
;;res
;;3 => (MARK MONGOOSE)
;;2 => (FREDDIE SEAL)
;;1 => (CHARLIE BROWN)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;remove an entry
;(~%-%~)
;remhash key hash-table

;;;example
>(remhash '003 emplist)