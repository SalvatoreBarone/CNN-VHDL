#ifndef NEUROMESH_H
#define NEUROMESH_H

#include <inttypes.h>
#include <iostream>

template <
    class data_t,                   /* Base data type for input, weights and outputs. */ 
    class bias_t,                   /* Base data type for biases. */ 
    /* Structural properties of the mesh */
    uint32_t parallel_weights_rows, /* Number of rows of the mesh, i.e. the amount of neurons processing the same inputs */
    uint32_t parallel_inputs_cols,  /* Number of columns of the mesh, i.e. the amount of neurons using the same weights on different inputs */
    /* Structural properties of the input feature map */
    uint32_t input_depth,           /* Number of input channels */
    uint32_t input_height,          /* Height of the input feature map */
    uint32_t input_width,           /* Width of the input feature map */
    /* Convolution parameters */
    uint32_t stride_x,              /* Stride of the convolution */
    uint32_t stride_y,              /* Stride of the convolution */
    uint32_t padding_x,             /* Padding of the convolution */
    uint32_t padding_y,             /* Padding of the convolution */
    /* Structural properties of convolutional kerneln */
    uint32_t conv_kern_height,      /* Kernel height */
    uint32_t conv_kern_width,       /* Kernel width */
    /* Structural properties of the output feature map */
    uint32_t output_depth,          /* Depth of the output volume, Number of filters, implicitely defines the number of kernels */
    uint32_t output_height,
    uint32_t output_width
  >
class neuromesh_t {
  public :
  
    void print_debug_biases_file(std::ostream& stream, const bias_t (&bias)[output_depth]){
      for (int output = 0; output < output_depth; output++) {
        print_binary(stream, 16*sizeof(data_t), bias[output]);
        stream << " ";
        if ((output+1) % parallel_weights_rows == 0) stream << std::endl;
      }
    }
  
    void print_debug_weights_file(std::ostream& stream, const data_t (*weights[output_depth][input_depth])[conv_kern_height][conv_kern_width]) {
      for (unsigned int output = 0; output < output_depth; output++) {
        for (unsigned int channel = 0; channel < input_depth; channel++) {
          if (weights[output][channel] == NULL) continue;
          for (unsigned int sy = 0; sy < conv_kern_height; sy++)
            for (unsigned int sx = 0; sx < conv_kern_width; sx++) {
              print_binary(stream, 8*sizeof(data_t), (*weights[output][channel])[sy][sx]); 
              stream << " ";
            }
        }
        if ((output+1) % parallel_weights_rows == 0) stream << std::endl;
      }
    }

    void print_debug_weights_file(std::ostream& stream, const data_t (&weights)[output_depth][input_depth]) {
      for (unsigned int output = 0; output < output_depth; output++) {
        for (unsigned int channel = 0; channel < input_depth; channel++) {
          print_binary(stream, 8*sizeof(data_t), weights[output][channel]); 
          stream << " ";
        }
        if ((output+1) % parallel_weights_rows == 0) stream << std::endl;
      }
    }

    void print_debug_inputs_file(std::ostream& stream, const data_t (&inputs)[input_depth][input_height][input_width]){
      for (unsigned int oy = 0; oy < output_height; ++oy)
        for (unsigned int ox = 0; ox < output_width; ++ox) {
          const unsigned int sxMin = (unsigned int) int_max((int) padding_x - (int) (ox * stride_x), 0);
          const unsigned int syMin = (unsigned int) int_max((int) padding_y - (int) (oy * stride_y), 0);
          const unsigned int sxMax = (unsigned int) int_max(int_min((int) input_width + padding_x - (int) (ox * stride_x),(int) conv_kern_width),0);
          const unsigned int syMax = (unsigned int) int_max(int_min((int) input_height + padding_y - (int) (oy * stride_y),(int) conv_kern_height),0);
          const int ix = (int) (ox * stride_x) - (int) padding_x;
          const int iy = (int) (oy * stride_y) - (int) padding_y;
          for (unsigned int channel = 0; channel < input_depth; ++channel) {
            for (unsigned int sy = syMin; sy < syMax; ++sy)
              for (unsigned int sx = sxMin; sx < sxMax; ++sx) {
                print_binary(stream, 8*sizeof(data_t), inputs[channel][iy + sy][ix + sx]);
                stream << " ";
              }
          }
          if ((1+ox + oy*output_width) % parallel_inputs_cols == 0) stream << std::endl;
        }
    }

    void print_debug_inputs_file(std::ostream& stream, const data_t (&inputs)[input_depth]){
      for (unsigned int channel = 0; channel < input_depth; ++channel) {
        print_binary(stream, 8*sizeof(data_t), inputs[channel]);
        stream << " ";
      }
      stream << std::endl;
    }
    
    void print_debug_outputs_file(std::ostream& stream, const data_t (&outputs)[output_depth][output_height][output_width]){
      for (int sy = 0; sy < output_height; sy++)
        for (int sx = 0; sx < output_width; sx++) 
         for (int sz = 0; sz < output_depth; sz++) {
           print_binary(stream, 8*sizeof(data_t), outputs[sz][sy][sx]);
           stream << " ";
           if ((1+sz+sx*output_depth+sy*output_depth*output_width) % (parallel_weights_rows*parallel_inputs_cols) == 0) stream << std::endl;
         }
    }

    void print_debug_outputs_file(std::ostream& stream, const data_t (&outputs)[output_depth]){
       for (int sz = 0; sz < output_depth; sz++) {
         print_binary(stream, 8*sizeof(data_t), outputs[sz]);
         stream << " ";
         if ((1+sz) % parallel_weights_rows == 0) stream << std::endl;
       }
    }

  private :
    void print_binary(std::ostream& stream, uint8_t desired_bitwidth, uint32_t data) {
      assert(desired_bitwidth <= 32);
      for (int i = desired_bitwidth-1; i >= 0; i--)
        stream << ((data & (1<<i)) ? '1' : '0');
    }
    int int_max(int a, int b) {return (a > b) ? a : b;}
    int int_min(int a, int b) {return (a < b) ? a : b;}
};

#endif
