#!/bin/bash
root_dir=${pwd}
oracles_dir=test/oracles

cd $oracles_dir
mkdir build && cd build
cmake ..
make -j `nproc`

cd $root_dir
mkdir build && cd build
cmake ..
make 
make test
