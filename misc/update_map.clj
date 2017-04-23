(defn update-map
  "Fast way to update values of a map, e.g. incrementing, using reduce-kv"
  [m f]
  (reduce-kv (fn [mm k v] (assoc mm k (f v)))
             {}
             m))

(let [foo {:a 1 :b 2}]
  (do
    (println foo)
    (-> foo
        (update-map inc)
        println)))
