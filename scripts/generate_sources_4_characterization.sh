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

cp -t $destination  ../HW/src/utils.vhd \
                    ../HW/src/mem/generic_register.vhd \
                    ../HW/src/mem/pipe_delay.vhd \
                    ../HW/src/math/full_adder.vhd \
                    ../HW/src/math/piped_adder.vhd \
                    ../HW/src/math/sum_reduct.vhd \
                    ../HW/src/math/wired_shift.vhd \
                    ../HW/src/math/adder.vhd \
                    ../HW/src/math/multiplier.vhd \
                    ../HW/src/nn/cells/data_types.vhd \
                    ../HW/src/nn/cells/activation.vhd \
                    ../HW/src/nn/cells/weighted_sum.vhd \
                    ../HW/src/nn/cells/neuron.vhd \
                    ../Vivado/create_project.tcl \
                    ../Vivado/run_sim.tcl \
                    ../Vivado/constraints.xdc \
                    ../Vivado/tb_neuron_4dpa.vhd \

sed "s/^\s\s\s\sunsigned_inputs\s\s\s:\sboolean/    unsigned_inputs   : boolean := true/g" -i $destination/neuron.vhd
sed "s/^\s\s\s\sact_kind\s\s\s\s\s\s\s\s\s\s:\sactivation_t/    act_kind : activation_t := rectifier/g" -i $destination/neuron.vhd
sed "s/^\s\s\s\sact_unsigned\s\s\s\s\s\s:\sboolean/    act_unsigned : boolean := true/g" -i $destination/neuron.vhd
sed "s/^\s\s\s\sshift\s\s\s\s\s\s\s\s\s\s\s\s\s:\sinteger/    shift :integer := 0/g" -i $destination/neuron.vhd
 

if [[ ! -z "$data_size" ]]; then
  sed "s/^\s\sconstant data_size\s:\snatural\s:=\s8/  constant data_size : natural := ${data_size}/g" -i $destination/data_types.vhd
fi

if [[ ! -z "$input_depth" ]]; then
  sed "s/^\s\s\s\sinput_depth\s\s\s\s\s\s\s:\snatural/    input_depth       : natural      := ${input_depth}/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sinput_depth\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s1;/  constant input_depth       : natural       := ${input_depth};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$kernel_width" ]]; then
  sed "s/^\s\s\s\sker_width\s\s\s\s\s\s\s\s\s:\snatural/    ker_width         : natural      := ${kernel_width}/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sker_width\s\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s5;/  constant ker_width         : natural       := ${kernel_width};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$kernel_height" ]]; then
  sed "s/^\s\s\s\sker_height\s\s\s\s\s\s\s\s:\snatural/    ker_height        : natural      := ${kernel_height}/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sker_height\s\s\s\s\s\s\s\s:\snatural\s\s\s\s\s\s\s:=\s5;/  constant ker_height        : natural       := ${kernel_height};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$add_approx" ]]; then
  sed "s/^\s\s\s\sadd_approx_degree\s:\snatural/    add_approx_degree : natural      := ${add_approx}/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\sadd_approx_degree\s:\snatural\s\s\s\s\s\s\s:=\s0;/  constant add_approx_degree : natural       := ${add_approx};/g" -i $destination/tb_neuron_4dpa.vhd
fi

if [[ ! -z "$mul_approx" ]]; then
  sed "s/^\s\s\s\smul_approx_degree\s:\snatural/    mul_approx_degree : natural      := ${mul_approx}/g" -i $destination/neuron.vhd
  sed "s/^\s\sconstant\smul_approx_degree\s:\snatural\s\s\s\s\s\s\s:=\s0;/  constant mul_approx_degree : natural       := ${mul_approx};/g" -i $destination/tb_neuron_4dpa.vhd
fi


echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source create_project.tcl" > ${destination}/run_synth.sh
chmod +x ${destination}/run_synth.sh
echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source run_sim.tcl" > ${destination}/run_sim.sh
chmod +x ${destination}/run_sim.sh











