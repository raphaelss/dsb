(defpackage #:dsb
  (:use #:cl))

(in-package #:dsb)

(defvar *block-descriptors* ())

(defclass block-descriptor ()
  ((name :initarg :name
         :reader block-name)
   (description :initarg :description
                :reader block-description)
   (inputs :initarg :inputs
           :reader block-inputs)
   (outputs :initarg :outputs
            :reader block-outputs)
   (parameters :initarg :parameters
               :reader block-parameters)))

(defclass block-instance ()
  ((descriptor :initarg :descriptor
               :reader block-descriptor)))

(defun make-block-descriptor (name description inputs outputs parameters)
  (make-instance 'block-descriptor :name name :description description
                 :inputs inputs :outputs outputs :parameters parameters))

(defun instantiate-block (descriptor)
  (make-instance 'block-instance :descriptor descriptor))

(defun load-blocks (path)
  (setf *block-descriptors* nil))
