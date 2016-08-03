(defconstant pool (make-array 1000 :fill-pointer t))

(defstruct ship
  name flag tons)

(dotimes (i 1000)
  (setf (aref pool i) (make-ship)))

(defconstant harbor (make-hash-table :size 1100
                                     :test #'eq))

(defun enter (n f d)
  (let ((s (if (plusp (length pool))
             (vector-pop pool)
             (make-ship))))
    (setf (ship-name s) n
          (ship-flag s) f
          (ship-tons s) d
          (gethash n harbor) s)))

(defun find-ship (n) (gethash n harbor))

(defun leave (n)
  (let ((s (gethash n harbor)))
    (remhash n harbor)
    (vector-push s pool)))

(enter 'first 'enter '10000)
(print (find-ship 'first))
(print harbor)

