add_vhdl_source(full_adder.vhd full_adder)

add_vhdl_source(adder.vhd adder)
add_dependencies(adder full_adder)

add_vhdl_source(multiplier.vhd multiplier)
add_dependencies(multiplier adder)
