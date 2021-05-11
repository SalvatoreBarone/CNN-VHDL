#!/bin/bash
current_dir=$(pwd); 
for i in $(find . -type d -name '*_bit_*' | sort); 
do 
  echo $i; 
  cd $i; 
  ./run_synth.sh; 
  cd $current_dir; 
done  

for i in $(find . -type d -name '*_bit_*' | sort); 
do 
  echo $i; 
  cd $i; 
  ./run_sim.sh
  cd $current_dir; 
done  
