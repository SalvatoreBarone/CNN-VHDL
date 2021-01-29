#include "fc2.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "neuromesh.h"

#define TEST_VECTORS 10000

int main(int argc, char** argv) {
  char * biases_out_file = NULL;
  char * weights_out_file = NULL;
  char * inputs_out_file = NULL;
  char * outputs_out_file = NULL;
  std::ofstream outstream;
  DATA_T inputs[FC2_NB_CHANNELS];
  DATA_T outputs[FC2_NB_OUTPUTS];
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

  neuromesh_t<
    DATA_T, BDATA_T, 
    10, 1, 
    FC2_NB_CHANNELS, 1, 1, 
    0, 0, 
    0, 0, 
    1, 1, 
    FC2_NB_OUTPUTS, 1, 1> fc2_neuromesh;

  /** writing biases onto file **/
  outstream.open(biases_out_file, std::ios::out);
  fc2_neuromesh.print_debug_biases_file(outstream, fc2_biases);
  outstream.close();

  /** writing weights onto file NOTE: output-index is the outer one! **/
  outstream.open(weights_out_file, std::ios::out);
  fc2_neuromesh.print_debug_weights_file(outstream, fc2_weights);
  outstream.close();


  std::ofstream input_stream(inputs_out_file, std::ios::out);
  std::ofstream output_stream(outputs_out_file, std::ios::out);
  /** generating a random input feature map **/
  srand(time(NULL));
  for (int test = 0; test < TEST_VECTORS; test++) {
    for (int sz = 0; sz < FC2_NB_CHANNELS; sz++)
      inputs[sz] = (DATA_T) rand();
    /** writing the input feature map onto file. Note: the feature map is written
        in a conv. volume fashion, in order to let neurons to read inputs easily */
    fc2_neuromesh.print_debug_inputs_file(input_stream, inputs);
    /** computing the output feature map **/
    fccell_upropagate(inputs, outputs, fc2_biases, fc2_weights);
    /** writing the output feature map onto file. NOTE, the feature map is written
     * fiber-per-fiber, since the hw-accelerator computes output fibers */
    fc2_neuromesh.print_debug_outputs_file(output_stream, outputs);
  }
  input_stream.close();
  output_stream.close();
}


