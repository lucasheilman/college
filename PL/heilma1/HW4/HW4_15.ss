#lang scheme
(define (duple n x)
  (cond 
    [(equal? 0 n) '()]
    [else (cons x (duple(- n 1) x))]))