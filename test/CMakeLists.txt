add_vhdl_source(debug_func.vhd debug_func)

add_testbench_source(tb_adder.vhd tb_adder)
add_dependencies(tb_adder adder)
 
add_testbench_source(tb_multiplier.vhd tb_multiplier)
add_dependencies(tb_multiplier multiplier)

add_testbench_source(tb_sum_reduct.vhd tb_sum_reduct)
add_dependencies(tb_sum_reduct sum_reduct debug_func)