# VHDL Continous Integration Example
# Copyright (C) 2017  Mario Barbareschi
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

#Uncomment and customize the following command whenever gtkwave is not your 
#default command to watch the VCD simulation file.

set(VCD_VIEWER gtkwave)

#To make everything working, just add macros specified in the vhdl_macros.cmake
#file
include(cmake/vhdl_macros.cmake)

#Give a name to the project
#Actually, the language could not be VHDL since there is no a compiler 
#environment for that language
#Better to say NONE instead of annoying VHDL
project(cnn_vhdl NONE)

#This project requires at least cmake 3.3
cmake_minimum_required(VERSION 3.3)

execute_process(COMMAND ghdl -v OUTPUT_VARIABLE GHDL_VERSION_STRING)
if($GHDL_VERSION_STRING STREQUAL "")
    message(FATAL_ERROR "GHDL not found")
else()
    message(STATUS "Found ${GHDL_VERSION_STRING}")
endif()
execute_process(COMMAND gtkwave --version OUTPUT_VARIABLE GTKWAVE_VERSION_STRING)
if($GTKWAVE_VERSION_STRING STREQUAL "")
    message(FATAL_ERROR "GTKWAVE not found")
else()
    message(STATUS "Found ${GTKWAVE_VERSION_STRING}")
endif()

#Let cmake enables the ctest environment, then specify that the command runtest
# effectively runs ctest
enable_testing()
add_custom_target(
	runtest 
	COMMAND ${CMAKE_CTEST_COMMAND} --verbose --build-run-dir=${CMAKE_CURRENT_BINARY_DIR}
)

#############

# Getting access to all VHDL sources
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
# Retrieve Testbenches as well
add_subdirectory(${CMAKE_SOURCE_DIR}/test)

add_custom_target(list ALL COMMAND ${CMAKE_VHDL_COMPILER} -d DEPENDS ${VHDL_MODULE} ${VHDL_TEST_MODULE})
set(CTEST_OUTPUT_ON_FAILURE 1)


