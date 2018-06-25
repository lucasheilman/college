(define factorial
  (lambda (num prod) ; a non-negative integer and another integer
    ;; assert:  desired factorial is prod * (factorial num)
    (if (= 0 num)  prod
        ;; assert:  num > 0
        (factorial (- num 1) (* num prod)))))

(define n 0)

(define print-factorials
  (lambda () ; print factorials from n to 5
    (if (>  n 5) 'done
	(begin 
	  (display (factorial n 1))
	  (newline)
	  (set! n (+ n 1))
	  (print-factorials)))))

(display "n!")
(newline)
(display "----------")
(newline)
(print-factorials)

