add_vhdl_source(full_adder.vhd full_adder)
add_vhdl_source(wired_shift.vhd wired_shift)

add_vhdl_source(adder.vhd adder)
add_dependencies(adder full_adder)

add_vhdl_source(piped_adder.vhd piped_adder)
add_dependencies(piped_adder adder generic_register)

add_vhdl_source(multiplier.vhd multiplier)
add_dependencies(multiplier utils piped_adder generic_register)

add_vhdl_source(sum_reduct.vhd sum_reduct)
add_dependencies(sum_reduct utils piped_adder)

add_subdirectory(EvoApproxLite)
