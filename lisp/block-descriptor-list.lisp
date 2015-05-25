(parameter-descriptor
 (label power)
 (name "Power")
 (description "Power description")
 (switch "On Bypass"))

(parameter-descriptor
 (label gain)
 (name "Gain")
 (description "Gain description")
 (float 0.0 1.0))

(block-descriptor
 (name "Amplifier")
 (description "Amplifier multiples the signal.")
 (inputs "In")
 (outputs "Out")
 (parameters))
