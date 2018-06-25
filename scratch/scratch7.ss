#lang scheme
(define (max ls)
  (cond
    [(null? (cdr ls)) (car ls)]
    [(> (car ls)(car(cdr ls)))(max (cons (car ls)(cdr(cdr ls))))]
    [else (max (cdr ls))]))