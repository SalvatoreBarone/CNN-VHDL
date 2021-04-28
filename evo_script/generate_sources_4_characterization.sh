#!/bin/bash
usage() {
        echo "Usage: $0 -t destination -z input_depth -y kernel_height -x kernel_width -c approx_component";
        exit 1;
}

while getopts "t:z:y:x:c:" o; do
    case "${o}" in
        t)
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

root_dir=$(pwd)
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
                    ../HW/src/math/EvoApproxLite/* \
                    ../HW/src/nn/cells/data_types.vhd \
                    ../HW/src/nn/cells/activation.vhd \
                    ../HW/src/nn/cells/evo_weighted_sum.vhd \
                    ../HW/src/nn/cells/evo_neuron.vhd \


if [[ ! -z "$input_depth" ]]; then
  sed "s/^\s\s\s\sinput_depth\s\s\s\s\s\s\s:\snatural\s:=\s1;/    input_depth       : natural      := ${input_depth};/g" -i $destination/evo_neuron.vhd
fi

if [[ ! -z "$kernel_width" ]]; then
  sed "s/^\s\s\s\sker_width\s\s\s\s\s\s\s\s\s:\snatural\s:=\s5;/    ker_width         : natural      := ${kernel_width};/g" -i $destination/evo_neuron.vhd
fi

if [[ ! -z "$kernel_height" ]]; then
  sed "s/^\s\s\s\sker_height\s\s\s\s\s\s\s\s:\snatural\s:=\s5;/    ker_height        : natural      := ${kernel_height};/g" -i $destination/evo_neuron.vhd
fi

if [[ ! -z "$approx" ]]; then
  sed "s/^\s\s\s\saxcomponent\s\s\s\s\s\s\s:\snatural\s:=\s0/    axcomponent       : natural := ${approx}/g" -i $destination/evo_neuron.vhd
fi












