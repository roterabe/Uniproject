#!/usr/bin/sbcl --script

;;Get the root element
(define (key node )(car node))

;;Get the Left sub tree
(define (left node) (cadr node))

;;Get the right sub tree
(define (right node) (caddr node))

;;insert element 'el' in the tree
(define (insert el tree)
  (cond ((null? tree) 
         (list el '() '()))
        ((= el (key tree))
         tree)
        ((< el (key tree))
         (list (key tree)  
               (insert el (left tree))
               (right tree)))
        ((> el (key tree))
         (list (key tree)
               (left tree)
               (insert el (right tree))))))

;;loop through all elements & insert in tree
(define (list2tree ls) 
  (list2tree-help ls '()))

(define (list2tree-help ls tree)
  (cond ((null? ls) tree)
        (else (list2tree-help (cdr ls )
(insert (car ls) tree)))))
