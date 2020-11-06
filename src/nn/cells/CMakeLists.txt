add_vhdl_source(activation.vhd activation)

add_vhdl_source(neuron.vhd neuron)
add_dependencies(neuron utils data_types config multiplier generic_register sum_reduct activation)
