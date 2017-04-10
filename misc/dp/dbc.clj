(defn int-sum
  "An example of DbC (Design by Contract). An accumulator that checks the
  pre-conditions and post-conditions with Clojure's `:pre' and `:post'."
  [& n]
  {:pre [(every? integer? n)] ; must be integer
   :post [(>= % 0)]}          ; the value must be non-negative
  (apply + n))

(int-sum 1 2 3)
;;=> 6

(int-sum 0.1 2 3)
;; Assertion error from pre-condition.

(int-sum -1 -2 3)
;;=> 0

(int-sum 1 -2 -3)
;; Assertion error from post-condition.
