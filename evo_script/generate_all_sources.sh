#!/bin/bash
usage() {
        echo "Usage: $0 -d destination -i config_file";
        exit 1;
}

while getopts "d:i:" o; do
    case "${o}" in
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

if [ -z "${destination}" ] || [ -z "${config_file}" ]; then
    usage
fi


root_dir=$(pwd)
destination=$(realpath $destination)
mkdir -p ${destination}

while read line ; 
do
  data_width=$(echo $line | cut -d ',' -f1);
  vol_depth=$(echo $line | cut -d ',' -f2);
  vol_height=$(echo $line | cut -d ',' -f3);
  vol_width=$(echo $line | cut -d ',' -f4);
  approx=$(echo $line | cut -d ',' -f5);

  `./generate_sources_4_characterization.sh -t ${destination}/${data_width}_bit_${vol_depth}_${vol_height}_${vol_width}_approx_${approx} -z ${vol_depth} -y ${vol_height} -x ${vol_width} -c ${approx}`
done < $config_file;
