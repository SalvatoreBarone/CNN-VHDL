add_vhdl_source(activation.vhd activation)
add_dependencies(activation wired_shift)

add_vhdl_source(neuron.vhd neuron)
add_dependencies(neuron utils multiplier generic_register sum_reduct activation)
