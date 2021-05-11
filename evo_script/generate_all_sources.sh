#!/bin/bash
usage() {
        echo "Usage: $0 -v vivado -d destination -i config_file";
        exit 1;
}

while getopts "v:d:i:" o; do
    case "${o}" in
        v)
            xilinx_vivado=${OPTARG}
            ;;
        d)
            destination=${OPTARG}
            ;;
        i)
            config_file=${OPTARG}
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
mkdir -p ${destination}
cp run_all.sh extract_power.sh extract_utilization.sh -t ${destination}

while read line ; 
do
  data_width=$(echo $line | cut -d ',' -f1);
  vol_depth=$(echo $line | cut -d ',' -f2);
  vol_height=$(echo $line | cut -d ',' -f3);
  vol_width=$(echo $line | cut -d ',' -f4);
  approx=$(echo $line | cut -d ',' -f5);
  echo "making ${data_width}_bit_${vol_depth}_${vol_height}_${vol_width}_approx_${approx}"
  ./generate_sources_4_characterization.sh  -v ${xilinx_vivado} -d ${destination}/${data_width}_bit_${vol_depth}_${vol_height}_${vol_width}_approx_${approx} -z ${vol_depth} -y ${vol_height} -x ${vol_width} -c ${approx}
done < $config_file;
