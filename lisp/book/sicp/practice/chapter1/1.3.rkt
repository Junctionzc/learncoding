#lang racket
(define (ReturnTwoMaxNumberSum a b c)
  (if (and (> (+ a b) (+ a c)) (> (+ a b) (+ b c))) (+ a b)
      (if (> (+ a c) (+ b c)) (+ a c) (+ b c)))
   )

(ReturnTwoMaxNumberSum 4 8 1)