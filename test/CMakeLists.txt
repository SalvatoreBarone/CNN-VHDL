add_testbench_source(tb_adder.vhd tb_adder)
add_dependencies(tb_adder adder)
 
add_testbench_source(tb_multiplier.vhd tb_multiplier)
add_dependencies(tb_multiplier multiplier)
