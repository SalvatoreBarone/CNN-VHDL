# CNN-VHDL
This repo is still under construction, so expect changes frequently!

CNN-VHDL is a VHDL component library to realize Neural Networks I'm developing during my PhD course. 
It provides fully-customizable neuron implementation, intended to be synthesized on FPGA/ASIC technologies. Feel free to play with it!
Ah, layers and networks implementation will follow soon.

Moreover, since my research topic is Approximate Computing, CNN-VHDL provides configurable approximation degree for both multiplications and additions performed within a neuron.

## Content of the repository
```
HW
 +-- src             : hardware root source directory
 |   +-- math        : custom and fully configurable signed integer arithmetic operators
 |   +-- mem         : registers, pipe stages, delay line and so forth 
 |   +-- nn          : NN stuff
 |       +-- cells   : Fully-configurable neuron implementation
 |       +-- layers  : Fully configurable, energy efficient implementations of fully-connected and
 |                     convolutional layers.
 +-- test            : Testbenches for unit-testing
 |   +-- oracles     : C++ Oracle generators for testbenches
 |   +
 +-- axis            : AXI-4 Lite/Stream interface for the neuromesh implementation
 +-- cmake           : Cmake script to build and run unit-testing with GHDL
 +-- CMakeLists.txt  : Root cmake file to build and run unit-testing with GHDL
SW
 +-- neuromesh.h     : Simple device driver to manage computations (and testing)
```

## How to build and run tests
In order to run unit testing, you must generate oracle files first. Go to /test/oracles and run
```
mkdir build && cd build
cmake ..
make -j `nproc`
```
This will generate oracle files for testbenches. Then, from the repository's root, run.
```
mkdir build && cd build
cmake ..
make
```
Then
```
ctest --output-on-failure
```
or
```
make test 
```
Please, be patient! The execution of the whole test suit will require quite a looooong time!

## Simulation of single entities
You can also get a full GHW simulation report for a single units by issuing
```
make sim_nameOfTheTbEntity
```

