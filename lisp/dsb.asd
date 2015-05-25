(in-package #:asdf-user)

(defsystem "dsb"
  :description ""
  :version "0.0.1"
  :author "Raphael Santos <contact@raphaelss.com>"
  :license "GPLv3 License"
  :components ((:file "package")
               (:file "parameter" :depends-on ("package"))))
