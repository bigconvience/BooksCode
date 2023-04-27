#lang racket

(define-syntax
  3-state
  (syntax-rules ()
    ((3-state value positive-body zero-body negative-body)
     (cond
       ((zero? value) zero-body)
       ((positive? value) positive-body)
       (else negative-body)))))

(3-state 100 (display "P") (display "Z") (display "N"))

(3-state 0 (display "P") (display "Z") (display "N"))

(3-state -100 (display "P") (display "Z") (display "N"))