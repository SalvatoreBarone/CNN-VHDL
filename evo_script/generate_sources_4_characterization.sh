#!/bin/bash
usage() {
        echo "Usage: $0 -v /xilinx/vivado -d destination -z input_depth -y kernel_height -x kernel_width -c approx_component";
        exit 1;
}

while getopts "v:d:z:y:x:c:" o; do
    case "${o}" in
        v)
            xilinx_vivado=${OPTARG}
            ;;
        d)
            destination=${OPTARG}
            ;;
        z)
            input_depth=${OPTARG}
            ;;
        y)
            kernel_height=${OPTARG}
            ;;
        x)  
            kernel_width=${OPTARG}
            ;;
        c)
            approx=${OPTARG}
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))

if [ -z "${xilinx_vivado}" ] || [ -z "${destination}" ]; then
    usage
fi


root_dir=$(pwd)
xilinx_vivado=$(realpath $xilinx_vivado)
mkdir -p $destination
destination=$(realpath $destination)

cp -t $destination  ../HW/src/utils.vhd \
                    ../HW/src/mem/generic_register.vhd \
                    ../HW/src/mem/pipe_delay.vhd \
                    ../HW/src/math/full_adder.vhd \
                    ../HW/src/math/piped_adder.vhd \
                    ../HW/src/math/sum_reduct.vhd \
                    ../HW/src/math/wired_shift.vhd \
                    ../HW/src/math/adder.vhd \
                    ../HW/src/math/EvoApproxLite/* \
                    ../HW/src/nn/cells/data_types.vhd \
                    ../HW/src/nn/cells/activation.vhd \
                    ../HW/src/nn/cells/evo_weighted_sum.vhd \
                    ../HW/src/nn/cells/evo_neuron.vhd \
                    ../Vivado/create_evo_project.tcl \
                    ../Vivado/run_evo_sim.tcl \
                    ../Vivado/constraints.xdc \
#                    ../Vivado/tb_evo_neuron_4dpa.vhd \

echo "Configuring ${destination}"
if [[ ! -z "$input_depth" ]]; then
  sed "s/^\s\s\s\sinput_depth\s\s\s\s\s\s\s:\snatural\s:=\s1;/    input_depth       : natural      := ${input_depth};/g" -i $destination/evo_neuron.vhd
  sed "s/^\s\sconstant\sinput_depth\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s1;/  constant input_depth       : natural       := ${input_depth};/g" -i $destination/tb_evo_neuron_4dpa.vhd
fi

if [[ ! -z "$kernel_width" ]]; then
  sed "s/^\s\s\s\sker_width\s\s\s\s\s\s\s\s\s:\snatural\s:=\s5;/    ker_width         : natural      := ${kernel_width};/g" -i $destination/evo_neuron.vhd
  sed "s/^\s\sconstant\sker_width\s\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s5;/  constant ker_width         : natural       := ${kernel_width};/g" -i $destination/tb_evo_neuron_4dpa.vhd
fi

if [[ ! -z "$kernel_height" ]]; then
  sed "s/^\s\s\s\sker_height\s\s\s\s\s\s\s\s:\snatural\s:=\s5;/    ker_height        : natural      := ${kernel_height};/g" -i $destination/evo_neuron.vhd
  sed "s/^\s\sconstant\sker_height\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s5;/  constant ker_height        : natural       := ${kernel_height};/g" -i $destination/tb_evo_neuron_4dpa.vhd
fi

if [[ ! -z "$approx" ]]; then
  sed "s/^\s\s\s\saxcomponent\s\s\s\s\s\s\s:\snatural\s:=\s0/    axcomponent       : natural := ${approx}/g" -i $destination/evo_neuron.vhd
  sed "s/^\s\sconstant\saxcomponent\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s0;/  constant axcomponent : natural       := ${approx};/g" -i $destination/tb_evo_neuron_4dpa.vhd
fi

echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source create_evo_project.tcl" > ${destination}/run_synth.sh
chmod +x ${destination}/run_synth.sh
echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source run_evo_sim.tcl" > ${destination}/run_sim.sh
chmod +x ${destination}/run_sim.sh










