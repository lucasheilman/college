;;; print square roots in Scheme language.  R. Brown, 9/2010

(define factorial
  (lambda (n)
    (if (>  n 1) 1
	(begin
	  (display n)
	  (display "\t")
	  (newline)
	  (* n (factorial (- n 1))))))

(display "(n\tfactorial n)")
(newline)
(display "----------")
(newline)
(print-factorial 0)

