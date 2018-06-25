#lang scheme
(define (every? pred lst)
  (cond 
    [(null? lst) #t]
    [(equal? (pred (car lst)) #f) #f]
    [else (every? pred (cdr lst))]))
