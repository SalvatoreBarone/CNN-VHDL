add_vhdl_source(generic_register.vhd generic_register)
add_vhdl_source(pipe_delay.vhd pipe_delay)
add_dependencies(pipe_delay generic_register)
add_vhdl_source(piso_register.vhd piso_register)
add_vhdl_source(sipo_register.vhd sipo_register)

