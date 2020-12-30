#!/bin/bash
usage() {
        echo "Usage: $0 -v /xilinx/vivado -t destination [-d data_size] [-z input_depth] [-y kernel_height] [-x kernel_width] [-m mul_approx_degree] [-a add_approx_degree]";
        exit 1;
}

while getopts "v:t:d:z:y:x:m:a:" o; do
    case "${o}" in
        v)
            xilinx_vivado=${OPTARG}
            ;;
        t)
            destination=${OPTARG}
            ;;
        d)
            data_size=${OPTARG}
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
        m)
            mul_approx=${OPTARG}
            ;;
        a)
            add_approx=${OPTARG}
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
destination=$(realpath $destination)


mkdir -p $destination
cp -t $destination  ../src/utils.vhd \
                    ../src/mem/generic_register.vhd \
                    ../src/mem/pipe_delay.vhd \
                    ../src/math/full_adder.vhd \
                    ../src/math/piped_adder.vhd \
                    ../src/math/sum_reduct.vhd \
                    ../src/math/wired_shift.vhd \
                    ../src/math/adder.vhd \
                    ../src/math/multiplier.vhd \
                    ../src/nn/cells/activation.vhd \
                    ../src/nn/cells/neuron.vhd \
                    ../Vivado/create_project.tcl \
                    ../Vivado/run_sim.tcl \
                    ../Vivado/constraints.xdc \
                    ../Vivado/tb_neuron_4dpa.vhd \

if [[ ! -z "$data_size" ]]; then
  sed "s/^\s\sconstant data_size\s:\snatural\s:=\s8/  constant data_size : natural := ${data_size}/g" -i $destination/neuron.vhd
fi

if [[ ! -z "$input_depth" ]]; then
  sed "s/^\s\s\s\sinput_depth\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s:=\s1;/    input_depth       : natural      := ${input_depth};/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sinput_depth\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s1;/  constant input_depth       : natural       := ${input_depth};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$kernel_width" ]]; then
  sed "s/^\s\s\s\sker_width\s\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s:=\s5;/    ker_width         : natural      := ${kernel_width};/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sker_width\s\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s5;/  constant ker_width         : natural       := ${kernel_width};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$kernel_height" ]]; then
  sed "s/^\s\s\s\sker_height\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s:=\s5;/    ker_height        : natural      := ${kernel_height};/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sker_height\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s5;/  constant ker_height        : natural       := ${kernel_height};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$add_approx" ]]; then
  sed "s/^\s\s\s\sadd_approx_degree\s:\snatural\s\s\s\s\s\s:=\s0;/    add_approx_degree : natural      := ${add_approx};/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sadd_approx_degree\s:\snatural\s\s\s\s\s\s\s:=\s0;/  constant add_approx_degree : natural       := ${add_approx};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$mul_approx" ]]; then
  sed "s/^\s\s\s\smul_approx_degree\s:\snatural\s\s\s\s\s\s:=\s0);/    mul_approx_degree : natural      := ${mul_approx});/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\smul_approx_degree\s:\snatural\s\s\s\s\s\s\s:=\s0;/  constant mul_approx_degree : natural       := ${mul_approx};/g" -i $destination/tb_neuron_4dpa.vhd
fi


echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source create_project.tcl" > ${destination}/run_synth.sh
chmod +x ${destination}/run_synth.sh
echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source run_sim.tcl" > ${destination}/run_sim.sh
chmod +x ${destination}/run_sim.sh











