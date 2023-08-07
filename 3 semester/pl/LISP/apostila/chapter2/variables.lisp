(defun SUM (x y) (+ x y))

(defun BIGGER (y) (LET ((VAL (SUM 10 30))) (if (> VAL Y) VAL Y)))

(print (BIGGER 10 ))

(print (BIGGER 10000000))
