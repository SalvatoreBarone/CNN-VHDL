// Copyright 2020-2021	Salvatore Barone <salvatore.barone@unina.it>
// 
// This file is part of CNN-VHDL
// 
// This is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or any later version.
// 
// This is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
// 
// You should have received a copy of the GNU General Public License along with
// RMEncoder; if not, write to the Free Software Foundation, Inc., 51 Franklin
// Street, Fifth Floor, Boston, MA 02110-1301, USA.

#include <iostream>
#include <cassert>
#include <climits>
#include <inttypes.h>
#include <cstdio>
typedef enum 
{
    Logistic,
    LogisticWithLoss,
    FastSigmoid,
    Tanh,
    TanhLeCun,
    Saturation,
    Rectifier,
    Linear,
    Softplus
} 
ActivationFunction_T;

#define NB_BITS 8
#define DATA_T_MAX ((1LL << (NB_BITS - 1)) - 1)
#define DATA_T_MIN (-(1LL << (NB_BITS - 1)))
#define UDATA_T_MAX ((1LL << NB_BITS) - 1)
#define UDATA_T_MIN 0LL

#if NB_BITS > 0 && NB_BITS <= 8
typedef int8_t DATA_T;
typedef uint8_t UDATA_T;
typedef int32_t SUM_T;
typedef SUM_T BDATA_T;
#elif NB_BITS > 8 && NB_BITS <= 16
typedef int16_t DATA_T;
typedef uint16_t UDATA_T;
typedef int64_t SUM_T;
typedef SUM_T BDATA_T;
#elif NB_BITS > 16
typedef int32_t DATA_T;
typedef uint32_t UDATA_T;
typedef int64_t SUM_T;
typedef SUM_T BDATA_T;
#endif

typedef DATA_T WDATA_T;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

DATA_T sat32(SUM_T x, char rs);
UDATA_T usat32(SUM_T x, char rs);
DATA_T usat(SUM_T weightedSum, ActivationFunction_T func, bool unsigned_data, int shift);
void print_binary(int amount, int num);
void fprint_binary(FILE * stream, int amount, int num);

#define INPUT_DEPTH     1
#define KER_WIDTH       5
#define KER_HEIGHT      5
#define ACTIVATION      Linear
#define UNSIGNED_DATA   1
#define SHIFT_AMOUNT    2
#define TEST_VECTORS    100000

#define WEIGHTS_COLS    2
#define INPUTS_ROWS     1


DATA_T single_neuron(
  DATA_T (&inputs)[INPUT_DEPTH][KER_HEIGHT][KER_WIDTH],
  const BDATA_T bias,
  const WDATA_T (&weights)[INPUT_DEPTH][KER_HEIGHT][KER_WIDTH],
  ActivationFunction_T activation,
  bool unsigned_data,
  int shift);


int main()
{
  srand(time(NULL));
  DATA_T inputs[INPUTS_ROWS][INPUT_DEPTH][KER_HEIGHT][KER_WIDTH];
  BDATA_T biases[WEIGHTS_COLS];
  WDATA_T weights[WEIGHTS_COLS][INPUT_DEPTH][KER_HEIGHT][KER_WIDTH]; 
  DATA_T outputs[INPUTS_ROWS][WEIGHTS_COLS];
  for (int test = 0; test < TEST_VECTORS; test++)
  {
    for (int w = 0; w < WEIGHTS_COLS; w++) {
      biases[w] = (BDATA_T) (int16_t) (rand() & 0xffff);
      print_binary(2*NB_BITS, biases[w]); printf(" ");;
      for (int sz = 0; sz < INPUT_DEPTH; sz++)
        for (int sy = 0; sy < KER_HEIGHT; sy++)
          for (int sx = 0; sx < KER_WIDTH; sx++)
          {
            weights[w][sz][sy][sx] =  (WDATA_T) rand();
            print_binary(NB_BITS, weights[w][sz][sy][sx]); printf(" "); 
          }
    }

    for (int i = 0; i < INPUTS_ROWS; i++) {
      for (int sz = 0; sz < INPUT_DEPTH; sz++)
        for (int sy = 0; sy < KER_HEIGHT; sy++)
          for (int sx = 0; sx < KER_WIDTH; sx++)
          {
            inputs[i][sz][sy][sx] = (DATA_T) rand();
            print_binary(NB_BITS, inputs[i][sz][sy][sx]); printf(" ");
          }
    }

    for (int i = 0; i < INPUTS_ROWS; i++)
      for (int w = 0; w < WEIGHTS_COLS; w++) { 
        print_binary(NB_BITS, (DATA_T) single_neuron(inputs[i], biases[w], weights[w], ACTIVATION, UNSIGNED_DATA, SHIFT_AMOUNT)); printf(" "); 
      }
    printf("\n");
  }
}

DATA_T single_neuron(
  DATA_T (&inputs)[INPUT_DEPTH][KER_HEIGHT][KER_WIDTH],
  const BDATA_T bias,
  const WDATA_T (&weights)[INPUT_DEPTH][KER_HEIGHT][KER_WIDTH],
  ActivationFunction_T activation,
  bool unsigned_data,
  int shift)
{
  SUM_T weightedSum = bias;
  for (unsigned int channel = 0; channel < INPUT_DEPTH; ++channel)
  {
    for (unsigned int sy = 0; sy < KER_HEIGHT; ++sy)
      for (unsigned int sx = 0; sx < KER_WIDTH; ++sx)
      {
        SUM_T prod = (SUM_T) weights[channel][sy][sx] * (SUM_T) ((UDATA_T) inputs[channel][sy][sx]);
        weightedSum = weightedSum + prod;
      }
  }
  return usat(weightedSum, activation, unsigned_data, shift);
}

DATA_T sat32(SUM_T x, char rs)
{
    const SUM_T y = (x >> rs);
    return (DATA_T)((y > DATA_T_MAX) ? DATA_T_MAX : (y < DATA_T_MIN) ? DATA_T_MIN : y);
}

UDATA_T usat32(SUM_T x, char rs)
{
    const SUM_T y = (x >> rs);
    return (UDATA_T)((y > UDATA_T_MAX) ? UDATA_T_MAX : (y < 0) ? 0 : y);
}

DATA_T usat(SUM_T weightedSum, ActivationFunction_T func, bool unsigned_data, int shift)
{
    if (shift > 0)
        weightedSum >>= shift;
    else if (shift < 0)
        weightedSum <<= (-shift);

    switch (func) {
    case Tanh:
    case TanhLeCun:

    case Saturation:
    case Linear:
        return sat32(weightedSum, NB_BITS);

    case Logistic:
    case LogisticWithLoss:
        return sat32(weightedSum, NB_BITS + 1);

    case Rectifier:
        if (unsigned_data)
          return usat32(MAX((SUM_T)0, weightedSum), NB_BITS - 1);
        return sat32(MAX((SUM_T)0, weightedSum), NB_BITS);

    default:
        fprintf(stderr, "Unsupported activation function in usat()\n");
        return 0;
    }
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

