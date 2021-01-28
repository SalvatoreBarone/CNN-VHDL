#ifndef CONV1_LAYER_H
#define CONV1_LAYER_H

#include <iostream>
#include <cassert>
#include <climits>
#include <inttypes.h>
#include <cmath>
#include <stdio.h>

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
int int_max(int a, int b);
int int_min(int a, int b);


#define CONV1_NB_OUTPUTS 6
#define CONV1_NB_CHANNELS 1
#define CONV1_OUTPUTS_WIDTH 28
#define CONV1_OUTPUTS_HEIGHT 28
#define CONV1_OUTPUT_OFFSET 0
#define CONV1_OX_SIZE 28
#define CONV1_OY_SIZE 28
#define CONV1_CHANNELS_WIDTH 32
#define CONV1_CHANNELS_HEIGHT 32
#define CONV1_KERNEL_WIDTH 5
#define CONV1_KERNEL_HEIGHT 5
#define CONV1_SUB_SAMPLE_X 1
#define CONV1_SUB_SAMPLE_Y 1
#define CONV1_STRIDE_X 1
#define CONV1_STRIDE_Y 1
#define CONV1_PADDING_X 0
#define CONV1_PADDING_Y 0

#define CONV1_ACTIVATION Rectifier
#define CONV1_SHIFT 2
static const BDATA_T conv1_biases[CONV1_NB_OUTPUTS] = {0, 0, 0, 0, 0, 0};
static const WDATA_T conv1_weights_0_0[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH] = {
    {24, -26, -29, -8, -5},
    {-36, -67, -15, 38, 21},
    {-27, 13, 90, 63, 15},
    {10, 58, 38, -48, -40},
    {4, 10, -41, -65, -20}};
static const WDATA_T conv1_weights_1_0[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH] = {
    {-28, -41, -30, 1, 19},
    {-6, -52, -59, -46, -25},
    {38, -21, -48, -49, -35},
    {63, 52, 17, -3, -1},
    {35, 85, 105, 83, 51}};
static const WDATA_T conv1_weights_2_0[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH] = {
    {-11, -26, -41, -49, -20},
    {-37, -48, -51, -38, 28},
    {-55, -48, -26, 19, 80},
    {-54, -29, 14, 64, 78},
    {-36, -6, 41, 69, 43}};
static const WDATA_T conv1_weights_3_0[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH] = {
    {40, 49, 51, 61, 62},
    {45, 62, 63, 68, 75},
    {9, 15, 5, 3, 18},
    {-45, -50, -58, -60, -30},
    {-54, -60, -66, -59, -32}};
static const WDATA_T conv1_weights_4_0[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH] = {
    {0, 23, 36, 33, 9},
    {-3, 10, 39, 44, 4},
    {-10, -9, 48, 53, 5},
    {-20, -15, 56, 59, 3},
    {-7, -3, 58, 47, 4}};
static const WDATA_T conv1_weights_5_0[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH] = {
    {9, 25, 24, 15, -5},
    {43, 60, 16, -10, -24},
    {81, 52, -17, -32, -27},
    {79, 23, -31, -31, -24},
    {45, 4, -25, -24, -12}};
typedef WDATA_T CONV1_KERNEL_T[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH];
static const CONV1_KERNEL_T* conv1_weights[CONV1_NB_OUTPUTS][CONV1_NB_CHANNELS] = {
    {&conv1_weights_0_0},
    {&conv1_weights_1_0},
    {&conv1_weights_2_0},
    {&conv1_weights_3_0},
    {&conv1_weights_4_0},
    {&conv1_weights_5_0}};


void convcell_upropagate_conv1(
  DATA_T (&inputs)[CONV1_NB_CHANNELS][CONV1_CHANNELS_HEIGHT][CONV1_CHANNELS_WIDTH],
  DATA_T (&outputs)[CONV1_NB_OUTPUTS][CONV1_OUTPUTS_HEIGHT][CONV1_OUTPUTS_WIDTH],
  const BDATA_T (&bias)[CONV1_NB_OUTPUTS],
  const WDATA_T (*weights[CONV1_NB_OUTPUTS][CONV1_NB_CHANNELS])[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH]);

#endif
