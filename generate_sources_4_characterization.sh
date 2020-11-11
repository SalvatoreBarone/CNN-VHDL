#!/bin/bash
usage() {
        echo "Usage: $0 -x /xilinx/vivado -d destination -i input_depth -m mul_approx_degree -a add_approx_degree";
        exit 1;
}

while getopts "x:d:i:m:a:" o; do
    case "${o}" in
        x)
            xilinx_vivado=${OPTARG}
            ;;
        d)
            destination=${OPTARG}
            ;;
        i)
            input_depth=${OPTARG}
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

if [ -z "${xilinx_vivado}" ] || [ -z "${destination}" ] || [ -z "${input_depth}" ] || [ -z "${mul_approx}" ]|| [ -z "${add_approx}" ]; then
    usage
fi


root_dir=$(pwd)
xilinx_vivado=$(realpath $xilinx_vivado)
destination=$(realpath $destination)


mkdir -p $destination
cp -t $destination src/utils.vhd src/math/piped_adder.vhd src/math/sum_reduct.vhd src/math/wired_shift.vhd src/math/adder.vhd src/math/full_adder.vhd src/mem/generic_register.vhd src/math/multiplier.vhd src/nn/cells/activation.vhd src/nn/cells/neuron.vhd Vivado/create_project.tcl 

echo "${xilinx_vivado} -mode batch -nojournal -nolog -notrace -source create_project.tcl > log.txt" > ${destination}/run_synth.sh
chmod +x ${destination}/run_synth.sh
