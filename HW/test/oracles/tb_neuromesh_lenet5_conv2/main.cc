#include "conv2.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char * biases_out_file = NULL;
char * weights_out_file = NULL;
char * inputs_out_file = NULL;
char * outputs_out_file = NULL;

void print_binary(int amount, int num);
void fprint_binary(FILE* stream, int amount, int num);

int main(int argc, char** argv) {
  DATA_T inputs[CONV2_NB_CHANNELS][CONV2_CHANNELS_HEIGHT][CONV2_CHANNELS_WIDTH];
  DATA_T outputs[CONV2_NB_OUTPUTS][CONV2_OUTPUTS_HEIGHT][CONV2_OUTPUTS_WIDTH];

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

  FILE * outfile = NULL;
  /** writing biases onto file **/
  assert((outfile = fopen(biases_out_file, "w")) != NULL);
  for (int i = 0; i < CONV2_NB_OUTPUTS; i++) {
    fprint_binary(outfile, 2*NB_BITS, conv2_biases[i]);
    fprintf(outfile, "\n");;
  }
  fclose(outfile);

  /** writing weights onto file NOTE: output-index is the outer one! **/
  assert((outfile = fopen(weights_out_file, "w")) != NULL);
  for (unsigned int output = 0; output < CONV2_NB_OUTPUTS; output++)
  {
    for (unsigned int channel = 0; channel < CONV2_NB_CHANNELS; channel++) {
      if (conv2_weights[output][channel] == NULL) continue;
      for (unsigned int sy = 0; sy < CONV2_KERNEL_HEIGHT; sy++)
        for (unsigned int sx = 0; sx < CONV2_KERNEL_WIDTH; sx++) {
          fprint_binary(outfile, NB_BITS, (*conv2_weights[output][channel])[sy][sx]); 
          fprintf(outfile, " ");
        }
    }
    fprintf(outfile, "\n");
  }
  fclose(outfile);

  /** generating a random input feature map **/
  srand(time(NULL));
  for (int sz = 0; sz < CONV2_NB_CHANNELS; sz++)
    for (int sy = 0; sy < CONV2_CHANNELS_HEIGHT; sy++)
      for (int sx = 0; sx < CONV2_CHANNELS_WIDTH; sx++)
        inputs[sz][sy][sx] = (DATA_T) rand();

  /** computing the output feature map **/
  convcell_upropagate_conv2(inputs, outputs, conv2_biases, conv2_weights);

  /** writing the input feature map onto file. Note: the feature map is written
      in a conv. volume fashion, in order to let neurons to read inputs easily */
  assert((outfile = fopen(inputs_out_file, "w")) != NULL);
  for (unsigned int oy = 0; oy < CONV2_OY_SIZE; ++oy)
    for (unsigned int ox = 0; ox < CONV2_OX_SIZE; ++ox) {
      const unsigned int sxMin = (unsigned int) int_max((int) CONV2_PADDING_X - (int) (ox * CONV2_STRIDE_X), 0);
      const unsigned int syMin = (unsigned int) int_max((int) CONV2_PADDING_Y - (int) (oy * CONV2_STRIDE_Y), 0);
      const unsigned int sxMax = (unsigned int) int_max(int_min((int) CONV2_CHANNELS_WIDTH + CONV2_PADDING_X - (int) (ox * CONV2_STRIDE_X),(int) CONV2_KERNEL_WIDTH),0);
      const unsigned int syMax = (unsigned int) int_max(int_min((int) CONV2_CHANNELS_HEIGHT + CONV2_PADDING_Y - (int) (oy * CONV2_STRIDE_Y),(int) CONV2_KERNEL_HEIGHT),0);
      const int ix = (int) (ox * CONV2_STRIDE_X) - (int) CONV2_PADDING_X;
      const int iy = (int) (oy * CONV2_STRIDE_Y) - (int) CONV2_PADDING_Y;
      for (unsigned int channel = 0; channel < CONV2_NB_CHANNELS; ++channel) {
        for (unsigned int sy = syMin; sy < syMax; ++sy)
          for (unsigned int sx = sxMin; sx < sxMax; ++sx) {
            fprint_binary(outfile, NB_BITS, inputs[channel][iy + sy][ix + sx]);
            fprintf(outfile, " ");
          }
      }
      fprintf(outfile, "\n");
    }
  fclose(outfile);

  /** writing the output feature map onto file. NOTE, the feature map is written
   * fiber-per-fiber, since the hw-accelerator computes output fibers */
  assert((outfile = fopen(outputs_out_file, "w")) != NULL);
  for (unsigned int oy = 0; oy < CONV2_OY_SIZE; ++oy)
    for (unsigned int ox = 0; ox < CONV2_OX_SIZE; ++ox) {
      for (unsigned int output = 0; output < CONV2_NB_OUTPUTS; ++output) {
        fprint_binary(outfile, NB_BITS, outputs[CONV2_OUTPUT_OFFSET + output][oy][ox]);
        fprintf(outfile, " ");
      }
      fprintf(outfile, "\n");
    }
  fclose(outfile);
}

void print_binary(int amount, int num)
{
  assert(amount <= 32);
  for (int i = amount-1; i >= 0; i--)
    printf("%d", (num & (1<<i)) ? 1 : 0);
}

void fprint_binary(FILE* stream, int amount, int num)
{
  assert(amount <= 32);
  for (int i = amount-1; i >= 0; i--)
    fprintf(stream, "%d", (num & (1<<i)) ? 1 : 0);
}

