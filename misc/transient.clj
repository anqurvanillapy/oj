(defn vrange
  "Builds up a persistent vector"
  [n]
  (loop [i 0 v []]
    (if (< i n)
      (recur (inc i) (conj v i))
      v)))

(defn vrange!
  "Builds up a transient vector"
  [n]
  (loop [i 0 v (transient [])]
    (if (< i n)
      (recur (inc i) (conj! v i))
      (persistent! v))))

;;; Lists don't support the transient feature, as there is no benefit to be
;;; had.

(defn -main
  "A benchmark of generating persistent and transient versions of vector
  and lists"
  [& args]
  (do
    (print "persistent vrange 1,000,000: ")
    (-> 1000000 vrange time)
    (print "transient vrange 1,000,000: ")
    (-> 1000000 vrange! time)))

(-main)
