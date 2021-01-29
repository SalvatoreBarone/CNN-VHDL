#include "conv1.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "neuromesh.h"
#include <stdio.h>

char * biases_out_file = NULL;
char * weights_out_file = NULL;
char * inputs_out_file = NULL;
char * outputs_out_file = NULL;

void fprint_binary(FILE* stream, int amount, int num)
{
  assert(amount <= 32);
  for (int i = amount-1; i >= 0; i--)
    fprintf(stream, "%d", (num & (1<<i)) ? 1 : 0);
}


int main(int argc, char** argv) {
  DATA_T inputs[CONV1_NB_CHANNELS][CONV1_CHANNELS_HEIGHT][CONV1_CHANNELS_WIDTH];
  DATA_T outputs[CONV1_NB_OUTPUTS][CONV1_OUTPUTS_HEIGHT][CONV1_OUTPUTS_WIDTH];

  char c;
  while ((c = getopt(argc, argv, "i:o:w:b:")) != -1)
  {
    switch (c)
    {
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

  if ((NULL == inputs_out_file) || (NULL == outputs_out_file) || (NULL == weights_out_file) || (NULL == biases_out_file))
  {
    printf("\n\nInvalid option: \n\n");
    printf("%s -i inputs_file -o outputs_file -w weights_file -b biases_file\n", argv[0]);
    return EXIT_FAILURE;
  }
  /** generating a random input feature map **/
  srand(time(NULL));
  for (int sz = 0; sz < CONV1_NB_CHANNELS; sz++)
    for (int sy = 0; sy < CONV1_CHANNELS_HEIGHT; sy++)
      for (int sx = 0; sx < CONV1_CHANNELS_WIDTH; sx++)
        inputs[sz][sy][sx] = (DATA_T) rand();
  /** computing the output feature map **/
  convcell_upropagate_conv1(inputs, outputs, conv1_biases, conv1_weights);

  neuromesh_t<
    DATA_T, BDATA_T, 
    6, 2, 
    CONV1_NB_CHANNELS, CONV1_CHANNELS_HEIGHT, CONV1_CHANNELS_WIDTH, 
    CONV1_STRIDE_X, CONV1_STRIDE_Y, 
    CONV1_PADDING_X, CONV1_PADDING_Y, 
    CONV1_KERNEL_HEIGHT, CONV1_KERNEL_WIDTH, 
    CONV1_NB_OUTPUTS, CONV1_OUTPUTS_HEIGHT, CONV1_OUTPUTS_WIDTH> conv1_neuromesh;

  /** writing biases onto file **/
//  FILE * outfile = NULL;
  std::ofstream outstream;
//  assert((outfile = fopen(biases_out_file, "w")) != NULL);
//  for (int i = 0; i < CONV1_NB_OUTPUTS; i++) {
//    fprint_binary(outfile, 2*NB_BITS, conv1_biases[i]);
//    fprintf(outfile, "\n");;
//  }
//  fclose(outfile);
  outstream.open(biases_out_file, std::ios::out);
  conv1_neuromesh.print_debug_biases_file(outstream, conv1_biases);
  outstream.close();

  /** writing weights onto file NOTE: output-index is the outer one! **/
//  assert((outfile = fopen(weights_out_file, "w")) != NULL);
//  for (unsigned int output = 0; output < CONV1_NB_OUTPUTS; output++)
//  {
//    for (unsigned int channel = 0; channel < CONV1_NB_CHANNELS; channel++) {
//      if (conv1_weights[output][channel] == NULL) continue;
//      for (unsigned int sy = 0; sy < CONV1_KERNEL_HEIGHT; sy++)
//        for (unsigned int sx = 0; sx < CONV1_KERNEL_WIDTH; sx++) {
//          fprint_binary(outfile, NB_BITS, (*conv1_weights[output][channel])[sy][sx]); 
//          fprintf(outfile, " ");
//        }
//    }
//    fprintf(outfile, "\n");
//  }
//  fclose(outfile);
  outstream.open(weights_out_file, std::ios::out);
  conv1_neuromesh.print_debug_weights_file(outstream, conv1_weights);
  outstream.close();

  /** writing the input feature map onto file. Note: the feature map is written
      in a conv. volume fashion, in order to let neurons to read inputs easily */
//  assert((outfile = fopen(inputs_out_file, "w")) != NULL);
//  for (unsigned int oy = 0; oy < CONV1_OY_SIZE; ++oy)
//    for (unsigned int ox = 0; ox < CONV1_OX_SIZE; ++ox) {
//      const unsigned int sxMin = (unsigned int) int_max((int) CONV1_PADDING_X - (int) (ox * CONV1_STRIDE_X), 0);
//      const unsigned int syMin = (unsigned int) int_max((int) CONV1_PADDING_Y - (int) (oy * CONV1_STRIDE_Y), 0);
//      const unsigned int sxMax = (unsigned int) int_max(int_min((int) CONV1_CHANNELS_WIDTH + CONV1_PADDING_X - (int) (ox * CONV1_STRIDE_X),(int) CONV1_KERNEL_WIDTH),0);
//      const unsigned int syMax = (unsigned int) int_max(int_min((int) CONV1_CHANNELS_HEIGHT + CONV1_PADDING_Y - (int) (oy * CONV1_STRIDE_Y),(int) CONV1_KERNEL_HEIGHT),0);
//      const int ix = (int) (ox * CONV1_STRIDE_X) - (int) CONV1_PADDING_X;
//      const int iy = (int) (oy * CONV1_STRIDE_Y) - (int) CONV1_PADDING_Y;
//      for (unsigned int channel = 0; channel < CONV1_NB_CHANNELS; ++channel) {
//        for (unsigned int sy = syMin; sy < syMax; ++sy)
//          for (unsigned int sx = sxMin; sx < sxMax; ++sx) {
//            fprint_binary(outfile, NB_BITS, inputs[channel][iy + sy][ix + sx]);
//            fprintf(outfile, " ");
//          }
//      }
//      fprintf(outfile, "\n");
//    }
//  fclose(outfile);
  outstream.open(inputs_out_file, std::ios::out);
  conv1_neuromesh.print_debug_inputs_file(outstream, inputs);
  outstream.close();

  /** writing the output feature map onto file. NOTE, the feature map is written
   * fiber-per-fiber, since the hw-accelerator computes output fibers */
//  assert((outfile = fopen(outputs_out_file, "w")) != NULL);
//  for (unsigned int oy = 0; oy < CONV1_OY_SIZE; ++oy)
//    for (unsigned int ox = 0; ox < CONV1_OX_SIZE; ++ox) {
//      for (unsigned int output = 0; output < CONV1_NB_OUTPUTS; ++output) {
//        fprint_binary(outfile, NB_BITS, outputs[CONV1_OUTPUT_OFFSET + output][oy][ox]);
//        fprintf(outfile, " ");
//      }
//      fprintf(outfile, "\n");
//    }
//  fclose(outfile);
  outstream.open(outputs_out_file, std::ios::out);
  conv1_neuromesh.print_debug_outputs_file(outstream, outputs);
  outstream.close();
}

