(defun typed-assoc (item alist type &key multiple default)
  (let* ((match (assoc item alist))
         (value (cdr match)))
    (unless match
      (return-from typed-assoc (values nil nil)))
    (values
     (cond
       ((not  value) default)
       (multiple (and (or (not (typep multiple 'fixnum))
                          (= multiple (length value)))
                      (every #'(lambda (x) (typep x type)) value)
                      value))
       ((/= (length value) 1) default)
       (t (let ((obj (car value)))
            (and (typep obj type) obj))))
     match)))

(defun load-base-parameters (alist)
  (let ((label (typed-assoc 'label alist 'symbol))
        (name (typed-assoc 'name alist 'string))
        (description (typed-assoc 'description alist 'string)))
    (and label name description
         (values label (list :name name :description description)))))

(defun load-parameter-descriptor (alist)
  (multiple-value-bind (label base-params) (load-base-parameters alist)
    (let ((value-list (typed-assoc 'switch alist 'string :multiple t))
          (range (typed-assoc 'range alist 'real :multiple 2))))))
