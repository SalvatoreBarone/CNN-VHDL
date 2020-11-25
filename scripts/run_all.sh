#!/bin/bash
current_dir=$(pwd); 
for i in $(find . -type d | sort); 
do 
  echo $i; 
  cd $i; 
  ./run_synth.sh; 
  ./run_sim.sh
  cd $current_dir; 
done  
