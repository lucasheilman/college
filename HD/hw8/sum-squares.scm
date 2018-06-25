;;; print square roots in Scheme language.  R. Brown, 9/2010
(define sumbefore
  (lambda (a)
    (if (< a 0) 0
	(begin
	  (+ (* a a) (sumbefore (- a 1)))))))
    
(define sum-squares
  (lambda (n)
    (if (> n 5) 'done
	(if (< n 0) 0
	  (begin
	    (display n)
	    (display "\t")
            (display (+ (* n n) (sumbefore (- n 1))))
	    (newline)
	    (sum-squares (+ n 1)))))))
			

(display "n\tsum of n squares")
(newline)
(display "--------------------------")
(newline)
(sum-squares 0)
