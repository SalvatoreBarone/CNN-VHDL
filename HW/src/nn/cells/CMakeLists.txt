add_vhdl_source(activation.vhd activation)
add_dependencies(activation wired_shift)

add_vhdl_source(data_types.vhd data_types)

add_vhdl_source(weighted_sum.vhd weighted_sum)
add_dependencies(weighted_sum utils data_types multiplier generic_register pipe_delay sum_reduct)

add_vhdl_source(neuron.vhd neuron)
add_dependencies(neuron weighted_sum activation)
