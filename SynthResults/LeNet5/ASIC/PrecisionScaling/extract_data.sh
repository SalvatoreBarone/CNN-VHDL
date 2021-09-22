#!/bin/bash
echo "Conv1 Area;Conv2 Area;Conv3 Area;FC1 Area; FC2 Area;Conv1 Pwr;Conv2 Pwr;Conv3 Pwr;FC1 Pwr;FC2 Pwr" > summary.csv
for i in {0..8}; do
  config_file=conf${i}.txt
  out_file=conf${i}.csv

  echo "Conf;Sequential instances;Sequential area(um²);Inverter instances;Inverter area (um²);Logic instances;Logic area (um²);Total area (um²);Leakage Power (nW);Dynamic Power (nW);Total Power (nW)" > ${out_file}


  while read line ; 
  do
    data_width=$(echo $line | cut -d ',' -f1);
    vol_depth=$(echo $line | cut -d ',' -f2);
    vol_height=$(echo $line | cut -d ',' -f3);
    vol_width=$(echo $line | cut -d ',' -f4);
    add_approx=$(echo $line | cut -d ',' -f5);
    mul_approx=$(echo $line | cut -d ',' -f6);
    conf=${data_width}_bit_${vol_depth}_${vol_height}_${vol_width}_nab_a${add_approx}_nab_m${mul_approx}

    name=${conf}/cell_${conf}.rep;

    sequential_instances=$(grep -e "sequential" ${name} | sed "s/ \+/,/g" | cut -d ',' -f2);
    sequential_area=$(grep -e "sequential" ${name} | sed "s/ \+/,/g" | cut -d ',' -f3);
    inverter_instances=$(grep -e "inverter" ${name} | sed "s/ \+/,/g" | cut -d ',' -f2);
    inverter_area=$(grep -e "inverter" ${name} | sed "s/ \+/,/g" | cut -d ',' -f3);
    logic_instances=$(grep -e "logic" ${name} | sed "s/ \+/,/g" | cut -d ',' -f2);
    logic_area=$(grep -e "logic" ${name} | sed "s/ \+/,/g" | cut -d ',' -f3);
    total_area=$(tail -n 2 ${name} | head -1 | sed "s/ \+/,/g" | cut -d ',' -f3);

    name=${conf}/power_${conf}.rep;
    leak=$(grep -e "neuron " ${name} | sed "s/ \+/,/g" | cut -d ',' -f3);
    dyna=$(grep -e "neuron " ${name} | sed "s/ \+/,/g" | cut -d ',' -f4);
    tota=$(grep -e "neuron " ${name} | sed "s/ \+/,/g" | cut -d ',' -f5);
    
    echo "${conf};${sequential_instances};${sequential_area};${inverter_instances};${inverter_area};${logic_instances};${logic_area};${total_area};${leak};${dyna};${tota}" >> ${out_file}
  done < $config_file;
  sed "s/\./,/g" -i ${out_file}

  summary_area=$(tail -n 5 ${out_file} | cut -d ';' -f8 | tr '\n' ';')
  summary_powe=$(tail -n 5 ${out_file} | cut -d ';' -f11 | tr '\n' ';')
  echo "${summary_area}${summary_powe}" >> summary.csv
done
sed "s/,/./g" -i summary.csv
