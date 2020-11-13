add_vhdl_source(debug_func.vhd debug_func)

add_testbench_source(tb_wired_shift.vhd tb_wired_shift)
add_dependencies(tb_wired_shift wired_shift)

add_testbench_source(tb_adder.vhd tb_adder)
add_dependencies(tb_adder adder)

add_testbench_source(tb_approx_adder.vhd tb_approx_adder)
add_dependencies(tb_approx_adder adder)

add_testbench_source(tb_piped_adder.vhd tb_piped_adder)
add_dependencies(tb_piped_adder piped_adder debug_func)
 
add_testbench_source(tb_multiplier.vhd tb_multiplier)
add_dependencies(tb_multiplier multiplier)

add_testbench_source(tb_approx_multiplier.vhd tb_approx_multiplier)
add_dependencies(tb_approx_multiplier multiplier)

add_testbench_source(tb_sum_reduct.vhd tb_sum_reduct)
add_dependencies(tb_sum_reduct sum_reduct debug_func)

add_testbench_source(tb_activation.vhd tb_activation)
add_dependencies(tb_activation activation debug_func)

add_testbench_source(tb_neuron.vhd tb_neuron)
add_dependencies(tb_neuron utils neuron)
