#!/bin/bash
for i in $(find Synthesis -name 'utilization_report.txt' | sort); 
do 
  total_luts=$(grep -e " neuron " $i | sed "s/ \+//g" | cut -d '|' -f4); 
  logic_luts=$(grep -e " neuron " $i | sed "s/ \+//g" | cut -d '|' -f5); 
  total_ffls=$(grep -e " neuron " $i | sed "s/ \+//g" | cut -d '|' -f8); 
  echo $i $total_luts $logic_luts $total_ffls;
done     

