#!/bin/bash
for i in $(find . -name 'report_utilization.txt' | sort); 
do 
  total_luts=$(grep -e " evo_neuron " $i | sed "s/ \+//g" | cut -d '|' -f4); 
  logic_luts=$(grep -e " evo_neuron " $i | sed "s/ \+//g" | cut -d '|' -f5); 
  total_ffls=$(grep -e " evo_neuron " $i | sed "s/ \+//g" | cut -d '|' -f8); 
  echo $i $total_luts $logic_luts $total_ffls;
done     

