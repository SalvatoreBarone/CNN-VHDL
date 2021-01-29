#include "conv3.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "neuromesh.h"

int main(int argc, char** argv) {
  char * biases_out_file = NULL;
  char * weights_out_file = NULL;
  char * inputs_out_file = NULL;
  char * outputs_out_file = NULL;
  std::ofstream outstream;
  DATA_T inputs[CONV3_NB_CHANNELS][CONV3_CHANNELS_HEIGHT][CONV3_CHANNELS_WIDTH];
  DATA_T outputs[CONV3_NB_OUTPUTS][CONV3_OUTPUTS_HEIGHT][CONV3_OUTPUTS_WIDTH];
  char c;

  while ((c = getopt(argc, argv, "i:o:w:b:")) != -1) {
    switch (c) {
      case 'i':
        inputs_out_file = (char*) malloc(strlen(optarg) + 1);
        strcpy(inputs_out_file, optarg);
        break;

      case 'o':
        outputs_out_file = (char*) malloc(strlen(optarg) + 1);
        strcpy(outputs_out_file, optarg);
        break;

      case 'w':
        weights_out_file = (char*) malloc(strlen(optarg) + 1);
        strcpy(weights_out_file, optarg);
        break;

      case 'b':
        biases_out_file = (char*) malloc(strlen(optarg) + 1);
        strcpy(biases_out_file, optarg);
        break;

      default:
        printf("\n\nInvalid option: \n\n");
        printf("%s -i inputs_file -o outputs_file -w weights_file -b biases_file\n", argv[0]);
        return EXIT_FAILURE;
    }
  }

  if ((NULL == inputs_out_file) || (NULL == outputs_out_file) || (NULL == weights_out_file) || (NULL == biases_out_file)) {
    printf("\n\nInvalid option: \n\n");
    printf("%s -i inputs_file -o outputs_file -w weights_file -b biases_file\n", argv[0]);
    return EXIT_FAILURE;
  }

  /** generating a random input feature map **/
  srand(time(NULL));
  for (int sz = 0; sz < CONV3_NB_CHANNELS; sz++)
    for (int sy = 0; sy < CONV3_CHANNELS_HEIGHT; sy++)
      for (int sx = 0; sx < CONV3_CHANNELS_WIDTH; sx++)
        inputs[sz][sy][sx] = (DATA_T) rand();

  /** computing the output feature map **/
  convcell_upropagate_conv3(inputs, outputs, conv3_biases, conv3_weights);

  neuromesh_t<
    DATA_T, BDATA_T, 
    5, 1, 
    CONV3_NB_CHANNELS, CONV3_CHANNELS_HEIGHT, CONV3_CHANNELS_WIDTH, 
    CONV3_STRIDE_X, CONV3_STRIDE_Y, 
    CONV3_PADDING_X, CONV3_PADDING_Y, 
    CONV3_KERNEL_HEIGHT, CONV3_KERNEL_WIDTH, 
    CONV3_NB_OUTPUTS, CONV3_OUTPUTS_HEIGHT, CONV3_OUTPUTS_WIDTH> conv3_neuromesh;

  /** writing biases onto file **/
  outstream.open(biases_out_file, std::ios::out);
  conv3_neuromesh.print_debug_biases_file(outstream, conv3_biases);
  outstream.close();

  /** writing weights onto file NOTE: output-index is the outer one! **/
  outstream.open(weights_out_file, std::ios::out);
  conv3_neuromesh.print_debug_weights_file(outstream, conv3_weights);
  outstream.close();

  /** writing the input feature map onto file. Note: the feature map is written
      in a conv. volume fashion, in order to let neurons to read inputs easily */
  outstream.open(inputs_out_file, std::ios::out);
  conv3_neuromesh.print_debug_inputs_file(outstream, inputs);
  outstream.close();

  /** writing the output feature map onto file. NOTE, the feature map is written
   * fiber-per-fiber, since the hw-accelerator computes output fibers */
  outstream.open(outputs_out_file, std::ios::out);
  conv3_neuromesh.print_debug_outputs_file(outstream, outputs);
  outstream.close();
}

