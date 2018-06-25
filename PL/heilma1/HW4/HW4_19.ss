#lang scheme
(define (list-set lst n x)
  (cond 
    [(null? lst) '()]
    [(equal? n 0) (cons x (cdr lst))]
    [else (cons (car lst) (list-set (cdr lst) (- n 1) x))]))