(in-package #:dsb)

(defvar *parameter-descriptors* (make-hash-table :test #'eq))

(defclass parameter-descriptor ()
  ((name :initarg :name
         :reader parameter-name
         :type string)
   (description :initarg :description
                :reader parameter-description
                :type 'string)))

(defclass real-parameter-descriptor (parameter-descriptor)
  ((range-min :initarg :min
              :reader parameter-range-min)
   (range-max :initarg :max
              :reader parameter-range-max)))

(defclass switch-parameter-descriptor (parameter-descriptor)
  ((value-list :initarg :value-list
               :reader parameter-value-list)))

(defun clear-parameter-descriptors ()
  (clrhash *parameter-descriptors*))

(defun add-real-parameter-descriptor (label name description min max)
  (setf (gethash label *parameter-descriptors*)
        (make-instance 'real-parameter-descriptor
                       :name name
                       :description description
                       :min min
                       :max max)))

(defun add-switch-parameter-descriptor (label name description value-list)
  (setf (gethash label *parameter-descriptors*)
        (make-instance 'switch-parameter-descriptor
                       :name name
                       :description description
                       :value-list value-list)))

(add-switch-parameter-descriptor 'bypass "On/bypass" "On/bypass description"
                                 '("On" "Bypass"))

(add-real-parameter-descriptor 'gain "Gain" "Gain description" 0 1)
