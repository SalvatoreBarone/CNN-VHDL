set _xil_proj_name_ "neuron_synth"
set origin_dir "[file normalize "."]"
set orig_proj_dir "[file normalize "$origin_dir/neuron_synth"]"

# Create project
open_project ./${_xil_proj_name_}/${_xil_proj_name_}.xpr
open_run synth_1
reset_simulation -simset sim_1 -mode post-synthesis -type timing
launch_simulation -mode post-synthesis -type timing
read_saif ${_xil_proj_dir_}/${_xil_proj_name_}.sim/sim_1/synth/timing/xsim/tb_neuron.saif}
set_units -power uW
report_power -file {reort_power.txt} -name {power_1}
 
