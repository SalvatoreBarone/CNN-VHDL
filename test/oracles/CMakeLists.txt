project(CNN-VHDL-Oracles)
cmake_minimum_required(VERSION 3.3)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY                     ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY                     ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY                      ${CMAKE_BINARY_DIR}/bin)
set(ORACLES_DESTINATION_DIRECTORY                  ${CMAKE_CURRENT_LIST_DIR}/..)

add_executable(tb_wired_shift                                 tb_wired_shift.cc)
add_executable(tb_weighted_sum                               tb_weighted_sum.cc)
add_executable(tb_activation                                   tb_activation.cc)
add_executable(tb_neuron                                           tb_neuron.cc)
#add_executable(tb_neuron_pipelined                     tb_neuron_pipeliened.cc)
#add_executable(tb_neuron_scomposto                       tb_neuron_scomposto.cc)
add_executable(tb_neuromesh_single_rect             tb_neuromesh_single_rect.cc)
add_executable(tb_neuromesh_single_linear         tb_neuromesh_single_linear.cc)
add_executable(tb_neuromesh_1i2w_linear             tb_neuromesh_1i2w_linear.cc)
add_executable(tb_neuromesh_2i1w_linear             tb_neuromesh_2i1w_linear.cc)
add_executable(tb_neuromesh_1i2w_rect                 tb_neuromesh_1i2w_rect.cc)
add_executable(tb_neuromesh_2i1w_rect                 tb_neuromesh_2i1w_rect.cc)
add_executable(tb_neuromesh_lenet5_fc2               tb_neuromesh_lenet5_fc2.cc)
add_executable(tb_neuromesh_lenet5_conv1      tb_neuromesh_lenet5_conv1/conv1.cc
                                              tb_neuromesh_lenet5_conv1/main.cc)
target_include_directories(tb_neuromesh_lenet5_conv1    
                                              PRIVATE tb_neuromesh_lenet5_conv1)
add_executable(tb_neuromesh_lenet5_conv2      tb_neuromesh_lenet5_conv2/conv2.cc
                                              tb_neuromesh_lenet5_conv2/main.cc)
target_include_directories(tb_neuromesh_lenet5_conv2    
                                              PRIVATE tb_neuromesh_lenet5_conv2)

add_executable(tb_approx_adder                      trunc.cc tb_approx_adder.cc)
add_executable(tb_approx_multiplier            trunc.cc tb_approx_multiplier.cc)
add_executable(tb_approx_weighted_sum        trunc.cc tb_approx_weighted_sum.cc)
add_executable(tb_approx_neuron                    trunc.cc tb_approx_neuron.cc)

add_custom_target(
    oracle_files ALL
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND echo "Please, wait. This may take a while..."
    COMMAND ./tb_wired_shift > ${ORACLES_DESTINATION_DIRECTORY}/tb_wired_shift_oracle.txt 
    COMMAND ./tb_weighted_sum > ${ORACLES_DESTINATION_DIRECTORY}/tb_weighted_sum_oracle.txt 
    COMMAND ./tb_activation > ${ORACLES_DESTINATION_DIRECTORY}/tb_activation_oracle.txt 
    # COMMAND ./tb_neuron_pipelined ${ORACLES_DESTINATION_DIRECTORY}/tb_neuron_oracle.txt ${ORACLES_DESTINATION_DIRECTORY}/tb_neuron_pipelining_input.txt ${ORACLES_DESTINATION_DIRECTORY}/tb_neuron_pipelining_oracle.txt 
    COMMAND ./tb_neuron > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuron_oracle.txt 
    # COMMAND ./tb_neuron_scomposto > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuron_scomposto_oracle.txt 
    COMMAND ./tb_neuromesh_single_rect > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_single_rect_oracle.txt
    COMMAND ./tb_neuromesh_single_linear > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_single_linear_oracle.txt
    COMMAND ./tb_neuromesh_1i2w_linear > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_1i2w_linear_oracle.txt
    COMMAND ./tb_neuromesh_2i1w_linear > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_2i1w_linear_oracle.txt
    COMMAND ./tb_neuromesh_1i2w_rect > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_1i2w_rect_oracle.txt
    COMMAND ./tb_neuromesh_2i1w_rect > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_2i1w_rect_oracle.txt
    COMMAND ./tb_neuromesh_lenet5_fc2 > ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_fc2_oracle.txt
    COMMAND ./tb_neuromesh_lenet5_conv1 -i ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv1_inputs.txt -o ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv1_outputs.txt -w ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv1_weights.txt -b ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv1_biases.txt
    COMMAND ./tb_neuromesh_lenet5_conv2 -i ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv2_inputs.txt -o ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv2_outputs.txt -w ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv2_weights.txt -b ${ORACLES_DESTINATION_DIRECTORY}/tb_neuromesh_lenet5_conv2_biases.txt
    COMMAND ./tb_approx_adder > ${ORACLES_DESTINATION_DIRECTORY}/tb_approx_adder_oracle.txt 
    COMMAND ./tb_approx_multiplier > ${ORACLES_DESTINATION_DIRECTORY}/tb_approx_multiplier_oracle.txt 
    COMMAND ./tb_approx_weighted_sum > ${ORACLES_DESTINATION_DIRECTORY}/tb_approx_weighted_sum_oracle.txt
    COMMAND ./tb_approx_neuron > ${ORACLES_DESTINATION_DIRECTORY}/tb_approx_neuron_oracle.txt 
    DEPENDS tb_activation tb_approx_adder tb_approx_multiplier tb_approx_neuron tb_approx_weighted_sum tb_neuron tb_weighted_sum tb_wired_shift tb_neuromesh_single_rect tb_neuromesh_single_linear tb_neuromesh_1i2w_linear tb_neuromesh_2i1w_linear tb_neuromesh_1i2w_rect tb_neuromesh_2i1w_rect tb_neuromesh_lenet5_fc2 tb_neuromesh_lenet5_conv1 tb_neuromesh_lenet5_conv2

    VERBATIM
)

    
