# CNN-VHDL
This repo is still under construction, so expect changes frequently!

CNN-VHDL is a VHDL component library to realize Neural Networks I'm developing during my PhD course. 
It provides fully-customizable neuron implementation, intended to be synthesized on FPGA/ASIC technologies. Feel free to play with it!
Ah, layers and networks implementation will follow soon.

Moreover, since my research topic is Approximate Computing, CNN-VHDL provides configurable approximation degree for both multiplications and additions performed within a neuron.

## Content of the repository
```
src               : root source directory
  +-- math        : custom and fully configurable signed integer arithmetic operators
  +-- mem         : registers, pipe stages, delay line and so forth 
  +-- nn          : NN stuff
  |   +-- cells   : Fully-configurable neuron implementation
  |   +-- layers  : Coming soon!
  test            : Testbenches for unit-testing
  +-- oracles     : Oracle generators for testbenches (in C++)
cmake             : Cmake script to build and run unit-testing with GHDL
CMakeLists.txt    : Root cmake file to build and run unit-testing with GHDL
```

## How to build and run tests
Warning, unit-testing will require a loooooot of time!
From the source root directory.
```
mkdir build && cd build
cmake ..
make
ctest --output-on-failure
```
Please, be patient! The execution of the whole test suit will require quite a looooong time!

## Simulation of single entities
You can also get a full GHW simulation report for a single units by issuing
```
make sim_nameOfTheTbEntity
```

