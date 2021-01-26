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
#include <cstring>

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

#define FC2_NB_OUTPUTS    10
#define FC2_NB_CHANNELS   84
#define FC2_OUTPUT_OFFSET 0
#define FC2_ACTIVATION    Linear
#define FC2_SHIFT         3
#define FC2_NB_WEIGHTS    (FC2_NB_OUTPUTS*FC2_NB_CHANNELS)
#define TEST_VECTORS      10000

DATA_T sat32(SUM_T x, char rs);
UDATA_T usat32(SUM_T x, char rs);
DATA_T usat(SUM_T weightedSum, ActivationFunction_T func, bool unsigned_data, int shift);
void print_binary(int amount, int num);
void fprint_binary(FILE * stream, int amount, int num);
void fccell_upropagate(
  DATA_T (&inputs)[FC2_NB_CHANNELS],
  DATA_T (&outputs)[FC2_NB_OUTPUTS],
  const BDATA_T (&bias)[FC2_NB_OUTPUTS],
  const WDATA_T (&weights)[FC2_NB_OUTPUTS][FC2_NB_CHANNELS]);

static const BDATA_T fc2_biases[FC2_NB_OUTPUTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const WDATA_T fc2_weights[FC2_NB_OUTPUTS][FC2_NB_CHANNELS] = 
{
    {-1, 1, -6, 0, -6, 0, -1, 0, -2, 0, 0, -1, 2, -1, 98, -2, -1, 0, 95, 95, 0, -2, -3, -3, 0, -2, -1, 0, -1, 93, 0, 0, 0, -6, 0, -3, -1, -2, -6, 0, -2, 0, 0, 0, 94, -2, 95, -1, -1, 59, -2, -3, -1, 0, 0, -1, -1, 0, -3, -5, -2, -3, -6, -6, 0, 93, -5, -1, -1, 94, -1, -1, -1, 0, -2, -1, 0, -1, 0, -1, 0, 21, -1, -1},
    {-1, 1, -1, -1, -1, 0, -1, -1, -1, 95, -1, -1, 5, 0, -1, -1, 93, -1, -1, 0, 0, -1, -1, -1, 0, -1, -1, 92, 94, 0, 94, 0, 0, -1, 0, -1, -1, -1, 0, 87, -1, 0, -1, -1, -1, -1, -1, -1, 91, 1, -1, -1, -1, 0, 0, -1, -1, 95, -1, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, 95, -1, 0, 10, -1, -1},
    {-1, 1, 107, -2, 109, -1, -2, 0, -1, 0, -1, -2, 14, 0, -5, 0, 0, -1, -5, -5, -2, 0, 0, 0, -2, -1, -1, 0, 0, -5, -1, -1, 0, 113, -2, -1, -1, -1, 109, 0, 0, -2, -1, -1, -4, -1, -6, -1, 0, 70, 0, 0, -2, -1, -1, 0, -1, 0, -1, 108, -1, 0, 111, 109, -2, -5, 107, -1, -2, -6, -1, 0, -2, -1, -1, -1, -1, -1, 0, -2, -1, 0, 0, -1},
    {-3, 0, -2, -4, -2, -2, -4, -1, -2, 0, -2, -5, 30, -1, 0, 0, 0, -2, 0, 0, 109, 0, 0, 0, 109, -2, -2, -1, 0, -1, -1, 106, -1, -2, 110, -1, -1, -1, -1, 0, 0, 109, 110, -2, 0, -2, 0, -4, 0, 0, 0, 0, -5, -2, 103, -1, -2, -1, -2, -1, -2, 0, -1, -2, 109, 0, -1, -3, -2, 0, -3, -1, -3, -1, -2, -2, -1, -3, 0, -2, -2, 2, -1, -3},
    {-1, -1, -1, -8, 0, -1, -8, 116, -2, 0, 0, -9, 10, 116, -1, -1, -1, -1, 0, 0, -1, -1, -1, -2, -1, -2, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 117, -1, 0, 1, -1, -1, -1, -1, -1, -1, 0, -7, -1, 0, -1, -2, -8, -1, -1, 114, -1, -1, -2, -1, -2, 0, 0, -1, -1, 0, -1, -9, -1, 0, 77, 119, -7, 117, -1, -1, -1, -2, -1, -1, -1, 11, 118, -1},
    {-1, -1, -1, -2, -1, -1, -3, -1, 111, -1, -1, -3, 14, -1, -2, -4, -1, -1, -2, -2, -2, -3, -3, -3, -2, 114, -3, -1, -1, -2, -1, -2, -1, -1, -1, 112, -1, 116, 0, -1, -3, -3, -1, -1, -2, 110, -2, -2, -1, -1, -4, -4, -3, -1, 0, -1, -3, -1, 111, -1, -3, -4, -1, -1, -2, -2, -1, -2, -4, -1, -2, -1, -3, -1, 109, -2, -1, -2, 0, -3, -1, 34, -1, -2},
    {0, 0, 0, -1, 0, 0, -1, -1, -4, -1, 0, -1, 0, -1, -2, 96, -1, 0, -2, -2, 0, 98, 99, 97, 0, -5, -2, -1, -1, -2, -1, 0, 0, 0, 0, -3, -1, -5, 0, -1, 95, 0, 0, 0, -2, -4, -3, -1, -1, 0, 97, 94, -1, 0, 0, -1, -2, -1, -4, 0, -2, 93, 0, 0, 0, -2, 0, -1, -1, -2, -1, -1, -1, -1, -5, -2, 0, -2, -1, -2, 0, 39, -1, -1},
    {103, 1, -1, -3, 0, 106, -3, -1, -1, -1, 103, -3, 18, -1, 0, 0, -1, 102, 0, 0, -2, 0, 0, 0, -2, -1, -1, 0, -1, 0, -1, -2, 102, -1, -2, -1, -1, -1, -1, 0, 0, -2, -2, 104, 0, -1, 0, -2, -1, 0, 0, 0, -3, 101, -1, -1, -1, -1, -1, -1, -2, 0, -1, -3, -2, 0, -2, -3, -2, 0, 0, 0, -3, -1, -1, -1, 105, -1, 0, -1, 105, 1, -1, -1},
    {-1, 0, -1, -3, -1, -1, -3, -1, -3, 0, -1, -3, 19, -1, -1, -2, 0, -1, -1, -1, -2, -1, -2, -2, -2, -2, 122, -1, -1, -1, 0, -2, -1, -1, -2, -2, -1, -3, -2, -1, -2, -2, -2, -1, -1, -3, -1, -2, -1, 1, -1, -2, -3, -1, -1, -1, 127, -1, -2, -1, 123, -2, -1, -2, -1, 0, -1, -2, 125, 0, -1, -1, -2, -1, -3, 119, -1, 126, -2, 123, -1, 15, -1, 123},
    {-2, 0, -2, 121, -1, -2, 123, -8, -3, -1, -1, 123, 37, -8, -1, -1, -1, -2, -1, -1, -4, -1, -1, -1, -3, -2, -3, 0, -1, 0, -1, -3, -2, -2, -4, -3, -7, -3, -1, 0, -1, -3, -3, -2, 0, -3, 0, 124, -1, -1, -1, -1, 121, -2, -3, -7, -2, -1, -3, -2, -2, -1, -1, -2, -3, 0, -2, 122, -3, -1, 49, -6, 121, -7, -2, -2, -2, -3, 0, -3, -2, 9, -9, -3}
};

int main(int argc, char** argv)
{
  srand(time(NULL));
  DATA_T inputs[FC2_NB_CHANNELS];
  DATA_T outputs[FC2_NB_OUTPUTS];
  for (int test = 0; test < TEST_VECTORS; test++)
  {
    for (int i = 0; i < FC2_NB_OUTPUTS; i++) {
      print_binary(2*NB_BITS, fc2_biases[i]); printf(" ");;
      for (int j = 0; j < FC2_NB_CHANNELS; j++) { 
        print_binary(NB_BITS, fc2_weights[i][j]); printf(" "); 
      }
    }
    memset(inputs, 0, sizeof(DATA_T) * FC2_NB_CHANNELS);
    for (int i = 0; i < FC2_NB_CHANNELS; i++) {
      inputs[i] = (DATA_T) rand();
      print_binary(NB_BITS, inputs[i]); printf(" ");
    }
    memset(outputs, 0, sizeof(DATA_T) * FC2_NB_OUTPUTS);
    fccell_upropagate(inputs, outputs, fc2_biases, fc2_weights);
    for (int i = 0; i < FC2_NB_OUTPUTS; i++) {
      print_binary(NB_BITS, outputs[i]); printf(" "); 
    }
    printf("\n");
  }
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


void fccell_upropagate(
  DATA_T (&inputs)[FC2_NB_CHANNELS],
  DATA_T (&outputs)[FC2_NB_OUTPUTS],
  const BDATA_T (&bias)[FC2_NB_OUTPUTS],
  const WDATA_T (&weights)[FC2_NB_OUTPUTS][FC2_NB_CHANNELS])
{
  for (unsigned int output = 0; output < FC2_NB_OUTPUTS; ++output)
  {
    SUM_T weightedSum = bias[output];
    for (unsigned int channel = 0; channel < FC2_NB_CHANNELS; ++channel)
    {
      SUM_T prod = (SUM_T) weights[output][channel] * (SUM_T) ((UDATA_T) inputs[channel]);
      weightedSum = weightedSum + prod;
    }
    outputs[FC2_OUTPUT_OFFSET + output] = usat(weightedSum, FC2_ACTIVATION, true, FC2_SHIFT);
  }
}


