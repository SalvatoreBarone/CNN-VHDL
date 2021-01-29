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

#define CONV3_NB_OUTPUTS 120
#define CONV3_NB_CHANNELS 16
#define CONV3_OUTPUTS_WIDTH 1
#define CONV3_OUTPUTS_HEIGHT 1
#define CONV3_OUTPUT_OFFSET 0
#define CONV3_OX_SIZE 1
#define CONV3_OY_SIZE 1
#define CONV3_CHANNELS_WIDTH 5
#define CONV3_CHANNELS_HEIGHT 5
#define CONV3_KERNEL_WIDTH 5
#define CONV3_KERNEL_HEIGHT 5
#define CONV3_SUB_SAMPLE_X 1
#define CONV3_SUB_SAMPLE_Y 1
#define CONV3_STRIDE_X 1
#define CONV3_STRIDE_Y 1
#define CONV3_PADDING_X 0
#define CONV3_PADDING_Y 0

#define CONV3_ACTIVATION Rectifier
#define CONV3_SHIFT 2
static const BDATA_T conv3_biases[CONV3_NB_OUTPUTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const WDATA_T conv3_weights_0_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -21, -8, -7, -6},
    {-17, -16, -21, -2, -23},
    {-6, -4, 17, -8, 7},
    {-26, -2, 34, 14, -9},
    {-10, 26, 26, 4, -10}};
static const WDATA_T conv3_weights_0_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {30, 34, 19, -5, 4},
    {27, 9, 2, 11, 13},
    {-25, 7, -6, 20, 13},
    {-11, 12, -10, 0, 6},
    {-9, -8, 15, 31, -4}};
static const WDATA_T conv3_weights_0_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, -18, 12, 32, 22},
    {-18, 10, 5, 25, 5},
    {18, 11, -16, 2, -10},
    {1, -3, -12, -3, -2},
    {14, 6, -1, -20, 8}};
static const WDATA_T conv3_weights_0_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -4, -15, -19},
    {-1, -28, -76, -51, -30},
    {19, -7, -34, 0, -30},
    {-5, -20, -14, 10, 17},
    {-20, -5, 32, 37, 38}};
static const WDATA_T conv3_weights_0_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -16, 6, 12, 16},
    {-5, -10, 12, 10, 11},
    {8, 21, 6, 13, 12},
    {16, 15, -3, 6, 5},
    {6, 10, 8, 3, 6}};
static const WDATA_T conv3_weights_0_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 10, 26, 51, 19},
    {17, -18, -24, 18, -27},
    {-2, -26, -16, 4, -14},
    {9, -11, -24, 15, -10},
    {11, 12, 9, 21, -3}};
static const WDATA_T conv3_weights_0_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -22, -10, 1, -10},
    {11, -18, -7, -18, 4},
    {3, 20, 1, 6, 13},
    {10, 12, 19, 19, 5},
    {-29, -14, -11, 21, 6}};
static const WDATA_T conv3_weights_0_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -9, 42, 9, 53},
    {-6, 11, 26, -4, 41},
    {18, 23, 20, -7, -3},
    {6, 34, 23, 7, -17},
    {-5, 9, -1, -18, 4}};
static const WDATA_T conv3_weights_0_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 31, 15, 3, -29},
    {58, 55, -6, -19, -40},
    {54, 10, 4, 10, -35},
    {-28, -39, -13, 1, -6},
    {-41, -39, -13, 40, 17}};
static const WDATA_T conv3_weights_0_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, -6, -10, -16, -16},
    {20, 2, 17, 19, 2},
    {15, 3, -11, 8, 13},
    {-2, -22, -6, 19, 3},
    {-8, 11, 13, 42, 29}};
static const WDATA_T conv3_weights_0_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -1, -1, -2},
    {3, 5, -3, 1, -2},
    {2, -3, 0, 0, 1},
    {-4, 1, 1, 3, 2},
    {1, 0, 3, 3, 3}};
static const WDATA_T conv3_weights_0_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -9, -6, -6, -4},
    {6, -6, -4, 2, 0},
    {9, 10, 12, 3, -3},
    {10, 8, 2, -1, 0},
    {-3, -3, 8, 6, 7}};
static const WDATA_T conv3_weights_0_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-28, -13, 2, -25, -50},
    {-43, -31, 13, 19, 9},
    {-9, -24, -40, -18, -6},
    {14, -9, -5, -10, -6},
    {26, -6, -5, 11, -3}};
static const WDATA_T conv3_weights_0_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {30, 53, 39, -6, -33},
    {-25, -23, 17, -10, -40},
    {-43, -17, 16, 8, -6},
    {-11, -16, 8, 8, -23},
    {0, 35, 22, 8, -5}};
static const WDATA_T conv3_weights_0_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -27, -33, -14, -26},
    {4, -10, 7, -4, -21},
    {-38, -44, 11, 16, 8},
    {-14, -18, -3, 11, 4},
    {39, 5, 25, 28, 3}};
static const WDATA_T conv3_weights_0_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -23, -13, 0, -25},
    {-4, 12, 32, 78, 76},
    {16, 11, -9, 9, 29},
    {20, 13, -19, 4, 13},
    {-2, -9, -6, 9, 14}};
static const WDATA_T conv3_weights_1_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -6, -5, -4, -4},
    {-5, -3, -5, -4, 1},
    {-4, -5, -8, -1, -1},
    {-2, -3, -8, -1, -3},
    {2, -9, -6, -7, 3}};
static const WDATA_T conv3_weights_1_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 9, 2, 2, 0},
    {-2, -6, -4, -2, 1},
    {-2, -5, -1, -2, -3},
    {-1, -8, -4, -5, -3},
    {-4, -3, 0, -3, -8}};
static const WDATA_T conv3_weights_1_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -7, -4, -5, -4},
    {-6, -6, -1, -3, 2},
    {-1, -2, 1, -2, -3},
    {2, -4, -2, 1, -1},
    {-5, 3, -1, 2, 1}};
static const WDATA_T conv3_weights_1_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -1, -1, 2},
    {-2, -6, -5, -2, -7},
    {-5, 4, 10, -4, 0},
    {8, 5, 2, -3, 2},
    {-4, -5, 1, 7, 5}};
static const WDATA_T conv3_weights_1_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -4, 0, -1},
    {0, -1, 0, -4, -1},
    {1, -2, -1, -4, -3},
    {4, -3, -3, 1, 1},
    {0, 2, -1, -4, -3}};
static const WDATA_T conv3_weights_1_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 3, 6, 1, -5},
    {2, 4, 8, 2, 3},
    {-3, -6, -3, -6, 1},
    {0, -2, -5, -1, -3},
    {0, -2, -4, -3, -6}};
static const WDATA_T conv3_weights_1_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -11, -3, -7, -1},
    {-7, 1, -4, -5, 3},
    {-4, 13, 15, -2, -5},
    {0, 8, 3, -4, 2},
    {1, 5, -4, 2, 2}};
static const WDATA_T conv3_weights_1_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, 1, -1, -2},
    {1, -6, -4, 2, 2},
    {-6, 7, -8, -5, 3},
    {-3, 6, -4, -5, -3},
    {3, -2, 6, 1, -7}};
static const WDATA_T conv3_weights_1_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -5, -7, -2, -1},
    {-10, -8, -4, -6, -4},
    {7, 12, 10, -2, 0},
    {13, 4, -6, -5, 2},
    {-9, -2, -4, -1, 0}};
static const WDATA_T conv3_weights_1_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -8, -7, -10, -9},
    {2, 1, 2, -10, -1},
    {-1, -8, -3, 3, 5},
    {3, 3, -2, -1, -4},
    {-4, -16, -25, -19, -6}};
static const WDATA_T conv3_weights_1_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, 5, -3, -1},
    {-1, 1, -2, 1, 1},
    {0, -1, 0, -4, 0},
    {1, 1, 1, -3, 2},
    {-1, 4, -5, 0, -1}};
static const WDATA_T conv3_weights_1_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, -1, 1, 1},
    {0, 2, 2, -1, 1},
    {0, -1, -1, 2, -2},
    {2, 2, -1, -3, -5},
    {1, -1, 1, -2, 1}};
static const WDATA_T conv3_weights_1_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 10, 17, 15, 7},
    {-4, -9, -5, 2, 0},
    {0, 1, 6, -2, 4},
    {-6, -2, 5, -3, 3},
    {-5, 1, 6, -6, 2}};
static const WDATA_T conv3_weights_1_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 10, 13, 8, 1},
    {-2, 1, 0, -2, -1},
    {2, -5, -3, -3, -3},
    {-2, -4, -4, -2, -1},
    {4, 3, -1, -1, -1}};
static const WDATA_T conv3_weights_1_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -2, -3, -2},
    {6, -6, -8, 2, 1},
    {-6, -8, -5, -1, 1},
    {-2, 2, 0, -2, 1},
    {-7, -16, -13, -8, -2}};
static const WDATA_T conv3_weights_1_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, -1, 1, 1},
    {-4, -1, -7, 1, 2},
    {-4, 13, 0, -10, 1},
    {-7, 7, -5, -1, 7},
    {0, -5, 3, -3, -5}};
static const WDATA_T conv3_weights_2_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, 27, 4, 5, 33},
    {14, 33, 1, -13, 17},
    {4, 15, -1, -5, -8},
    {13, 0, 34, -11, -17},
    {-6, 23, 7, -15, -6}};
static const WDATA_T conv3_weights_2_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, 19, 24, 27, 25},
    {-21, -1, 5, 16, -3},
    {2, 15, 27, -6, 9},
    {-15, -11, -4, -28, -22},
    {8, 0, 12, -8, 5}};
static const WDATA_T conv3_weights_2_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {42, 45, 40, 1, -9},
    {25, 4, 1, -32, -9},
    {17, -21, 26, -9, 19},
    {4, 13, -4, 25, 7},
    {-5, -4, -11, 8, 4}};
static const WDATA_T conv3_weights_2_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, 0, -11, 11},
    {-17, 8, 43, 26, 47},
    {-17, 11, 21, -19, 27},
    {9, 17, -1, -8, -17},
    {12, -9, 14, 22, 7}};
static const WDATA_T conv3_weights_2_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 33, 3, 15, -3},
    {18, 38, 2, 16, 11},
    {16, 23, 22, 9, 16},
    {0, 24, 31, 18, 6},
    {17, 21, 26, 21, 8}};
static const WDATA_T conv3_weights_2_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 5, 2, -8, -3},
    {3, 27, 29, -3, 17},
    {-8, 10, 42, 3, 26},
    {-27, 2, 20, -5, -1},
    {-20, -24, -2, -13, -5}};
static const WDATA_T conv3_weights_2_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, 24, 41, 35, 3},
    {0, 13, -10, 16, 6},
    {-2, -37, 16, 6, -14},
    {-17, -12, 0, -13, -5},
    {0, -28, -3, 12, 12}};
static const WDATA_T conv3_weights_2_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 20, -20, -35, -21},
    {25, 28, -12, -28, -30},
    {16, -8, 15, 7, 3},
    {8, 14, 4, 2, 3},
    {-3, 15, 16, 21, 34}};
static const WDATA_T conv3_weights_2_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -42, -54, 2, 19},
    {-49, -64, -27, 1, 4},
    {-71, -90, -26, -11, -3},
    {-30, -34, 24, 21, 0},
    {21, -34, -24, 19, -13}};
static const WDATA_T conv3_weights_2_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, 0, 11, 18, 62},
    {-12, -7, -1, 23, 4},
    {-5, 25, 11, 10, 0},
    {-10, 11, 7, -1, -9},
    {-8, -26, -22, 6, -13}};
static const WDATA_T conv3_weights_2_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 0, 2, 1},
    {-2, -5, 0, 1, -2},
    {0, 2, 0, -7, -2},
    {0, -1, 3, -2, -1},
    {-3, 1, -1, -2, 3}};
static const WDATA_T conv3_weights_2_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 5, 2, 1},
    {-2, 7, 3, -2, 0},
    {-3, -7, -6, -3, -3},
    {-2, -1, -5, 10, 1},
    {-1, 2, -6, 2, -1}};
static const WDATA_T conv3_weights_2_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {40, 34, 3, 29, 35},
    {36, 44, 13, -10, -8},
    {47, -4, -2, 11, 3},
    {13, 10, 13, -1, -21},
    {-11, 8, 9, -4, -12}};
static const WDATA_T conv3_weights_2_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -18, -25, -3, 23},
    {-35, -57, -56, 1, -3},
    {-23, -56, -33, 4, -16},
    {-18, -22, 6, -2, -24},
    {-27, -16, 15, 2, -13}};
static const WDATA_T conv3_weights_2_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 19, 21, 20, 33},
    {-5, 15, 3, 9, 22},
    {19, 3, -25, -28, -12},
    {16, -14, -27, -6, -20},
    {-6, -2, 29, 6, -32}};
static const WDATA_T conv3_weights_2_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 40, 43, 27, 22},
    {16, 24, -29, -56, -58},
    {12, 32, -4, 6, -6},
    {13, 37, 6, -10, -23},
    {-9, 28, 34, 15, 18}};
static const WDATA_T conv3_weights_3_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 17, 11, -8, -7},
    {10, 28, 17, -4, 0},
    {6, 16, 13, -8, -2},
    {-5, -3, 8, -2, 4},
    {2, 13, 16, 12, 12}};
static const WDATA_T conv3_weights_3_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 8, 1, 2, 9},
    {-1, -2, 4, -1, 5},
    {2, 4, 4, 3, 0},
    {7, -3, -4, -4, -1},
    {-10, -3, -4, -1, 5}};
static const WDATA_T conv3_weights_3_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 1, -1, 1, -2},
    {6, -8, 2, -5, -8},
    {11, -13, -1, -2, 6},
    {4, -4, 4, 6, 12},
    {2, 10, 10, 5, -1}};
static const WDATA_T conv3_weights_3_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 1, 2, 2},
    {-2, 7, 6, -5, -22},
    {2, 3, 1, 6, -20},
    {9, 7, 3, -2, -11},
    {0, 5, 11, 1, -13}};
static const WDATA_T conv3_weights_3_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 15, 11, 10, 2},
    {3, 20, 17, 12, 3},
    {7, 16, 19, 12, 8},
    {5, 9, 13, 13, 11},
    {5, 7, 11, 16, 12}};
static const WDATA_T conv3_weights_3_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, 4, 7, -9},
    {4, -2, 0, 10, -4},
    {2, -10, 9, 22, 4},
    {7, -4, -3, 13, 0},
    {2, -6, -5, 1, -2}};
static const WDATA_T conv3_weights_3_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 2, -4, -2},
    {-14, 3, -3, 8, 5},
    {-8, 0, 5, 13, 0},
    {0, 9, 15, -1, -3},
    {-2, 2, 3, -4, -6}};
static const WDATA_T conv3_weights_3_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, -3, 6, 2},
    {0, 5, 0, -8, 0},
    {0, -2, 10, -15, 0},
    {-4, 1, 7, -23, 5},
    {-2, 9, -1, -29, -5}};
static const WDATA_T conv3_weights_3_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 0, 5, 0, -8},
    {-11, -13, 2, -5, -11},
    {-11, -4, 9, 10, -1},
    {1, 3, 13, 14, 3},
    {-4, 4, 12, 11, 0}};
static const WDATA_T conv3_weights_3_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 12, 10, -7, -23},
    {-2, 4, 17, -10, -17},
    {-8, 4, 2, 9, 3},
    {-2, 2, 2, 13, -7},
    {6, -1, 6, 1, 4}};
static const WDATA_T conv3_weights_3_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 4, 2, -1},
    {2, 3, 3, 2, 0},
    {-2, -1, 0, 2, 1},
    {-1, 0, -1, 1, 0},
    {-3, 3, -3, -2, 1}};
static const WDATA_T conv3_weights_3_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 3, 3, 0},
    {-1, 1, 3, 0, 0},
    {-1, 3, 0, 1, 1},
    {2, 0, 3, 2, -1},
    {1, 1, 2, 3, -2}};
static const WDATA_T conv3_weights_3_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 5, -2, -6, 0},
    {-4, -7, -13, 5, 5},
    {-6, -5, -2, 10, 7},
    {-7, 0, 5, 8, 0},
    {-3, -6, -6, -1, 1}};
static const WDATA_T conv3_weights_3_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -3, -6, 2},
    {-5, 10, 14, 16, 1},
    {6, 7, 0, -3, -9},
    {0, 13, 17, 7, -1},
    {-11, -8, 9, 12, 2}};
static const WDATA_T conv3_weights_3_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 5, -1, -7},
    {5, -9, -2, 7, 7},
    {4, 11, 12, -6, -5},
    {-16, -36, -10, 9, 8},
    {0, -12, -13, 3, 5}};
static const WDATA_T conv3_weights_3_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, 9, 28, 10},
    {5, 6, 14, 22, -11},
    {13, -6, 8, 0, -32},
    {4, 1, 18, 0, -10},
    {2, 11, 6, -3, -14}};
static const WDATA_T conv3_weights_4_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, -8, 5, -1},
    {1, -3, 1, 7, 4},
    {9, 3, -2, 3, 3},
    {8, -2, -2, 3, 1},
    {1, -5, -5, 0, 0}};
static const WDATA_T conv3_weights_4_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 4, 5, -7, -2},
    {-1, -5, -7, -4, -12},
    {-2, 3, 8, 15, 5},
    {-3, -2, -2, -5, -3},
    {4, 1, -3, -4, -3}};
static const WDATA_T conv3_weights_4_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -7, -8, 3, -4},
    {0, -6, -7, -3, -9},
    {-2, -6, -1, -5, -10},
    {-4, 1, -3, -3, -3},
    {1, -1, 0, -6, -5}};
static const WDATA_T conv3_weights_4_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, 0, 0},
    {-2, -2, 0, -7, -3},
    {3, 2, 6, 2, 12},
    {3, 4, -1, -7, -5},
    {9, 5, 0, 4, 6}};
static const WDATA_T conv3_weights_4_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, 5, 0, 1},
    {-1, -2, -1, 0, 0},
    {-5, 4, 2, -1, 2},
    {-5, 3, 1, 0, 0},
    {2, -1, 0, -4, 1}};
static const WDATA_T conv3_weights_4_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -4, -1, -4},
    {-1, 4, -4, 4, -3},
    {-3, 0, 1, 4, -2},
    {-6, 7, -1, 7, 10},
    {-4, -2, -3, -6, -5}};
static const WDATA_T conv3_weights_4_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 10, 14, 4, -2},
    {14, 11, 2, 3, 0},
    {4, -4, 2, -2, -3},
    {-3, 1, -5, 0, -5},
    {-2, -4, -3, 1, -1}};
static const WDATA_T conv3_weights_4_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 0, 0, -1},
    {5, -6, -1, 1, -9},
    {-3, -6, 0, -4, -8},
    {-8, -5, 1, -5, -6},
    {-2, -1, -1, 1, -4}};
static const WDATA_T conv3_weights_4_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 7, 8, 7, 2},
    {8, 6, -3, -2, -6},
    {0, -10, -6, -6, -2},
    {1, -4, -8, 2, 2},
    {10, -2, 6, 0, 1}};
static const WDATA_T conv3_weights_4_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -2, 1, 14, 8},
    {8, 16, 8, 3, -1},
    {11, 1, -14, 1, 3},
    {0, -4, 4, 4, -3},
    {1, -6, -11, -9, -6}};
static const WDATA_T conv3_weights_4_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -1, -2, 2},
    {2, 3, 1, 1, 4},
    {-2, 0, 6, 0, 0},
    {-1, -4, 3, 1, -4},
    {0, 2, 2, -1, -2}};
static const WDATA_T conv3_weights_4_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, 0, 2, 1},
    {-2, -1, 1, -1, -3},
    {1, 0, 0, -4, -3},
    {1, -4, 1, 0, 2},
    {2, 2, 0, 0, 2}};
static const WDATA_T conv3_weights_4_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 10, 16, 11, 4},
    {6, 1, -6, -7, -3},
    {2, 6, 0, -2, 5},
    {2, -1, 0, -1, 3},
    {-3, -4, -5, -5, 1}};
static const WDATA_T conv3_weights_4_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, -5, -3, -7},
    {-6, -7, -8, 0, -4},
    {5, -4, -1, -1, 4},
    {2, -1, -5, -10, -1},
    {-1, 2, 0, 1, 0}};
static const WDATA_T conv3_weights_4_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -5, -2, 1, -1},
    {0, 0, -5, 3, 4},
    {5, 1, -4, -1, -4},
    {10, 7, 8, 2, 2},
    {-4, -10, -4, -6, -2}};
static const WDATA_T conv3_weights_4_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 14, 8, 1, -1},
    {5, -4, -10, -6, -5},
    {0, 4, 0, -2, -5},
    {-2, 2, -5, -3, -4},
    {0, -2, 7, 10, -9}};
static const WDATA_T conv3_weights_5_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -20, -27, -16, -2},
    {3, 2, -1, -2, 3},
    {-3, -7, 16, 15, 11},
    {-5, 3, 14, 28, 19},
    {-11, -1, 7, 14, 8}};
static const WDATA_T conv3_weights_5_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 5, -8, -10, -20},
    {4, 10, -3, -3, 12},
    {-10, 0, -9, -7, 1},
    {-12, -8, -4, -6, -18},
    {-12, -18, -16, -4, 1}};
static const WDATA_T conv3_weights_5_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 53, 45, 24, -9},
    {17, 29, 31, 10, -1},
    {26, 5, 5, -7, -4},
    {11, -8, -16, 5, -8},
    {-5, -9, -7, -7, -2}};
static const WDATA_T conv3_weights_5_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 4, 1, 0, 0},
    {-3, 1, -13, -8, 13},
    {7, 12, -25, -23, -10},
    {21, 1, -2, 10, -4},
    {12, -11, -4, -7, 26}};
static const WDATA_T conv3_weights_5_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 19, 7, 12, 2},
    {2, 14, 4, 6, 4},
    {4, 3, -2, 0, 5},
    {6, 3, -1, 2, 13},
    {6, 3, 5, 5, 2}};
static const WDATA_T conv3_weights_5_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -34, -45, -34},
    {16, 18, 13, -15, 2},
    {2, 4, 2, 2, 16},
    {-5, 7, 0, -1, 5},
    {-4, -17, -17, -8, 14}};
static const WDATA_T conv3_weights_5_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 9, 8, 23, 17},
    {5, 3, 10, 3, 1},
    {-8, 15, 16, 7, 5},
    {-1, 18, 0, 18, -1},
    {4, 5, 4, -1, -1}};
static const WDATA_T conv3_weights_5_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, 37, 23, -7, -15},
    {36, 32, 4, -24, -28},
    {28, -6, 0, -32, -2},
    {19, 3, 2, 4, -6},
    {2, 4, 8, 20, 10}};
static const WDATA_T conv3_weights_5_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -27, -19, -4, 9},
    {3, -23, -20, 7, 16},
    {-16, -29, -11, -10, -16},
    {7, -10, -9, 3, -20},
    {5, -22, -26, -23, -13}};
static const WDATA_T conv3_weights_5_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, -16, -11, 8, 25},
    {19, 16, 16, 22, 17},
    {11, -13, -13, 0, -2},
    {-1, -13, -24, 7, 20},
    {-6, -19, -11, -3, 0}};
static const WDATA_T conv3_weights_5_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 0, 0, -1},
    {-2, -2, 1, -1, 0},
    {-5, -1, 1, 1, 2},
    {-3, -1, 0, -3, 3},
    {1, 0, 0, -3, 0}};
static const WDATA_T conv3_weights_5_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -1, 1, 5, 7},
    {-1, -3, -1, 4, 4},
    {0, -1, -3, 0, -5},
    {9, 5, 0, 3, -5},
    {5, 1, 0, 5, 3}};
static const WDATA_T conv3_weights_5_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 12, 3, -3, 0},
    {22, 19, 28, 5, 2},
    {-7, -7, 10, -9, 4},
    {2, 11, 10, 2, -5},
    {-8, -4, -9, -4, 4}};
static const WDATA_T conv3_weights_5_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -10, -11, -8, 31},
    {-25, -10, 1, -18, 11},
    {-22, -17, -24, -9, -8},
    {-16, -20, -9, -14, -1},
    {6, -6, 13, -2, -11}};
static const WDATA_T conv3_weights_5_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -13, -20, -15, -9},
    {2, 14, 11, -10, -34},
    {6, 4, 7, -5, -8},
    {27, 18, 4, 14, 2},
    {-8, -15, -9, 1, 17}};
static const WDATA_T conv3_weights_5_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 28, 41, 57, 50},
    {10, 12, -7, 15, 25},
    {16, 1, -16, -8, -10},
    {18, -4, -20, -3, -12},
    {6, 2, -4, -11, 0}};
static const WDATA_T conv3_weights_6_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -11, -14, -7, -6},
    {4, -12, -16, -15, -3},
    {-1, -6, -9, -6, 8},
    {-13, -6, -4, -6, 6},
    {-4, 2, -5, -1, 4}};
static const WDATA_T conv3_weights_6_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 10, 4, -1, -8},
    {-6, -9, 17, 18, 11},
    {1, -10, -4, 1, -2},
    {-2, 3, 3, 1, -2},
    {1, -3, 2, 1, 5}};
static const WDATA_T conv3_weights_6_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -13, 10, 3, -3},
    {-7, -10, 5, 10, -9},
    {-1, -10, -2, -1, -10},
    {7, -1, 8, -6, -4},
    {5, 4, -3, -11, -4}};
static const WDATA_T conv3_weights_6_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 5, 2, -6},
    {-17, -12, 3, -2, -11},
    {-1, 4, -6, 0, -10},
    {-3, -9, -1, 4, 4},
    {5, 16, 20, 18, 3}};
static const WDATA_T conv3_weights_6_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, 2, -3, -9},
    {-6, -1, 7, -2, -8},
    {-2, 0, 8, 6, 6},
    {5, -3, 5, 0, 1},
    {3, -8, -10, -10, -8}};
static const WDATA_T conv3_weights_6_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -10, -2, 4, -21},
    {-1, -8, 7, 24, 7},
    {3, -5, -19, 11, 7},
    {2, -2, 10, 9, -1},
    {-3, -3, 4, -2, -3}};
static const WDATA_T conv3_weights_6_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -7, 13, 6, -6},
    {-10, 13, 6, 4, 6},
    {10, 20, -3, 1, 9},
    {12, -6, 0, 3, 0},
    {-4, -1, 7, 11, 3}};
static const WDATA_T conv3_weights_6_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, 6, 8, -4, -10},
    {-6, 0, 9, -5, 0},
    {-1, 1, 17, 14, -6},
    {-1, -1, 22, 4, -8},
    {-2, 6, 14, -5, -7}};
static const WDATA_T conv3_weights_6_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, 7, 4, -3},
    {-14, -15, -8, 1, -1},
    {6, 6, 2, -3, -5},
    {-3, -5, -8, 2, 4},
    {-16, -2, 13, 26, 14}};
static const WDATA_T conv3_weights_6_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -16, -13, -6, -15},
    {6, -11, -6, -17, -14},
    {-12, 4, 3, -8, 0},
    {-9, 6, 22, 3, 3},
    {-8, 3, 7, -18, -14}};
static const WDATA_T conv3_weights_6_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, -3, 2, 6},
    {3, 6, -3, 4, -3},
    {0, 0, 0, 0, -1},
    {1, 2, -1, 1, -1},
    {0, -1, -1, -1, -3}};
static const WDATA_T conv3_weights_6_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, -2, -2, 3},
    {0, -1, -1, 0, 2},
    {-1, -2, 2, 1, -2},
    {-5, 3, 5, 6, 3},
    {-3, -1, 8, 7, 5}};
static const WDATA_T conv3_weights_6_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -5, 8, -7, -10},
    {-17, 13, 14, -9, 9},
    {3, 7, 0, -1, -4},
    {15, 16, 10, 2, 4},
    {14, 2, -9, -2, -3}};
static const WDATA_T conv3_weights_6_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -1, 15, 15, 11},
    {-7, -6, 2, -2, 1},
    {-2, 4, 6, 12, -2},
    {-9, 2, 8, 4, -1},
    {12, 26, 19, 12, 9}};
static const WDATA_T conv3_weights_6_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -14, -3, -5, -9},
    {-4, -4, 1, -2, -8},
    {-1, -9, -14, 2, -2},
    {-10, 5, 14, 22, 15},
    {-16, -1, 9, 9, 9}};
static const WDATA_T conv3_weights_6_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 5, -3, -1, 7},
    {1, 13, -4, 6, -10},
    {6, 5, 15, 5, -17},
    {-1, -4, 21, 2, 3},
    {-7, 3, 2, 1, -21}};
static const WDATA_T conv3_weights_7_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -8, -7, -4, -6},
    {-4, 7, 6, -3, -4},
    {-5, 11, 7, -2, 5},
    {-7, 0, 1, 10, 10},
    {-8, -8, -5, 0, 6}};
static const WDATA_T conv3_weights_7_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 15, 10, -3, 2},
    {-7, -1, 2, -5, -10},
    {-11, 1, 20, 15, 4},
    {4, 4, 8, 3, 5},
    {0, 0, 0, 5, 6}};
static const WDATA_T conv3_weights_7_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -8, -10, -6, 1},
    {0, -11, 0, -9, -7},
    {7, -15, 3, -9, -3},
    {1, 1, -5, 4, 3},
    {3, -1, -9, -9, -8}};
static const WDATA_T conv3_weights_7_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -4, 0, -2, -1},
    {-8, -4, 0, -3, 7},
    {-5, -8, 0, 3, 6},
    {3, -2, -11, -19, -1},
    {-4, -6, -2, 5, 4}};
static const WDATA_T conv3_weights_7_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, 0, -1, -3},
    {-1, 3, 2, 4, 5},
    {5, 8, 8, 0, 1},
    {0, 3, 0, -3, -2},
    {2, -2, 3, -9, 2}};
static const WDATA_T conv3_weights_7_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 0, 13, 10},
    {3, 7, 1, 3, -9},
    {0, -13, -3, 11, -2},
    {-3, -3, 9, 21, 13},
    {-1, -6, -1, 1, 6}};
static const WDATA_T conv3_weights_7_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 13, 14, -2, -1},
    {4, 13, 1, 8, 3},
    {-7, -13, 2, -1, 0},
    {6, 1, -4, -5, -1},
    {0, -10, -4, -5, -3}};
static const WDATA_T conv3_weights_7_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 4, -4, -4, 3},
    {-2, 7, 5, 1, 1},
    {0, 23, 24, -8, -12},
    {-8, 10, 13, -7, -7},
    {-7, 0, 16, 9, -1}};
static const WDATA_T conv3_weights_7_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 12, 19, 7, 5},
    {10, 18, -12, -6, -9},
    {0, -12, -10, 1, -14},
    {9, -9, -15, 4, 0},
    {7, -2, -6, -12, -5}};
static const WDATA_T conv3_weights_7_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -15, 10, 16, 0},
    {-3, 7, 11, -9, 4},
    {-5, -21, -17, 15, 4},
    {-12, -11, 3, 6, -7},
    {0, -5, -17, -18, -6}};
static const WDATA_T conv3_weights_7_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -5, -1, 0},
    {1, 5, 0, 1, -1},
    {-2, 0, 1, -3, 4},
    {-2, 1, 0, 1, -1},
    {-2, -3, 2, -1, -2}};
static const WDATA_T conv3_weights_7_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -2, 1, 3},
    {3, -1, 2, -4, -2},
    {3, 5, 2, -1, 2},
    {2, 4, -2, -2, 1},
    {-1, 2, 1, 2, 2}};
static const WDATA_T conv3_weights_7_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 10, 17, 2, -4},
    {9, 6, -11, -8, -1},
    {7, -1, -2, -8, -2},
    {6, -3, 3, 6, 9},
    {-1, -8, -8, 1, -2}};
static const WDATA_T conv3_weights_7_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 14, 17, 0, -9},
    {-8, -13, -3, -2, 2},
    {11, -7, -6, -7, -3},
    {20, 9, -6, -1, 7},
    {1, 3, -5, 3, 2}};
static const WDATA_T conv3_weights_7_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -7, -16, -10, -3},
    {-5, -17, -14, 0, -2},
    {-1, 11, 16, -6, -6},
    {-8, 8, 27, 17, 6},
    {-23, -19, -15, -4, 10}};
static const WDATA_T conv3_weights_7_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 21, 8, 8, 10},
    {-2, -8, -10, 12, 2},
    {-7, -3, 16, 6, 13},
    {-5, 1, 12, 9, 14},
    {-3, 4, -7, -4, -15}};
static const WDATA_T conv3_weights_8_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -3, 5, 0, -3},
    {-2, -3, -2, -1, 3},
    {-5, -4, -1, 6, 13},
    {-8, -16, -7, 10, 7},
    {-6, -4, 0, 0, 0}};
static const WDATA_T conv3_weights_8_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 14, 7, 4, 4},
    {0, 1, 8, 10, -2},
    {-7, -7, 0, 5, 15},
    {-3, -2, 3, -3, 9},
    {-4, -5, -2, 5, 2}};
static const WDATA_T conv3_weights_8_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, -4, 9, 2},
    {1, -9, -4, 3, 3},
    {4, -8, -3, 1, 4},
    {0, -4, -2, -3, 0},
    {1, -11, 1, -8, 0}};
static const WDATA_T conv3_weights_8_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 0, -3, 0},
    {-7, -11, -12, 1, 4},
    {-7, -16, -8, -2, -1},
    {-4, -1, 1, -9, 8},
    {4, -8, -9, -4, 1}};
static const WDATA_T conv3_weights_8_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -6, 0, 0, 2},
    {0, -6, 3, 0, -1},
    {5, 7, 4, -4, -1},
    {1, 3, 1, -3, 0},
    {-3, 0, 1, -2, 2}};
static const WDATA_T conv3_weights_8_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 5, 10, 13, 9},
    {0, -2, 0, 3, 2},
    {-3, -5, -9, -8, 2},
    {-6, -12, -3, -1, 8},
    {-2, -8, -8, -7, 4}};
static const WDATA_T conv3_weights_8_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 13, -2, 3, 1},
    {14, 4, -2, 0, -3},
    {-6, -6, -11, -10, 0},
    {3, 0, -11, 1, 0},
    {-5, -12, -7, -1, 0}};
static const WDATA_T conv3_weights_8_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -7, -1, -1},
    {1, 1, 6, 9, 6},
    {-3, 12, 10, 11, 10},
    {-3, 9, 9, 18, 19},
    {-6, 0, 8, 13, 19}};
static const WDATA_T conv3_weights_8_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 2, 5, 3, 3},
    {8, 14, 0, -6, -5},
    {-4, -8, -14, -14, -6},
    {4, 5, -7, 4, 3},
    {-1, -17, -10, -11, -6}};
static const WDATA_T conv3_weights_8_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -6, 3, 11, 7},
    {-11, 15, 1, -6, -1},
    {12, -5, -29, -12, -6},
    {-8, -13, -6, -5, 8},
    {-1, 15, -2, -1, 11}};
static const WDATA_T conv3_weights_8_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, 0, 0, 0},
    {3, 1, 0, 1, -4},
    {1, -1, -1, 1, -1},
    {-3, 0, 1, 2, 0},
    {0, 0, -2, -3, 3}};
static const WDATA_T conv3_weights_8_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 1, -1, 1},
    {-2, -1, -2, 0, -4},
    {-1, 4, -1, 0, -3},
    {5, 4, 1, 2, -2},
    {-1, 0, 4, -1, -2}};
static const WDATA_T conv3_weights_8_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 11, 0, -4, -6},
    {23, 2, -7, 4, 5},
    {3, -17, -16, -6, -1},
    {-1, -7, -10, -2, 0},
    {4, -8, -2, 3, 2}};
static const WDATA_T conv3_weights_8_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 4, 1, 2, -7},
    {-3, -11, -12, -8, -7},
    {2, -10, -18, -10, 0},
    {2, -9, -4, -3, -7},
    {-9, 1, -2, -1, -3}};
static const WDATA_T conv3_weights_8_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -9, -11, -3},
    {-5, -7, 0, 4, -2},
    {-1, 1, -6, 2, 4},
    {5, 7, 6, 8, 6},
    {-1, -4, 5, 11, 19}};
static const WDATA_T conv3_weights_8_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 7, -1, -3, 2},
    {-2, -7, -8, -4, 8},
    {-5, -12, -6, 6, 12},
    {-8, -3, -4, -8, -16},
    {-4, 1, 2, -16, -3}};
static const WDATA_T conv3_weights_9_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, -5, -2, 2},
    {-2, 0, -2, 1, 0},
    {1, 5, -3, -2, 1},
    {-2, 5, 7, 9, 3},
    {-2, -1, -4, -2, -1}};
static const WDATA_T conv3_weights_9_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 6, 5, -1, -6},
    {1, -4, -3, -4, -7},
    {-2, -3, 0, 0, 0},
    {-3, 5, -4, -2, 2},
    {1, -2, -2, 1, 4}};
static const WDATA_T conv3_weights_9_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -7, 2, 2, -1},
    {0, -4, 8, 1, -1},
    {-1, -1, 3, 5, 2},
    {3, 4, -1, 3, 2},
    {-3, -3, -3, 0, 2}};
static const WDATA_T conv3_weights_9_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, 0, 0, -2},
    {0, 3, -2, -9, -3},
    {3, 5, 5, -3, 5},
    {1, -1, -3, -8, -5},
    {-3, -1, -3, -2, -2}};
static const WDATA_T conv3_weights_9_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, 2, 1, 0},
    {2, 1, 1, 4, 0},
    {4, -4, 1, -1, -1},
    {-1, -1, 2, -1, -1},
    {-3, 3, 5, -2, 2}};
static const WDATA_T conv3_weights_9_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 4, 2, 5, -2},
    {-4, 0, -1, 1, -2},
    {-3, -4, 0, -3, -2},
    {-2, 1, 8, 4, 4},
    {-2, -3, -1, 1, 2}};
static const WDATA_T conv3_weights_9_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -7, 1, 5},
    {7, 2, 5, -3, 1},
    {7, 3, 4, -3, 3},
    {-1, -5, -6, 1, -2},
    {-2, -2, 2, 1, -5}};
static const WDATA_T conv3_weights_9_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 2, -3, -3},
    {1, 3, 6, 5, -8},
    {4, 3, 0, 1, -6},
    {0, 1, -3, -4, -5},
    {-1, 1, 2, 7, 0}};
static const WDATA_T conv3_weights_9_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -5, 3, 1},
    {3, 3, -1, -2, -1},
    {0, -4, 0, -2, -1},
    {-2, -6, -3, -2, -4},
    {3, 4, 11, 0, -4}};
static const WDATA_T conv3_weights_9_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 4, 2, 4, 9},
    {1, 2, -4, 2, 1},
    {1, -3, -5, -3, -1},
    {1, 4, 4, 2, -2},
    {-2, -5, -10, -6, 1}};
static const WDATA_T conv3_weights_9_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 0, -1, 1},
    {-4, -1, -1, -3, 1},
    {3, 1, 1, -1, -5},
    {5, 3, 3, -6, 2},
    {2, 0, -1, 0, 2}};
static const WDATA_T conv3_weights_9_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, 1, -2, 0},
    {1, -1, -3, 1, 2},
    {-1, -2, 2, 0, -2},
    {1, 0, 0, 1, -1},
    {0, 0, 0, 3, 6}};
static const WDATA_T conv3_weights_9_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 5, 6, -1},
    {6, 1, -2, -1, -4},
    {6, -1, 4, -2, 4},
    {0, 2, 7, 5, 5},
    {-10, -5, -4, 0, -2}};
static const WDATA_T conv3_weights_9_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, 0, -7, -6},
    {-5, -2, -6, -5, 0},
    {-2, -6, 1, -6, 1},
    {0, 0, -2, 0, 3},
    {-1, -2, -6, -5, -5}};
static const WDATA_T conv3_weights_9_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 3, 4, -3, -4},
    {1, -4, -3, -1, 2},
    {-5, -3, -5, -5, -1},
    {4, 10, 11, 3, -2},
    {-3, -5, -4, -10, -8}};
static const WDATA_T conv3_weights_9_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -4, -4, 0, -3},
    {-3, -7, -8, -2, 6},
    {-2, 7, 3, 7, 9},
    {-4, 2, -4, 3, -2},
    {-1, 3, -5, -11, -2}};
static const WDATA_T conv3_weights_10_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -9, -8, 2},
    {-6, 3, -22, -29, -5},
    {10, 15, -11, -25, 3},
    {8, -4, -2, -1, 7},
    {-4, -7, -1, 4, 5}};
static const WDATA_T conv3_weights_10_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 9, 6, -1, -5},
    {0, -6, -1, -5, -6},
    {-9, -8, 3, -4, -6},
    {-5, -3, -20, -40, -14},
    {0, -5, -5, -11, -2}};
static const WDATA_T conv3_weights_10_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 26, 25, 14},
    {7, -10, 10, 16, 15},
    {8, -20, 1, 6, 11},
    {4, 20, 3, 11, 18},
    {10, 10, 8, 7, 3}};
static const WDATA_T conv3_weights_10_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, 1, 0, -5},
    {-5, -9, -9, -23, -16},
    {-9, -10, -8, -34, -20},
    {5, 11, 0, -7, 1},
    {11, 15, 3, 11, 2}};
static const WDATA_T conv3_weights_10_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -1, 3, 5},
    {7, 6, 14, 10, 2},
    {2, 8, 24, 11, 1},
    {-4, 9, 8, 8, 0},
    {0, 12, 14, 4, 4}};
static const WDATA_T conv3_weights_10_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -9, 10, 23, 6},
    {3, 10, 6, -1, -9},
    {-1, -6, 16, 15, -13},
    {-11, 8, 10, 10, 2},
    {-5, -8, -4, 4, 1}};
static const WDATA_T conv3_weights_10_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 20, 2, 12, 7},
    {16, 11, -23, 2, 5},
    {13, -23, -3, 5, -8},
    {-1, -3, 8, 2, -5},
    {-1, -4, -6, -15, -8}};
static const WDATA_T conv3_weights_10_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 8, 12, -8, 7},
    {6, 5, 6, 27, 20},
    {5, -8, 18, 18, 10},
    {4, 8, 17, -11, 8},
    {0, 21, 19, 8, 19}};
static const WDATA_T conv3_weights_10_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 6, 1, 5, 1},
    {1, -15, -13, -7, -17},
    {-34, -52, -16, -3, -17},
    {-16, -19, 5, 12, -2},
    {20, 15, 3, -9, -15}};
static const WDATA_T conv3_weights_10_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 13, 11, -2, 5},
    {4, 23, 8, 8, 12},
    {-3, 8, 3, 17, 4},
    {10, 2, -14, -9, -3},
    {4, -17, -34, -2, -15}};
static const WDATA_T conv3_weights_10_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, -4, -1, 0},
    {3, 0, -1, -3, 1},
    {1, -1, -1, 1, 1},
    {2, -1, -2, -1, 4},
    {1, 1, -4, 1, -1}};
static const WDATA_T conv3_weights_10_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, -1, 1, -1},
    {-2, 3, 3, -1, -5},
    {2, -6, -2, -1, 1},
    {0, 1, 0, 2, 0},
    {2, -1, -1, 0, -1}};
static const WDATA_T conv3_weights_10_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 25, 14, 20, -10},
    {11, 10, 20, 17, -5},
    {7, -4, 7, 24, 1},
    {6, 14, 18, 19, 2},
    {-7, 19, 1, 1, -2}};
static const WDATA_T conv3_weights_10_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -11, -18, -20, -30},
    {-28, -25, -14, 2, -29},
    {-12, -16, -10, -10, -21},
    {2, 11, 4, -5, -3},
    {-9, -13, -2, 2, -2}};
static const WDATA_T conv3_weights_10_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -13, -17, -6, -11},
    {1, 7, -2, -7, -3},
    {17, 23, 15, -14, -9},
    {17, -6, -11, -26, 0},
    {1, -14, -12, -14, 8}};
static const WDATA_T conv3_weights_10_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 1, 2, -20, -12},
    {12, 8, -9, -5, -2},
    {8, 24, 16, 6, 35},
    {-2, 17, 14, 11, -12},
    {-4, 14, 10, 2, -6}};
static const WDATA_T conv3_weights_11_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 30, 20, 0, -8},
    {23, 14, 17, 19, 25},
    {-5, -14, 6, 11, 17},
    {21, -24, 3, -2, -26},
    {36, 33, 18, -18, -17}};
static const WDATA_T conv3_weights_11_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 5, -17, -15, 5},
    {-13, -1, -10, -15, -11},
    {20, 0, -7, 4, 35},
    {32, 21, 2, 26, 45},
    {11, -1, 12, 27, 34}};
static const WDATA_T conv3_weights_11_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, -16, 18, 30, -2},
    {-15, -33, 2, -10, -5},
    {-20, 5, -5, 3, -2},
    {-15, 2, 10, 22, -18},
    {-3, 3, 22, -12, 6}};
static const WDATA_T conv3_weights_11_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, 2, 8, 4},
    {-4, -5, -2, 7, -24},
    {5, -12, -20, 32, 13},
    {-9, -36, 1, 15, -9},
    {-15, -31, -19, -5, -46}};
static const WDATA_T conv3_weights_11_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -11, 12, -5, -2},
    {-3, -2, 18, -8, -9},
    {9, 7, 8, 4, -19},
    {0, 13, 6, 4, -9},
    {-1, 4, -3, 20, 9}};
static const WDATA_T conv3_weights_11_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 4, 6, 2, -2},
    {6, -20, -13, 4, -21},
    {7, -6, -16, 6, -6},
    {3, 7, -11, 43, 22},
    {4, 5, -12, 27, 16}};
static const WDATA_T conv3_weights_11_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -19, -21, 2, -2},
    {-23, -1, 9, -7, -18},
    {-31, -18, -11, -24, -18},
    {-44, -21, -3, -14, -17},
    {-20, -4, 21, 16, 3}};
static const WDATA_T conv3_weights_11_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -17, -7, 5, -32},
    {-17, -7, 37, 18, -38},
    {-27, -17, 57, 24, -2},
    {-30, -25, 18, 7, 12},
    {-5, 9, 0, -7, 29}};
static const WDATA_T conv3_weights_11_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 2, 7, 12, 6},
    {12, 2, 17, 1, -10},
    {15, 4, 29, -4, 3},
    {29, 27, -3, 10, -3},
    {35, 44, 11, 30, -15}};
static const WDATA_T conv3_weights_11_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 12, 12, 0, 6},
    {-9, 17, 14, 15, 17},
    {-23, 6, 12, -41, -47},
    {-1, 4, -29, -10, -27},
    {-24, -14, 12, 38, 28}};
static const WDATA_T conv3_weights_11_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -1, 1, 0},
    {-5, 0, 2, 1, 0},
    {-1, 0, 0, -1, 0},
    {1, 4, -1, 1, 1},
    {2, 1, 2, 3, 0}};
static const WDATA_T conv3_weights_11_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, -1, 3, -1},
    {-1, 1, 6, 6, 2},
    {5, 9, 5, -1, 2},
    {-4, 2, 3, 2, -1},
    {0, 1, -10, -15, -10}};
static const WDATA_T conv3_weights_11_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-25, 12, 17, 28, 9},
    {-32, -12, -39, -6, -7},
    {-30, 14, -43, -14, -4},
    {-33, 44, 5, -24, -7},
    {-24, 12, -6, 7, -9}};
static const WDATA_T conv3_weights_11_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 18, 1, -18, -9},
    {6, -7, -3, -11, -19},
    {45, 37, 26, -1, -8},
    {27, 37, 28, -8, -18},
    {23, 7, -16, -18, -25}};
static const WDATA_T conv3_weights_11_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, -1, -5, -19, -20},
    {23, -5, -6, 11, 12},
    {20, 1, -11, 2, 10},
    {-10, -18, -24, 4, -24},
    {-25, -11, -6, -19, -51}};
static const WDATA_T conv3_weights_11_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -8, 3, 46, 42},
    {5, 3, -17, -5, 36},
    {-14, -17, -17, -3, -43},
    {-19, 29, -33, -14, -32},
    {1, 23, 12, -6, 25}};
static const WDATA_T conv3_weights_12_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 25, 46, 18, -23},
    {6, 29, 27, 20, 8},
    {5, 39, 31, 9, 13},
    {25, 26, 18, -1, 6},
    {1, 26, 13, -6, -3}};
static const WDATA_T conv3_weights_12_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 4, 14, 18, 16},
    {-6, 10, 25, 9, -9},
    {14, 10, -15, 15, 25},
    {-9, -13, 5, 16, 21},
    {4, -10, -3, 23, 16}};
static const WDATA_T conv3_weights_12_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -64, -83, -43, -7},
    {-6, -29, -45, -39, 1},
    {-8, 14, -33, 8, 10},
    {7, -29, -28, 18, 6},
    {5, -7, -10, 26, 16}};
static const WDATA_T conv3_weights_12_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, 6, 9, 18},
    {15, 8, -19, 4, 23},
    {13, 0, -3, 27, 20},
    {2, -16, 14, 21, 16},
    {-37, -15, -3, -33, -43}};
static const WDATA_T conv3_weights_12_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -6, 7, 0, -6},
    {10, 3, -13, 2, 3},
    {8, 11, -3, 12, -3},
    {9, 1, -1, 4, 4},
    {-4, -6, 7, 9, 7}};
static const WDATA_T conv3_weights_12_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 5, 4, 0, -1},
    {5, -24, -16, -2, 10},
    {17, -8, -17, 16, 26},
    {-1, -6, -22, 2, 13},
    {-8, -4, -27, 3, 10}};
static const WDATA_T conv3_weights_12_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, -1, -5, -36, -9},
    {-17, 8, 13, -2, 7},
    {-3, 2, 2, -1, 5},
    {19, 12, 11, -9, -14},
    {-5, 9, -5, -7, -22}};
static const WDATA_T conv3_weights_12_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, -25, -19, -6, -7},
    {-36, -21, -4, 10, 1},
    {-28, 12, -25, -26, 1},
    {-21, -29, -20, 15, 22},
    {-6, -28, 20, 2, 20}};
static const WDATA_T conv3_weights_12_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 30, 16, -1, -5},
    {-1, -2, -26, 2, 11},
    {26, 38, 22, 11, 6},
    {20, 9, 1, -1, 19},
    {-18, 16, 3, 7, -4}};
static const WDATA_T conv3_weights_12_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {27, 27, 8, -2, -31},
    {-5, -8, 9, 11, 21},
    {-45, -3, 47, 7, -25},
    {11, 28, 32, -16, -38},
    {-9, 15, 13, -10, 3}};
static const WDATA_T conv3_weights_12_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 3, 2, 0},
    {5, 1, -3, -3, 1},
    {7, -1, 2, 0, 1},
    {1, 1, -3, -1, 0},
    {-1, 2, 1, -1, -5}};
static const WDATA_T conv3_weights_12_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 4, -1, 1, -2},
    {6, 1, 2, -2, 7},
    {8, 17, 4, 8, 8},
    {1, 11, 12, -2, -9},
    {1, 4, 5, -5, -1}};
static const WDATA_T conv3_weights_12_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -28, -27, -13, -15},
    {-15, -7, -57, 0, -4},
    {11, 5, -29, 0, 4},
    {3, -3, 2, -12, -25},
    {5, -2, -3, -8, -8}};
static const WDATA_T conv3_weights_12_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 46, 45, 5, -6},
    {43, 28, 22, 26, 42},
    {35, 17, 5, -4, 6},
    {-6, -7, -19, 2, -11},
    {20, 18, -11, 7, 4}};
static const WDATA_T conv3_weights_12_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -1, -6, -2},
    {21, -10, -4, -6, -13},
    {-17, -20, -15, -11, 19},
    {-25, 21, 31, -3, 1},
    {9, 19, 18, -14, -27}};
static const WDATA_T conv3_weights_12_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -3, -20, 4, 0},
    {-11, -7, -9, 37, 38},
    {3, -16, 1, 28, 12},
    {-15, -21, -44, -9, -2},
    {1, -12, -38, 0, 6}};
static const WDATA_T conv3_weights_13_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {27, 13, 2, -15, -4},
    {-3, -17, -31, 6, -8},
    {19, 4, -17, 6, -10},
    {22, -12, -13, 13, 5},
    {-27, -40, 2, 17, 28}};
static const WDATA_T conv3_weights_13_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 8, -4, 16, 7},
    {4, 3, 2, -18, 26},
    {-14, -20, -15, -37, -14},
    {-3, 0, -72, -98, -54},
    {5, -16, -62, -68, -14}};
static const WDATA_T conv3_weights_13_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 21, 16, 5, 15},
    {27, 8, 10, 18, 28},
    {46, 31, -2, -2, 12},
    {17, -14, -26, 17, 6},
    {-17, -21, 3, 13, -10}};
static const WDATA_T conv3_weights_13_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 0, -3, -2},
    {-3, 2, -23, -26, -5},
    {23, 31, 5, -20, -11},
    {16, 33, 4, -16, -13},
    {8, -20, -6, 22, 46}};
static const WDATA_T conv3_weights_13_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 17, 9, -1, -13},
    {19, 6, 1, 7, -5},
    {14, -5, 18, 9, -12},
    {3, -1, 24, 11, -4},
    {-3, 20, 36, 6, 0}};
static const WDATA_T conv3_weights_13_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 41, 18, 1, -5},
    {15, 17, 5, -9, 29},
    {-13, 2, -17, -15, 20},
    {-29, 7, 0, -37, -28},
    {-20, -38, -34, -17, -26}};
static const WDATA_T conv3_weights_13_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 17, 9, 21, 6},
    {22, 9, 19, 4, 5},
    {-23, -14, -12, 28, 3},
    {-27, 3, -4, 21, 10},
    {68, 55, 19, -24, 12}};
static const WDATA_T conv3_weights_13_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 20, -4, -38, -40},
    {26, 11, -6, 4, -5},
    {44, -15, -11, 0, 49},
    {32, -10, 3, 18, 52},
    {-7, -5, 22, 53, 58}};
static const WDATA_T conv3_weights_13_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -16, -8, -2, 1},
    {-17, -16, 28, 9, -24},
    {-33, 3, 30, -3, -28},
    {-16, 20, 14, 15, -19},
    {26, 34, -37, -68, -56}};
static const WDATA_T conv3_weights_13_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 19, 0, 28, 28},
    {9, 17, -4, 15, -6},
    {10, -37, -43, 3, 32},
    {-3, -4, -38, 21, 27},
    {18, -18, -108, -92, -73}};
static const WDATA_T conv3_weights_13_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, -3, -1},
    {0, -1, 0, 2, -3},
    {-1, 2, -4, 3, 0},
    {-3, 3, -4, 5, -3},
    {0, 1, -1, 1, -3}};
static const WDATA_T conv3_weights_13_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -1, 3, 0},
    {-3, 2, -4, -2, -4},
    {-2, 4, -3, 2, 0},
    {12, -1, -10, 2, -3},
    {0, -11, -9, 10, 1}};
static const WDATA_T conv3_weights_13_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {25, 16, 19, 17, -10},
    {31, 10, 16, 17, -4},
    {-1, 5, 59, 12, 1},
    {-31, 21, 68, 54, 13},
    {-12, 11, -14, -17, -9}};
static const WDATA_T conv3_weights_13_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, -13, -26, -11, 21},
    {-36, -7, -8, -8, 1},
    {-33, -16, 25, 7, -24},
    {5, -4, -11, -19, -17},
    {-23, -36, -15, -27, -28}};
static const WDATA_T conv3_weights_13_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {30, 34, 8, 11, -2},
    {-3, 25, 8, 7, 0},
    {0, 37, 44, -9, 0},
    {41, 46, 11, -14, -1},
    {-81, -99, -79, -41, 21}};
static const WDATA_T conv3_weights_13_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 11, 25, 54, 39},
    {-14, 2, -1, 15, 3},
    {21, 40, -18, 5, -5},
    {14, 13, 17, 16, 22},
    {-2, 25, 38, 10, -10}};
static const WDATA_T conv3_weights_14_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 40, 46, 17, 25},
    {26, 45, 32, 5, 30},
    {-1, 14, -9, -6, -6},
    {4, 2, 3, -17, -24},
    {19, 37, 19, -9, -6}};
static const WDATA_T conv3_weights_14_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-38, -16, 5, 8, 8},
    {-24, 3, 10, 13, 6},
    {9, 16, 31, 4, 10},
    {-15, -15, 7, 21, 8},
    {-4, -15, 13, 6, 10}};
static const WDATA_T conv3_weights_14_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {35, 28, 25, -6, -5},
    {12, 11, 9, -20, -16},
    {-7, -8, 35, 10, 2},
    {-9, -4, 23, 26, -1},
    {-1, -4, 10, 13, -5}};
static const WDATA_T conv3_weights_14_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 2, 8, 24},
    {-20, 8, 53, 50, 35},
    {-20, -1, 11, 12, 24},
    {0, 12, 6, 7, -7},
    {-2, -6, 7, 2, -24}};
static const WDATA_T conv3_weights_14_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 16, 1, 0, -5},
    {2, 15, -8, 0, -3},
    {0, -4, -5, -6, 3},
    {-9, 14, 2, 12, 0},
    {13, 13, 2, 19, -2}};
static const WDATA_T conv3_weights_14_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -22, -23, -31, -15},
    {-20, 25, 13, -6, 0},
    {-10, 23, 45, 10, 14},
    {-4, -5, 28, 1, -5},
    {-11, -14, 9, 0, 3}};
static const WDATA_T conv3_weights_14_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {41, 51, 59, 18, 1},
    {-5, 2, -5, -1, -3},
    {10, -29, -13, -21, -17},
    {13, -14, -21, -14, -10},
    {11, -40, -17, 7, 5}};
static const WDATA_T conv3_weights_14_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 17, -17, -16, -30},
    {3, -7, -1, -27, -40},
    {-5, -26, 10, 26, -17},
    {-4, -22, 11, 25, -7},
    {5, 4, 0, -1, -4}};
static const WDATA_T conv3_weights_14_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -22, -21, 9, 17},
    {-71, -64, -32, -4, 15},
    {-62, -40, -8, -6, 8},
    {-3, 1, 6, 1, 21},
    {9, -23, -20, 8, 11}};
static const WDATA_T conv3_weights_14_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, 5, 14, 22, 20},
    {-22, -31, 4, -19, -27},
    {-19, 13, 26, -8, 1},
    {-6, 12, 12, -15, -18},
    {-12, -15, 17, 21, 9}};
static const WDATA_T conv3_weights_14_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 5, -1, -2, -1},
    {1, 0, 1, 1, -1},
    {2, 0, -2, 1, -2},
    {1, 0, 2, -1, 2},
    {0, -1, -3, 3, 6}};
static const WDATA_T conv3_weights_14_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 6, 3, 7, 0},
    {1, 8, 1, -3, 0},
    {-3, -11, -8, -8, 0},
    {-13, -7, -8, -2, -1},
    {-2, 4, -4, -7, -2}};
static const WDATA_T conv3_weights_14_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 10, -15, 10, 47},
    {4, 37, 13, -34, -10},
    {26, 31, -6, 4, 5},
    {12, 28, -6, 3, -7},
    {1, 9, -9, -10, 1}};
static const WDATA_T conv3_weights_14_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -30, -34, 2, 8},
    {-1, -9, -34, 12, 18},
    {6, -30, -27, 13, 7},
    {-19, -30, 3, 13, -11},
    {-27, -1, -1, 3, -3}};
static const WDATA_T conv3_weights_14_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, 13, 18, 12, 37},
    {20, 30, 6, 4, 39},
    {33, 27, -11, -24, -3},
    {-2, -11, -10, -8, -20},
    {-5, 19, 33, 9, -26}};
static const WDATA_T conv3_weights_14_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 48, 13, -3, 16},
    {1, 6, -14, -64, -76},
    {-2, -18, -5, 12, -49},
    {6, 4, 25, 14, -33},
    {1, 12, 32, 14, 9}};
static const WDATA_T conv3_weights_15_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 5, 4, 0, -2},
    {-3, 1, 1, 0, 0},
    {-2, -2, -4, 1, -3},
    {-4, -5, 0, -2, 0},
    {-1, 1, 0, -2, 1}};
static const WDATA_T conv3_weights_15_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -8, -3, -6, 2},
    {6, 3, 0, 0, -3},
    {0, -2, -2, -3, 2},
    {0, -2, -2, -5, 1},
    {-3, 0, -2, -4, -1}};
static const WDATA_T conv3_weights_15_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -3, 1, -1},
    {-2, -3, -5, -1, 1},
    {0, 5, 3, 2, -5},
    {-3, -1, 7, 1, -2},
    {4, 2, 3, 4, -2}};
static const WDATA_T conv3_weights_15_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 2, -1, -2},
    {-1, 3, 2, 1, 4},
    {-2, -1, -1, -1, 5},
    {-2, 1, -5, 1, -1},
    {1, 1, 6, 5, 1}};
static const WDATA_T conv3_weights_15_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 5, 0, -2},
    {5, -1, 2, 6, -1},
    {-1, -2, -2, 0, 1},
    {-1, 4, 5, 0, -1},
    {-5, -1, -2, 0, 0}};
static const WDATA_T conv3_weights_15_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, 4, 6, 4},
    {-2, -4, -7, -5, -3},
    {0, 3, -2, 1, 3},
    {-2, -3, -3, -3, -1},
    {-5, -2, -3, 0, -3}};
static const WDATA_T conv3_weights_15_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -7, -2, -2, -3},
    {-2, 5, 6, -2, 2},
    {1, 1, -3, -4, 1},
    {-2, -4, 2, 4, 5},
    {-1, 4, 1, 2, 0}};
static const WDATA_T conv3_weights_15_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, -4, 3, 1},
    {3, -2, -1, -2, 5},
    {0, 1, 1, -2, -4},
    {2, 6, -1, 3, -4},
    {2, 7, 6, 4, -1}};
static const WDATA_T conv3_weights_15_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, -2, -5, -1},
    {3, 7, 5, -1, 0},
    {4, 0, -10, -1, 3},
    {-4, -5, -7, 1, -1},
    {0, 2, -1, -1, 0}};
static const WDATA_T conv3_weights_15_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 7, 5, 4, -1},
    {2, -3, -3, -5, 0},
    {-2, 0, -8, 2, 4},
    {0, -2, -6, -6, -4},
    {-4, -5, -4, -3, -2}};
static const WDATA_T conv3_weights_15_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, 1, 0, -1},
    {0, 0, 0, -1, 1},
    {1, 1, 0, 2, -1},
    {1, -1, 3, 1, 0},
    {1, 0, -1, -2, -1}};
static const WDATA_T conv3_weights_15_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, 0, 1, -1},
    {2, 3, 2, 0, 2},
    {-5, -1, 1, 1, 2},
    {2, -2, 0, 1, 0},
    {1, 1, -2, -2, 0}};
static const WDATA_T conv3_weights_15_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, -5, -6, -2},
    {1, -3, -2, 2, 1},
    {-3, 4, 7, -1, 0},
    {0, 1, -2, -4, 2},
    {0, 8, 4, -1, 3}};
static const WDATA_T conv3_weights_15_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, -1, 3, 2},
    {8, 6, 2, 1, 1},
    {-7, -11, -3, 1, 1},
    {-1, -4, -2, 4, -4},
    {-4, -1, -2, 0, -3}};
static const WDATA_T conv3_weights_15_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 2, 1, -2},
    {-3, -5, -7, -4, -2},
    {2, -5, -2, -1, 0},
    {-1, 0, -3, -2, 0},
    {-3, -3, 2, -4, -2}};
static const WDATA_T conv3_weights_15_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -2, -5, 3},
    {-1, -4, -1, 3, 0},
    {-3, -2, -1, -2, 0},
    {-4, -2, 0, 0, 2},
    {1, 2, -1, 0, -3}};
static const WDATA_T conv3_weights_16_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -14, -28, 5, 23},
    {1, -29, 5, -1, 39},
    {-36, -36, 31, 46, 51},
    {-7, -6, 15, 31, -14},
    {-8, 41, 31, -14, -39}};
static const WDATA_T conv3_weights_16_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 20, 3, -34, -38},
    {23, 28, 6, -10, -37},
    {23, 37, 49, 24, 54},
    {33, 38, 50, 70, 42},
    {-29, -21, 15, 57, 14}};
static const WDATA_T conv3_weights_16_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 71, 54, 44, 4},
    {-5, 34, 59, 8, -5},
    {-15, -14, 13, -3, -6},
    {-18, -21, 13, -31, -6},
    {14, -5, -3, -42, 7}};
static const WDATA_T conv3_weights_16_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 7, -11, 3},
    {-4, -19, 21, 15, -2},
    {-3, -17, 26, 1, 25},
    {16, -11, -7, 18, 26},
    {3, -14, -4, 28, 37}};
static const WDATA_T conv3_weights_16_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 24, 32, 14, 22},
    {-14, 12, 36, 24, 19},
    {22, 33, 17, 5, 13},
    {16, 24, 6, 3, 11},
    {19, 2, 4, 8, 15}};
static const WDATA_T conv3_weights_16_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 21, 35, -2, 16},
    {12, -9, 15, -3, -4},
    {4, -3, 28, 13, 13},
    {-3, 7, 27, 40, 30},
    {7, -1, 2, 9, 17}};
static const WDATA_T conv3_weights_16_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-32, -14, -30, 47, 26},
    {-14, -24, -7, 5, 13},
    {-3, 56, 60, -6, 14},
    {23, 30, 18, -3, 1},
    {-52, -32, 9, 27, 13}};
static const WDATA_T conv3_weights_16_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -3, 18, 15, 0},
    {6, 36, 7, -30, 3},
    {-7, 26, 9, -24, -9},
    {-9, 20, -1, -20, -21},
    {-4, 40, 18, 28, 1}};
static const WDATA_T conv3_weights_16_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -31, -68, -15, 14},
    {13, 27, 0, -21, 0},
    {118, 48, -14, -17, 13},
    {46, 1, -13, 0, 17},
    {3, -24, -20, 25, 38}};
static const WDATA_T conv3_weights_16_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-35, -32, -10, 13, 24},
    {12, 36, -16, -41, 53},
    {83, 54, -24, -34, -15},
    {29, -14, -4, -28, 5},
    {-6, -4, 47, 68, 44}};
static const WDATA_T conv3_weights_16_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, -3, -4, 1},
    {2, 2, -1, -2, 0},
    {-1, 1, 3, 1, 0},
    {0, -1, -2, 0, 3},
    {2, -2, 2, 2, 0}};
static const WDATA_T conv3_weights_16_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 4, 4, 1},
    {-11, -14, 0, 13, 6},
    {5, 13, 5, 1, 7},
    {13, 15, 6, 6, -3},
    {6, 8, 1, 1, -3}};
static const WDATA_T conv3_weights_16_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 37, 22, 29, 21},
    {16, 24, 57, 15, 28},
    {-14, 13, 16, -19, 2},
    {11, 6, -30, -8, -15},
    {20, -9, -16, 2, -10}};
static const WDATA_T conv3_weights_16_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, -4, 9, 17},
    {25, 23, 20, -15, -6},
    {14, 11, 25, 41, 7},
    {3, -35, -44, 10, -12},
    {-25, 20, 29, -4, -23}};
static const WDATA_T conv3_weights_16_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -10, 8, 4, 20},
    {10, -24, -21, -14, 5},
    {-40, -41, -40, 29, 23},
    {-13, -26, -20, 32, 3},
    {53, 6, 8, 16, -15}};
static const WDATA_T conv3_weights_16_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -23, 25, 47, 56},
    {21, 21, 35, -20, 23},
    {-11, -20, 8, -46, 23},
    {-21, 18, 18, -31, -27},
    {11, 6, -4, -22, 11}};
static const WDATA_T conv3_weights_17_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -24, -26, -14, -26},
    {-12, -21, -8, -9, -9},
    {5, 7, 13, 0, 11},
    {0, 2, -17, 12, 20},
    {18, 4, -2, 13, 2}};
static const WDATA_T conv3_weights_17_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 7, 4, -1, -12},
    {11, -23, -22, -7, -13},
    {-3, -8, -12, -5, -6},
    {15, 17, 8, 4, 9},
    {15, 16, 10, 16, 11}};
static const WDATA_T conv3_weights_17_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -12, -8, 4, 2},
    {-14, -11, -5, 14, 9},
    {-7, -10, -9, -4, 9},
    {-18, -2, -3, -15, 3},
    {-6, 2, -11, -25, -3}};
static const WDATA_T conv3_weights_17_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, 0, -7, -6},
    {15, 7, -7, -32, -27},
    {-1, -12, -16, -12, -11},
    {-1, -2, -1, 6, 4},
    {-11, 2, -9, -1, 21}};
static const WDATA_T conv3_weights_17_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 4, 2, 2},
    {2, 5, 11, 4, -4},
    {-1, -1, 3, -2, -8},
    {0, -4, 0, -5, -3},
    {-2, -15, -8, -7, -4}};
static const WDATA_T conv3_weights_17_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 10, 2, 7, -4},
    {5, -15, -25, -14, -11},
    {6, -3, -19, -12, 2},
    {12, 0, -2, 23, 26},
    {19, 14, -7, -4, 25}};
static const WDATA_T conv3_weights_17_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-25, -27, -16, -10, -5},
    {-12, -3, 8, 7, -3},
    {12, 15, -1, -10, 4},
    {-18, -2, 0, 9, 4},
    {-13, -5, 2, -11, -10}};
static const WDATA_T conv3_weights_17_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -7, -11, 22, 19},
    {-12, -6, 2, 31, 15},
    {-6, -3, 4, -9, -14},
    {-9, -8, -18, -27, -13},
    {-2, -6, -27, -29, -10}};
static const WDATA_T conv3_weights_17_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 12, 12, -5, -9},
    {47, 73, 50, 5, -16},
    {54, 72, 28, -11, -4},
    {10, 19, -1, -4, 15},
    {15, 25, 37, 7, -2}};
static const WDATA_T conv3_weights_17_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 3, -9, -23, -22},
    {15, 10, 8, -2, 0},
    {8, -5, -4, -5, 14},
    {13, 1, 15, 1, -5},
    {26, 45, 40, 15, -4}};
static const WDATA_T conv3_weights_17_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 4, -2, 3, -2},
    {3, -1, 1, 1, -1},
    {0, 2, 1, 0, 0},
    {-3, 0, 0, -3, 1},
    {1, 3, 0, 2, 1}};
static const WDATA_T conv3_weights_17_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 2, 1, -4},
    {1, 0, 1, 3, -3},
    {4, 4, 8, 4, 2},
    {-3, 1, -1, -1, 1},
    {1, -1, 7, 1, -3}};
static const WDATA_T conv3_weights_17_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-28, -9, -4, -6, -15},
    {-18, -30, -12, 5, 3},
    {-25, -45, -4, 9, 4},
    {-6, -16, -1, -9, 17},
    {-1, 4, 2, 0, 5}};
static const WDATA_T conv3_weights_17_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 20, 21, -6, -15},
    {32, 36, 31, -4, -8},
    {22, 48, 16, 1, 7},
    {26, 49, 5, -17, 18},
    {8, 3, 2, 10, 15}};
static const WDATA_T conv3_weights_17_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 2, -9, -12, -26},
    {-16, -17, 4, -10, -22},
    {-32, -14, -2, 0, 8},
    {2, 3, 3, 0, 14},
    {8, 11, 2, 8, 21}};
static const WDATA_T conv3_weights_17_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -22, -26, 3, -11},
    {-2, -2, 10, 39, 50},
    {8, -5, -17, 4, 14},
    {-2, -32, -24, -17, 0},
    {2, -7, -22, -27, -34}};
static const WDATA_T conv3_weights_18_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -20, -26, 6, 3},
    {-5, -8, 32, 13, 28},
    {-6, 21, 15, -4, -14},
    {-2, 1, -8, -12, -13},
    {0, -7, -23, -3, -7}};
static const WDATA_T conv3_weights_18_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -12, -5, -9, -31},
    {-28, -26, -24, 3, -20},
    {0, 17, -2, 16, 59},
    {25, 22, 33, 18, 13},
    {22, 22, 9, -6, 2}};
static const WDATA_T conv3_weights_18_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 38, -18, -27, -31},
    {6, 25, 3, -53, -39},
    {7, 49, 21, -15, -11},
    {1, 19, 1, 7, 1},
    {-22, -12, -4, -2, 3}};
static const WDATA_T conv3_weights_18_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 13, 9, 30},
    {0, -8, 27, 42, 31},
    {-10, -21, 6, 38, 51},
    {10, 14, 42, 20, -40},
    {-17, -40, -13, -17, -35}};
static const WDATA_T conv3_weights_18_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 12, 9, 5, -5},
    {4, 6, -5, -7, -21},
    {3, -1, 0, 3, -11},
    {-1, -17, -1, 0, 4},
    {-1, -21, -8, -2, 3}};
static const WDATA_T conv3_weights_18_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -3, -30, -56, -59},
    {-5, 6, 10, -20, -3},
    {4, -16, 5, 15, 64},
    {11, -2, 4, 9, 30},
    {25, -1, -10, -39, 3}};
static const WDATA_T conv3_weights_18_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-28, 10, 33, 17, 3},
    {-4, 35, 33, 15, 5},
    {-25, -5, 4, 0, -1},
    {-52, 5, 10, 7, -11},
    {1, -18, 13, 18, -1}};
static const WDATA_T conv3_weights_18_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 30, -10, -19, -26},
    {29, 26, -19, -34, -66},
    {-11, 15, -16, -27, -14},
    {-26, -3, -31, -34, 11},
    {-6, -2, -19, 3, 2}};
static const WDATA_T conv3_weights_18_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, -28, -26, -1, 7},
    {-6, 17, 14, -6, 36},
    {-26, 0, 4, -6, 45},
    {-13, 22, 36, 7, 5},
    {24, 11, 17, -2, -15}};
static const WDATA_T conv3_weights_18_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, -36, -42, 10, 50},
    {-30, -23, -6, -27, -8},
    {-31, 4, -20, -92, -55},
    {-45, -6, 47, 27, -19},
    {-7, 29, 47, 37, 5}};
static const WDATA_T conv3_weights_18_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -1, -1, 0, -2},
    {-3, -1, -1, -1, 3},
    {1, 0, 0, -1, -3},
    {-2, 0, 3, 3, 1},
    {0, 1, 1, -2, 0}};
static const WDATA_T conv3_weights_18_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, -1, 6, 11},
    {-5, -14, -10, 7, 16},
    {-5, 0, -1, -4, 6},
    {-4, 3, -5, -1, 1},
    {-5, -2, 3, 0, -8}};
static const WDATA_T conv3_weights_18_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -2, 6, 18, 40},
    {24, 19, -12, -19, 13},
    {10, 3, -4, -18, 3},
    {34, 33, -31, -41, -14},
    {-9, -5, -1, -2, -4}};
static const WDATA_T conv3_weights_18_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -16, 7, 5, 32},
    {-20, -4, 20, 50, 63},
    {43, 46, -4, 14, 22},
    {32, 52, 22, -18, 6},
    {17, 4, 11, -11, -9}};
static const WDATA_T conv3_weights_18_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -15, 0, -5, 7},
    {-15, -24, 4, 1, 13},
    {-19, -20, -28, -15, -22},
    {17, 41, 14, 16, -8},
    {-5, 14, 23, -6, -35}};
static const WDATA_T conv3_weights_18_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, 25, 26, 62, 88},
    {4, 0, 23, 2, -8},
    {-24, -39, 8, -52, -127},
    {-15, -68, -44, -35, -11},
    {15, 4, 22, 19, 22}};
static const WDATA_T conv3_weights_19_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 40, 44, 2, 9},
    {21, 28, 30, 39, 19},
    {-15, 33, 33, 9, 4},
    {0, 15, 10, -11, -18},
    {0, 14, 0, -33, -13}};
static const WDATA_T conv3_weights_19_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -15, -16, 3, 4},
    {-25, 7, -3, 15, 17},
    {25, 33, -10, 18, 34},
    {17, 5, 10, 14, 23},
    {25, -2, 10, 28, 7}};
static const WDATA_T conv3_weights_19_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, 1, -3, 9},
    {5, 18, 19, -12, 1},
    {2, -9, -2, -11, 1},
    {11, -12, -18, -2, -14},
    {10, -1, -8, 1, -3}};
static const WDATA_T conv3_weights_19_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -4, 2, 5},
    {-6, -4, -20, -7, 24},
    {20, 3, -9, 4, 23},
    {-1, -23, -4, 31, 26},
    {-21, -20, 6, 1, -26}};
static const WDATA_T conv3_weights_19_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 1, 9, 11, 16},
    {-9, 7, -2, -3, 16},
    {-12, 2, -14, -9, 3},
    {-13, 13, -17, 5, 5},
    {10, 15, 14, 16, 8}};
static const WDATA_T conv3_weights_19_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -2, -6, -11, 24},
    {-15, -13, -26, -24, -16},
    {1, -8, 17, 0, 4},
    {6, 6, 5, 7, 2},
    {19, 14, -22, 0, -22}};
static const WDATA_T conv3_weights_19_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, 0, -2, -2, 8},
    {-4, -8, -23, -10, -8},
    {-14, -33, -26, -22, -20},
    {-5, -14, -13, -7, -6},
    {6, -4, -9, 8, 4}};
static const WDATA_T conv3_weights_19_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -15, -23, -23},
    {14, 9, -19, -8, -36},
    {-12, -3, -13, 0, -16},
    {-21, -14, -32, 20, 12},
    {-4, -3, 1, 18, 34}};
static const WDATA_T conv3_weights_19_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 3, 5, -1, 4},
    {20, -5, -44, -28, 31},
    {-11, -49, -37, -1, -3},
    {28, 13, -3, -4, 0},
    {23, 12, -14, 8, -10}};
static const WDATA_T conv3_weights_19_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 0, -15, 12, -5},
    {3, -18, 11, 25, 28},
    {-11, -8, 41, 38, -2},
    {-10, -18, 7, -7, -19},
    {-21, -13, 12, 42, 25}};
static const WDATA_T conv3_weights_19_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -2, -1, 0},
    {3, -1, -2, -3, -2},
    {-2, -2, 3, -1, -1},
    {1, 3, 1, 1, -2},
    {1, 0, 3, 3, -1}};
static const WDATA_T conv3_weights_19_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, -4, 0, -1},
    {2, 4, 2, -2, 2},
    {6, 2, 2, 3, -1},
    {-5, -3, 6, 0, -3},
    {2, 2, -12, -5, 1}};
static const WDATA_T conv3_weights_19_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -24, -8, -17, 5},
    {-22, -31, -30, -28, -19},
    {-13, 6, -12, -27, -6},
    {14, -13, -19, -21, -35},
    {-18, -14, 0, -4, -18}};
static const WDATA_T conv3_weights_19_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, 2, -7, -17, -21},
    {-22, -33, -45, -30, -21},
    {49, 17, -13, -15, -20},
    {42, 30, -6, -4, -36},
    {36, 31, -12, -13, -17}};
static const WDATA_T conv3_weights_19_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -13, 0, -11, 11},
    {18, 5, -9, -13, -4},
    {29, 36, 26, 14, 1},
    {-24, 3, 14, -18, -23},
    {9, 3, -10, -40, -42}};
static const WDATA_T conv3_weights_19_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, -5, 10, 17},
    {-2, -10, -6, 10, 40},
    {-10, -27, -12, 2, 5},
    {-6, 9, -35, -26, -16},
    {7, 10, 7, 35, 40}};
static const WDATA_T conv3_weights_20_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, -2, 0, -1},
    {-1, 1, 0, -2, -2},
    {-1, 1, -2, -1, -1},
    {-1, -1, -2, 0, -2},
    {0, -3, 0, -1, -1}};
static const WDATA_T conv3_weights_20_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 2, 2, -1},
    {1, 3, 0, -1, 0},
    {-1, -1, 1, -1, -1},
    {0, 3, 0, -3, 1},
    {2, -2, -3, -2, -2}};
static const WDATA_T conv3_weights_20_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 4, 0, 3},
    {0, -1, 3, 0, 0},
    {-1, -7, 4, 0, 1},
    {2, 2, -2, -1, -2},
    {1, -1, -1, -1, -1}};
static const WDATA_T conv3_weights_20_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 0, -2, -4},
    {-1, 0, 2, 2, -2},
    {1, 0, -1, 0, -1},
    {-2, 1, 0, -1, 0},
    {0, 0, 2, -1, 1}};
static const WDATA_T conv3_weights_20_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, -2, -2, -2},
    {0, 3, -1, -2, 2},
    {1, 1, 2, 4, -2},
    {0, 1, -2, -2, 2},
    {1, -1, 1, 3, -4}};
static const WDATA_T conv3_weights_20_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, -3, -3, -2},
    {-3, 0, -1, 1, -3},
    {2, 3, -4, -1, 0},
    {2, -3, 0, -2, 1},
    {0, -3, -2, -1, -2}};
static const WDATA_T conv3_weights_20_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -3, 0, -1},
    {2, 2, -1, 0, 0},
    {2, 4, 2, -2, 2},
    {-2, 1, 0, 0, 0},
    {0, -3, -2, -1, 2}};
static const WDATA_T conv3_weights_20_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, 0, 2, -4},
    {-1, -2, 0, 0, 0},
    {-2, 0, 0, -3, 0},
    {0, 1, 1, 1, 0},
    {-2, 1, 5, 1, 0}};
static const WDATA_T conv3_weights_20_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 4, -2, 3},
    {1, -1, -1, 1, 1},
    {-2, -3, 1, 0, 3},
    {-4, 1, -2, -4, -2},
    {2, 1, 0, -5, 0}};
static const WDATA_T conv3_weights_20_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -3, -2, 0, -2},
    {4, -2, -1, 4, -2},
    {-3, 0, -2, -1, -6},
    {0, 1, 0, -2, 3},
    {0, 1, -1, 0, 0}};
static const WDATA_T conv3_weights_20_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, 0, -2, -2},
    {0, 2, -3, 0, 1},
    {2, -2, 3, 0, -1},
    {3, 1, 1, 2, 0},
    {0, -3, -3, -2, -2}};
static const WDATA_T conv3_weights_20_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 2, 2, -4},
    {1, 1, 1, 3, 1},
    {0, 1, -2, 1, 0},
    {-3, 1, 1, -1, -2},
    {1, -2, 1, 0, 1}};
static const WDATA_T conv3_weights_20_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, 0, -2, 0},
    {-3, 1, -1, 0, -2},
    {0, -2, -1, -4, 2},
    {2, -2, -4, -2, 1},
    {-1, 1, -1, 1, -3}};
static const WDATA_T conv3_weights_20_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, 2, 1, 2},
    {0, 1, 4, 0, 3},
    {-2, 0, 4, 3, 1},
    {-3, -3, 2, 0, 0},
    {-1, -2, 3, -5, 2}};
static const WDATA_T conv3_weights_20_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 2, 1, 0},
    {-1, 2, -2, -1, 0},
    {-1, -1, -4, 2, -2},
    {-2, -2, 1, -1, -2},
    {1, -3, 0, 0, -2}};
static const WDATA_T conv3_weights_20_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 2, 0, -1},
    {0, 2, 3, 0, -2},
    {-1, 0, -4, -1, 1},
    {0, -1, -1, 1, 3},
    {-1, 2, 2, 0, 1}};
static const WDATA_T conv3_weights_21_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, 0, 1, -4},
    {-2, 0, -5, 0, -1},
    {-6, -3, -2, -4, 2},
    {2, 2, 8, 0, 0},
    {-2, -2, 2, 4, 2}};
static const WDATA_T conv3_weights_21_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 3, 6, 6, -5},
    {8, 4, 7, 5, -4},
    {-2, -5, -11, 5, 5},
    {-1, -6, -4, -2, 0},
    {1, -5, -1, 0, -3}};
static const WDATA_T conv3_weights_21_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 5, 2, 2, 2},
    {1, 6, -2, 2, 2},
    {3, -1, -4, -1, 3},
    {6, 1, -5, 2, 4},
    {2, 0, -1, 3, 5}};
static const WDATA_T conv3_weights_21_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -4, -3, 1, -3},
    {-2, -7, -8, -6, -3},
    {0, -5, -4, -7, -4},
    {1, 5, 1, -1, 0},
    {0, 0, -8, -8, -6}};
static const WDATA_T conv3_weights_21_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 1, 0, 1},
    {3, -3, 1, 1, 1},
    {0, 2, 0, 5, 2},
    {2, 4, 0, 1, -1},
    {1, 4, 1, 2, 2}};
static const WDATA_T conv3_weights_21_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, -1, -3, -5},
    {0, -1, 4, 8, 2},
    {2, -1, -2, 0, -1},
    {-1, 2, 0, -2, 3},
    {0, -2, -3, 0, 0}};
static const WDATA_T conv3_weights_21_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -8, -7, -1, 1},
    {0, -1, 1, -3, 3},
    {2, -3, -2, 2, 1},
    {-1, 2, 2, 1, -2},
    {1, 3, 5, -1, -3}};
static const WDATA_T conv3_weights_21_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -1, 0, 1},
    {3, 0, -3, 8, 3},
    {5, 4, -3, 8, 5},
    {2, 7, 0, 0, 4},
    {0, 4, 0, -3, 5}};
static const WDATA_T conv3_weights_21_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -6, -2, 3, 3},
    {-1, 2, -3, -2, 2},
    {-3, -3, -8, -6, -1},
    {-2, -2, 8, 1, -4},
    {-4, -3, 1, 5, -2}};
static const WDATA_T conv3_weights_21_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -6, -9, -7, -1},
    {-1, 0, 2, 5, -1},
    {2, 5, 0, -2, 0},
    {4, 1, 0, 0, 3},
    {-3, 0, 0, 5, 0}};
static const WDATA_T conv3_weights_21_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 0, 3, 0},
    {-1, 0, 0, -5, -3},
    {-1, -1, -3, 4, 0},
    {0, -5, 2, -2, 1},
    {0, 5, 1, 0, 1}};
static const WDATA_T conv3_weights_21_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 2, 0, 4},
    {-1, 2, 0, 1, -3},
    {-1, 0, 0, 3, 1},
    {0, 2, -1, 0, -1},
    {1, 1, -2, -1, 5}};
static const WDATA_T conv3_weights_21_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -5, -2, -4, -2},
    {5, 8, 5, 8, 5},
    {3, -5, -3, -1, 2},
    {3, -4, -3, 2, 0},
    {1, -5, -4, 2, 3}};
static const WDATA_T conv3_weights_21_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 8, 3, 2, 1},
    {-3, -7, -3, -3, -5},
    {-2, -1, 2, 2, -3},
    {1, -1, -2, -1, 2},
    {2, 1, -3, 2, -4}};
static const WDATA_T conv3_weights_21_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 0, -1, -6, -3},
    {-2, 0, 5, 3, 1},
    {0, -2, -4, 2, 2},
    {3, 2, 1, -5, -1},
    {0, -3, 5, 4, 3}};
static const WDATA_T conv3_weights_21_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 2, -3, -4},
    {1, 2, 0, 3, 4},
    {2, -1, 3, 5, 2},
    {0, 7, 5, 1, 2},
    {1, 3, -7, -3, 6}};
static const WDATA_T conv3_weights_22_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -20, -18, -8, -6},
    {-3, -14, -17, -19, -5},
    {-7, -6, -2, -1, 1},
    {-7, 6, 17, 18, 10},
    {-16, 5, 25, 26, 7}};
static const WDATA_T conv3_weights_22_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -6, 11, 9, -7},
    {-17, -16, -10, 3, 2},
    {8, 8, -8, -16, -9},
    {-4, -3, 11, -15, -14},
    {-11, -5, 11, 6, 9}};
static const WDATA_T conv3_weights_22_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -8, -22, -21, -11},
    {1, -9, -9, -9, -13},
    {-2, -6, -1, -1, -9},
    {0, 4, -3, -3, 1},
    {6, 9, -9, -5, 1}};
static const WDATA_T conv3_weights_22_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 6, 6, 1, 4},
    {15, 19, 7, -8, -5},
    {10, 10, 1, -7, 2},
    {0, -7, -1, -5, -2},
    {5, 3, 2, -6, 11}};
static const WDATA_T conv3_weights_22_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -6, 0, 0},
    {-2, 1, 1, 6, 4},
    {-4, 4, 6, 2, 3},
    {4, 2, 2, 3, 6},
    {4, -1, 1, -4, 0}};
static const WDATA_T conv3_weights_22_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -6, 7, 15, -8},
    {-3, -11, -9, 1, -4},
    {-3, -2, -16, -11, -2},
    {9, -3, 13, -6, 2},
    {3, -2, 14, 9, 16}};
static const WDATA_T conv3_weights_22_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 7, 7, -1, -3},
    {7, 6, 9, 5, 7},
    {-2, 6, 15, 11, 12},
    {27, 27, 6, 2, -5},
    {-6, -10, -4, -15, -5}};
static const WDATA_T conv3_weights_22_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 8, 5, 3, 14},
    {3, -7, 0, 13, 12},
    {-4, 7, -6, -14, -13},
    {7, 9, -8, -37, -28},
    {-3, -5, -20, -21, -15}};
static const WDATA_T conv3_weights_22_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, 8, -1, 2},
    {3, -5, -4, -6, -1},
    {-17, 6, 7, 0, 9},
    {9, 19, 7, 3, 8},
    {-4, -16, -6, -8, 1}};
static const WDATA_T conv3_weights_22_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, -6, -15, -13, -16},
    {1, 3, 7, 5, -5},
    {-7, -6, 0, 5, 9},
    {7, -5, 4, 10, 17},
    {6, -1, 12, 18, 14}};
static const WDATA_T conv3_weights_22_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 2, 1, -3},
    {-2, -1, 4, 2, 3},
    {3, 1, 0, 2, 0},
    {-1, -1, -2, 3, -1},
    {-1, 1, 1, -3, 0}};
static const WDATA_T conv3_weights_22_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 0, 0, 2},
    {2, -2, 1, 1, 2},
    {1, 0, -1, 0, 3},
    {-3, 2, -1, -2, -2},
    {5, -2, 6, -1, -1}};
static const WDATA_T conv3_weights_22_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -26, -15, -17, -4},
    {0, -8, -4, -3, 1},
    {-1, 1, 22, -2, 3},
    {24, -2, 9, -7, -8},
    {15, -10, -6, 2, 10}};
static const WDATA_T conv3_weights_22_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -17, -8, 1, -7},
    {-10, -15, -2, -1, 12},
    {14, 27, 14, 9, 10},
    {-16, -24, -1, -1, 4},
    {-13, 7, 2, 9, 10}};
static const WDATA_T conv3_weights_22_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, 1, 9, -2, -3},
    {0, -8, -2, -3, 0},
    {3, -7, -18, -15, -3},
    {-34, -31, -11, -6, -1},
    {9, 12, 30, 30, 11}};
static const WDATA_T conv3_weights_22_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -4, -13, -25, -25},
    {3, -6, 6, -2, 0},
    {18, 2, 35, 4, -5},
    {2, -10, 11, -8, -14},
    {-9, -5, -17, 1, -2}};
static const WDATA_T conv3_weights_23_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 7, 8, -1, -6},
    {8, 4, 11, 4, 0},
    {12, 22, 18, 3, -5},
    {13, 16, 13, 1, 4},
    {-9, 9, 10, 5, 2}};
static const WDATA_T conv3_weights_23_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 1, -10, -3, -7},
    {21, 20, 0, 2, 11},
    {3, -2, 1, 2, 3},
    {-10, -2, -5, 5, -6},
    {-10, -6, -7, -1, -2}};
static const WDATA_T conv3_weights_23_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, -12, 19, -14},
    {-1, -22, -22, 5, -20},
    {6, -31, -7, 6, -8},
    {5, -7, -5, -6, 2},
    {3, -1, -7, -1, 4}};
static const WDATA_T conv3_weights_23_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 3, 1, 3},
    {-3, -14, -8, -1, -6},
    {-7, -12, -17, -19, -28},
    {6, 3, 19, 16, -3},
    {10, 15, 10, 4, 1}};
static const WDATA_T conv3_weights_23_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 6, 10, 2, 2},
    {6, 9, 10, 5, 3},
    {11, 7, 10, 4, 7},
    {13, 0, 9, 5, 11},
    {5, -1, 16, 15, 10}};
static const WDATA_T conv3_weights_23_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -13, -29, -19, -12},
    {7, 12, 8, 2, 9},
    {11, 7, 10, 21, 21},
    {-4, -3, 6, 13, 7},
    {-3, -12, -4, -4, 1}};
static const WDATA_T conv3_weights_23_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-21, -9, -7, -12, -6},
    {-11, -2, -15, -11, 4},
    {4, -6, -19, 2, 1},
    {-1, -5, 0, 18, 7},
    {-9, -8, 8, 8, 6}};
static const WDATA_T conv3_weights_23_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -10, 4, 11, -2},
    {-7, -9, -4, 11, -7},
    {-1, -11, -7, -3, -5},
    {4, 0, 5, 1, -10},
    {2, 8, -5, 9, -5}};
static const WDATA_T conv3_weights_23_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -6, -5, -1, -4},
    {-6, -1, -5, -16, -7},
    {18, 3, -10, -7, 5},
    {0, 2, 17, 22, 8},
    {-6, 12, 2, -17, -13}};
static const WDATA_T conv3_weights_23_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 0, -4, -3, -35},
    {7, -2, 0, -7, -5},
    {10, 14, 9, 3, 7},
    {9, -4, -9, -4, -7},
    {-13, -24, 7, 13, 7}};
static const WDATA_T conv3_weights_23_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 1, 0, 2},
    {0, 3, 2, 2, 2},
    {2, 1, 4, -2, -2},
    {-3, 1, 0, 1, 0},
    {-2, 0, -1, -2, 0}};
static const WDATA_T conv3_weights_23_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -1, 0, -2},
    {-1, -2, 2, 0, 3},
    {1, -2, 0, 0, -1},
    {3, 9, 2, 1, -5},
    {2, 0, 1, 5, -3}};
static const WDATA_T conv3_weights_23_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, 4, 9, -17, -6},
    {-3, 26, 21, 3, 15},
    {-2, 5, 4, 5, 12},
    {-2, -7, 0, 8, 4},
    {-1, -16, -4, 4, 4}};
static const WDATA_T conv3_weights_23_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 20, 14, 9, 10},
    {8, 20, 9, -3, 9},
    {-14, -5, 3, 5, 5},
    {-1, -8, -1, 7, 7},
    {-3, 5, 4, 3, -6}};
static const WDATA_T conv3_weights_23_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -11, -6, -7, -6},
    {-3, 8, 12, 1, 4},
    {-5, 5, 22, 10, 6},
    {-6, 0, -2, -15, -18},
    {-11, -10, 0, -2, -9}};
static const WDATA_T conv3_weights_23_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 16, 10, 22, 17},
    {6, 7, -10, 20, -17},
    {5, -7, 13, 6, -29},
    {5, 16, 8, 8, 9},
    {1, 9, 7, 19, 11}};
static const WDATA_T conv3_weights_24_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -10, -12, 4, -9},
    {-18, -13, 18, -2, -7},
    {-3, 1, 25, 2, 3},
    {-26, 13, 17, 8, 13},
    {-4, 12, 16, 14, 0}};
static const WDATA_T conv3_weights_24_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -6, 9, 2, -11},
    {-5, -4, 14, 21, -4},
    {3, -9, 29, 29, 5},
    {2, -4, 23, 54, 30},
    {-4, 2, 23, 33, 24}};
static const WDATA_T conv3_weights_24_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -11, -31, -33, -8},
    {-9, -14, -14, -22, -9},
    {-11, -11, -14, -1, 5},
    {7, 4, -4, -2, 12},
    {6, 3, -7, -8, 7}};
static const WDATA_T conv3_weights_24_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 5, 1, 10},
    {15, 3, 11, 2, 4},
    {-4, -11, 2, 12, 9},
    {-6, -18, -7, 14, -1},
    {-2, 8, -6, -13, -15}};
static const WDATA_T conv3_weights_24_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -6, -1, -2, 6},
    {-7, -1, 1, 2, 13},
    {-6, 1, -5, -1, 10},
    {1, -6, -1, -1, 3},
    {4, -21, -13, -3, 2}};
static const WDATA_T conv3_weights_24_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -25, -7, -3, -12},
    {-2, -5, 3, -3, 3},
    {4, -17, -19, 15, 12},
    {17, -2, -4, 25, 36},
    {12, 0, 0, 12, 34}};
static const WDATA_T conv3_weights_24_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 4, 13, -6, -1},
    {-8, 2, 15, 10, 4},
    {16, 14, 0, -6, 10},
    {18, 23, 10, -5, -12},
    {-27, 1, 8, -5, -24}};
static const WDATA_T conv3_weights_24_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 4, -7, 13, 24},
    {-6, -1, -9, -2, 2},
    {-12, 9, 11, -11, -28},
    {3, 6, 22, 4, -27},
    {1, -1, -27, -18, -15}};
static const WDATA_T conv3_weights_24_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 22, 6, -2, -2},
    {19, 28, -4, -21, 12},
    {31, 38, -15, 6, 25},
    {-5, 7, -6, -17, 1},
    {-7, 13, 36, 23, 14}};
static const WDATA_T conv3_weights_24_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -5, 8, -8, -19},
    {12, 0, 4, 9, -4},
    {3, 7, 14, -22, -19},
    {11, 11, 23, -18, -1},
    {9, 24, 70, 36, 23}};
static const WDATA_T conv3_weights_24_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -2, 1, 1},
    {1, 4, -2, -1, 2},
    {2, -1, -2, 1, 2},
    {-4, -3, -1, 0, 3},
    {2, -2, 3, 2, -1}};
static const WDATA_T conv3_weights_24_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, -1, 4, 2},
    {3, -4, -4, 1, 2},
    {2, -2, 3, 4, 3},
    {-7, 3, 7, -4, -1},
    {3, 9, 11, -1, 0}};
static const WDATA_T conv3_weights_24_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-24, -27, -27, -26, 2},
    {-12, -20, -18, -20, -2},
    {-3, -21, -27, 1, 4},
    {19, -13, -26, -11, -17},
    {12, -5, -7, 8, 14}};
static const WDATA_T conv3_weights_24_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 2, 20, 8, 2},
    {16, -2, 16, 8, 19},
    {20, 5, -5, -1, 0},
    {-4, 2, -11, -3, 6},
    {26, 30, 23, 23, 21}};
static const WDATA_T conv3_weights_24_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, -6, 9, -3, 2},
    {-7, -22, -7, -2, 8},
    {-24, -39, -9, 0, -4},
    {-8, -9, 12, 17, 7},
    {26, 40, 44, 16, -2}};
static const WDATA_T conv3_weights_24_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -1, -10, -21, -9},
    {1, -6, 0, -15, 4},
    {1, -24, 8, 6, -4},
    {-3, -8, -5, -16, -10},
    {8, 9, -38, 16, -7}};
static const WDATA_T conv3_weights_25_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 3, -2, -3},
    {0, 4, -2, -1, 3},
    {-1, 2, 1, -2, -1},
    {2, 1, 3, 7, 5},
    {1, 1, 0, 4, 3}};
static const WDATA_T conv3_weights_25_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -4, 0, 2, -2},
    {1, -2, 1, 0, 1},
    {-2, 0, 3, 0, 0},
    {-2, -2, 1, -2, -2},
    {0, -3, -2, 2, 1}};
static const WDATA_T conv3_weights_25_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 1, -7, -2},
    {1, 0, -1, -2, 0},
    {3, -1, 0, -1, -3},
    {-3, 1, 1, -1, -1},
    {-1, 0, 5, -2, -3}};
static const WDATA_T conv3_weights_25_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 0, -1, -1},
    {1, 0, 2, -1, 0},
    {0, -2, 0, -5, -4},
    {-4, 0, 1, -3, -1},
    {-2, -2, -2, -6, 5}};
static const WDATA_T conv3_weights_25_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -1, -1, -2},
    {-3, 1, -1, 1, 0},
    {0, 1, 0, -1, 0},
    {0, 0, -1, -4, 1},
    {-2, 0, 0, -1, 0}};
static const WDATA_T conv3_weights_25_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, 0, -3, -3},
    {-2, 0, -2, -1, -1},
    {1, 3, -2, 4, 4},
    {1, -1, -1, 4, 2},
    {-1, -2, -2, 1, 4}};
static const WDATA_T conv3_weights_25_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, 1, 1, 2},
    {-3, -1, 0, 2, -2},
    {3, 2, 1, 2, 2},
    {3, 1, 0, 1, -1},
    {2, 3, -3, -4, 1}};
static const WDATA_T conv3_weights_25_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -1, 4, 5},
    {-1, 0, 1, 0, -1},
    {1, 2, -1, -3, 1},
    {-2, -1, -6, -6, -4},
    {0, -2, -1, -2, -3}};
static const WDATA_T conv3_weights_25_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 1, -1, -1},
    {0, 4, 0, -2, -1},
    {-1, 0, 4, -1, 0},
    {-2, -2, 0, -3, 0},
    {-3, -6, -1, 2, 1}};
static const WDATA_T conv3_weights_25_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -2, 0, 2},
    {-1, -2, -3, -1, -1},
    {-1, 1, -4, 0, 1},
    {0, -2, 4, -2, 1},
    {3, -1, -3, -8, 4}};
static const WDATA_T conv3_weights_25_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 2, 0, 1},
    {-1, -1, 0, 0, 1},
    {0, 2, 1, -2, -1},
    {0, 1, -1, -1, 2},
    {0, -1, -4, 2, 0}};
static const WDATA_T conv3_weights_25_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, 2, 1, 0},
    {-2, 0, 0, -1, 2},
    {-1, 1, -1, 0, -1},
    {-1, -1, 2, -1, 0},
    {-4, -4, 0, 2, 2}};
static const WDATA_T conv3_weights_25_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -4, -3, -3},
    {2, 0, -2, 0, 4},
    {1, -2, 4, 2, 1},
    {-2, -7, 1, 1, -2},
    {0, -1, -3, 4, 3}};
static const WDATA_T conv3_weights_25_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -1, -2, 0},
    {2, 6, 3, 3, 1},
    {-3, -1, 3, -2, -1},
    {-3, -2, -4, 2, 4},
    {-1, 0, 1, 0, 2}};
static const WDATA_T conv3_weights_25_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 5, 2, 1, 2},
    {0, -1, -3, 1, -2},
    {2, 1, -1, -4, 5},
    {2, 0, -2, 2, 2},
    {0, -1, 1, 4, 3}};
static const WDATA_T conv3_weights_25_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, 1, 2},
    {0, 0, 2, -1, 1},
    {1, 0, 0, 2, -1},
    {3, -3, 4, 0, 0},
    {2, 0, -2, -7, -9}};
static const WDATA_T conv3_weights_26_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -38, -83, -21, -22},
    {-19, -35, -23, -27, -16},
    {10, 22, 21, 9, 7},
    {-4, -13, -4, -5, 2},
    {-14, -20, 4, 20, -3}};
static const WDATA_T conv3_weights_26_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -2, 11, 18, -2},
    {20, -2, -10, 35, 17},
    {8, -15, -8, -20, -5},
    {12, 21, 31, 24, 10},
    {-6, 6, 8, -4, 4}};
static const WDATA_T conv3_weights_26_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -12, -42, -30, -21},
    {-20, -17, -28, -2, -12},
    {6, 22, -17, -5, -14},
    {2, 5, 21, -18, -22},
    {7, 10, 17, -18, -21}};
static const WDATA_T conv3_weights_26_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 6, 8, 6, 3},
    {20, 10, -6, -23, -6},
    {13, 18, 1, 20, 5},
    {16, 7, 10, -8, -20},
    {-6, -1, 2, 19, 28}};
static const WDATA_T conv3_weights_26_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 10, 6, -4, -8},
    {10, -5, 3, -2, -9},
    {2, -2, 10, 5, 3},
    {11, -21, 0, -13, 0},
    {-1, -28, -32, -19, -12}};
static const WDATA_T conv3_weights_26_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -23, -24, -3, -21},
    {16, -23, -10, -2, 38},
    {24, -17, -34, -20, 28},
    {12, 1, 4, -23, 8},
    {8, 22, 33, -2, 2}};
static const WDATA_T conv3_weights_26_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, -13, 23, -10, -25},
    {-3, 36, 63, 13, 14},
    {-2, 61, 29, 13, 23},
    {-12, 32, 15, -7, -6},
    {-2, 1, -3, 5, 2}};
static const WDATA_T conv3_weights_26_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 5, 4, 30, 34},
    {-13, 19, -16, -12, 26},
    {-20, 22, -10, -45, 18},
    {6, 2, 8, -2, 5},
    {11, 19, -3, -12, -31}};
static const WDATA_T conv3_weights_26_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-32, 2, 1, 5, -6},
    {19, 40, 79, 42, -8},
    {53, 93, 73, 0, 14},
    {-23, 23, 4, -7, -22},
    {-46, -22, 14, 16, 8}};
static const WDATA_T conv3_weights_26_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -11, -16, -11, -15},
    {20, 5, 4, -18, -59},
    {-11, -28, -23, -51, -22},
    {2, -2, 44, 18, 32},
    {3, 24, 12, -4, -19}};
static const WDATA_T conv3_weights_26_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 1, 0, -1, 4},
    {2, 1, -2, 0, 1},
    {-2, 4, 1, 1, -2},
    {2, 0, 4, -1, 4},
    {-1, 1, 2, 1, 2}};
static const WDATA_T conv3_weights_26_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -2, 4, 3},
    {-6, -7, -6, 4, 8},
    {-3, 4, 5, 3, 5},
    {2, 3, 3, -3, -3},
    {-6, -7, 12, 11, 4}};
static const WDATA_T conv3_weights_26_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-22, -16, 21, -24, -10},
    {11, 17, 38, 5, 25},
    {3, -2, -13, -27, 3},
    {2, 13, -11, -23, -3},
    {23, 35, -2, -5, 12}};
static const WDATA_T conv3_weights_26_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 2, 27, 21, 58},
    {56, 61, 61, 42, 59},
    {17, 27, 10, 9, 31},
    {-10, -3, 31, 7, 21},
    {-4, 22, 27, 18, 16}};
static const WDATA_T conv3_weights_26_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -9, -4, 6, -26},
    {-23, -22, -12, -11, -17},
    {-55, -35, 1, 1, -16},
    {-1, 18, 11, 41, 26},
    {10, -18, 23, 36, 5}};
static const WDATA_T conv3_weights_26_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 10, 14, 37, 17},
    {6, 16, 12, 43, -11},
    {-2, -15, -17, 32, -44},
    {-11, -28, 30, 28, 48},
    {12, 14, -34, -10, 7}};
static const WDATA_T conv3_weights_27_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 19, 2, -2, -7},
    {11, 22, 9, 6, 6},
    {-3, 4, 21, 18, 9},
    {1, -28, 4, 30, -6},
    {-8, 12, 22, 6, -9}};
static const WDATA_T conv3_weights_27_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 9, 2, -10, -1},
    {11, 12, -6, -8, -3},
    {-4, 4, 4, 7, 8},
    {2, -3, 7, 2, 22},
    {-4, -22, -13, 18, 15}};
static const WDATA_T conv3_weights_27_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, -4, 3, 21, 0},
    {5, -3, -8, 22, 10},
    {1, 5, -5, 17, 11},
    {-10, -20, 4, 3, 0},
    {-11, -11, -3, -10, 17}};
static const WDATA_T conv3_weights_27_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 2, 8, 1},
    {5, 9, 6, 11, -6},
    {5, 15, 25, 19, -4},
    {6, -3, -17, -18, -13},
    {9, -17, -26, -18, -1}};
static const WDATA_T conv3_weights_27_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 5, 12, 11, 5},
    {11, 2, 10, 15, 5},
    {12, 6, 3, 14, 0},
    {4, 7, 3, 7, 3},
    {1, 6, 12, 20, 12}};
static const WDATA_T conv3_weights_27_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 21, 6, -5, -9},
    {9, -7, -6, -7, 7},
    {-3, 0, 2, 13, 11},
    {-6, 7, 7, 10, 16},
    {-8, -13, -18, -5, 13}};
static const WDATA_T conv3_weights_27_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, 7, 1, 1},
    {3, -8, 17, 4, -2},
    {-20, -11, -10, 8, 1},
    {-25, -29, -12, 7, -11},
    {-5, -12, 3, 5, 2}};
static const WDATA_T conv3_weights_27_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -22, 2, 12, -17},
    {1, -3, 9, 19, -11},
    {2, 3, 4, -5, -22},
    {-2, -2, 12, -4, -13},
    {-4, 8, -1, 11, 13}};
static const WDATA_T conv3_weights_27_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -7, 2, 10, -3},
    {13, 16, 5, 8, -11},
    {-2, -7, -6, 10, -1},
    {26, 6, -4, -4, -11},
    {5, 19, -16, -22, -15}};
static const WDATA_T conv3_weights_27_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 15, 12, 24, -3},
    {18, 6, 1, -4, -10},
    {2, -21, -31, -17, -3},
    {-3, -10, -24, -1, 3},
    {-16, -34, -36, 3, 6}};
static const WDATA_T conv3_weights_27_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 1, 1, -2},
    {-1, 1, -1, 0, 0},
    {-2, 2, 1, 3, -2},
    {2, 0, 1, 2, -3},
    {1, -3, -2, 2, -2}};
static const WDATA_T conv3_weights_27_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -3, 0, 1},
    {-2, 3, 6, 2, -4},
    {5, 7, 4, 3, 0},
    {4, 5, -3, -3, -3},
    {2, -2, -8, -4, -1}};
static const WDATA_T conv3_weights_27_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -6, 19, 0, -6},
    {12, 8, 19, 20, 15},
    {-13, 11, 12, -2, 2},
    {-32, 0, 14, -4, 2},
    {-20, -19, 3, 3, -5}};
static const WDATA_T conv3_weights_27_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 9, -7, -4, 8},
    {-11, -8, -11, -10, 5},
    {-1, 2, 20, 9, 6},
    {9, -4, -5, 7, 0},
    {-11, -4, 0, -9, -16}};
static const WDATA_T conv3_weights_27_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 6, 9, -2, -10},
    {0, 6, 10, 8, -6},
    {5, -2, -2, 4, 6},
    {-12, -3, -2, -8, -13},
    {-43, -58, -19, 6, -23}};
static const WDATA_T conv3_weights_27_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 12, 18, 15, 22},
    {-8, 2, -5, 20, 28},
    {-3, 10, -4, 17, -5},
    {-4, 3, 15, -6, -35},
    {-6, 9, 5, -33, 10}};
static const WDATA_T conv3_weights_28_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -1, 8, -11, -5},
    {24, 21, 27, 11, 16},
    {0, 4, 24, 20, 25},
    {9, 14, 14, -1, 4},
    {7, 20, 17, -4, 1}};
static const WDATA_T conv3_weights_28_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -8, -18, -4, -7},
    {1, 15, 18, 3, 6},
    {3, 8, -4, 6, 17},
    {-11, -8, -10, 6, 10},
    {1, -3, 1, 6, -4}};
static const WDATA_T conv3_weights_28_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 29, 14, 14, -1},
    {-2, 16, 8, -10, -17},
    {-1, 6, -8, -14, -10},
    {15, -17, 2, -16, -22},
    {-2, -8, -3, -30, -17}};
static const WDATA_T conv3_weights_28_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 6, 5, 4, 5},
    {-15, -11, -3, 15, 26},
    {-5, -16, -12, 17, 11},
    {-6, -17, 3, 36, 21},
    {-16, -12, 30, 26, 11}};
static const WDATA_T conv3_weights_28_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 22, 17, 9, 1},
    {5, 11, 2, -2, -7},
    {16, 12, -3, 0, -4},
    {11, 17, -2, 7, 2},
    {2, 2, 1, 6, 1}};
static const WDATA_T conv3_weights_28_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -7, -28, -23, -6},
    {-3, 3, 4, -10, -10},
    {-2, 11, 18, 27, 17},
    {-6, -14, -4, 16, 6},
    {-2, -5, 2, -6, -9}};
static const WDATA_T conv3_weights_28_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -8, -3, 5, 5},
    {-24, -4, 5, -2, 0},
    {-6, 31, -7, -13, 3},
    {9, -2, -17, 1, 4},
    {-9, -15, -9, -1, 3}};
static const WDATA_T conv3_weights_28_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 17, 13, -5, -12},
    {6, 6, 5, -29, -35},
    {-17, -20, -7, -32, -1},
    {-3, -10, 2, 13, 7},
    {-9, 8, 35, 9, 1}};
static const WDATA_T conv3_weights_28_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 0, -19, -4, 3},
    {-11, 2, -1, 4, 3},
    {13, 30, -10, -2, -2},
    {-2, -22, -9, 22, 13},
    {-24, -31, -23, 6, 10}};
static const WDATA_T conv3_weights_28_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 10, 5, 7, -1},
    {-3, -14, 3, -18, 2},
    {8, 18, 43, 11, -7},
    {-2, 3, -8, -2, -9},
    {-9, -13, 5, 3, 4}};
static const WDATA_T conv3_weights_28_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 2, 2, 0},
    {1, 5, -1, 1, 2},
    {3, 2, 2, -3, 0},
    {-2, 0, 5, -3, 2},
    {0, 0, 0, 0, -2}};
static const WDATA_T conv3_weights_28_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 3, -1, 0},
    {-1, -1, -2, 0, 9},
    {1, 5, -2, 1, -1},
    {8, 14, 3, 1, -3},
    {4, 2, 0, 1, 3}};
static const WDATA_T conv3_weights_28_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -14, -8, -7, 4},
    {-8, 2, 3, -5, 5},
    {11, 19, -1, -14, -7},
    {21, 34, -17, -15, -7},
    {17, -4, -21, -14, -11}};
static const WDATA_T conv3_weights_28_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 23, 5, 0, 30},
    {15, 31, 19, 29, 19},
    {-30, -37, -28, 5, 13},
    {-19, -9, -6, 1, -13},
    {6, 14, 11, -6, -7}};
static const WDATA_T conv3_weights_28_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -4, -6, 1},
    {-14, -20, -13, -26, -16},
    {-7, -12, 8, 19, 17},
    {-3, 4, 11, 19, 2},
    {10, 24, 12, 6, 5}};
static const WDATA_T conv3_weights_28_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, 21, 32, 52, 62},
    {-5, 5, 13, 32, 57},
    {-2, -30, 0, 14, -24},
    {5, 0, 1, -26, -27},
    {-2, -1, 0, -1, -6}};
static const WDATA_T conv3_weights_29_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 31, 47, 7, 0},
    {24, 42, 6, -11, -11},
    {-2, 5, -7, -7, 3},
    {8, 14, 15, -8, 5},
    {11, 35, 15, -9, -3}};
static const WDATA_T conv3_weights_29_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -4, 21, 18, 33},
    {2, 8, 14, 12, -3},
    {-4, 13, 15, 2, -30},
    {-38, -27, -8, 7, -2},
    {-16, -17, 15, 18, -1}};
static const WDATA_T conv3_weights_29_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -16, -11, -2, 5},
    {0, -10, -42, -6, -6},
    {-4, -27, -16, 6, 5},
    {-11, -9, 4, 3, -2},
    {4, -4, -16, -12, -8}};
static const WDATA_T conv3_weights_29_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, -4, -4, -6},
    {-13, -2, -9, -7, -8},
    {-15, -26, -1, -7, -5},
    {-14, -9, -4, -4, 21},
    {-19, 13, 14, 9, -4}};
static const WDATA_T conv3_weights_29_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -6, -10, -7, 1},
    {12, 9, -8, 3, 16},
    {14, 14, -7, 4, 16},
    {4, 12, 4, -7, 8},
    {-2, 5, 4, 3, 6}};
static const WDATA_T conv3_weights_29_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -10, 6, 18, 27},
    {-10, -10, -22, 5, -9},
    {-3, 9, 7, -4, -24},
    {-5, -18, 0, -11, -20},
    {-8, -13, -4, -7, -16}};
static const WDATA_T conv3_weights_29_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, 17, 20, -8, -13},
    {-2, -12, -16, 11, 6},
    {19, -7, -1, 24, -3},
    {29, -18, -8, 11, 12},
    {-24, -15, -10, 16, 9}};
static const WDATA_T conv3_weights_29_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -9, 0, -9, 15},
    {-19, -2, 17, 23, 18},
    {7, 2, 12, 43, -8},
    {2, 5, 4, 3, -5},
    {0, -10, -2, -10, 10}};
static const WDATA_T conv3_weights_29_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 30, 27, 21, -9},
    {-9, -32, -30, 1, -19},
    {-21, -56, -28, 8, 1},
    {-17, -28, 3, 11, 11},
    {-40, -41, 1, 29, -4}};
static const WDATA_T conv3_weights_29_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 12, 11, 18, -21},
    {-21, -24, 17, 12, 2},
    {-9, 12, 18, 46, 22},
    {16, 3, 13, -5, -34},
    {-9, 7, 9, -4, 14}};
static const WDATA_T conv3_weights_29_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 0, 1, -1},
    {-2, 1, -1, 0, 3},
    {1, -1, 3, 1, 0},
    {-3, 1, 1, 0, -1},
    {5, 0, 1, 0, 0}};
static const WDATA_T conv3_weights_29_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, -2, -1, -4},
    {2, 11, 3, -8, -12},
    {3, 3, -1, 0, 1},
    {2, -1, 4, 5, 2},
    {3, -1, 1, -1, 1}};
static const WDATA_T conv3_weights_29_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -11, -18, -5, -4},
    {-21, -15, -11, 4, -6},
    {13, 3, -13, 12, 3},
    {-4, -36, -18, -8, 2},
    {7, -10, -8, 4, 1}};
static const WDATA_T conv3_weights_29_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, -12, -28, -26},
    {13, -4, -30, -26, -34},
    {-28, -47, -33, -15, -15},
    {-38, -42, -14, 13, -1},
    {-28, -3, -2, 6, -1}};
static const WDATA_T conv3_weights_29_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 4, -6, -16, -9},
    {9, 28, 2, -16, -21},
    {7, 8, 4, 2, 5},
    {-32, -33, -16, -7, -13},
    {35, 25, 33, 24, -2}};
static const WDATA_T conv3_weights_29_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 11, 13, -33, -54},
    {2, 5, -9, -10, -40},
    {22, 10, 10, 34, 34},
    {4, 21, -1, 15, 9},
    {-12, -8, -3, 7, -4}};
static const WDATA_T conv3_weights_30_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, 0, -1, -2},
    {0, -2, 1, -1, -1},
    {1, 3, 1, -2, -1},
    {5, -4, -1, 1, 0},
    {2, -1, -1, -1, -2}};
static const WDATA_T conv3_weights_30_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 2, 1, 1},
    {2, 3, 0, 0, 6},
    {3, -2, 1, -2, 1},
    {-1, 2, -4, 2, -1},
    {-5, 0, 1, -4, -3}};
static const WDATA_T conv3_weights_30_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 2, 0, -2},
    {0, -2, -1, -3, -4},
    {-1, 0, -2, -3, 1},
    {0, 2, 1, 0, 0},
    {-1, -3, 4, -2, 1}};
static const WDATA_T conv3_weights_30_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -4, -2, -2},
    {2, -1, 1, -1, 0},
    {1, 1, -1, 3, -2},
    {0, 3, 0, -1, -3},
    {-2, -3, 5, 4, 3}};
static const WDATA_T conv3_weights_30_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -2, 5, 3},
    {1, 0, 0, -1, 0},
    {-2, -1, 1, -1, 0},
    {0, 5, 0, -1, -1},
    {1, 0, -1, 2, 1}};
static const WDATA_T conv3_weights_30_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -1, -1, -3},
    {2, 1, -2, 1, 0},
    {-2, 1, 0, -1, 2},
    {1, 1, -2, 0, 0},
    {1, -2, 2, 0, -2}};
static const WDATA_T conv3_weights_30_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 0, -1, -1},
    {1, 0, 3, -1, 2},
    {3, -3, 4, -4, 0},
    {-1, -1, -5, 1, -1},
    {-1, 3, -1, -1, -3}};
static const WDATA_T conv3_weights_30_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 4, 0, 0, 2},
    {2, 2, 1, -1, -2},
    {-1, 2, 0, 1, -2},
    {3, 1, -3, 0, 0},
    {-2, 0, -3, -2, -1}};
static const WDATA_T conv3_weights_30_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 1, 0, 2},
    {1, 2, -2, 1, 2},
    {1, 3, 0, -2, 3},
    {-4, 0, -1, -1, 1},
    {-3, -3, 1, 1, 6}};
static const WDATA_T conv3_weights_30_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 3, -2, -3},
    {-3, 1, 1, 3, -2},
    {0, -1, -1, -2, -2},
    {3, -1, 1, 1, 2},
    {1, 1, 0, -3, -2}};
static const WDATA_T conv3_weights_30_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, -2, 2},
    {-1, -1, 2, -2, -5},
    {0, 1, -4, -3, -2},
    {2, 0, 1, -2, -2},
    {-3, 0, -1, -1, 1}};
static const WDATA_T conv3_weights_30_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -2, 1, -1},
    {-2, 2, 2, 4, -1},
    {1, -4, 5, 1, -1},
    {-1, 0, -2, 2, 3},
    {0, 0, 1, 0, 0}};
static const WDATA_T conv3_weights_30_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, -1, -4, 1},
    {1, -2, 0, 2, -1},
    {1, -2, 2, -3, 3},
    {-1, -1, -2, -1, 3},
    {-2, -4, 1, -1, -1}};
static const WDATA_T conv3_weights_30_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, 2, 0, 1},
    {4, 1, 2, 2, 2},
    {-1, 1, -2, 0, 2},
    {-2, 3, -3, -1, 0},
    {0, 1, 3, 2, 0}};
static const WDATA_T conv3_weights_30_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 2, -3, 3},
    {-1, -1, -5, -1, -3},
    {-1, -3, -1, 1, -2},
    {0, 3, 3, 2, 1},
    {0, 2, 0, 2, 1}};
static const WDATA_T conv3_weights_30_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -5, 0, 1},
    {0, 1, 2, -1, -2},
    {2, -1, 1, 0, -4},
    {1, 1, 1, -1, 2},
    {1, -3, 1, 0, -3}};
static const WDATA_T conv3_weights_31_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -6, 1, 1},
    {-2, -6, -4, 0, -1},
    {-2, 4, 0, -3, -1},
    {-5, -7, -4, -2, 2},
    {-5, -5, -2, -4, -1}};
static const WDATA_T conv3_weights_31_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 10, 12, -4, -5},
    {0, 0, 8, 7, -4},
    {0, -4, -5, 1, 4},
    {0, -2, -1, -6, 1},
    {0, -7, -4, -1, 0}};
static const WDATA_T conv3_weights_31_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 7, 8, 0, 1},
    {-1, 4, 4, -8, 1},
    {-4, 3, -4, -2, -3},
    {-7, 2, -1, -2, 0},
    {-1, -1, 0, -2, 2}};
static const WDATA_T conv3_weights_31_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -4, -1, 4},
    {-4, -1, -6, -8, -1},
    {-5, -7, -5, -5, 0},
    {-6, -3, 0, -1, 7},
    {-7, -9, -5, -7, -6}};
static const WDATA_T conv3_weights_31_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -2, 1, 1},
    {0, -3, -1, -3, -3},
    {0, 1, 1, -6, 3},
    {0, 4, 3, 0, -3},
    {-4, -2, -1, -1, 3}};
static const WDATA_T conv3_weights_31_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 9, 9, -2, -5},
    {-5, 1, 11, 9, -1},
    {0, -3, 0, -2, -1},
    {0, 1, 0, -7, 5},
    {2, -3, -6, -3, 1}};
static const WDATA_T conv3_weights_31_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -7, -2, 9, -2},
    {-6, -3, 0, -3, -1},
    {1, 0, -1, -1, 0},
    {0, 3, 1, 1, -1},
    {-2, -7, 1, -2, -2}};
static const WDATA_T conv3_weights_31_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 3, -7, 3},
    {1, 10, 3, -5, -1},
    {2, 7, 0, 10, 4},
    {0, 6, 2, 11, 8},
    {-1, 4, 7, 2, 2}};
static const WDATA_T conv3_weights_31_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -7, -6, 0, 1},
    {2, -2, -4, -4, -3},
    {-6, -5, -11, -4, -2},
    {1, 5, 6, 1, -4},
    {0, -3, -5, 5, 3}};
static const WDATA_T conv3_weights_31_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -8, -8, -3, 3},
    {-7, -2, -6, -1, 3},
    {-4, -2, 7, -4, -8},
    {1, 4, 6, -6, -4},
    {3, 5, 2, 0, 4}};
static const WDATA_T conv3_weights_31_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 0, 3, -1, -1},
    {1, 2, -4, 0, 0},
    {1, 0, 4, 0, 0},
    {1, 3, 3, -1, -2},
    {-4, 3, 3, 0, -3}};
static const WDATA_T conv3_weights_31_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, 2, 0, -1},
    {-1, -1, 1, -2, 0},
    {3, -1, 0, -2, -1},
    {2, 2, -2, -1, 0},
    {2, -1, 4, 1, -2}};
static const WDATA_T conv3_weights_31_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, 5, 6, -3},
    {-1, -3, 13, 5, 3},
    {0, -6, -5, -4, 0},
    {4, -5, -3, -2, 0},
    {2, 4, -4, -2, -1}};
static const WDATA_T conv3_weights_31_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, 4, 7, 0},
    {-1, -1, -3, 3, 1},
    {6, 5, -2, -1, 0},
    {-3, -3, -5, -2, -3},
    {-1, 0, -1, 1, -1}};
static const WDATA_T conv3_weights_31_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, -4, -2, 3},
    {2, 9, 8, -3, -2},
    {-12, -2, -7, -3, 0},
    {-3, 1, -4, -6, -1},
    {1, 4, 5, 1, 2}};
static const WDATA_T conv3_weights_31_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 4, 10, -6, -7},
    {-2, 3, 3, -14, -5},
    {0, -2, 0, 3, 3},
    {-3, -1, -3, 4, 8},
    {2, 6, -3, -3, 5}};
static const WDATA_T conv3_weights_32_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -10, 0, 8, 16},
    {-2, -3, -8, -3, -8},
    {6, -1, -12, -24, -18},
    {5, 9, -6, -9, 1},
    {3, -6, -10, 9, 6}};
static const WDATA_T conv3_weights_32_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 15, 13, 2, -7},
    {-8, -10, 1, 7, 5},
    {-10, -4, 26, 8, -1},
    {9, 11, 11, 12, -11},
    {2, 12, 8, -8, -1}};
static const WDATA_T conv3_weights_32_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 6, -7, -5, -8},
    {12, 8, 4, 4, -9},
    {4, 13, 20, 8, -3},
    {-15, 12, 21, 18, 10},
    {-11, 0, 6, 2, -3}};
static const WDATA_T conv3_weights_32_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 1, -2, 4},
    {0, 16, 32, 35, 17},
    {-1, 21, 12, 21, 2},
    {6, 10, 10, -7, -33},
    {0, 2, -4, -14, -5}};
static const WDATA_T conv3_weights_32_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 2, -3, 2, -1},
    {4, 0, 4, -2, -2},
    {11, -4, 5, 7, 10},
    {7, -10, 6, 4, 4},
    {2, -6, -7, -4, 3}};
static const WDATA_T conv3_weights_32_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 15, 9, 2},
    {4, 8, 24, 31, 15},
    {-7, 2, 11, 1, 1},
    {0, 2, 14, 13, -1},
    {-3, 3, 24, 2, -1}};
static const WDATA_T conv3_weights_32_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 13, 8, -7, -3},
    {20, 12, -2, 0, -2},
    {-16, -7, -10, -3, 4},
    {-27, 5, 7, -2, -4},
    {-7, 3, 5, 4, 3}};
static const WDATA_T conv3_weights_32_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 13, -5, 12, -3},
    {9, -5, 5, 9, -2},
    {1, -8, 14, 13, -8},
    {-6, 18, 32, -7, -12},
    {9, 7, 15, 15, -3}};
static const WDATA_T conv3_weights_32_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -22, -8, -2, -2},
    {-17, -30, -7, 6, 22},
    {-21, -22, -22, 1, 21},
    {-7, 7, 4, 0, -2},
    {-5, -12, -3, 1, -2}};
static const WDATA_T conv3_weights_32_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -9, -5, -7, 2},
    {8, -11, -25, -45, -33},
    {0, 1, -34, -68, -15},
    {-4, -14, -14, 10, 25},
    {-14, -1, 7, 30, 4}};
static const WDATA_T conv3_weights_32_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -3, -5, -2},
    {2, 0, 2, 4, 1},
    {-1, -2, 3, 0, 4},
    {-3, 0, 0, -1, 0},
    {-3, -1, 0, 1, -1}};
static const WDATA_T conv3_weights_32_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, 1, 3, 2},
    {-2, -6, -1, 1, 5},
    {-5, -5, -3, -5, -2},
    {1, 0, -1, -3, -1},
    {1, -3, -3, 1, 1}};
static const WDATA_T conv3_weights_32_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 17, -6, 10, 17},
    {33, 32, -1, -8, -14},
    {18, 14, 8, 16, 8},
    {10, 33, 7, -1, 13},
    {-12, 10, 2, 10, 5}};
static const WDATA_T conv3_weights_32_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, -12, 2, 21, 14},
    {-37, -9, 31, 35, 14},
    {-10, 13, 15, 35, 27},
    {2, 10, 18, -10, 2},
    {8, 11, 12, -1, -1}};
static const WDATA_T conv3_weights_32_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 14, 16, 18, 12},
    {-22, -25, 6, 10, 27},
    {-6, -28, -45, -33, -16},
    {1, -4, -15, 5, 2},
    {-5, -10, 1, 25, 14}};
static const WDATA_T conv3_weights_32_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 1, -8, -2, -11},
    {5, 0, -5, -48, -81},
    {1, -6, -5, -32, -57},
    {0, -6, 5, -3, 11},
    {5, 5, 4, 10, 11}};
static const WDATA_T conv3_weights_33_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -4, 3, 3, -1},
    {-3, -2, -1, 2, 4},
    {-3, 2, 0, 2, 1},
    {0, 0, -4, -5, -3},
    {-3, -3, -7, -1, -1}};
static const WDATA_T conv3_weights_33_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -4, -11, -3},
    {-2, 1, 8, 6, -2},
    {-4, 0, 1, 8, 5},
    {-3, 2, 6, -1, 3},
    {4, 3, 5, -2, -1}};
static const WDATA_T conv3_weights_33_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -3, -6, -5},
    {0, -2, -3, 0, -8},
    {-2, 5, -5, -1, 1},
    {-2, 1, -3, 0, 2},
    {-1, 0, -2, 3, 2}};
static const WDATA_T conv3_weights_33_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, 3, -1, -8},
    {-5, 1, 0, 18, 18},
    {0, -6, -2, 5, 5},
    {-3, -1, 5, 0, -3},
    {-1, -1, 3, 3, -1}};
static const WDATA_T conv3_weights_33_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -2, 2, 4},
    {-3, 0, -1, 2, 0},
    {2, 0, 1, 0, -3},
    {2, -2, -3, -2, -2},
    {0, 1, -5, -1, 1}};
static const WDATA_T conv3_weights_33_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -8, -5, -5, -1},
    {0, -2, -1, -2, -4},
    {-1, -1, 5, -6, 6},
    {1, 4, 4, -4, 8},
    {2, 2, 8, 0, 3}};
static const WDATA_T conv3_weights_33_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 10, -3, -6, -4},
    {8, -5, -1, -4, -1},
    {-7, -3, 1, 1, -1},
    {-3, 2, 0, -2, 3},
    {0, -1, -1, -1, -2}};
static const WDATA_T conv3_weights_33_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, -1, -2, 1},
    {1, -4, -5, -9, -6},
    {-2, 2, -1, -2, -3},
    {-3, 6, 0, 2, 2},
    {1, 2, 0, -5, 4}};
static const WDATA_T conv3_weights_33_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 5, -1, -3, -3},
    {3, -5, -3, -2, 1},
    {-7, -7, -2, 5, 3},
    {-9, -4, -3, -4, 0},
    {1, -3, -6, 0, 0}};
static const WDATA_T conv3_weights_33_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, 9, 5, 6},
    {-4, -2, -1, -8, -6},
    {4, 3, -5, -8, -2},
    {-2, -2, -7, -8, -2},
    {-4, -7, -6, -4, 3}};
static const WDATA_T conv3_weights_33_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 0, 0, 2},
    {1, -1, -2, 0, 3},
    {-1, 2, 0, 1, -4},
    {0, 0, 3, 0, 2},
    {-4, 3, -1, 0, -1}};
static const WDATA_T conv3_weights_33_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, -2, -1, 2},
    {-1, 1, -1, 0, 3},
    {-3, 0, -1, -3, -1},
    {2, 2, -3, -1, -1},
    {-1, 0, 1, -1, -1}};
static const WDATA_T conv3_weights_33_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -3, -9, -2, -5},
    {9, -1, -3, -3, -3},
    {6, -6, 0, 0, 1},
    {-7, -4, -1, -1, -2},
    {-3, -3, 1, 0, 3}};
static const WDATA_T conv3_weights_33_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -1, 3, -2, -8},
    {-9, -4, -4, 13, 12},
    {1, -3, -2, 2, -1},
    {8, 1, -1, 3, 0},
    {4, 2, 5, -1, 3}};
static const WDATA_T conv3_weights_33_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -6, -1, 6},
    {-7, -6, 0, -5, -3},
    {1, 2, 0, 6, 2},
    {1, 5, -3, 3, 4},
    {-5, -6, 2, 3, -1}};
static const WDATA_T conv3_weights_33_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -3, -14, -7},
    {-3, 0, 1, -15, 0},
    {-3, 2, 0, -6, 0},
    {-3, -1, 0, -3, -2},
    {-1, -3, -2, -7, -3}};
static const WDATA_T conv3_weights_34_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -18, 4, 2, -2},
    {-14, -11, -5, -11, -6},
    {-6, -7, -2, -4, -4},
    {-2, -1, 2, -6, -7},
    {-7, -2, 10, -8, -8}};
static const WDATA_T conv3_weights_34_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -4, -6, -3, 1},
    {6, 9, -8, -12, -1},
    {-5, 0, -6, -12, -12},
    {-10, -13, -10, -8, -12},
    {2, 7, 5, 8, 1}};
static const WDATA_T conv3_weights_34_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -16, 10, 18},
    {6, -7, -17, 3, -2},
    {5, -1, -20, -16, -7},
    {8, 6, -9, 1, -8},
    {3, 1, -2, -5, -1}};
static const WDATA_T conv3_weights_34_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, 1, -1, -3},
    {-4, -15, -15, -6, 5},
    {-3, -11, -12, 2, 11},
    {-8, -11, 2, 13, 23},
    {2, -3, 3, 11, -2}};
static const WDATA_T conv3_weights_34_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, 4, 5, -1},
    {-8, 0, 17, 4, -3},
    {1, 8, 18, 9, -1},
    {4, 12, 11, 2, 7},
    {0, 0, 1, -1, 0}};
static const WDATA_T conv3_weights_34_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -19, -29, 3, 10},
    {5, 3, -19, -7, 3},
    {3, -2, -11, -6, -10},
    {-5, -7, -7, -5, -14},
    {-5, -4, -2, 8, -2}};
static const WDATA_T conv3_weights_34_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 29, 24, 10, -6},
    {13, 24, 6, 5, 0},
    {2, 15, -6, -3, 2},
    {5, 7, -1, 5, 6},
    {-4, 2, 4, 2, -3}};
static const WDATA_T conv3_weights_34_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -1, -10, -13, -3},
    {-1, -9, -19, -7, 9},
    {-5, -8, -14, 2, 10},
    {-2, -1, -2, -3, 4},
    {-1, 3, 14, 1, -6}};
static const WDATA_T conv3_weights_34_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, 14, 14, 14, 1},
    {2, 5, 0, 9, -4},
    {-1, 15, 12, 5, -11},
    {-4, 0, 0, 4, -1},
    {8, 9, 3, -5, -7}};
static const WDATA_T conv3_weights_34_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -17, -2, 20, 16},
    {-3, 5, 11, 7, 0},
    {4, 2, 21, 16, -12},
    {1, 25, 13, -17, -21},
    {4, -7, -17, -6, -1}};
static const WDATA_T conv3_weights_34_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 1, 1, 2, -1},
    {0, -3, -2, -1, 1},
    {1, 0, -1, -2, 2},
    {-3, 0, -1, -3, -1},
    {-1, 0, 1, -3, 1}};
static const WDATA_T conv3_weights_34_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, 1, -1, -1},
    {-3, 0, -2, 1, 0},
    {-2, 4, 4, 1, 0},
    {0, -2, 6, 5, 4},
    {1, 0, -1, -4, 0}};
static const WDATA_T conv3_weights_34_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-25, 0, 9, 6, -7},
    {-2, 20, 8, 2, 1},
    {3, 5, -4, -6, -8},
    {8, 5, -4, -5, -3},
    {13, 3, 2, 4, 1}};
static const WDATA_T conv3_weights_34_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, 7, 7, -1, 1},
    {-9, 8, 3, 2, -2},
    {-12, -5, 0, -3, -8},
    {-12, -3, 6, -6, -12},
    {2, -7, -2, 4, 5}};
static const WDATA_T conv3_weights_34_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -16, -15, -12, -5},
    {-12, -17, -2, 5, 0},
    {-10, -28, -19, -14, -3},
    {6, -10, -11, -6, -11},
    {-12, -6, -1, -15, -19}};
static const WDATA_T conv3_weights_34_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 20, 13, -3, 5},
    {14, 14, -1, 5, 17},
    {5, 3, -7, 13, 21},
    {8, -3, -7, 30, 17},
    {-2, 1, 1, 7, -4}};
static const WDATA_T conv3_weights_35_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, 1, 2, -1},
    {-1, 0, -2, 3, -3},
    {0, -1, -2, 1, 0},
    {0, -2, 1, -1, -1},
    {0, -2, 0, 2, 0}};
static const WDATA_T conv3_weights_35_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 1, 0, -1},
    {1, -3, -1, 0, -2},
    {0, 2, -2, 0, 0},
    {1, 0, -3, -3, -1},
    {1, -1, 0, 2, -2}};
static const WDATA_T conv3_weights_35_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 3, -4, 1},
    {-2, -2, -1, 0, 0},
    {-2, 2, -2, 0, -1},
    {-2, -1, -2, -1, -2},
    {0, -1, -3, 1, 2}};
static const WDATA_T conv3_weights_35_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 2, 0, -2},
    {-4, -2, -2, -2, -3},
    {-2, 2, 4, -1, -1},
    {-1, 0, -1, -1, 1},
    {1, -2, 0, -1, -2}};
static const WDATA_T conv3_weights_35_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -1, -1, -2},
    {1, 0, 0, 4, 0},
    {-1, 0, 1, -1, -1},
    {0, 2, 1, -2, -1},
    {0, 1, 1, 4, 1}};
static const WDATA_T conv3_weights_35_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 0, 1, 0},
    {0, 0, -2, 1, -1},
    {3, -5, 4, -1, 1},
    {1, 1, 0, 1, -3},
    {0, 3, -1, -1, -1}};
static const WDATA_T conv3_weights_35_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 1, 1, -1, 1},
    {0, 2, 0, 0, 1},
    {5, 0, 0, -1, 3},
    {-1, -1, 0, -3, 1},
    {4, 2, 0, 1, 0}};
static const WDATA_T conv3_weights_35_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, 2, 1, 3},
    {0, 3, -1, -1, -2},
    {-3, -1, -2, -2, -1},
    {1, -4, 0, 3, -1},
    {-2, 2, -1, 1, -4}};
static const WDATA_T conv3_weights_35_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, 2, -1, 0},
    {-2, -3, 0, 2, 0},
    {1, 2, -3, -2, -3},
    {-1, 0, 0, 2, 0},
    {1, -3, -3, 4, 3}};
static const WDATA_T conv3_weights_35_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, -3, 0, 3},
    {2, -2, -4, 3, 1},
    {2, 0, 1, 0, 4},
    {0, -1, -1, 3, -3},
    {-2, 0, 0, -1, -1}};
static const WDATA_T conv3_weights_35_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, 2, -2},
    {-2, -2, -2, 0, 0},
    {1, -2, 0, -4, -2},
    {2, 0, -1, 0, 1},
    {-2, -2, -2, -2, 3}};
static const WDATA_T conv3_weights_35_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 0, 2, 1, -1},
    {3, -3, -3, 2, 2},
    {0, -1, 2, 4, 1},
    {1, -1, 2, 2, 1},
    {3, 1, 2, -3, 2}};
static const WDATA_T conv3_weights_35_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 2, -1, 1, -1},
    {-3, 0, -7, 1, -1},
    {-1, 2, 3, -1, -1},
    {-2, 1, 1, 0, -1},
    {-2, -3, 4, -4, -1}};
static const WDATA_T conv3_weights_35_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, -1, -1, -1},
    {-2, 0, -2, 0, 1},
    {-2, -2, -1, -2, -2},
    {0, 2, -3, 1, 1},
    {2, 2, -3, 2, 0}};
static const WDATA_T conv3_weights_35_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 2, -2, -1},
    {-3, 0, -1, -2, -2},
    {2, -6, 0, -1, 1},
    {-2, -2, 2, 2, 0},
    {-1, -1, -1, -5, 2}};
static const WDATA_T conv3_weights_35_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 2, -1, -2},
    {1, -1, 0, 1, 1},
    {0, -2, -2, 0, -2},
    {2, 3, -4, -2, 0},
    {0, -2, 1, -3, 0}};
static const WDATA_T conv3_weights_36_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -15, -8, 5, 5},
    {-2, -18, -2, 5, 9},
    {4, 6, 10, 0, -6},
    {0, 5, 15, 1, -8},
    {8, 7, 2, -3, -7}};
static const WDATA_T conv3_weights_36_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 1, 4, -4, -1},
    {4, 15, 2, 2, 5},
    {11, 11, -14, -3, 12},
    {10, 11, -2, -6, 3},
    {-3, -1, -3, 1, -5}};
static const WDATA_T conv3_weights_36_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 18, 5, 11, -20},
    {-8, 7, -8, -3, -19},
    {3, -10, -9, 10, -5},
    {9, 0, -4, 11, 3},
    {6, 3, -6, -2, 4}};
static const WDATA_T conv3_weights_36_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, 2, 0, 2},
    {-15, -27, -20, -15, -4},
    {-2, -8, -20, -3, 11},
    {-9, -15, -8, -6, -1},
    {-8, 2, 14, 17, 2}};
static const WDATA_T conv3_weights_36_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 6, 14, 6, 7},
    {9, 8, 19, 8, 5},
    {5, 17, 18, 7, 2},
    {6, 15, 12, 5, 5},
    {9, 3, 14, 3, 3}};
static const WDATA_T conv3_weights_36_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -8, 4, 9},
    {4, 16, 6, -3, -2},
    {6, -2, 0, 10, 7},
    {1, 7, 8, 8, 13},
    {1, -7, -13, -8, 6}};
static const WDATA_T conv3_weights_36_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-40, -20, 1, 9, -8},
    {-11, 7, -12, -13, -1},
    {6, -1, -8, -8, -6},
    {-8, -2, -2, 7, -2},
    {-13, -3, 16, 25, 8}};
static const WDATA_T conv3_weights_36_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, 3, 4, -1, -4},
    {2, 15, 2, -2, -11},
    {0, -6, 12, 18, -4},
    {0, -6, 9, 5, 11},
    {0, 5, -6, 3, 18}};
static const WDATA_T conv3_weights_36_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -19, -14, 0, 0},
    {-20, -18, -25, -6, -7},
    {16, -16, 5, 0, 2},
    {-4, -4, 4, 8, 2},
    {-9, 8, 24, 17, 0}};
static const WDATA_T conv3_weights_36_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -34, -39, -10, 9},
    {-13, -25, -4, -1, -9},
    {-6, 2, 9, 4, 6},
    {5, 22, 35, 4, -6},
    {23, -1, 8, 5, 13}};
static const WDATA_T conv3_weights_36_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 1, -2, 2, -2},
    {1, 1, -3, 1, 1},
    {-2, 3, 1, 2, 0},
    {2, -3, 0, -2, -1},
    {-2, 0, -4, -5, -1}};
static const WDATA_T conv3_weights_36_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -1, 3, 1},
    {-5, -8, -3, 3, 0},
    {-3, -3, 0, -2, 1},
    {2, 4, 6, 1, 0},
    {3, 8, 3, 1, 1}};
static const WDATA_T conv3_weights_36_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, 17, 22, -1, 3},
    {-8, 24, 22, -14, 2},
    {11, -1, -12, -7, 0},
    {16, 6, 1, 0, -8},
    {-7, -21, -8, -5, 1}};
static const WDATA_T conv3_weights_36_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 7, 5, -6, -17},
    {-7, -2, -3, -9, -12},
    {-3, -2, -6, 1, -3},
    {-10, -10, -22, -4, -8},
    {17, 13, 0, -3, -4}};
static const WDATA_T conv3_weights_36_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -12, -15, 1, 13},
    {-3, -21, -20, -7, 8},
    {-22, -14, -9, -11, -6},
    {16, 18, 12, 0, -7},
    {18, 20, 19, 17, 5}};
static const WDATA_T conv3_weights_36_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -9, -10, -19, -9},
    {15, 10, -30, -10, -20},
    {-1, -3, -1, 10, -29},
    {-2, -9, -4, 26, 3},
    {1, 2, 18, 3, 25}};
static const WDATA_T conv3_weights_37_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 26, 24, 14, -11},
    {3, 22, 31, 0, -8},
    {-1, 6, 13, -8, -5},
    {-2, 1, 0, -9, -6},
    {18, 31, 7, 1, -3}};
static const WDATA_T conv3_weights_37_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -3, -1, 12, 7},
    {-5, -1, -9, 9, 5},
    {-4, 0, 10, -8, -2},
    {8, 0, 2, 9, 5},
    {9, 8, 12, 14, 9}};
static const WDATA_T conv3_weights_37_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 2, 10, 8, -7},
    {0, -4, 13, -7, -13},
    {2, 9, 11, 8, 6},
    {1, 10, 10, 20, 17},
    {-2, 11, 10, 17, 16}};
static const WDATA_T conv3_weights_37_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 6, 12, 14},
    {-1, 6, 9, -1, -18},
    {-2, 7, -4, 15, -17},
    {9, 3, -10, -18, -12},
    {-16, -11, -19, 0, -11}};
static const WDATA_T conv3_weights_37_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 17, 21, 13, -1},
    {14, 28, 20, 9, -2},
    {14, 18, 25, 18, 3},
    {14, 12, 18, 21, 12},
    {5, 2, 21, 24, 9}};
static const WDATA_T conv3_weights_37_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -22, 6, 25, -18},
    {-4, -9, -3, 18, 7},
    {3, -18, -6, 10, 14},
    {-2, -11, -12, 26, 20},
    {7, 10, 2, 9, 15}};
static const WDATA_T conv3_weights_37_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 10, -6, -3, -4},
    {-14, -4, -3, 9, -3},
    {-10, -12, -2, 10, -1},
    {-20, -3, 7, 2, 3},
    {-9, 6, 17, 11, -3}};
static const WDATA_T conv3_weights_37_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 5, -2, 9, -7},
    {-3, 19, 8, 0, -15},
    {-12, -2, 20, -14, -12},
    {-15, -15, 26, 7, -2},
    {-2, -13, 8, -1, 8}};
static const WDATA_T conv3_weights_37_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 10, 1, 0, 1},
    {-20, -31, -11, -4, -23},
    {-4, 23, 49, 11, 1},
    {1, -23, -24, -15, -1},
    {-21, 4, 16, 14, -5}};
static const WDATA_T conv3_weights_37_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 0, 10, -19, -39},
    {0, 13, 12, -13, -16},
    {-14, -28, -21, -5, -3},
    {-5, -6, 23, -5, -30},
    {-2, 4, 9, -8, 9}};
static const WDATA_T conv3_weights_37_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, 0, -2, -2},
    {1, 2, 0, 2, -1},
    {-3, 0, 0, -1, 0},
    {-3, 0, 1, 0, -2},
    {3, -3, 0, -2, -3}};
static const WDATA_T conv3_weights_37_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, 4, 2, -2},
    {-1, 2, 6, 3, -2},
    {-2, 6, 6, 3, 2},
    {-6, 2, 7, 4, 3},
    {0, -3, 2, 0, -2}};
static const WDATA_T conv3_weights_37_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -8, -25, -17, -6},
    {-11, -11, -17, 3, -5},
    {-5, -3, -7, 11, 1},
    {-2, 22, 25, 10, -4},
    {0, 25, 18, 10, 4}};
static const WDATA_T conv3_weights_37_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -17, -9, -9, -7},
    {12, 22, 25, 2, -11},
    {-11, -4, 5, 4, 2},
    {-12, 30, 27, 17, -1},
    {1, 17, 12, 11, 5}};
static const WDATA_T conv3_weights_37_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 5, 23, -2, -17},
    {8, 11, 11, 12, 12},
    {-27, -24, -18, -26, -9},
    {-10, -9, 14, 9, 0},
    {-10, -14, -17, -5, -10}};
static const WDATA_T conv3_weights_37_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 4, 6, 13, 3},
    {5, 7, 16, 18, -32},
    {2, -6, 9, 5, -19},
    {10, 5, 3, 1, -6},
    {5, 12, 10, 25, -3}};
static const WDATA_T conv3_weights_38_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -20, -20, -11, -6},
    {-5, -10, -11, -13, 0},
    {-6, -8, -11, -1, 3},
    {-18, -7, -5, 12, 1},
    {-8, -22, 0, 7, 1}};
static const WDATA_T conv3_weights_38_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 0, -20, -24},
    {4, 7, 10, 2, -1},
    {-2, -3, 8, -9, 2},
    {-13, -3, 6, -3, -8},
    {-3, -7, -5, -1, 1}};
static const WDATA_T conv3_weights_38_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 7, 10, 16, 2},
    {-2, 12, 25, 20, -4},
    {4, 9, -3, 0, -19},
    {10, 18, 9, 2, -9},
    {4, 5, 3, -5, -10}};
static const WDATA_T conv3_weights_38_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -2, 3, 10},
    {-10, -27, -24, -14, -3},
    {-7, -13, -14, -12, -4},
    {1, 0, -8, -9, 16},
    {18, 19, 5, 10, 8}};
static const WDATA_T conv3_weights_38_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -8, 0, 0, 3},
    {-6, -13, 6, -7, -5},
    {2, -5, 5, -6, 0},
    {4, -11, 1, -2, 2},
    {0, -10, -6, -1, 1}};
static const WDATA_T conv3_weights_38_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -20, -12, -7, -12},
    {0, 7, 13, 12, -6},
    {0, 0, 11, 12, -3},
    {-4, -9, 9, 9, 8},
    {-2, -10, -5, -2, 2}};
static const WDATA_T conv3_weights_38_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -2, -2, 17, 6},
    {8, 3, -1, -2, 7},
    {15, 6, -13, -9, -1},
    {11, 7, -7, -4, -4},
    {9, 11, 6, 3, 3}};
static const WDATA_T conv3_weights_38_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 5, 11, 12, 10},
    {11, 6, 10, 2, -9},
    {12, -5, 6, 8, -16},
    {8, 3, 7, 15, -3},
    {-1, 7, 3, 14, -3}};
static const WDATA_T conv3_weights_38_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -1, -8, -2, 0},
    {-5, -7, -19, -2, -6},
    {6, -4, -9, -8, -6},
    {-1, -3, -16, 10, 1},
    {3, 1, -3, -2, 6}};
static const WDATA_T conv3_weights_38_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -32, -22, -3, 1},
    {-7, 5, -3, -13, -3},
    {11, 2, -2, 1, 8},
    {-2, 4, -9, -5, 15},
    {0, -6, -14, -1, -4}};
static const WDATA_T conv3_weights_38_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -1, 0, 0},
    {3, 2, -1, 3, 3},
    {2, 0, -3, 2, 1},
    {-1, 1, 1, -1, 2},
    {1, -1, -1, 2, 3}};
static const WDATA_T conv3_weights_38_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, -2, 2, -3},
    {-1, -1, -2, 0, 2},
    {1, 0, 0, 2, -4},
    {-1, 0, 2, 4, 2},
    {-1, -1, 1, 7, 4}};
static const WDATA_T conv3_weights_38_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, 1, 17, 5, -3},
    {0, 2, 37, -2, 7},
    {11, -4, 7, -8, -2},
    {27, 22, -6, 5, 4},
    {10, 12, -8, -2, 6}};
static const WDATA_T conv3_weights_38_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 8, 2, 5, -7},
    {0, 14, -4, 8, 6},
    {-18, -12, -6, 5, -1},
    {4, -16, -9, 2, 4},
    {-1, 2, -2, 2, 2}};
static const WDATA_T conv3_weights_38_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -5, -7, -10, -7},
    {-9, 0, -1, -2, -1},
    {-5, -3, 6, 13, 5},
    {6, 31, 25, 13, -2},
    {-19, 5, -7, 11, 21}};
static const WDATA_T conv3_weights_38_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 3, 10, 9, 7},
    {8, 5, 39, 22, 16},
    {-8, 1, 27, 8, 0},
    {-3, -2, 5, 7, -5},
    {4, 9, 7, -17, -13}};
static const WDATA_T conv3_weights_39_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 17, 54, 13, -4},
    {4, 27, -11, -14, -39},
    {17, 5, -21, -22, -26},
    {-17, -11, 6, 7, 11},
    {-13, -20, 4, 19, 14}};
static const WDATA_T conv3_weights_39_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 16, 19, 64, 85},
    {-17, -19, 13, 14, 37},
    {-10, -20, -60, -23, -35},
    {0, 0, -33, -43, -21},
    {-3, -13, -16, -17, 12}};
static const WDATA_T conv3_weights_39_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -91, -94, -53, 3},
    {4, -70, -104, -38, 1},
    {21, 28, -40, 16, -2},
    {10, -5, -16, 45, 10},
    {-18, -8, -6, 29, 7}};
static const WDATA_T conv3_weights_39_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, -2, 7, -7},
    {4, 22, 12, 0, -11},
    {16, 24, -4, 10, -24},
    {-4, -16, 0, -15, 11},
    {-38, -18, 1, -19, -24}};
static const WDATA_T conv3_weights_39_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -12, -9, -5, -16},
    {24, 4, 4, 3, 9},
    {18, 12, 13, 26, 7},
    {-4, 5, 21, -2, -1},
    {-11, -6, 16, -13, -2}};
static const WDATA_T conv3_weights_39_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 27, 39, 67, 23},
    {2, 3, -13, 18, 23},
    {-5, -14, -39, -12, -20},
    {3, 4, -20, -26, -16},
    {-17, -25, -25, -2, 8}};
static const WDATA_T conv3_weights_39_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {57, 32, 38, -55, -38},
    {2, 23, 26, 2, 6},
    {-30, -13, 10, 13, 0},
    {-4, 10, 2, -4, 2},
    {27, 35, 3, -25, -23}};
static const WDATA_T conv3_weights_39_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -24, -49, -44, -13},
    {-30, -37, -21, 20, 46},
    {-1, 19, 20, 19, 34},
    {11, 2, 13, 37, 21},
    {-6, 0, 18, 11, 26}};
static const WDATA_T conv3_weights_39_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {28, 43, 50, 23, -13},
    {-12, -14, -4, 1, -25},
    {-58, -12, 10, 34, -16},
    {-25, 11, 21, 17, 5},
    {-17, 31, 5, -5, -12}};
static const WDATA_T conv3_weights_39_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {44, 73, 26, -4, -45},
    {10, -9, -1, 4, -14},
    {-71, -37, 46, 73, 22},
    {-24, 14, 26, 7, -21},
    {5, 4, -49, -44, -26}};
static const WDATA_T conv3_weights_39_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, -1, -1, 0},
    {1, 0, 2, 1, 0},
    {-4, 1, -1, -2, -1},
    {-4, 0, -3, -3, 3},
    {3, 2, 0, 0, 1}};
static const WDATA_T conv3_weights_39_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -1, 0, -4, -3},
    {11, 13, -3, -8, -6},
    {8, 10, 2, -1, -2},
    {-1, -1, 10, 4, 1},
    {-4, -8, -1, 1, 5}};
static const WDATA_T conv3_weights_39_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, -10, -10, -11, -10},
    {-15, -33, -94, -19, -23},
    {3, -32, -63, 3, -15},
    {-16, -12, 2, 4, -9},
    {-6, -11, -21, -4, -4}};
static const WDATA_T conv3_weights_39_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 23, 9, -7, -8},
    {-15, -42, 2, 18, -23},
    {13, 8, 11, -8, -21},
    {-15, 6, 11, 1, -8},
    {3, -1, -19, 1, 6}};
static const WDATA_T conv3_weights_39_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -1, 3, 7, -10},
    {20, -20, -13, 31, 6},
    {7, 10, 11, -18, -16},
    {-13, -4, 9, -24, -20},
    {-35, -27, 3, 7, -5}};
static const WDATA_T conv3_weights_39_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 35, -23, -61, -65},
    {-11, 5, -42, -21, -31},
    {22, 13, -8, 74, 40},
    {7, 3, -21, 31, 50},
    {0, -4, -23, -13, -15}};
static const WDATA_T conv3_weights_40_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 35, 49, 24, -10},
    {25, 13, 23, 16, 21},
    {10, -7, -26, -3, 36},
    {19, -6, -10, 15, 6},
    {19, 8, -3, -14, 4}};
static const WDATA_T conv3_weights_40_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 20, 19, -20, -12},
    {25, 23, 23, -9, -41},
    {51, 27, -6, -19, 23},
    {28, 26, -22, -26, 10},
    {-5, -18, 1, 39, 35}};
static const WDATA_T conv3_weights_40_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {25, -3, 10, 37, 16},
    {-1, -16, 25, 1, 19},
    {-23, 4, -12, 7, 23},
    {1, -30, -2, 19, 8},
    {4, -18, 26, -8, 12}};
static const WDATA_T conv3_weights_40_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 1, 7, 13, 0},
    {11, 0, 6, 11, 13},
    {-6, -28, -21, 8, 22},
    {10, 5, 15, 5, 38},
    {-10, 6, -10, -2, -19}};
static const WDATA_T conv3_weights_40_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 17, 22, -6, 5},
    {3, 7, 29, 7, -5},
    {31, 14, 20, 18, -28},
    {18, 15, -10, 3, -18},
    {-4, 21, 23, 20, 15}};
static const WDATA_T conv3_weights_40_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 1, 36, 43, 10},
    {-3, -4, 17, 2, -39},
    {20, -1, 2, 14, -11},
    {0, 10, -4, 15, 33},
    {-2, -15, -18, 22, 35}};
static const WDATA_T conv3_weights_40_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -29, -34, -14, 3},
    {-29, -29, 8, 11, 2},
    {-6, -16, -18, -1, -6},
    {7, 15, -7, -5, 4},
    {6, 14, 20, -10, -19}};
static const WDATA_T conv3_weights_40_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-30, -11, -13, -10, -40},
    {-35, 5, 43, 28, -25},
    {-26, -11, 37, 8, 8},
    {-22, -56, -8, 0, 35},
    {-19, 5, 30, 35, 49}};
static const WDATA_T conv3_weights_40_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 11, 13, 6, 16},
    {3, -25, -33, 12, 23},
    {15, 1, -5, 4, -4},
    {65, 28, 8, 8, 22},
    {65, 70, 15, -25, -31}};
static const WDATA_T conv3_weights_40_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 0, -19, -1, 19},
    {-18, 7, 10, 25, 60},
    {21, -6, 21, 19, -3},
    {32, 26, -8, -25, -59},
    {13, 3, 4, -8, -17}};
static const WDATA_T conv3_weights_40_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 0, 1, -2},
    {2, 6, 0, 0, 1},
    {3, 3, 2, -1, 1},
    {0, 0, 0, -3, 4},
    {-3, -2, 2, -4, -1}};
static const WDATA_T conv3_weights_40_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 6, 5, 4, -8},
    {5, 0, 6, 0, -3},
    {2, 20, 8, 9, 10},
    {5, 15, 8, -2, -4},
    {7, 5, -6, -7, -14}};
static const WDATA_T conv3_weights_40_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -10, 7, 14, 1},
    {-3, 31, 16, -7, -20},
    {-21, 5, 33, 36, 4},
    {-4, 33, 33, -2, -4},
    {-2, 9, -24, -7, 13}};
static const WDATA_T conv3_weights_40_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 30, 8, -15, -21},
    {48, 57, 17, -18, -24},
    {79, 61, 2, -38, -18},
    {27, 35, -15, -16, -8},
    {4, -13, -18, -9, -10}};
static const WDATA_T conv3_weights_40_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 7, 13, 7, 5},
    {36, 33, 21, 14, 7},
    {14, 42, 18, 12, 12},
    {-3, -4, -20, -11, 16},
    {-19, -6, -34, -25, 10}};
static const WDATA_T conv3_weights_40_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-30, -27, -32, 9, 42},
    {-8, -36, 2, -38, 42},
    {-16, -3, 37, 41, 49},
    {-9, -6, 14, 32, -20},
    {6, 36, 12, -27, -49}};
static const WDATA_T conv3_weights_41_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -10, -9, 6, 9},
    {-9, 2, -2, 1, -12},
    {0, 5, 10, -4, -14},
    {-10, -1, 8, -16, -6},
    {-9, 2, -1, -4, -5}};
static const WDATA_T conv3_weights_41_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 1, -8, 16},
    {0, -11, -12, 12, 26},
    {-11, -1, 2, 2, -2},
    {-2, 4, 11, 4, -12},
    {-2, 8, 3, -14, -22}};
static const WDATA_T conv3_weights_41_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 7, 0, -16, -2},
    {3, 17, -19, -14, -10},
    {16, 7, 3, -13, -15},
    {6, 10, -2, -4, -6},
    {5, 9, -5, 4, -4}};
static const WDATA_T conv3_weights_41_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, -5, -6, -3},
    {-3, 4, 1, -2, 1},
    {1, 5, -2, 4, -17},
    {-7, -1, -6, -1, -13},
    {7, 0, 6, 17, 21}};
static const WDATA_T conv3_weights_41_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 10, 3, 7, -9},
    {11, 11, -1, -1, 0},
    {3, 11, 4, 4, 17},
    {-1, 3, 4, -6, 7},
    {4, -4, -4, -7, 1}};
static const WDATA_T conv3_weights_41_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -9, -13, -16, -1},
    {6, -6, -11, 6, 17},
    {-4, -5, -11, -15, 1},
    {-3, 2, 2, -4, -22},
    {-5, 0, 11, -6, -21}};
static const WDATA_T conv3_weights_41_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 12, 17, -1, -15},
    {13, 13, 5, 0, 2},
    {-7, 0, 3, 5, 8},
    {-12, -2, 9, 3, 8},
    {-12, -7, -4, 22, 18}};
static const WDATA_T conv3_weights_41_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 7, 7, 2, 14},
    {16, 13, -10, -18, 17},
    {16, 12, -4, -3, 8},
    {8, 18, 7, 1, -1},
    {6, -1, -19, -22, -9}};
static const WDATA_T conv3_weights_41_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -5, 12, 10, -8},
    {-3, -7, 9, 1, -10},
    {-11, -19, 9, 8, 3},
    {-36, -31, -10, -2, -13},
    {-31, -37, -6, 24, 22}};
static const WDATA_T conv3_weights_41_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, -1, -2, -16},
    {6, -2, 3, -1, -29},
    {-6, -2, -30, -15, 9},
    {-26, -14, 2, 16, 15},
    {-15, -3, 4, 14, 10}};
static const WDATA_T conv3_weights_41_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, 0, -2, 1},
    {0, 0, -2, -1, 0},
    {-2, -4, 0, -1, -2},
    {-2, -2, 1, 1, -2},
    {3, -1, -1, -2, 1}};
static const WDATA_T conv3_weights_41_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -3, 1, -3},
    {1, -2, 2, -1, 0},
    {1, -4, 0, 0, -1},
    {0, -1, 4, 0, 0},
    {-3, -2, 5, 5, 2}};
static const WDATA_T conv3_weights_41_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, -4, -13, -9},
    {3, 2, -8, 6, 10},
    {3, -9, -17, -13, 8},
    {-3, -17, -15, -7, 2},
    {-4, -11, 9, 5, -1}};
static const WDATA_T conv3_weights_41_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -7, 8, 15, 28},
    {-30, -40, -15, 14, 15},
    {-50, -18, 15, 16, 2},
    {-22, -18, 8, 3, -10},
    {2, 14, 20, 13, 0}};
static const WDATA_T conv3_weights_41_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -16, -19, -6, 2},
    {-19, -33, -8, 1, 4},
    {-9, -23, -19, -18, -11},
    {8, 2, 4, 19, 2},
    {12, 3, 37, 36, -3}};
static const WDATA_T conv3_weights_41_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 21, 25, 18, -6},
    {8, 20, 13, 12, -32},
    {10, 6, -13, -21, -40},
    {11, 2, -10, -5, 23},
    {2, 4, 6, 23, 35}};
static const WDATA_T conv3_weights_42_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -4, -8, 1, 0},
    {3, -2, 4, 10, 2},
    {17, 2, -6, 0, -5},
    {17, 4, -8, -8, -1},
    {3, -8, -11, -5, 1}};
static const WDATA_T conv3_weights_42_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 20, 17, 8, 6},
    {2, 1, 6, -3, -14},
    {-10, -12, -1, 18, -2},
    {-10, -21, -9, -3, -1},
    {5, 0, -10, -2, -10}};
static const WDATA_T conv3_weights_42_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -13, -5, -10, -15},
    {-9, -7, -3, -7, -21},
    {-10, -12, -3, -13, -18},
    {-13, -6, 3, -5, -16},
    {1, 0, 4, -4, -13}};
static const WDATA_T conv3_weights_42_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 0, -5, -6},
    {-9, -11, -3, -4, -20},
    {-7, -3, 6, 25, 37},
    {-3, 6, 12, 14, 4},
    {17, 25, 7, 0, -9}};
static const WDATA_T conv3_weights_42_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -1, 0, -2},
    {2, 4, 2, -2, -2},
    {8, 4, 1, -2, 3},
    {3, -2, 0, -6, 0},
    {-1, -7, -5, -2, -1}};
static const WDATA_T conv3_weights_42_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, -1, 12, 0},
    {7, 12, 15, 20, -9},
    {-3, -4, -2, 0, -10},
    {0, -7, -3, 6, 6},
    {0, -7, -9, -15, -2}};
static const WDATA_T conv3_weights_42_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -6, 4, -4, -5},
    {7, 5, -9, -7, 3},
    {7, -10, -13, -4, -4},
    {-9, -8, -9, -6, 0},
    {-6, -2, 0, 4, 2}};
static const WDATA_T conv3_weights_42_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -6, -5, -12, -3},
    {1, -9, -5, -19, -14},
    {-10, -1, 8, 6, -18},
    {-14, -11, 7, 8, -6},
    {-1, -3, -11, -9, -21}};
static const WDATA_T conv3_weights_42_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, 2, 6, -3},
    {7, 5, 8, 9, 6},
    {7, 13, 0, 12, 11},
    {-4, -3, -9, 8, 11},
    {-2, 4, 28, 30, 19}};
static const WDATA_T conv3_weights_42_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -22, -20, 4, 5},
    {11, 1, 20, 4, -2},
    {14, 21, 1, 5, 8},
    {12, 20, 18, 2, -14},
    {-8, -9, -18, -27, -20}};
static const WDATA_T conv3_weights_42_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -1, 0, 1},
    {-3, 0, 2, 4, 0},
    {1, 0, -1, 1, -2},
    {-3, 1, 2, 0, -1},
    {-1, 1, 0, 2, 2}};
static const WDATA_T conv3_weights_42_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -1, 1, 0},
    {-3, -2, -3, 0, 1},
    {-2, -2, -3, -2, 0},
    {-5, 1, -1, 3, 5},
    {4, 7, 6, 3, 2}};
static const WDATA_T conv3_weights_42_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, 16, 19, 15, 25},
    {1, 16, 0, -6, 6},
    {5, -4, -21, -10, 2},
    {0, -13, -11, -13, 4},
    {-4, -4, -10, -3, 6}};
static const WDATA_T conv3_weights_42_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 22, 22, 19, 16},
    {-8, -4, -3, 12, 10},
    {4, -12, -14, 15, 13},
    {-2, -13, -13, 1, 0},
    {10, 9, 3, 14, 11}};
static const WDATA_T conv3_weights_42_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -15, -8, 2, 12},
    {-4, -5, -4, 7, 22},
    {-7, -12, -17, -3, 3},
    {23, 29, 15, 3, 8},
    {-2, 0, -2, -11, -5}};
static const WDATA_T conv3_weights_42_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 17, 7, -10, -17},
    {4, -4, -11, -11, -38},
    {-2, -9, 6, 3, -30},
    {3, -15, 6, 14, -13},
    {3, -2, -6, -17, -29}};
static const WDATA_T conv3_weights_43_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 8, 9, 2, -5},
    {1, 4, 6, 0, -5},
    {2, 8, 6, -3, -2},
    {-1, 4, 7, 4, 0},
    {3, 9, 7, 2, 3}};
static const WDATA_T conv3_weights_43_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, 3, -4, -8},
    {-3, 4, 9, 0, -6},
    {-1, 2, 2, -2, -7},
    {0, 3, 4, 1, -4},
    {-2, -1, -1, -1, 5}};
static const WDATA_T conv3_weights_43_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -2, -7, -6},
    {-1, 1, -2, -2, -5},
    {-2, 2, 1, 4, 1},
    {1, 11, 2, 12, 2},
    {1, 9, 4, 7, 2}};
static const WDATA_T conv3_weights_43_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -2, 5, 0},
    {-4, 0, 1, -1, -5},
    {2, 1, -4, 2, -4},
    {0, -1, 3, 2, -4},
    {4, 5, 0, 1, -4}};
static const WDATA_T conv3_weights_43_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 10, 13, 9, 6},
    {0, 11, 18, 9, 4},
    {5, 12, 22, 9, 3},
    {8, 14, 16, 10, 4},
    {4, 5, 11, 7, 6}};
static const WDATA_T conv3_weights_43_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, -2, -3, -10},
    {0, 1, 4, 11, -1},
    {4, -4, -1, 10, -3},
    {3, 2, 3, 11, 3},
    {-1, 2, 1, 10, 5}};
static const WDATA_T conv3_weights_43_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -2, 1, 2, -4},
    {-6, 1, 3, 3, 2},
    {-8, -1, 3, 7, 3},
    {-4, 3, 6, 8, -1},
    {-1, 10, 5, 3, -4}};
static const WDATA_T conv3_weights_43_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, -3, -2, 1},
    {0, 5, -5, -9, -2},
    {0, 2, 1, -8, -3},
    {0, 3, -2, -7, -8},
    {2, 3, -10, -11, -1}};
static const WDATA_T conv3_weights_43_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 7, 7, 2, -3},
    {-7, 0, -4, -3, -5},
    {-3, 0, 1, 0, 3},
    {0, 3, 1, 3, -1},
    {-1, 5, 5, 2, -3}};
static const WDATA_T conv3_weights_43_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 3, 3, -3},
    {3, 2, 1, 7, -1},
    {-3, 1, 6, 2, -1},
    {-2, 5, 7, 7, -4},
    {-4, -5, 1, -4, -5}};
static const WDATA_T conv3_weights_43_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 1, 5, 3},
    {3, 2, 4, 0, -1},
    {0, 0, 0, 2, 0},
    {2, -1, 2, -2, 0},
    {0, 0, 2, 6, 3}};
static const WDATA_T conv3_weights_43_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, 1, -4},
    {2, 2, 1, 2, 1},
    {-2, 3, -2, 1, 0},
    {0, 2, 5, 4, 0},
    {1, 0, 2, 3, 1}};
static const WDATA_T conv3_weights_43_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -13, -3, -4, -4},
    {-10, -4, -2, -1, 5},
    {-10, -2, 2, 1, 1},
    {-7, 0, 9, 6, 0},
    {-8, -8, 0, 3, 3}};
static const WDATA_T conv3_weights_43_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 3, 4, 3, -3},
    {0, 1, 7, 2, -2},
    {4, 10, 13, 5, -3},
    {-1, 4, 6, 6, -1},
    {-1, 5, 4, 1, 0}};
static const WDATA_T conv3_weights_43_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, 3, -4, -6},
    {-2, 2, 5, 4, -2},
    {-2, -2, -1, -2, -3},
    {-5, -8, -3, 1, 0},
    {-5, -12, -12, -6, -5}};
static const WDATA_T conv3_weights_43_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, 8, 4, 3},
    {0, 3, 3, 11, -3},
    {5, 1, 8, 6, -9},
    {5, 2, 14, 8, -4},
    {1, 11, 8, 5, -10}};
static const WDATA_T conv3_weights_44_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 5, -1, 1, -1},
    {1, 3, 2, 7, 2},
    {2, 1, -3, 3, 4},
    {-1, -1, -4, 4, 0},
    {-7, -4, -4, -3, -3}};
static const WDATA_T conv3_weights_44_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, -7, -8, -3},
    {6, 9, 7, 4, 5},
    {-2, 1, 5, -6, -5},
    {-2, 0, -4, -4, -13},
    {1, 3, -1, -4, -6}};
static const WDATA_T conv3_weights_44_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, 8, -1, 4},
    {-3, 6, 10, -3, 5},
    {-4, 2, 5, -3, -2},
    {-6, -5, 0, -9, -5},
    {-1, -1, 0, -6, -2}};
static const WDATA_T conv3_weights_44_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -1, -1, 1},
    {-2, -3, -1, -2, -1},
    {-4, 1, 0, -2, -6},
    {6, 6, -1, -3, 11},
    {12, 18, 10, 10, 20}};
static const WDATA_T conv3_weights_44_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, 0, -3, -1},
    {-5, 1, 1, 1, 3},
    {-6, -4, 0, 0, 5},
    {-1, -2, -2, -3, -1},
    {-2, -1, -3, -6, -1}};
static const WDATA_T conv3_weights_44_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 4, -1, -13, -9},
    {3, 5, 9, 3, 3},
    {2, 0, 3, -2, 0},
    {5, 1, -2, -4, -9},
    {2, -2, 0, -7, -2}};
static const WDATA_T conv3_weights_44_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -8, -5, 3, 0},
    {-4, -8, 1, 3, -1},
    {-8, -2, -3, -2, 1},
    {2, -4, 1, 3, -1},
    {4, -1, -1, 6, 9}};
static const WDATA_T conv3_weights_44_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -1, -5, 0},
    {-6, 1, -3, -12, -1},
    {-4, 1, -4, -9, -4},
    {4, -6, -2, 3, 1},
    {0, -6, -8, -4, -2}};
static const WDATA_T conv3_weights_44_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -9, 1, -1},
    {-3, 4, 7, 5, 2},
    {8, 9, 2, 3, 3},
    {4, 0, 0, 0, 3},
    {2, 9, 9, 15, 17}};
static const WDATA_T conv3_weights_44_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -4, -6, -9, -2},
    {2, -8, -5, -2, -3},
    {7, -3, -4, 5, 20},
    {-1, 0, 0, 6, 13},
    {-8, -6, -9, -11, -10}};
static const WDATA_T conv3_weights_44_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, -3, -3, -3},
    {0, 0, 1, -1, 2},
    {-2, -4, -3, 4, -2},
    {1, 2, -2, 1, -1},
    {1, 5, 1, 1, -2}};
static const WDATA_T conv3_weights_44_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 2, 0, -3},
    {-2, -4, -1, 4, -1},
    {-5, 1, 1, -1, 3},
    {-2, -3, 1, -2, 5},
    {1, 1, -1, 2, 0}};
static const WDATA_T conv3_weights_44_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -10, -3, -3, -1},
    {-1, 3, 11, -2, 2},
    {-4, 2, 5, -6, 4},
    {-10, 1, 4, 0, -1},
    {-6, -5, 2, -2, -2}};
static const WDATA_T conv3_weights_44_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 12, 14, 10, 8},
    {7, -1, -13, 1, 5},
    {-3, -3, -2, -2, -3},
    {3, -3, -3, 1, 1},
    {-2, 5, 5, 0, -1}};
static const WDATA_T conv3_weights_44_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, 0, 2, -1},
    {-1, 4, 5, 2, 0},
    {1, 0, 12, 9, 6},
    {5, 12, 12, 19, 8},
    {-4, -15, -12, -2, -6}};
static const WDATA_T conv3_weights_44_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -5, -2, 10},
    {-4, -8, 4, -3, 6},
    {0, -7, -1, -9, -6},
    {3, -7, 2, -5, 6},
    {-4, -6, -7, -11, -3}};
static const WDATA_T conv3_weights_45_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 12, 16, 20, 16},
    {8, -5, 6, 23, 20},
    {-3, 0, 8, -3, -3},
    {4, -7, 12, -15, -15},
    {6, 30, 8, -12, -16}};
static const WDATA_T conv3_weights_45_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -9, -21, -22, 12},
    {-4, -13, 1, 7, 1},
    {13, 19, -9, 22, 39},
    {16, 22, 10, 4, 4},
    {-5, 2, 12, 6, -12}};
static const WDATA_T conv3_weights_45_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 18, 18, -1, -10},
    {1, 12, -6, -35, -25},
    {4, 9, 11, -18, -17},
    {5, 2, 13, -2, -10},
    {-1, 2, 7, -5, -3}};
static const WDATA_T conv3_weights_45_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, -1, -4, -9},
    {-8, -11, -5, 8, 9},
    {-18, -28, -8, 8, 11},
    {-15, -22, 13, 31, -2},
    {-13, -19, 20, 9, -11}};
static const WDATA_T conv3_weights_45_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 5, 14, 6, -5},
    {3, 8, 4, 3, 1},
    {11, 18, 1, 10, 9},
    {-2, 13, 2, 5, 7},
    {4, -1, -7, 2, 5}};
static const WDATA_T conv3_weights_45_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 4, -10, -14, -5},
    {-3, -13, -8, -1, -15},
    {0, -6, 1, 2, 10},
    {3, 16, 10, 4, -8},
    {-1, 5, 1, 12, -21}};
static const WDATA_T conv3_weights_45_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 2, -5, 6, -8},
    {-19, -16, -3, 4, -3},
    {-16, -14, -2, -8, 2},
    {-6, 0, 5, 0, 6},
    {-21, -28, 1, 27, 13}};
static const WDATA_T conv3_weights_45_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -8, 5, -11, -10},
    {0, 16, 19, -21, -9},
    {-1, 4, 20, 10, 12},
    {2, 3, 12, 15, 10},
    {-3, 8, 7, -14, -15}};
static const WDATA_T conv3_weights_45_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, -10, 2, 3},
    {16, -1, -21, -3, 16},
    {11, -20, -24, -5, 9},
    {-12, -7, -1, 6, 4},
    {-9, -14, 11, 48, 26}};
static const WDATA_T conv3_weights_45_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -15, -3, 7, 3},
    {-8, -9, -3, 14, 16},
    {5, 12, -2, -12, -17},
    {-12, -12, 3, 3, 13},
    {-7, -5, 28, 41, 19}};
static const WDATA_T conv3_weights_45_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 4, 1, 0, 0},
    {1, 0, 1, 3, 0},
    {1, -2, -3, 1, 0},
    {-1, -2, 0, 0, -2},
    {0, 2, 0, 2, -1}};
static const WDATA_T conv3_weights_45_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -1, 0, 1},
    {-5, -8, -2, 3, 4},
    {0, 0, -3, -4, 3},
    {3, 4, 7, -1, 2},
    {1, 4, 3, -1, 3}};
static const WDATA_T conv3_weights_45_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, 21, -6, -2, 11},
    {-14, 0, -23, -20, 5},
    {-1, 1, -41, -23, -7},
    {6, -1, -18, -5, -14},
    {2, -9, -6, 2, -7}};
static const WDATA_T conv3_weights_45_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -4, 8, -5, 13},
    {-16, -26, -24, 2, 11},
    {-5, -3, 12, 8, -13},
    {-8, -12, 0, 7, -15},
    {22, 23, 25, 4, -5}};
static const WDATA_T conv3_weights_45_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -15, -23, -12, 5},
    {-15, -28, -4, 6, 7},
    {-17, -20, -15, -3, -3},
    {14, -7, -12, 14, -9},
    {34, 11, 35, 27, -10}};
static const WDATA_T conv3_weights_45_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 2, 14, 23, 20},
    {8, -1, -10, -15, -25},
    {2, 3, -15, -48, -59},
    {-5, 16, -16, -13, 2},
    {6, 6, 10, 18, 33}};
static const WDATA_T conv3_weights_46_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 12, 11, 8, -7},
    {-8, 6, 22, 3, -3},
    {25, 42, -6, -23, -29},
    {8, 21, -2, -20, -14},
    {-14, -24, -26, -4, 5}};
static const WDATA_T conv3_weights_46_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -1, 7, 15, -2},
    {-4, -14, -12, -1, 7},
    {4, -9, -13, -10, 0},
    {33, 10, -10, -17, -13},
    {11, 25, 17, -15, 5}};
static const WDATA_T conv3_weights_46_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 9, -8, -19, -26},
    {7, -12, 8, -7, -2},
    {8, -11, -7, 5, 9},
    {-8, 1, 0, 9, 1},
    {-8, 19, 23, 25, -8}};
static const WDATA_T conv3_weights_46_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -4, 2, 17},
    {3, -2, 24, 21, 31},
    {0, 13, 18, 3, 14},
    {10, 21, 28, 2, -30},
    {9, 12, 17, 21, 15}};
static const WDATA_T conv3_weights_46_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 14, 10, 5, -2},
    {12, 12, 7, 8, -22},
    {6, -2, 19, 2, -10},
    {-3, -14, 7, -1, -6},
    {-6, -1, 4, -5, -4}};
static const WDATA_T conv3_weights_46_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -7, -13, -1, -13},
    {3, 10, 4, -3, 31},
    {6, -7, 1, 7, 37},
    {-5, -2, 11, -31, 12},
    {-7, 2, 22, 1, 19}};
static const WDATA_T conv3_weights_46_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-24, -4, -2, 12, -8},
    {-12, 5, -2, 5, 7},
    {-18, -53, -35, 6, 12},
    {-31, 8, 18, 13, -2},
    {36, 32, 37, 24, 11}};
static const WDATA_T conv3_weights_46_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -7, -29, -23, -19},
    {5, 14, -16, -5, -18},
    {-10, -2, 2, 20, -7},
    {-5, -13, -6, -15, 3},
    {3, 2, -19, -13, -9}};
static const WDATA_T conv3_weights_46_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -23, -9, 11, 15},
    {12, 14, 7, 2, 26},
    {8, 18, -8, -1, 15},
    {20, 39, 34, 8, -5},
    {62, 65, 44, -15, -16}};
static const WDATA_T conv3_weights_46_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, -12, 1, 22, 23},
    {-11, 6, 19, 18, -18},
    {-11, -14, -19, -31, -8},
    {-17, -17, -14, -18, -2},
    {0, -1, -13, -13, -24}};
static const WDATA_T conv3_weights_46_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, -3, -4, -2},
    {2, 1, -1, 0, 1},
    {1, -3, -1, 0, 1},
    {0, 2, -1, 4, 0},
    {-1, -2, -3, 1, -1}};
static const WDATA_T conv3_weights_46_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, 1, 6, 5},
    {-7, -1, -3, 10, 11},
    {-2, 0, 7, 7, 3},
    {-5, 2, 4, 1, 9},
    {-5, 1, -4, -2, -7}};
static const WDATA_T conv3_weights_46_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -1, -10, -18, -3},
    {15, 6, 2, -15, -5},
    {-4, -5, 15, 13, 20},
    {-26, -16, 16, 4, 3},
    {-12, 2, 32, 2, 19}};
static const WDATA_T conv3_weights_46_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -7, 2, 4, -1},
    {14, 12, 6, 11, 25},
    {47, 45, 28, 27, 23},
    {38, 48, 35, -12, 12},
    {14, -7, -16, -13, 7}};
static const WDATA_T conv3_weights_46_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 20, 24, 18, 20},
    {-21, 6, 31, 36, 32},
    {5, 58, 30, 9, -8},
    {-16, 4, -3, -5, 12},
    {-59, -49, -45, -43, -25}};
static const WDATA_T conv3_weights_46_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -11, -19, 19, 12},
    {-11, -34, -4, -10, -17},
    {-26, -23, 11, -3, -56},
    {-9, -12, 12, 39, 6},
    {17, 33, 79, 49, -32}};
static const WDATA_T conv3_weights_47_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -4, 2, 1, 2},
    {1, -1, -3, -3, 2},
    {-1, 3, -2, 1, 1},
    {0, 0, 2, 2, -1},
    {0, -2, 2, 0, 2}};
static const WDATA_T conv3_weights_47_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -1, -4, -3},
    {0, -4, 1, -3, 3},
    {1, -1, -3, 0, -4},
    {1, -1, -2, -4, 0},
    {2, 1, 0, 2, -1}};
static const WDATA_T conv3_weights_47_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, 1, -2, 2},
    {2, -3, 1, 1, -2},
    {-2, -3, -1, -1, -3},
    {3, 3, 1, -2, -2},
    {0, 0, 1, 1, -2}};
static const WDATA_T conv3_weights_47_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 1, 1, 1},
    {1, -1, -3, 0, -4},
    {-5, -1, 0, -1, -3},
    {-1, -2, -4, -1, -2},
    {-1, -2, -1, -2, 1}};
static const WDATA_T conv3_weights_47_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 2, 3, 1},
    {-2, -3, -1, 3, 0},
    {1, 1, 1, 0, -1},
    {-1, 2, 2, -2, 1},
    {-3, -1, 0, 2, -1}};
static const WDATA_T conv3_weights_47_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 0, -4, 2},
    {0, -1, -3, -1, -1},
    {-1, -2, 1, 1, -3},
    {-1, -2, 0, 0, 3},
    {-1, -5, 3, 1, 1}};
static const WDATA_T conv3_weights_47_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, -3, 3, 0},
    {0, 0, -2, 2, 1},
    {-1, 2, 3, -1, -2},
    {-1, 2, 2, -2, 2},
    {1, 2, 1, 0, -2}};
static const WDATA_T conv3_weights_47_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, -1, 2, 0},
    {-1, 0, 0, -2, 0},
    {-2, 1, 0, -1, 4},
    {2, -4, 2, 1, 0},
    {0, 4, -1, 1, -1}};
static const WDATA_T conv3_weights_47_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, -1, 1, 2},
    {0, -1, 0, -1, -2},
    {-5, 2, 1, -2, -4},
    {1, 0, 0, 2, -5},
    {0, 1, 0, 0, -3}};
static const WDATA_T conv3_weights_47_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 0, 1, -2},
    {-2, 1, 0, 2, -2},
    {4, -1, 1, 5, 0},
    {0, -1, -1, 0, -2},
    {0, -1, -1, -1, -1}};
static const WDATA_T conv3_weights_47_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 1, 2, -1, 1},
    {-3, -1, 0, -2, -2},
    {0, 0, -3, -1, -1},
    {-2, 2, 0, 1, -1},
    {-2, -2, 3, 1, 0}};
static const WDATA_T conv3_weights_47_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -2, -1, -1},
    {0, 1, -1, 4, 0},
    {0, 0, 0, 2, 0},
    {1, -4, -1, 1, 3},
    {0, 0, 1, 2, 0}};
static const WDATA_T conv3_weights_47_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 0, 0, 2},
    {-1, 0, -2, -3, 1},
    {-2, 2, 3, 2, -1},
    {-1, 1, 1, 0, 0},
    {-1, -2, 1, -1, 1}};
static const WDATA_T conv3_weights_47_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, -1, -2, -4},
    {3, -2, 1, -5, 1},
    {-2, 0, -2, 0, 3},
    {0, 2, 1, -4, 2},
    {-3, -2, -3, -4, 0}};
static const WDATA_T conv3_weights_47_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, -1, 0, -1},
    {-1, 1, 3, 1, 1},
    {-2, -2, -2, 0, 0},
    {0, 0, -1, 0, -1},
    {2, 1, 1, 2, -1}};
static const WDATA_T conv3_weights_47_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -2, 1, -2, -2},
    {0, -2, 4, -1, -2},
    {1, 0, -1, 0, -3},
    {3, 1, -2, -1, -1},
    {0, 0, 0, -1, -3}};
static const WDATA_T conv3_weights_48_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -6, -16, -1, -11},
    {-3, -15, -11, -16, -3},
    {-4, -13, -3, -7, -3},
    {-5, -7, 3, -15, -11},
    {9, 11, 16, 3, -7}};
static const WDATA_T conv3_weights_48_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -12, -1, 4, -3},
    {6, 12, -11, 12, 11},
    {7, 5, -14, -19, -4},
    {3, 6, 10, -13, -9},
    {2, 7, 15, 11, -3}};
static const WDATA_T conv3_weights_48_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -10, -6, 21, 6},
    {2, -6, -13, 17, -1},
    {5, -5, -19, -4, 0},
    {3, 11, -2, 2, -4},
    {4, 7, -2, -9, -1}};
static const WDATA_T conv3_weights_48_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 0, 1, 0},
    {-1, 14, 16, 7, 9},
    {-6, 2, -6, 4, 6},
    {-1, -9, -3, 10, 12},
    {-4, -8, 2, 7, -9}};
static const WDATA_T conv3_weights_48_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 8, 0, -5},
    {-3, 6, 16, 3, -4},
    {3, 11, 25, 9, 5},
    {9, 15, 17, 11, 4},
    {6, 6, -2, 7, 2}};
static const WDATA_T conv3_weights_48_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -20, -26, 10, 0},
    {6, -6, -22, 4, 15},
    {6, -4, -13, -5, -1},
    {1, -2, 5, -6, -13},
    {5, 9, 16, 11, -6}};
static const WDATA_T conv3_weights_48_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, 4, 17, 18, -2},
    {-6, 34, 21, 13, 2},
    {-2, 13, 1, -4, 0},
    {-8, -9, 5, 2, 9},
    {-8, 5, 2, 9, -3}};
static const WDATA_T conv3_weights_48_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -7, 0, -7, -3},
    {-1, -10, -16, 5, -2},
    {-2, -10, -13, 3, 8},
    {-8, 2, 8, -4, 8},
    {-6, -2, 25, 3, -8}};
static const WDATA_T conv3_weights_48_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, 2, 14, 19, 1},
    {-15, 3, 30, 11, -7},
    {-8, -6, 10, 0, -8},
    {-12, -7, -16, -2, -2},
    {-11, -3, 4, 6, -8}};
static const WDATA_T conv3_weights_48_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -1, 8, -3},
    {-11, -11, -5, -5, -10},
    {-10, -1, -4, -8, -20},
    {-10, 6, 24, 3, -19},
    {1, 11, 6, 5, -4}};
static const WDATA_T conv3_weights_48_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -1, 2, -4},
    {1, 2, 4, -1, 2},
    {2, 6, 1, 1, -2},
    {-2, 4, -2, 0, 1},
    {1, -1, 1, 0, 1}};
static const WDATA_T conv3_weights_48_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -4, 0, -3},
    {-2, -2, 2, 3, -1},
    {-1, 1, 6, 5, 3},
    {0, 2, 3, 2, -3},
    {-2, 0, 5, 4, -3}};
static const WDATA_T conv3_weights_48_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-35, -16, 1, 3, -6},
    {-9, 19, 23, 10, 1},
    {11, 7, 14, -8, -6},
    {15, 23, 21, -10, -7},
    {14, 16, 3, 11, 1}};
static const WDATA_T conv3_weights_48_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -2, 2, 8, 7},
    {-9, 6, 14, 3, -8},
    {-24, 8, 18, 8, -9},
    {1, 22, 33, 6, -10},
    {2, 7, 3, 7, 7}};
static const WDATA_T conv3_weights_48_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -15, 1, 4, -8},
    {-4, -12, -7, -6, -6},
    {-8, -27, -23, -17, -6},
    {-13, -17, -13, -5, -4},
    {-11, 3, 15, 2, -16}};
static const WDATA_T conv3_weights_48_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 12, 16, 11, 1},
    {19, 16, -2, 18, 1},
    {9, 9, -3, 17, 0},
    {8, 2, 0, 16, 13},
    {2, 8, 7, 15, 16}};
static const WDATA_T conv3_weights_49_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 26, 24, 6, 5},
    {20, 42, 30, -6, 15},
    {40, 54, 2, -22, -7},
    {24, 18, -6, -11, 2},
    {25, 7, 6, 4, 5}};
static const WDATA_T conv3_weights_49_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-37, -35, -6, 6, 0},
    {-33, -8, -9, 0, 4},
    {17, 25, 9, -4, -21},
    {-14, -6, 4, -5, -7},
    {-1, 9, 2, -4, 19}};
static const WDATA_T conv3_weights_49_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {31, 18, -2, -10, -2},
    {19, 5, 5, -17, 1},
    {-11, -6, 1, 4, 33},
    {-10, -12, -18, 22, 25},
    {-14, -21, 1, 15, -3}};
static const WDATA_T conv3_weights_49_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, 7, 13, 22},
    {1, 29, 42, 34, 46},
    {0, 9, -1, 2, 26},
    {2, 34, 31, 9, -14},
    {14, 13, 13, -14, -41}};
static const WDATA_T conv3_weights_49_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 26, 4, 5, -2},
    {1, 19, 0, 7, -4},
    {-9, -4, 5, 1, -12},
    {-3, 3, 3, 8, -7},
    {5, 8, 2, 3, 0}};
static const WDATA_T conv3_weights_49_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -30, -42, -30, -27},
    {-12, 21, -1, 5, 27},
    {4, 23, 19, 15, 24},
    {-14, 6, 21, -11, 9},
    {-16, -15, 15, -3, 28}};
static const WDATA_T conv3_weights_49_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {45, 57, 60, 18, 4},
    {3, 13, 10, 18, -3},
    {0, -42, 0, 10, -7},
    {0, -24, 2, 9, -8},
    {23, -10, -17, -23, -28}};
static const WDATA_T conv3_weights_49_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {32, 33, -27, -15, -13},
    {6, -9, -18, -14, -24},
    {-18, -38, -15, 11, 2},
    {-14, -26, -11, 1, 15},
    {-8, -19, -1, -2, 18}};
static const WDATA_T conv3_weights_49_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -23, -2, 3, 17},
    {-62, -75, -21, 0, 21},
    {-75, -55, 23, 15, 14},
    {-12, 13, 7, -8, 14},
    {29, 13, 6, -23, -25}};
static const WDATA_T conv3_weights_49_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 17, 15, 34, 16},
    {-5, -23, 9, -11, -33},
    {-27, 8, 18, 2, -11},
    {3, 38, 25, -39, -52},
    {5, 14, 17, -26, -21}};
static const WDATA_T conv3_weights_49_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, -3, 0, 0},
    {1, -1, -2, 0, 0},
    {1, 2, 0, -1, -1},
    {2, -4, -1, -3, 1},
    {4, 0, -3, 0, 2}};
static const WDATA_T conv3_weights_49_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 8, 4, 2, 5},
    {9, 5, 3, -3, 8},
    {-10, -10, 1, -10, -3},
    {-7, -4, -2, -4, 0},
    {1, 3, 2, -5, -7}};
static const WDATA_T conv3_weights_49_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {29, 7, -16, -19, 31},
    {27, 10, -1, -28, -7},
    {21, 24, 41, 17, -11},
    {-3, 25, 25, -4, -14},
    {-1, 17, -4, -24, -2}};
static const WDATA_T conv3_weights_49_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-28, -48, -49, -2, 22},
    {4, 21, -12, 34, 34},
    {35, 11, -31, 0, 5},
    {-12, 2, 8, 0, -1},
    {-30, -19, -9, 2, 5}};
static const WDATA_T conv3_weights_49_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 7, -3, -10, 25},
    {41, 51, 17, -19, 16},
    {43, 46, 16, -35, -5},
    {9, 12, -3, -13, 0},
    {-22, 3, -2, -11, 17}};
static const WDATA_T conv3_weights_49_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {30, 44, 24, 18, 16},
    {1, 1, -20, -71, -100},
    {4, -38, -10, 5, -49},
    {3, -42, -18, 18, -3},
    {-6, -22, 10, 16, -13}};
static const WDATA_T conv3_weights_50_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, 1, 0},
    {1, -2, -2, -1, 2},
    {-1, -3, -1, -3, -3},
    {0, -2, -3, -2, -2},
    {2, 1, 0, 2, 0}};
static const WDATA_T conv3_weights_50_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -2, -4, -3},
    {6, 3, -2, 0, -3},
    {2, 2, -4, 0, 6},
    {0, 2, 3, -1, -5},
    {-4, -1, -2, -3, -1}};
static const WDATA_T conv3_weights_50_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -2, 0, 1, 3},
    {1, -1, 1, -4, -1},
    {0, 1, -5, -3, 2},
    {-1, 0, -5, -2, 0},
    {-2, 1, 1, -2, 1}};
static const WDATA_T conv3_weights_50_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -1, -2, 0},
    {-3, 1, -3, -2, -3},
    {-3, 0, -2, -3, 1},
    {2, 1, 2, 0, -2},
    {-5, -5, 1, 6, 5}};
static const WDATA_T conv3_weights_50_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -2, -2, 2, -2},
    {-1, -1, 2, -2, -1},
    {-1, 0, -4, 1, 1},
    {-2, -3, 3, -1, 2},
    {0, 3, 2, -2, -4}};
static const WDATA_T conv3_weights_50_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -4, -2, -2, -2},
    {2, -2, -4, 1, 1},
    {2, 0, -2, 0, 1},
    {-3, 0, 4, -1, 0},
    {-3, -2, 1, 1, 0}};
static const WDATA_T conv3_weights_50_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, -1, -1},
    {-2, 0, -3, 1, 4},
    {-2, -2, -1, 2, -2},
    {3, 0, 0, -5, -1},
    {-1, -2, -2, -3, -3}};
static const WDATA_T conv3_weights_50_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 4, 2, -1, -1},
    {-1, -2, 1, 3, 0},
    {-1, -2, 2, 2, 5},
    {1, 0, 2, 1, 3},
    {-3, -1, 2, -2, 3}};
static const WDATA_T conv3_weights_50_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, 1, -1, 0},
    {0, -7, -1, -1, 0},
    {2, -3, 0, 1, -2},
    {-1, 2, 3, -3, -2},
    {3, -1, -1, 1, 4}};
static const WDATA_T conv3_weights_50_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -2, -2, 1, -5},
    {2, -3, 1, 2, -1},
    {-2, 1, -3, -5, 1},
    {2, -2, -1, 4, 1},
    {-1, -3, 4, 4, -1}};
static const WDATA_T conv3_weights_50_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 2, 2, -1},
    {-1, -1, 2, 0, -2},
    {0, 0, 1, 1, 0},
    {0, -1, 3, 1, -1},
    {-3, 0, 1, 3, 2}};
static const WDATA_T conv3_weights_50_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -3, 2, -3},
    {-3, 1, 0, 0, 0},
    {4, -1, -1, 3, 0},
    {2, 1, -3, -1, 2},
    {-1, -2, -2, -1, -3}};
static const WDATA_T conv3_weights_50_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 3, 1, -1, -1},
    {2, 6, 1, 1, -1},
    {-2, 0, -2, -3, 0},
    {0, -4, 4, 0, 1},
    {-1, -4, 0, 0, -1}};
static const WDATA_T conv3_weights_50_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -2, 2, 0},
    {6, 2, -1, -4, -2},
    {1, 1, 3, 2, -1},
    {-4, -6, -1, -2, 1},
    {0, -3, 3, 1, 1}};
static const WDATA_T conv3_weights_50_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -3, -3, -2},
    {1, -1, 2, 7, -4},
    {0, -4, -4, -2, -3},
    {5, 3, -4, -1, 1},
    {2, 7, 7, 3, 0}};
static const WDATA_T conv3_weights_50_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 3, 0, 1, 3},
    {-2, -3, -5, -2, 3},
    {-3, -3, -2, -3, -3},
    {-1, -1, -1, -2, 4},
    {0, 1, 3, -2, 3}};
static const WDATA_T conv3_weights_51_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 1, 5, 2},
    {1, -2, 2, 0, -1},
    {-1, 0, 0, -1, -2},
    {0, -1, 3, -2, 0},
    {-1, 0, 4, 3, -3}};
static const WDATA_T conv3_weights_51_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -3, 0, 0},
    {1, 2, -4, -2, 1},
    {-1, -1, 0, 0, 0},
    {1, -1, -3, 0, -1},
    {0, 0, -2, 2, -1}};
static const WDATA_T conv3_weights_51_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -2, -1, -5, -2},
    {1, -1, 1, -2, -1},
    {3, -3, -3, 4, 0},
    {-1, 0, 1, 0, 3},
    {0, 0, 0, 1, 1}};
static const WDATA_T conv3_weights_51_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 4, 0, 3},
    {4, -3, -1, 2, -3},
    {-1, -3, -5, -2, 0},
    {1, -1, 0, 0, 0},
    {1, 2, -1, 1, 0}};
static const WDATA_T conv3_weights_51_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 2, 0, -1},
    {-1, -2, -3, 1, 4},
    {1, 0, 1, 2, -1},
    {-1, -2, 0, 0, 1},
    {2, 0, -1, 3, 1}};
static const WDATA_T conv3_weights_51_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -1, -1, 2},
    {1, 0, -5, -2, -5},
    {-1, -1, 0, -3, 0},
    {0, -3, -3, 2, 1},
    {1, 0, -2, -3, 0}};
static const WDATA_T conv3_weights_51_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -1, -1, -6},
    {-3, 0, 1, 2, -2},
    {-1, -2, -3, 0, 1},
    {-1, 0, 1, 2, -3},
    {0, -2, 0, 1, 0}};
static const WDATA_T conv3_weights_51_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 0, 0, -1},
    {-2, 2, -2, -3, 0},
    {4, 1, 4, -1, -1},
    {-1, 1, 3, 1, 0},
    {0, 1, -2, 0, 0}};
static const WDATA_T conv3_weights_51_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 0, -1, 4},
    {0, -2, -2, -2, 3},
    {0, -3, 2, 1, -2},
    {-1, 0, -1, 4, 1},
    {1, -2, 0, 0, 0}};
static const WDATA_T conv3_weights_51_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, -3, -2, -1},
    {3, -1, 0, -4, 0},
    {-2, -2, 3, 0, 1},
    {1, 1, 0, -4, -1},
    {-3, -1, 0, 1, 0}};
static const WDATA_T conv3_weights_51_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -1, 1, -1},
    {0, 1, -2, 0, -2},
    {-1, 0, 1, -1, 1},
    {0, -1, 0, 6, 1},
    {-2, -1, -2, 1, -2}};
static const WDATA_T conv3_weights_51_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, -2, -2, 0},
    {1, 0, 0, 1, 1},
    {-1, 0, 0, -1, -1},
    {0, 2, 0, -2, 3},
    {1, 2, 1, -2, -1}};
static const WDATA_T conv3_weights_51_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -1, 0, -4},
    {-1, -2, 3, 2, -4},
    {3, 0, 1, -1, 2},
    {1, 1, -1, 1, 1},
    {1, -1, -1, -3, 2}};
static const WDATA_T conv3_weights_51_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -5, 0, 0},
    {-2, 2, -1, -1, 2},
    {2, 0, 1, -1, -2},
    {3, 3, -2, -1, -2},
    {1, -2, -1, 3, 1}};
static const WDATA_T conv3_weights_51_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 2, 1, 0},
    {4, 0, -1, -2, -2},
    {0, 0, -1, -1, -1},
    {-3, 1, -2, -1, -3},
    {2, -2, 3, -2, -1}};
static const WDATA_T conv3_weights_51_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, -3, 1, -2},
    {2, -1, -2, 2, 0},
    {-2, -1, -2, 0, -1},
    {-4, 1, 2, -2, -1},
    {5, 0, 3, -1, 1}};
static const WDATA_T conv3_weights_52_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -27, -26, -9, -6},
    {-6, -26, -41, -32, -6},
    {-7, -50, -36, -19, 0},
    {-11, -34, -8, 12, 0},
    {6, -7, 4, 14, 1}};
static const WDATA_T conv3_weights_52_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -10, -8, -3},
    {6, -2, -1, -7, -6},
    {-8, -16, -14, -20, -8},
    {9, 0, -11, -2, 2},
    {-3, -8, 1, 9, 10}};
static const WDATA_T conv3_weights_52_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -3, 24, 15, 10},
    {-15, -18, 1, 20, -2},
    {-12, -18, -6, 7, -7},
    {-12, 0, 8, 2, -2},
    {-5, 9, 5, -23, -9}};
static const WDATA_T conv3_weights_52_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, 3, 7, -7},
    {-8, -1, 7, 14, -16},
    {-5, 1, 2, 2, -15},
    {-2, -6, -6, -10, -5},
    {1, -5, 0, 9, -8}};
static const WDATA_T conv3_weights_52_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -3, 0, -6, -11},
    {-4, -4, 9, -5, -15},
    {4, 1, 18, 6, -5},
    {0, 7, 10, 2, -10},
    {-5, -8, -13, -7, -3}};
static const WDATA_T conv3_weights_52_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -15, -10, 7, -13},
    {11, 1, 2, 19, -11},
    {2, -9, -23, 6, -30},
    {-1, -3, -13, 13, -11},
    {6, 4, 11, 25, 14}};
static const WDATA_T conv3_weights_52_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -11, 12, 14, 0},
    {-10, 24, 14, 4, -1},
    {6, 32, 18, 2, 0},
    {2, 11, 10, 4, 8},
    {-2, 9, 7, 0, -5}};
static const WDATA_T conv3_weights_52_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 1, 26, -2, 2},
    {-7, -9, 20, 14, 20},
    {-2, -11, 31, 33, 20},
    {-4, 1, 30, -9, -2},
    {0, 18, 18, -7, -11}};
static const WDATA_T conv3_weights_52_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -7, -1, 15, -1},
    {-6, 4, 23, 1, -16},
    {10, 24, 26, 3, -10},
    {10, 10, -9, 2, 2},
    {2, -4, -2, 10, 6}};
static const WDATA_T conv3_weights_52_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -2, 3, -1, -10},
    {14, 11, 2, -27, -15},
    {13, 17, -1, -7, -8},
    {-2, 12, -9, -2, -3},
    {18, -4, -32, 0, 8}};
static const WDATA_T conv3_weights_52_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 4, -2, 2},
    {0, 4, 0, 1, -2},
    {0, 0, 2, -3, 0},
    {2, 2, 1, -1, -1},
    {1, 1, -2, 1, -1}};
static const WDATA_T conv3_weights_52_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, 3, -2, 2},
    {1, 2, 2, 4, -4},
    {4, 1, 0, -4, -1},
    {-2, 2, 1, 0, 2},
    {1, -3, -3, -5, -4}};
static const WDATA_T conv3_weights_52_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 21, 19, 29, 0},
    {-5, 32, 21, 11, -3},
    {-2, 14, -12, -1, -2},
    {6, 36, 20, 4, 15},
    {14, 27, -9, 7, 5}};
static const WDATA_T conv3_weights_52_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 4, -3, 5, 1},
    {-10, -11, -9, -6, -14},
    {-9, 0, 5, -4, -4},
    {4, 22, 26, 9, 15},
    {-3, -4, 2, -1, 5}};
static const WDATA_T conv3_weights_52_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -11, -4, -3, -17},
    {-4, -15, -15, -4, -6},
    {-2, -26, -42, -25, -2},
    {-15, -36, -34, -1, -5},
    {-8, -14, -3, 29, 20}};
static const WDATA_T conv3_weights_52_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 6, 17, 20, 13},
    {16, 16, 2, -2, -7},
    {7, 20, 8, 19, 3},
    {12, 16, 27, 38, 20},
    {3, 17, 4, -44, -30}};
static const WDATA_T conv3_weights_53_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 27, 24, -5, 20},
    {11, 27, 25, 17, 1},
    {-8, -17, 6, 14, 2},
    {9, -10, 12, 0, -10},
    {13, -3, -14, -45, -15}};
static const WDATA_T conv3_weights_53_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 12, 21, 24, 22},
    {-9, 18, 31, 0, 7},
    {10, 16, 9, -3, 4},
    {21, 1, -14, 9, 12},
    {19, 10, -5, 9, 19}};
static const WDATA_T conv3_weights_53_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 3, 12, 10, 18},
    {5, -2, -4, -8, 12},
    {6, -10, -10, -11, -12},
    {9, -13, -1, 11, -27},
    {2, -10, 2, -5, -2}};
static const WDATA_T conv3_weights_53_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -3, -1, -10, -3},
    {-14, -9, 0, 2, 22},
    {8, -12, -5, 2, 18},
    {-8, -19, -4, 0, 23},
    {-47, -46, 42, 44, -13}};
static const WDATA_T conv3_weights_53_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -7, 1, -1, 10},
    {-1, 0, 16, -5, 13},
    {4, 13, 10, 0, 0},
    {2, 20, 5, -2, -2},
    {9, 24, 4, 15, 0}};
static const WDATA_T conv3_weights_53_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 35, 30, 18, 42},
    {-3, 5, 11, -2, -9},
    {-4, 6, 22, 7, -28},
    {-14, -6, -5, 2, -15},
    {12, 11, -12, 4, -19}};
static const WDATA_T conv3_weights_53_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -12, -3, -6, -3},
    {-33, -30, -18, -10, 0},
    {-50, -6, -13, -30, -14},
    {-15, -16, -29, -3, 11},
    {10, -45, -10, 26, 18}};
static const WDATA_T conv3_weights_53_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -2, -24, -27, -28},
    {-11, 11, -3, -19, -20},
    {-12, -4, 11, 10, 3},
    {-8, -4, -2, 21, 12},
    {-7, 5, 51, 58, 41}};
static const WDATA_T conv3_weights_53_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, -10, -31, 1, 7},
    {-10, -35, -43, -21, 17},
    {-6, -40, -32, -11, -17},
    {40, -5, -13, -5, 9},
    {40, -30, -39, 12, -15}};
static const WDATA_T conv3_weights_53_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 2, 1, 22, 29},
    {-24, -26, -4, 15, 30},
    {-29, 4, 28, 52, 13},
    {-23, -15, -44, -24, -46},
    {-8, -11, -20, 23, 1}};
static const WDATA_T conv3_weights_53_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, 0, 4, -2},
    {3, 1, 2, -1, -4},
    {0, 1, 1, 0, 2},
    {4, -1, -3, 2, -2},
    {0, -1, -2, 2, 1}};
static const WDATA_T conv3_weights_53_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, 1, -2, 0},
    {-4, -3, 0, 1, -3},
    {5, 5, -6, -1, 0},
    {-4, -2, 2, 3, 1},
    {-4, -10, -18, -14, -3}};
static const WDATA_T conv3_weights_53_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -1, 24, 16, 16},
    {-15, 26, 1, -3, -20},
    {-9, 36, -11, -18, -16},
    {-19, -4, -14, -11, -13},
    {-2, 17, -10, -21, -33}};
static const WDATA_T conv3_weights_53_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, 4, -10, 9, 8},
    {2, -12, -21, -7, -27},
    {20, 6, -21, -3, -11},
    {65, 42, 26, -11, -44},
    {1, 1, -14, -31, -34}};
static const WDATA_T conv3_weights_53_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, 7, 12, 18, 4},
    {19, 9, -10, -6, -14},
    {-1, -5, 27, 30, 6},
    {-40, -34, -12, 4, -19},
    {-32, -21, -5, -39, -36}};
static const WDATA_T conv3_weights_53_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, -10, 20, 1, 32},
    {-17, -13, -18, -13, 7},
    {-17, -10, -2, 28, 46},
    {8, 23, -15, 10, -43},
    {-3, 17, 18, 3, 6}};
static const WDATA_T conv3_weights_54_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -5, -7, -6, -3},
    {3, -5, -9, 7, 0},
    {-5, -9, 10, 7, 1},
    {1, -2, 17, 19, 14},
    {-15, -1, 8, 13, 3}};
static const WDATA_T conv3_weights_54_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 27, 25, 22, 4},
    {8, -2, 16, 12, 22},
    {-1, 3, 6, 6, 0},
    {-7, -2, 1, -3, -10},
    {-7, -6, -9, -2, 3}};
static const WDATA_T conv3_weights_54_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -14, 6, -10, -12},
    {-11, -10, -5, -13, 3},
    {2, -11, -4, -7, 9},
    {-3, -16, 5, -5, 0},
    {2, 0, -6, -11, 0}};
static const WDATA_T conv3_weights_54_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 1, -2, -5},
    {-1, -3, -14, -17, -22},
    {-1, 5, -5, -5, -25},
    {4, -8, -11, -14, -15},
    {7, 1, -2, -2, 19}};
static const WDATA_T conv3_weights_54_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 3, 1, -6},
    {4, 7, -3, 6, 5},
    {5, 7, 5, 11, 13},
    {4, 5, 17, 6, 10},
    {3, 9, 6, 3, 1}};
static const WDATA_T conv3_weights_54_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 5, 16, 13, -15},
    {13, -6, 10, 23, 14},
    {5, 2, -11, 2, 10},
    {-4, 2, 0, 2, 0},
    {-8, -11, -9, -7, -3}};
static const WDATA_T conv3_weights_54_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -24, -9, -1, -9},
    {-12, -4, -3, -1, 3},
    {-19, -11, -5, 10, 7},
    {-2, -1, 11, 3, -4},
    {3, -2, 1, 6, 12}};
static const WDATA_T conv3_weights_54_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -2, 6, -3, -7},
    {-10, -3, 22, 1, -8},
    {-1, 0, 18, 1, -3},
    {-2, 5, 15, -1, -9},
    {4, -1, -13, -13, 4}};
static const WDATA_T conv3_weights_54_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, -9, -6, -1, -3},
    {13, -5, -2, 12, 3},
    {7, -22, -10, 11, 0},
    {3, -3, 3, 0, -3},
    {1, 4, -9, 7, 16}};
static const WDATA_T conv3_weights_54_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -23, -29, -11, -19},
    {17, -3, -5, 4, -5},
    {6, -7, -15, -13, 17},
    {-8, -30, -21, 10, 35},
    {-25, -26, 1, 2, -4}};
static const WDATA_T conv3_weights_54_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, -1, 2},
    {2, -2, -2, 2, 0},
    {1, -2, 3, 0, -1},
    {-1, -1, 3, 1, -4},
    {-1, 0, 1, 1, 3}};
static const WDATA_T conv3_weights_54_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 3, 1, -2},
    {2, 1, -2, 2, 1},
    {3, 2, 4, -3, 3},
    {2, 4, 0, 0, 0},
    {1, 2, -1, 3, 3}};
static const WDATA_T conv3_weights_54_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -21, -4, -8, 2},
    {-4, 6, 5, 14, 6},
    {-14, 0, -17, -4, -1},
    {-26, -8, 18, 6, 0},
    {-4, -4, 1, 0, -3}};
static const WDATA_T conv3_weights_54_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 17, 12, 11, 18},
    {-9, -16, -10, -10, 4},
    {-6, -2, 7, 8, 0},
    {1, -8, -7, -6, -1},
    {-4, 11, 11, 10, 3}};
static const WDATA_T conv3_weights_54_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -2, -11, -8, -7},
    {-9, 4, 20, 4, -14},
    {8, -15, -9, -2, 2},
    {-4, -4, 17, 22, 9},
    {-27, -35, 16, 28, 11}};
static const WDATA_T conv3_weights_54_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -2, 5, -1},
    {-3, -10, -17, 12, -9},
    {11, -3, 2, 2, -22},
    {12, -3, 14, -14, 7},
    {2, 1, -1, -2, 17}};
static const WDATA_T conv3_weights_55_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -9, -3, 1, -1},
    {0, -7, -1, -1, 1},
    {1, 0, 1, 3, 3},
    {-4, -1, -3, 1, 4},
    {2, -1, -4, 0, 2}};
static const WDATA_T conv3_weights_55_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, 0, -1, -5},
    {-3, -4, 5, 4, 2},
    {-3, -3, 2, 1, 5},
    {-4, 0, -4, 0, 4},
    {-2, -3, -5, 1, 3}};
static const WDATA_T conv3_weights_55_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, -1, 2},
    {-2, 0, 1, 4, -1},
    {1, 7, -2, 3, 3},
    {2, 1, 2, 2, 4},
    {1, -2, -6, -2, 2}};
static const WDATA_T conv3_weights_55_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 1, 1, 2},
    {2, -2, -4, -6, 0},
    {3, 1, 1, -3, -5},
    {-1, -3, 3, -2, -2},
    {-3, -1, -1, -2, -4}};
static const WDATA_T conv3_weights_55_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, -2, -3, -1},
    {2, 2, 2, -3, -1},
    {1, -1, 0, 1, 2},
    {2, 0, 0, -1, 2},
    {2, 0, -1, 0, 1}};
static const WDATA_T conv3_weights_55_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 3, 2, -5},
    {0, -1, 0, 3, 6},
    {1, -6, -7, 4, 6},
    {1, -3, 0, -3, 5},
    {-1, -1, -4, -7, 6}};
static const WDATA_T conv3_weights_55_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 4, 1, 0, -1},
    {1, -1, 0, -4, 2},
    {3, 12, 7, -2, -1},
    {-1, 2, 0, 0, -3},
    {-1, -3, 0, -3, -1}};
static const WDATA_T conv3_weights_55_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 3, -1, 2, 1},
    {2, 1, 0, 4, 3},
    {5, 3, -3, -7, -1},
    {5, 2, 0, 1, 3},
    {1, 2, -2, -6, 8}};
static const WDATA_T conv3_weights_55_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 1, 2, -6, 0},
    {5, -1, -3, -4, -1},
    {3, 5, 0, 0, -4},
    {0, 0, 3, -1, 2},
    {-3, 2, 3, -3, -2}};
static const WDATA_T conv3_weights_55_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 7, -2, -5, -4},
    {4, 3, -1, -5, -4},
    {-3, 4, -1, -2, 3},
    {4, 8, 9, -2, 1},
    {2, 8, 1, -5, 2}};
static const WDATA_T conv3_weights_55_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 1, -2, 3},
    {1, 4, -1, -1, 0},
    {4, 1, 2, -2, -3},
    {-1, -1, 1, -1, -2},
    {-2, -1, 2, -2, 1}};
static const WDATA_T conv3_weights_55_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 0, -2, -2, -2},
    {-1, 0, 3, -1, -2},
    {-1, 3, -3, -3, 3},
    {0, 1, 2, -1, -3},
    {-2, 3, 1, 0, -2}};
static const WDATA_T conv3_weights_55_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 1, 1, 0, -2},
    {-1, 0, 7, 2, 4},
    {-1, -3, 0, -3, -5},
    {8, 5, 0, 1, -4},
    {1, -1, -6, 2, 1}};
static const WDATA_T conv3_weights_55_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, -2, 3, 5},
    {-4, -4, -5, 3, 6},
    {-8, -8, -8, 0, 0},
    {-2, -6, -2, -2, -5},
    {4, 2, -1, 2, 2}};
static const WDATA_T conv3_weights_55_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 0, -6, -1},
    {2, -3, -7, 0, 0},
    {-6, -9, -3, 3, 5},
    {6, 4, 1, 0, 6},
    {1, 5, 6, -1, 9}};
static const WDATA_T conv3_weights_55_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -1, -3, 0},
    {-3, 5, 5, 3, 4},
    {2, 8, 3, -3, -2},
    {0, 4, -2, -9, -10},
    {-2, 0, -5, -7, -5}};
static const WDATA_T conv3_weights_56_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -3, 2, -2},
    {-1, 5, 1, 1, 1},
    {-1, 2, -3, 1, 0},
    {0, 1, 0, 0, 4},
    {1, 1, -1, -1, 1}};
static const WDATA_T conv3_weights_56_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -2, -2, 2, 3},
    {3, 0, -1, 0, -2},
    {1, 5, -2, 0, -1},
    {1, 0, 0, 1, -1},
    {-1, -2, -1, 1, -2}};
static const WDATA_T conv3_weights_56_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -1, -2, 1},
    {2, 2, 1, 1, 1},
    {1, 1, 2, -1, 2},
    {1, -1, 0, 1, -2},
    {1, 0, 2, -2, -1}};
static const WDATA_T conv3_weights_56_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -1, 1, 2},
    {0, -1, -5, -2, -2},
    {1, 0, -2, 0, -2},
    {-3, -2, -3, 0, -1},
    {0, 0, -4, -2, 3}};
static const WDATA_T conv3_weights_56_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 1, -1, -2},
    {1, -1, -2, -1, -4},
    {0, 1, 2, 0, 0},
    {0, 2, 2, -1, 2},
    {-1, 0, -1, 4, 2}};
static const WDATA_T conv3_weights_56_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 4, -2, 1, 0},
    {-1, -1, -1, 2, -1},
    {-3, -2, 3, -1, -1},
    {1, 2, 1, -1, 1},
    {-1, -2, -5, -1, -2}};
static const WDATA_T conv3_weights_56_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 1, -1, -1},
    {2, 0, -2, 0, 1},
    {-1, 0, -1, -6, -3},
    {-1, -2, 1, 1, 1},
    {1, 0, 0, -5, 1}};
static const WDATA_T conv3_weights_56_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -1, 4, 2},
    {0, -1, 0, 0, -2},
    {2, 0, 2, 0, 1},
    {0, 0, 1, 2, -3},
    {0, 1, 2, -1, 1}};
static const WDATA_T conv3_weights_56_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 1, 1, 6},
    {0, 0, 1, 4, 2},
    {-3, 4, 1, 0, 0},
    {0, 3, -1, -3, 0},
    {-3, 0, -3, 0, -2}};
static const WDATA_T conv3_weights_56_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, -1, 3},
    {1, -2, -1, 0, 0},
    {-2, -2, 2, -2, 0},
    {2, -5, -2, 1, 1},
    {1, -3, 0, 2, 2}};
static const WDATA_T conv3_weights_56_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, 0, 2, 0},
    {3, 0, 3, -1, -3},
    {2, 4, -1, -1, 1},
    {2, 1, -2, -1, -2},
    {-1, 0, 2, -2, -2}};
static const WDATA_T conv3_weights_56_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -5, -3, 1, 2},
    {1, 0, 0, -2, 1},
    {-2, 1, -2, 1, -2},
    {2, 2, -1, 1, -2},
    {2, 1, 2, 1, 2}};
static const WDATA_T conv3_weights_56_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -2, -1, -1},
    {-1, 1, -1, 0, 1},
    {-5, 1, -3, -2, 2},
    {1, -2, 0, 0, 2},
    {-3, -1, -1, -3, 0}};
static const WDATA_T conv3_weights_56_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -1, 0, -1},
    {1, -2, 2, -4, -1},
    {-2, -1, 0, 5, -3},
    {-1, 1, 0, 0, 0},
    {-1, -1, 3, -1, 3}};
static const WDATA_T conv3_weights_56_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 3, 1, -2, 0},
    {0, -4, -5, 0, 1},
    {-1, 0, 1, 1, 0},
    {0, 2, 0, 1, 1},
    {0, 2, -2, 1, -3}};
static const WDATA_T conv3_weights_56_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, -1, -3, 0},
    {1, -3, 1, -1, -5},
    {1, 0, -1, 1, -2},
    {0, 1, 0, -3, 1},
    {2, -1, 1, 2, 0}};
static const WDATA_T conv3_weights_57_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -21, -20, -4, -2},
    {-18, -26, -15, -25, -17},
    {21, 12, -13, -9, 0},
    {11, 20, -4, 22, 21},
    {19, 16, 18, 26, 17}};
static const WDATA_T conv3_weights_57_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 3, 20, 0, -19},
    {7, -7, -3, 4, -7},
    {-9, -11, 10, -4, -18},
    {-21, -15, -10, -12, -11},
    {-12, -10, -9, -6, -8}};
static const WDATA_T conv3_weights_57_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -14, -19, -5, 12},
    {-3, -9, -10, 9, 10},
    {-9, 0, 1, 9, 21},
    {-3, 24, 8, 3, 11},
    {7, 11, -3, -18, -4}};
static const WDATA_T conv3_weights_57_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -4, 4, 6},
    {11, 18, 14, -15, -25},
    {-11, -2, -4, -26, -35},
    {-8, 11, -16, -50, -28},
    {9, 32, -15, -15, 20}};
static const WDATA_T conv3_weights_57_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -5, -3, 6, -2},
    {2, 8, 5, 13, 4},
    {7, 5, 2, 2, 10},
    {16, 0, 9, 1, 4},
    {4, -7, 7, -9, 4}};
static const WDATA_T conv3_weights_57_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -15, 0, 23, -4},
    {8, 5, 2, 12, 2},
    {0, -2, -16, -6, -15},
    {5, 6, 0, 1, 5},
    {-3, -5, 9, 2, 14}};
static const WDATA_T conv3_weights_57_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 14, 6, -3, 1},
    {25, 16, 14, 22, 9},
    {30, 5, 6, 9, 16},
    {17, 3, -6, 8, -7},
    {-27, -14, -10, -20, -12}};
static const WDATA_T conv3_weights_57_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 1, 31, 40},
    {-4, -11, 1, 24, 29},
    {11, -1, -1, -22, -10},
    {7, 9, -4, -27, -18},
    {6, -5, -32, -35, -32}};
static const WDATA_T conv3_weights_57_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 15, 12, 2, -2},
    {10, 12, 8, -8, -18},
    {16, 23, -1, -6, 5},
    {-18, -15, -16, -7, -3},
    {-21, -3, 31, 1, 7}};
static const WDATA_T conv3_weights_57_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -5, 7, -20, -29},
    {11, 17, 1, -23, -29},
    {27, 1, -35, -24, 14},
    {35, 22, 30, 5, 22},
    {29, 29, 10, -17, 0}};
static const WDATA_T conv3_weights_57_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, -3, 1, 1},
    {4, 0, -3, 0, 2},
    {0, -4, 0, -2, 3},
    {-1, -5, -1, 0, 3},
    {3, 1, 0, 2, -3}};
static const WDATA_T conv3_weights_57_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, 2, 2, -6},
    {-2, 0, 1, 1, -3},
    {-6, -1, -1, -1, 1},
    {1, -4, -5, -4, -1},
    {1, 5, 15, 10, 5}};
static const WDATA_T conv3_weights_57_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 4, -14, -13, -14},
    {11, -4, 6, 13, 4},
    {-1, -31, 21, 12, 13},
    {15, -21, 9, 16, 15},
    {-3, -16, -1, 9, 14}};
static const WDATA_T conv3_weights_57_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 6, 5, 15, -4},
    {3, 18, 31, 7, -14},
    {-46, -22, 3, -5, 6},
    {-41, -37, -11, 4, 30},
    {-9, 1, 10, 22, 22}};
static const WDATA_T conv3_weights_57_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -8, 0, 1, -8},
    {-20, -13, -5, -2, 9},
    {-33, -41, -40, -31, -2},
    {13, 14, 9, 5, 13},
    {25, 40, 40, 40, 48}};
static const WDATA_T conv3_weights_57_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 4, -11, -32, -60},
    {2, 6, 12, -2, -39},
    {18, 17, 17, 17, 32},
    {10, -3, 19, 22, 1},
    {-11, -9, -34, -23, -34}};
static const WDATA_T conv3_weights_58_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 20, 28, 15, -3},
    {12, 29, 44, 25, 7},
    {4, 79, 68, 25, 5},
    {15, 46, 56, 11, 8},
    {-16, 35, 23, 16, 7}};
static const WDATA_T conv3_weights_58_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 29, 46, 21, 4},
    {17, 6, -6, 10, 8},
    {7, 26, -6, -2, 17},
    {-27, 1, 6, -41, -16},
    {-14, -14, -15, -5, -15}};
static const WDATA_T conv3_weights_58_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, -6, -34, -15, -22},
    {25, -5, -10, -18, -16},
    {25, -21, -25, -5, 15},
    {2, 5, -35, 19, 1},
    {9, 2, -19, 33, 8}};
static const WDATA_T conv3_weights_58_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 7, 5, 2, -4},
    {12, 13, -20, -47, -6},
    {24, 9, -3, -8, 4},
    {15, 4, 9, -4, 7},
    {-3, 5, 8, 9, 27}};
static const WDATA_T conv3_weights_58_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {37, 36, 31, 36, 13},
    {31, 47, 24, 38, 26},
    {28, 35, 35, 26, 27},
    {30, 18, 38, 15, 19},
    {13, 13, 54, 24, 25}};
static const WDATA_T conv3_weights_58_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 20, 19, 34, 2},
    {14, 6, -19, 2, 36},
    {27, 7, -9, -2, 47},
    {-18, -16, 9, 2, 17},
    {-19, -37, -24, -12, 2}};
static const WDATA_T conv3_weights_58_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 22, -10, -13, -14},
    {17, 6, 0, 10, 8},
    {-16, -3, 14, 24, 11},
    {-10, 22, 12, 7, -2},
    {-7, -11, -10, 24, 10}};
static const WDATA_T conv3_weights_58_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -8, -26, -17, 4},
    {2, 21, -15, -15, -16},
    {-7, 38, -30, -52, 0},
    {-8, 27, -39, -38, 21},
    {-8, -14, -7, -18, 23}};
static const WDATA_T conv3_weights_58_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 11, 10, 4, -4},
    {27, 4, -3, -4, -20},
    {1, -2, 0, 9, -3},
    {-10, -9, 4, 20, 6},
    {2, -6, -15, -5, -10}};
static const WDATA_T conv3_weights_58_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {26, 12, -14, 7, -7},
    {10, 13, 13, 25, 4},
    {-1, -4, -26, 16, 17},
    {-1, 1, 39, 14, -4},
    {2, 19, 9, -2, 6}};
static const WDATA_T conv3_weights_58_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -3, -2, 0, 0},
    {2, 2, -1, 1, -3},
    {1, 1, 0, 2, 2},
    {1, -1, -1, 2, 1},
    {-1, 1, 0, 3, -2}};
static const WDATA_T conv3_weights_58_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 4, 1, -1, 2},
    {-2, 0, -2, -4, 2},
    {2, 11, 6, 3, 2},
    {9, 13, 1, 3, 0},
    {3, 2, 10, 10, 9}};
static const WDATA_T conv3_weights_58_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, -20, -23, -32, -14},
    {41, -27, -43, 6, 18},
    {26, -23, 15, -10, 13},
    {14, -30, 14, 12, -2},
    {-7, -43, 7, -6, -1}};
static const WDATA_T conv3_weights_58_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 24, 16, -4, -10},
    {17, 29, 25, 3, -9},
    {-18, -26, -16, 8, 10},
    {-27, -48, -20, 6, -5},
    {5, 3, 0, 22, 2}};
static const WDATA_T conv3_weights_58_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -14, -15, -24, -13},
    {-16, -33, -1, 8, 2},
    {-18, -11, 6, -5, 4},
    {-8, 22, 40, 11, 22},
    {-16, -22, 28, -10, -7}};
static const WDATA_T conv3_weights_58_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 18, -1, -4, -7},
    {8, 28, -17, 7, -1},
    {16, -11, 4, -5, -12},
    {2, -5, -41, 4, 30},
    {-5, -4, -16, 40, 26}};
static const WDATA_T conv3_weights_59_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 8, 2, -3},
    {-6, 3, -6, 6, 6},
    {-10, 4, 0, 2, 1},
    {-15, -1, 2, -8, -9},
    {-13, 6, 8, 0, -5}};
static const WDATA_T conv3_weights_59_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, 3, 5, -3},
    {1, -7, 5, 17, 4},
    {-8, 0, -1, -3, 15},
    {-9, -5, 3, -6, 1},
    {-6, -4, 2, 2, -1}};
static const WDATA_T conv3_weights_59_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -5, 2, 11, 9},
    {-2, 4, -7, 9, 15},
    {3, 9, 1, 13, 18},
    {6, 9, 8, 9, 8},
    {7, 0, 6, 4, 9}};
static const WDATA_T conv3_weights_59_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, -1, 3, 3},
    {-3, -2, -2, -5, -7},
    {-1, -7, -10, -21, -7},
    {0, -8, -10, -19, 1},
    {-6, -4, -13, -8, -5}};
static const WDATA_T conv3_weights_59_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 4, 1, 4, 3},
    {11, 5, 7, 6, 4},
    {11, 7, -2, 2, 1},
    {9, 8, 5, 1, 8},
    {6, 2, 8, 8, 8}};
static const WDATA_T conv3_weights_59_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 11, 12, 3},
    {2, -1, -7, 3, 8},
    {-7, -3, -1, -3, 16},
    {-9, -16, 0, -1, 3},
    {-8, -15, -4, -9, -5}};
static const WDATA_T conv3_weights_59_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, -2, -7, -7, -4},
    {2, -8, 9, -1, -4},
    {-8, 12, -10, -11, -6},
    {4, 12, -5, 6, 1},
    {2, -1, -1, 7, 3}};
static const WDATA_T conv3_weights_59_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -8, 2, 15, 3},
    {-5, 9, 11, 27, -5},
    {-2, 19, -1, 21, 0},
    {2, 23, 0, 4, 20},
    {4, 0, 12, -1, 15}};
static const WDATA_T conv3_weights_59_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, -2, -1, -3, -2},
    {5, -1, 3, -8, -4},
    {2, 2, -15, -10, -2},
    {-3, 0, -7, -4, 1},
    {2, -12, -15, -5, 0}};
static const WDATA_T conv3_weights_59_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 17, 6, -10, -15},
    {0, 1, -20, -22, -10},
    {0, -19, -20, -20, -10},
    {-8, -12, 0, -10, 3},
    {-10, 9, 14, 21, 6}};
static const WDATA_T conv3_weights_59_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 1, 0, 1},
    {1, -4, -4, 3, 0},
    {-1, 0, 1, -1, -3},
    {3, -2, 2, -2, 2},
    {-4, 1, 0, 3, 2}};
static const WDATA_T conv3_weights_59_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 1, -2, -3},
    {0, -2, 4, 2, -1},
    {1, 5, 1, -2, -3},
    {2, -3, -1, 1, 1},
    {0, 2, 1, 3, 3}};
static const WDATA_T conv3_weights_59_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, -13, -13, -14, -7},
    {-2, -16, 1, 12, 5},
    {-1, -14, 4, -1, -2},
    {0, -4, -7, -4, -8},
    {9, -3, 3, 2, 3}};
static const WDATA_T conv3_weights_59_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 8, 5, 2, -9},
    {-2, -10, -7, -10, -6},
    {-8, -21, -5, -1, -6},
    {-12, -20, -9, -14, -12},
    {-11, 6, -1, 8, 4}};
static const WDATA_T conv3_weights_59_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, -1, -17, -9},
    {-7, -7, 1, -3, -5},
    {2, -6, -12, -6, 2},
    {-15, -6, -1, -9, 4},
    {-19, -4, 19, 17, 3}};
static const WDATA_T conv3_weights_59_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -3, 1, -9, 0},
    {-6, 8, 8, -16, 4},
    {-3, 6, -17, -9, 6},
    {1, -7, -25, -3, -6},
    {4, 9, 21, 13, 27}};
static const WDATA_T conv3_weights_60_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, -1, 2, -2},
    {-2, -8, -2, 1, -1},
    {4, 4, 1, 0, -2},
    {-2, -1, -2, -7, 0},
    {4, 3, -1, -1, -2}};
static const WDATA_T conv3_weights_60_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 1, -2, -3, 1},
    {3, 5, -3, -3, 0},
    {1, -2, -2, -1, -3},
    {0, 3, 3, -5, -11},
    {-1, -3, 4, 2, 0}};
static const WDATA_T conv3_weights_60_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 0, 2, 6},
    {2, 1, -5, 3, -1},
    {2, -3, -6, 3, 1},
    {4, 2, -1, 2, 1},
    {3, 4, 0, 5, 4}};
static const WDATA_T conv3_weights_60_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 2, -2, -4},
    {1, -1, -3, 2, 4},
    {-2, 1, -4, 4, -1},
    {0, -2, 1, 1, 3},
    {1, -4, -7, -6, 3}};
static const WDATA_T conv3_weights_60_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 3, 4, 1},
    {1, 5, 4, 2, 1},
    {2, 1, 8, 3, 2},
    {3, 0, 2, 2, 6},
    {2, 6, 0, 1, 3}};
static const WDATA_T conv3_weights_60_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, -1, 1, -1},
    {5, -2, -8, -2, -3},
    {0, -3, -6, -6, 2},
    {0, -7, 2, -4, -2},
    {-2, -1, 2, -2, -3}};
static const WDATA_T conv3_weights_60_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 7, 1, 3, -4},
    {5, 4, 4, 2, 3},
    {-4, 3, 0, 2, 1},
    {-3, 10, 4, 2, 7},
    {2, -1, 0, 3, -1}};
static const WDATA_T conv3_weights_60_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -1, 4, 3},
    {1, 0, 0, 1, 2},
    {-5, -1, 2, -1, 0},
    {0, 5, 6, 1, 0},
    {1, 1, 7, 8, 8}};
static const WDATA_T conv3_weights_60_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, 2, 4, -3},
    {-2, -13, 0, 3, 0},
    {-4, -3, 9, 2, 3},
    {-2, -1, -4, -1, -4},
    {4, 9, 1, -5, -7}};
static const WDATA_T conv3_weights_60_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, 2, 2, -2},
    {-1, 1, -5, 1, -1},
    {-3, -6, -2, 0, -1},
    {-4, -1, 7, 1, -9},
    {6, 9, 7, 5, 5}};
static const WDATA_T conv3_weights_60_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 0, 0, 1},
    {3, 0, 3, -2, 1},
    {-3, 4, 0, -1, 1},
    {-1, -1, 0, 0, 0},
    {3, 1, -1, -2, -1}};
static const WDATA_T conv3_weights_60_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 2, 0, 0},
    {2, -3, 1, 2, 0},
    {-3, 2, 2, 1, -3},
    {-2, 0, 4, 1, 2},
    {1, 2, 2, 0, -1}};
static const WDATA_T conv3_weights_60_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -4, -3, -7, -7},
    {1, 5, 6, 2, -3},
    {1, -4, -5, -3, -2},
    {3, 6, 4, -3, 0},
    {1, 0, 4, 3, 3}};
static const WDATA_T conv3_weights_60_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -2, -1, -1, -4},
    {1, 2, 3, 0, -4},
    {-6, -3, 0, 5, 0},
    {-8, -2, 1, -5, -7},
    {4, 3, 3, 2, 1}};
static const WDATA_T conv3_weights_60_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, -4, -6, -1},
    {-1, -6, 3, 0, -3},
    {-5, -13, -14, -11, -3},
    {0, -1, -7, -9, -2},
    {-8, 2, 10, 9, -7}};
static const WDATA_T conv3_weights_60_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, -1, -3, 4},
    {6, 12, -1, 6, 6},
    {0, 1, 2, 2, 1},
    {2, 1, -3, 5, 0},
    {5, 3, 7, 9, 8}};
static const WDATA_T conv3_weights_61_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -9, -18, -4, -5},
    {-25, -32, -22, 3, 1},
    {-41, -55, -8, 9, -3},
    {2, -17, -1, 12, -12},
    {-10, -20, -16, -10, -6}};
static const WDATA_T conv3_weights_61_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 29, 23, 6, -3},
    {17, 15, -5, -21, -19},
    {-7, 3, -7, 2, 3},
    {2, 1, -13, -12, -9},
    {18, 2, -14, -9, -7}};
static const WDATA_T conv3_weights_61_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 0, -18, -7, -12},
    {8, -17, -34, 1, 5},
    {10, 8, -16, -4, -10},
    {-1, 3, 6, 6, 6},
    {-12, 2, -3, 1, 8}};
static const WDATA_T conv3_weights_61_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, -3, -5, -1},
    {-9, -11, -4, -9, 2},
    {-7, -13, 9, 11, 12},
    {7, 4, -3, -14, -7},
    {-7, -29, -18, 26, 28}};
static const WDATA_T conv3_weights_61_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 0, 1, -1, 2},
    {5, 1, 7, 5, 7},
    {13, 5, -1, 2, 6},
    {9, -4, 13, 6, -7},
    {1, 10, 17, -1, -1}};
static const WDATA_T conv3_weights_61_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 47, 42, 16, 7},
    {18, 3, 6, 3, 6},
    {3, 5, -14, -14, 6},
    {-16, -11, -5, -12, -10},
    {7, -5, -21, -14, -14}};
static const WDATA_T conv3_weights_61_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, -38, -24, -10, -1},
    {-29, -10, 3, -9, 4},
    {-19, 35, 27, 6, 3},
    {-17, 7, 7, 1, 6},
    {14, -7, 1, 4, 23}};
static const WDATA_T conv3_weights_61_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -13, -19, -17, -16},
    {-12, -5, -3, 5, 4},
    {7, 35, -2, -5, 15},
    {9, 22, -4, -5, 5},
    {6, 11, 17, 38, 14}};
static const WDATA_T conv3_weights_61_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -24, -29, -8, 0},
    {-18, 35, 23, -1, -8},
    {35, 47, 11, -18, -8},
    {9, 11, 17, 13, -4},
    {2, 12, -14, -21, -12}};
static const WDATA_T conv3_weights_61_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -5, -10, 14, 23},
    {-6, 24, 0, -12, 5},
    {19, 9, -15, -10, 10},
    {11, -11, -10, 5, 10},
    {0, 2, -25, -26, -26}};
static const WDATA_T conv3_weights_61_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 1, -1, 0},
    {2, -4, 2, 2, 1},
    {2, 1, -3, -1, -2},
    {5, 2, 0, -1, 3},
    {-3, 2, 2, 0, 0}};
static const WDATA_T conv3_weights_61_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, -2, 1, 0},
    {-7, -2, -3, 4, -1},
    {-1, 9, 2, 1, -1},
    {6, 8, -3, 2, 1},
    {3, -5, -4, 0, -2}};
static const WDATA_T conv3_weights_61_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 16, 27, 7},
    {0, 21, -9, 19, 6},
    {-9, 19, 8, -6, -2},
    {-26, -15, 4, 3, 0},
    {-4, -6, 9, -1, -12}};
static const WDATA_T conv3_weights_61_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 30, 15, 14, 19},
    {15, 15, 20, -10, -4},
    {-18, 8, 28, 17, 7},
    {45, 11, -1, -9, -6},
    {-22, -7, -2, -22, -24}};
static const WDATA_T conv3_weights_61_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 9, 15, 10, -4},
    {-2, -29, -18, 15, -7},
    {-48, -56, -25, 18, 10},
    {-36, -27, -14, 1, -7},
    {-36, -73, -58, -39, -35}};
static const WDATA_T conv3_weights_61_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-26, -15, 5, 9, 17},
    {-11, -12, -32, 6, 26},
    {-8, 19, 21, 14, 12},
    {3, 49, 19, 4, 13},
    {7, 20, 6, -9, 20}};
static const WDATA_T conv3_weights_62_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 22, 15, 10, -8},
    {8, 17, 27, 8, 4},
    {5, 22, 31, 6, -6},
    {4, 15, 21, 16, -1},
    {-7, 15, 23, 8, 1}};
static const WDATA_T conv3_weights_62_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 13, 26, 10, -16},
    {10, 16, 21, 4, 7},
    {1, 6, 10, 2, 0},
    {-2, 4, -8, -6, -4},
    {-9, 4, -2, 0, 12}};
static const WDATA_T conv3_weights_62_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 5, -7, -21, -24},
    {9, -9, -9, -6, -14},
    {1, 4, 0, 17, 11},
    {-2, 17, 14, 21, 16},
    {3, 13, 22, 12, 18}};
static const WDATA_T conv3_weights_62_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 5, 5, 7},
    {-6, -10, 9, 8, -10},
    {-23, -26, -10, 2, -5},
    {-18, -16, -8, -6, -18},
    {3, 8, 7, 1, -9}};
static const WDATA_T conv3_weights_62_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 25, 29, 24, 10},
    {17, 34, 49, 31, 10},
    {25, 37, 54, 38, 20},
    {20, 31, 50, 33, 18},
    {16, 30, 45, 32, 11}};
static const WDATA_T conv3_weights_62_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -17, 14, 0, -28},
    {4, -6, 13, 32, 22},
    {6, 0, 11, 30, 25},
    {-1, -2, 0, 21, 14},
    {-9, -13, -3, -3, 12}};
static const WDATA_T conv3_weights_62_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, -7, 14, -2, -4},
    {-17, 9, 12, 9, 8},
    {-21, -11, -4, 22, 10},
    {-19, 10, 20, 18, -1},
    {5, 17, 22, 18, 2}};
static const WDATA_T conv3_weights_62_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, 11, -9, -9, -15},
    {-3, 32, 2, -21, -21},
    {1, 11, 14, -12, -18},
    {2, 17, 4, -10, -12},
    {2, 21, -25, -22, 1}};
static const WDATA_T conv3_weights_62_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 9, 10, 8, -3},
    {4, 17, 16, -1, -10},
    {-2, -12, -9, -1, 4},
    {-10, 10, 10, 21, -2},
    {-5, 18, 11, 2, -3}};
static const WDATA_T conv3_weights_62_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 18, 20, 4, -8},
    {-1, 11, 6, 7, -5},
    {1, 17, 7, -7, -5},
    {0, 18, 10, -9, -6},
    {-5, -15, -11, -11, -10}};
static const WDATA_T conv3_weights_62_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, 1, 1, -1},
    {1, -3, -1, -3, 4},
    {-2, -2, 4, -1, 0},
    {1, 3, -2, 1, 0},
    {0, -2, 0, 2, 2}};
static const WDATA_T conv3_weights_62_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 3, 0, 1, -2},
    {-1, 1, 6, 5, 4},
    {-1, 6, 9, 6, 6},
    {1, 9, 4, 8, 0},
    {3, 1, 4, 6, -1}};
static const WDATA_T conv3_weights_62_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -31, -20, -14, 2},
    {-13, 11, 7, 7, 14},
    {-18, -6, 12, 0, 7},
    {-15, -22, 9, 4, 4},
    {-10, -21, -3, 9, 3}};
static const WDATA_T conv3_weights_62_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 11, 9, 10, 12},
    {2, 11, 20, 13, 4},
    {1, 22, 28, 17, -5},
    {-16, -9, 5, 0, 3},
    {-18, -5, 16, 7, -3}};
static const WDATA_T conv3_weights_62_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -13, -5, 6, -10},
    {-21, -14, -2, 2, 13},
    {-30, -35, -1, -6, -5},
    {-24, -29, -10, 2, -11},
    {-31, -52, -38, -13, -7}};
static const WDATA_T conv3_weights_62_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 12, 13, 19, 3},
    {5, 19, 11, 3, -24},
    {6, 0, 32, 3, -33},
    {9, 22, 43, 21, -1},
    {8, 34, 33, 16, -4}};
static const WDATA_T conv3_weights_63_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -15, 7, 11, 8},
    {17, 30, 12, -10, -29},
    {-10, -9, 15, 6, 25},
    {1, -1, 24, 6, 28},
    {1, 62, 64, 21, 6}};
static const WDATA_T conv3_weights_63_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -1, 10, 27, 49},
    {5, 17, 47, 27, 36},
    {-25, 19, 47, 36, -16},
    {-63, -49, 5, 43, 32},
    {-25, -33, -5, 19, -1}};
static const WDATA_T conv3_weights_63_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 9, -5, -17, -4},
    {-15, 6, -38, -19, -28},
    {-24, -9, -16, -2, -19},
    {-27, -30, 2, 2, -10},
    {8, -8, -24, -23, -6}};
static const WDATA_T conv3_weights_63_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 8, -2, -13},
    {0, 11, -37, -31, -14},
    {-6, 1, -5, -3, -24},
    {-7, -14, -22, 17, 36},
    {2, 11, 11, 8, 4}};
static const WDATA_T conv3_weights_63_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 3, -6, -1, -1},
    {-7, 0, -13, 4, 19},
    {-2, 9, -2, 2, 16},
    {0, 15, 20, 7, 2},
    {7, -5, 2, 0, -6}};
static const WDATA_T conv3_weights_63_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -28, -47, -17, -2},
    {3, 4, -6, 12, -8},
    {2, 8, 21, 7, -28},
    {10, -20, -1, 13, 9},
    {-4, -20, -9, 20, 3}};
static const WDATA_T conv3_weights_63_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {33, 41, 46, -14, -9},
    {5, -14, 0, 11, 2},
    {21, 31, 21, 11, 26},
    {82, 28, -4, 4, -7},
    {-47, -35, -36, -23, -23}};
static const WDATA_T conv3_weights_63_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {36, 36, 51, 19, 37},
    {-13, -3, 16, -31, 21},
    {-6, 18, 11, 2, -8},
    {14, 30, 54, 20, -40},
    {-4, 5, -15, -49, -42}};
static const WDATA_T conv3_weights_63_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 35, -1, -9, -25},
    {-15, -22, -42, -16, -39},
    {-7, -23, -39, 25, -18},
    {-19, -41, -43, 0, 7},
    {-76, -105, -29, 54, 31}};
static const WDATA_T conv3_weights_63_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 11, 55, 7, -58},
    {12, -14, 29, 18, 7},
    {17, 37, 23, 40, 22},
    {33, 31, 16, -22, -4},
    {-13, -9, 42, -7, -6}};
static const WDATA_T conv3_weights_63_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, -2, 1, 1},
    {4, 3, 0, 3, 2},
    {2, 4, -4, 3, -3},
    {-2, 1, 1, 0, -1},
    {-1, -1, 5, 1, 0}};
static const WDATA_T conv3_weights_63_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, 2, -5, -3},
    {6, 9, -4, -7, -4},
    {10, 9, 1, -1, 0},
    {11, 5, 0, -3, 2},
    {2, 15, 15, 6, 9}};
static const WDATA_T conv3_weights_63_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, -14, -46, -52, -12},
    {-7, 15, -6, -12, 1},
    {28, 24, -18, -18, -15},
    {10, -13, -10, 1, -1},
    {32, 2, -22, 1, 1}};
static const WDATA_T conv3_weights_63_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 3, -7, -20, 14},
    {27, 26, 8, 2, -12},
    {-37, -80, -16, 0, -22},
    {-69, -109, -30, 12, -9},
    {-37, 29, 47, 32, 23}};
static const WDATA_T conv3_weights_63_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, -17, -22, -21},
    {11, 9, -22, -45, -43},
    {-8, -32, -46, -18, 6},
    {-13, -23, 0, 31, 18},
    {54, 66, 90, 58, 28}};
static const WDATA_T conv3_weights_63_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {25, 31, 31, -7, -43},
    {-3, 13, -3, 31, -38},
    {41, -10, -14, 25, 27},
    {38, 8, 38, -18, -21},
    {-21, -31, -66, -22, -20}};
static const WDATA_T conv3_weights_64_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 17, 32, 31, 16},
    {8, 4, 3, 4, 6},
    {17, -3, 1, -11, -25},
    {11, -14, -14, -38, -23},
    {15, 16, -2, -19, -10}};
static const WDATA_T conv3_weights_64_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -6, -13, -17, 37},
    {0, -18, -28, 12, 17},
    {3, 8, -13, -13, 11},
    {17, 17, -7, -3, -17},
    {4, 10, 9, -6, -20}};
static const WDATA_T conv3_weights_64_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, 7, 12, -4},
    {1, 11, -17, -4, -26},
    {6, 9, 10, -8, -18},
    {-3, 10, 19, 8, -18},
    {3, 8, 13, 11, -2}};
static const WDATA_T conv3_weights_64_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -3, -5, -6, -3},
    {-22, -8, 0, 14, 3},
    {-21, -13, -13, 6, 4},
    {-19, -19, -7, 3, 5},
    {-9, -4, -1, 13, -2}};
static const WDATA_T conv3_weights_64_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 7, -8, -12},
    {17, 14, 8, -5, -3},
    {20, 13, 10, 17, 12},
    {6, 12, 3, 0, 10},
    {6, 1, -7, -2, 4}};
static const WDATA_T conv3_weights_64_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -10, -11, 6, 20},
    {2, -8, -20, 7, -1},
    {2, 4, -19, -15, -3},
    {2, 12, -7, 19, -18},
    {4, 16, 5, 2, -29}};
static const WDATA_T conv3_weights_64_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 14, 12, -13, -18},
    {-4, -8, -8, 1, -3},
    {-26, -31, -26, -13, -6},
    {-33, -19, -4, 9, 17},
    {-19, -10, 6, 36, 28}};
static const WDATA_T conv3_weights_64_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -14, -5, -5, 1},
    {-1, 5, 21, 17, 7},
    {-2, -7, 37, 39, 7},
    {-8, -7, 35, 25, 16},
    {9, -11, 11, -12, -5}};
static const WDATA_T conv3_weights_64_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 24, 19, 19, -5},
    {7, -11, 2, 26, -3},
    {-4, -35, 0, 8, 9},
    {-26, -30, -14, 8, 10},
    {6, -6, 14, 53, 33}};
static const WDATA_T conv3_weights_64_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -4, 7, 13, -25},
    {-4, -11, 7, 5, -25},
    {-12, -10, -14, -8, 4},
    {-31, -5, 3, 15, 1},
    {-2, 16, 19, 38, 17}};
static const WDATA_T conv3_weights_64_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, -1, -1, 0},
    {0, 2, 1, -1, 2},
    {-1, 0, -1, 5, 2},
    {1, -1, 2, 0, 0},
    {-1, -1, -1, -1, -1}};
static const WDATA_T conv3_weights_64_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -2, -2, 1, -1},
    {-3, 1, 5, 3, -1},
    {1, 5, 3, -2, -4},
    {-4, -6, 3, 3, 9},
    {-7, 1, 2, 2, 6}};
static const WDATA_T conv3_weights_64_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 21, -4, -19, -3},
    {-20, 3, -12, 2, 4},
    {-17, -5, -36, -12, -2},
    {-14, 4, -11, -8, 12},
    {0, 10, 13, 6, 6}};
static const WDATA_T conv3_weights_64_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -3, -1, -3, 3},
    {-9, -27, -28, -11, -16},
    {-34, -12, 24, 9, -9},
    {-14, 10, 7, -2, -2},
    {8, 11, 5, 8, 0}};
static const WDATA_T conv3_weights_64_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-28, -31, -23, -13, 4},
    {-18, -2, 8, 6, 14},
    {-3, -11, -29, -35, -11},
    {16, -15, -13, -1, -5},
    {21, 30, 51, 31, -11}};
static const WDATA_T conv3_weights_64_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, 17, 9, -4, -12},
    {10, 17, 10, -11, -60},
    {7, 13, -19, -10, -47},
    {16, -5, -16, 14, 8},
    {7, 17, 39, 10, 40}};
static const WDATA_T conv3_weights_65_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -15, -18, -8, -2},
    {-5, -7, -9, -9, 15},
    {2, -8, -9, 2, 8},
    {-6, -8, -3, 5, 2},
    {-7, -15, -1, -2, -1}};
static const WDATA_T conv3_weights_65_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -9, -2, -19, -25},
    {2, 8, -3, 9, 0},
    {-1, 4, -1, -21, 1},
    {-7, 4, -5, -14, -8},
    {-2, -9, -1, 0, -4}};
static const WDATA_T conv3_weights_65_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 20, 26, 22, 7},
    {12, 26, 29, 21, 9},
    {-1, 15, 3, 1, -2},
    {3, 16, 7, -7, -2},
    {7, 5, 11, -5, -9}};
static const WDATA_T conv3_weights_65_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -5, -1, 1},
    {1, -4, -14, -14, -2},
    {-3, -5, -10, -13, -7},
    {2, 5, -6, -7, 8},
    {21, 17, 3, 8, 4}};
static const WDATA_T conv3_weights_65_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 3, 7, 8},
    {-3, -1, 1, 0, -4},
    {-3, -6, 5, 0, -5},
    {1, 4, -3, 5, -1},
    {4, 4, -2, 2, 0}};
static const WDATA_T conv3_weights_65_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -14, -16, -3, -5},
    {-1, 2, -1, -1, -5},
    {-4, 2, 13, 2, -3},
    {-4, -9, 4, -3, -17},
    {1, -4, -1, 0, -5}};
static const WDATA_T conv3_weights_65_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 13, 3, 29, 13},
    {10, -5, 0, 7, 2},
    {9, 7, -8, -7, -1},
    {11, 9, -7, -1, 0},
    {3, 0, -2, -3, -3}};
static const WDATA_T conv3_weights_65_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -1, 11, 7, 2},
    {9, 10, 0, 5, -11},
    {13, -4, -6, -3, -12},
    {3, 2, 4, -9, -6},
    {-1, 10, 12, -1, 0}};
static const WDATA_T conv3_weights_65_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -10, -9, -1, 2},
    {-4, -12, -13, -3, -7},
    {-9, -17, -8, -7, -5},
    {4, -3, -9, 4, 0},
    {18, -2, -6, -11, -1}};
static const WDATA_T conv3_weights_65_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -20, -13, 6, 13},
    {-14, 3, 1, -6, 5},
    {21, 2, -9, -1, 6},
    {2, -7, -13, -12, -1},
    {4, -11, -23, 5, 1}};
static const WDATA_T conv3_weights_65_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 0, 1, -1},
    {-2, 1, -2, 4, -1},
    {2, 1, -1, -1, 0},
    {2, -1, 0, 0, 0},
    {3, 1, 0, -2, -1}};
static const WDATA_T conv3_weights_65_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 0, 0, 1},
    {-4, -3, 1, -1, 1},
    {-3, -1, -1, 0, -2},
    {2, 0, 1, 2, 0},
    {5, -1, -1, 2, -1}};
static const WDATA_T conv3_weights_65_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 11, 10, 12, 0},
    {8, 1, 49, 19, 7},
    {5, 2, 25, 3, -7},
    {14, 18, -6, -7, -4},
    {2, 11, -11, 0, -1}};
static const WDATA_T conv3_weights_65_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -13, -12, -2, -1},
    {-10, 6, -2, 4, 2},
    {-16, -10, -3, -5, -11},
    {-2, -21, -5, -1, 1},
    {-9, -6, -7, -5, -3}};
static const WDATA_T conv3_weights_65_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -5, -7, -4},
    {-6, 2, 2, -10, -4},
    {9, 14, 7, 7, 7},
    {7, 3, 0, -2, -7},
    {-9, -3, 0, 2, 4}};
static const WDATA_T conv3_weights_65_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 29, 10, 11},
    {12, 3, 43, 18, 17},
    {-1, 3, 8, 3, -2},
    {4, -8, 11, 12, -22},
    {3, 5, 19, -13, -21}};
static const WDATA_T conv3_weights_66_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -33, -81, -38, -3},
    {-6, -3, 1, -21, 2},
    {2, 20, 3, 8, 13},
    {-7, 7, -1, 13, 5},
    {-7, -12, -4, 5, -7}};
static const WDATA_T conv3_weights_66_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 3, -6, -56, -79},
    {8, 34, -1, -3, -26},
    {-2, 12, 50, -11, -12},
    {-17, -7, 6, -6, -13},
    {-23, -23, -22, -9, -7}};
static const WDATA_T conv3_weights_66_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 71, 88, 56, 8},
    {21, 43, 94, 54, 20},
    {11, -29, 10, 7, 1},
    {2, 7, -10, -20, -6},
    {7, 8, -6, -10, -17}};
static const WDATA_T conv3_weights_66_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 1, 1, -5, 2},
    {0, -10, -31, -53, -9},
    {-5, -9, -13, -41, -19},
    {8, 21, -7, -16, 3},
    {45, 38, 32, 31, 56}};
static const WDATA_T conv3_weights_66_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 20, 9, 18, 18},
    {-14, 14, 12, 12, 6},
    {-13, -2, 15, -14, 1},
    {3, -2, 1, 2, 3},
    {13, 1, 1, 8, 3}};
static const WDATA_T conv3_weights_66_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -36, -34, -43, -32},
    {0, 15, 15, -33, -28},
    {6, 10, 56, 5, 13},
    {-6, 12, 23, 13, 20},
    {-11, -22, -8, -13, 8}};
static const WDATA_T conv3_weights_66_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-35, 15, -18, 65, 39},
    {25, -4, -29, 11, 11},
    {36, -12, -22, -8, -10},
    {11, 3, -14, 1, 0},
    {-7, -9, 4, 14, 7}};
static const WDATA_T conv3_weights_66_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 24, 45, 37, 20},
    {35, 53, 1, -17, -20},
    {22, -13, -17, -20, -32},
    {-1, -1, -13, -7, -15},
    {3, 19, -6, 18, -8}};
static const WDATA_T conv3_weights_66_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-31, -39, -37, -6, 9},
    {5, -35, -19, -9, -2},
    {1, -49, -20, -24, -13},
    {9, -14, -27, 0, -18},
    {15, -25, -9, 11, 6}};
static const WDATA_T conv3_weights_66_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-26, -49, -33, -2, 51},
    {-11, 34, 10, 1, 10},
    {53, 5, -55, -13, 13},
    {13, -14, 16, -14, 16},
    {13, -2, -24, -17, 1}};
static const WDATA_T conv3_weights_66_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -3, 2, -1},
    {0, 3, -2, -2, -1},
    {-2, -2, 1, 0, -1},
    {0, -2, -4, -2, 0},
    {4, -2, 0, -1, -1}};
static const WDATA_T conv3_weights_66_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -1, 1, 1, 1},
    {-8, -4, -2, 4, 1},
    {-6, -12, -6, 3, -5},
    {6, -1, -6, 5, -5},
    {5, 3, 6, 7, 3}};
static const WDATA_T conv3_weights_66_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 30, 12, 10, -3},
    {27, 7, 91, 17, 4},
    {9, -28, 65, 21, 11},
    {16, -17, -7, 14, 7},
    {0, 8, -14, -14, 2}};
static const WDATA_T conv3_weights_66_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -11, -19, -29, -27},
    {-15, 37, 33, -10, -30},
    {-29, -16, -6, 15, -1},
    {-25, -35, -17, -10, 3},
    {-7, -13, 1, 5, 3}};
static const WDATA_T conv3_weights_66_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -7, -6, -13, -15},
    {-16, 14, 9, -15, -13},
    {10, 35, 46, 26, 8},
    {40, -1, -10, 16, 28},
    {7, -6, -21, -1, 31}};
static const WDATA_T conv3_weights_66_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -15, 21, 41, 40},
    {31, 11, 30, 30, 19},
    {6, -5, 3, -42, 0},
    {-12, -4, -9, -1, -32},
    {3, 8, 18, -13, -42}};
static const WDATA_T conv3_weights_67_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-21, -5, 0, 1, 1},
    {14, 16, 0, -9, -5},
    {17, 40, 1, -18, 19},
    {17, 0, -5, 7, 4},
    {8, 4, -1, -1, -3}};
static const WDATA_T conv3_weights_67_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 0, -10, -24, -15},
    {-17, -8, 7, 1, 2},
    {14, 16, 8, -9, -5},
    {-17, 0, 10, -27, -8},
    {-15, -12, 0, 18, -1}};
static const WDATA_T conv3_weights_67_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 19, 24, 34, 15},
    {5, 15, 30, 23, 2},
    {-8, -12, 10, 13, 11},
    {-9, -1, -4, -2, 14},
    {13, -10, 3, -9, 1}};
static const WDATA_T conv3_weights_67_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -1, -3, -8},
    {-10, -20, -12, -18, -16},
    {-6, -4, -7, -31, -28},
    {-12, -2, 8, 0, 19},
    {19, 25, 5, 6, -4}};
static const WDATA_T conv3_weights_67_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 2, 4, 7, 8},
    {-1, 4, 4, 15, 12},
    {4, 6, -2, 1, -3},
    {2, -2, -7, -4, 0},
    {4, 9, 6, 1, 9}};
static const WDATA_T conv3_weights_67_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -12, -5, 1, 4},
    {-11, -7, 3, -18, -28},
    {3, 10, 27, 4, -11},
    {-2, 14, 25, 5, 8},
    {-3, -9, -12, 9, 7}};
static const WDATA_T conv3_weights_67_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 26, 9, 25, 12},
    {15, -9, -2, 18, 4},
    {5, -35, -14, 4, -11},
    {15, 1, -22, -7, -5},
    {5, -8, -11, -13, -14}};
static const WDATA_T conv3_weights_67_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 15, 14, 9, 18},
    {2, 12, 8, -1, -2},
    {2, -23, 12, 5, -6},
    {2, -10, 5, 5, 10},
    {3, 7, 22, 25, 13}};
static const WDATA_T conv3_weights_67_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 23, 17, -1, 0},
    {6, -15, -7, 17, -7},
    {-43, -71, -24, 2, -10},
    {-9, -9, -4, 7, 8},
    {26, 2, 11, -12, -8}};
static const WDATA_T conv3_weights_67_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -5, 9, -4, -6},
    {0, 5, -21, 5, 21},
    {14, 2, 16, 36, 8},
    {22, 15, -6, -40, -33},
    {9, -9, -15, -13, -10}};
static const WDATA_T conv3_weights_67_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -1, 1, 1},
    {1, -3, -3, -3, 1},
    {1, -1, 0, -4, 2},
    {0, 0, -2, 0, 3},
    {4, 2, 1, 3, 0}};
static const WDATA_T conv3_weights_67_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 5, 1, -7},
    {-1, 0, 4, -3, -3},
    {-2, -1, 2, -4, 1},
    {-3, -7, 2, -3, 2},
    {5, 2, 2, 0, -1}};
static const WDATA_T conv3_weights_67_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 11, 5, 1, -4},
    {8, -14, 51, -1, -10},
    {1, 3, 25, 11, 6},
    {18, 8, 2, 5, -4},
    {-1, 0, -34, -3, -2}};
static const WDATA_T conv3_weights_67_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -17, -17, -23, -36},
    {-2, -2, -18, -24, -29},
    {5, 1, -8, -14, -14},
    {-23, -27, -17, 0, 3},
    {-19, 2, -6, 7, 3}};
static const WDATA_T conv3_weights_67_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -18, -11, -1, -2},
    {-9, 18, 23, -20, -12},
    {33, 51, 34, 16, 12},
    {19, 9, -3, -22, 9},
    {12, 1, -17, -7, 16}};
static const WDATA_T conv3_weights_67_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -5, -13, -16},
    {7, -3, -7, -3, 5},
    {-3, -4, -2, 0, 49},
    {-8, -23, -5, 4, -38},
    {-5, -6, -4, -8, -14}};
static const WDATA_T conv3_weights_68_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 13, 14, 3, 5},
    {2, 0, 4, 10, 1},
    {2, -3, 11, 5, 3},
    {6, 9, 6, 2, 9},
    {-5, -1, -1, 2, 5}};
static const WDATA_T conv3_weights_68_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 20, 24, 11, 4},
    {3, 2, 27, 15, 16},
    {-7, 3, 17, 19, 1},
    {-4, 10, 1, -3, -9},
    {1, 4, -3, -2, 2}};
static const WDATA_T conv3_weights_68_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -8, 6, -20, -14},
    {-6, -9, 4, -15, -9},
    {-7, -10, 4, -4, -11},
    {-4, -10, -1, 2, -7},
    {1, 0, -3, -2, -6}};
static const WDATA_T conv3_weights_68_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 0, -1, -4},
    {-2, 1, 8, 4, -12},
    {-1, 10, 4, 1, -2},
    {2, -6, -10, -8, -6},
    {12, 16, 8, 11, 21}};
static const WDATA_T conv3_weights_68_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, -4, -1, -3},
    {6, 8, 4, 5, 0},
    {7, 5, 7, 7, 11},
    {3, 0, 7, -1, 2},
    {0, 0, 5, -1, -5}};
static const WDATA_T conv3_weights_68_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 10, 21, -4, -19},
    {5, 2, 21, 33, 17},
    {3, 4, -7, 10, 10},
    {1, 0, 4, 5, 1},
    {1, 0, 0, -7, -3}};
static const WDATA_T conv3_weights_68_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -17, -6, -5, -7},
    {-15, -11, -5, -3, -2},
    {-9, -15, -10, 0, 7},
    {-11, -1, 2, 7, -4},
    {-2, 4, 6, 8, 14}};
static const WDATA_T conv3_weights_68_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 0, 1, -11, -11},
    {-7, 0, 25, -14, -20},
    {0, -2, 21, 13, -20},
    {-2, -3, 11, 2, -18},
    {1, 0, -5, -6, -7}};
static const WDATA_T conv3_weights_68_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -9, -8, 0, 0},
    {-3, 1, 5, 16, 2},
    {13, -4, -11, 5, 12},
    {0, -1, -1, 7, 3},
    {3, 9, 14, 21, 19}};
static const WDATA_T conv3_weights_68_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -2, -2, -4, -17},
    {9, -15, -10, -2, -10},
    {8, -5, -21, -13, 16},
    {-1, -4, -7, 14, 29},
    {-14, -19, 6, 1, -16}};
static const WDATA_T conv3_weights_68_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 1, -1, 2},
    {1, 1, 2, 4, 3},
    {-2, -1, 0, -3, 3},
    {-2, 1, 1, -2, 1},
    {2, -4, 3, -2, 0}};
static const WDATA_T conv3_weights_68_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -2, 0, -2},
    {0, 1, 1, 1, -1},
    {2, 1, 0, 1, 3},
    {-1, 4, 0, 5, 5},
    {-2, 3, 0, 6, 3}};
static const WDATA_T conv3_weights_68_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -5, -3, 0, 13},
    {-5, 5, -3, 0, 9},
    {-16, -6, -16, -1, 1},
    {-15, 4, 7, 0, 5},
    {-7, 8, 1, 5, 4}};
static const WDATA_T conv3_weights_68_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 5, 22, 15, 22},
    {11, -2, -4, 1, 7},
    {-9, 4, 14, 22, 5},
    {6, 8, -3, -9, 0},
    {-5, 10, 11, 6, 8}};
static const WDATA_T conv3_weights_68_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 6, 7, 4, 9},
    {-16, -3, 16, 6, 2},
    {-8, -18, -15, 1, 1},
    {0, -3, 3, 17, 13},
    {-14, -20, -3, 6, 0}};
static const WDATA_T conv3_weights_68_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -5, 0, -3},
    {-5, -11, -15, -20, -26},
    {8, 2, 8, -22, -39},
    {15, 1, -3, -15, -6},
    {2, 0, -7, -5, 2}};
static const WDATA_T conv3_weights_69_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 18, 25, 4, -11},
    {2, 12, 31, -8, -7},
    {0, -6, 11, -2, -5},
    {-6, -6, 0, 3, 3},
    {15, 30, 19, 13, 2}};
static const WDATA_T conv3_weights_69_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 4, 2, -12, -2},
    {1, 0, 11, 5, -5},
    {-2, 2, 12, 3, 5},
    {1, 7, 2, 28, 16},
    {-10, -18, -4, 1, 17}};
static const WDATA_T conv3_weights_69_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 10, 23, -2, -9},
    {-10, -13, 7, -19, -12},
    {-14, -4, 11, 5, 5},
    {-15, 7, -1, 13, 9},
    {1, 5, 13, -7, 6}};
static const WDATA_T conv3_weights_69_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 3, 7, 9},
    {-4, 0, 14, 26, -15},
    {-8, -10, -15, -7, -32},
    {-4, -18, -18, -15, -16},
    {-5, -12, -10, -5, -8}};
static const WDATA_T conv3_weights_69_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 26, 22, 9, -1},
    {-3, 27, 24, 8, -4},
    {10, 19, 21, 10, 0},
    {8, 15, 21, 19, 9},
    {6, 14, 15, 17, 2}};
static const WDATA_T conv3_weights_69_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -20, 5, -8, -19},
    {-4, -5, 22, 30, -6},
    {-2, -7, -1, 33, 0},
    {0, 6, -3, 43, 25},
    {-3, -6, -5, 5, 20}};
static const WDATA_T conv3_weights_69_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -1, 1, -1, 1},
    {-17, -4, -10, 4, -2},
    {-20, -15, -4, 3, -1},
    {-15, -1, 8, 2, 0},
    {3, 12, 6, 6, 1}};
static const WDATA_T conv3_weights_69_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 19, -3, -1, -5},
    {-7, 14, 18, -25, -12},
    {-14, -15, 32, -2, -7},
    {-7, -11, 17, 1, -7},
    {2, 3, -10, -1, 10}};
static const WDATA_T conv3_weights_69_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 5, 7, -1},
    {-5, 10, 8, -17, -20},
    {3, 4, 18, 3, 0},
    {4, 6, -6, -1, 2},
    {1, 18, 5, 13, 5}};
static const WDATA_T conv3_weights_69_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 3, 16, -26, -43},
    {-3, 6, 8, -15, -16},
    {-6, -4, -6, -9, -4},
    {1, 2, 4, 5, -2},
    {9, 9, 14, 6, 9}};
static const WDATA_T conv3_weights_69_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 1, -4, -1},
    {-2, -3, 1, 0, 0},
    {2, 0, 2, 1, -2},
    {-1, 1, -1, 3, 1},
    {0, -2, 0, 1, -1}};
static const WDATA_T conv3_weights_69_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 2, 2, 2},
    {-1, 4, 2, 2, -3},
    {-3, 3, 6, 0, -2},
    {-4, 2, 0, -4, -5},
    {-3, -4, -2, -1, -3}};
static const WDATA_T conv3_weights_69_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -8, -22, -5, -3},
    {-12, -8, -16, 3, -4},
    {-20, -8, -2, 5, 6},
    {-17, 18, 30, 12, 7},
    {-3, 6, -4, 0, -2}};
static const WDATA_T conv3_weights_69_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 3, 1, -9, 4},
    {17, 15, 0, -4, -13},
    {8, 23, 15, 4, 9},
    {-16, 8, 16, 5, 0},
    {-8, -2, 11, 3, 1}};
static const WDATA_T conv3_weights_69_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 14, 9, -3, -7},
    {1, -1, 6, -3, 1},
    {-9, -5, 3, -10, -9},
    {-8, -24, -9, 14, -2},
    {-12, -30, -21, 13, 20}};
static const WDATA_T conv3_weights_69_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 7, 7, 27, 18},
    {5, -2, 8, -2, -30},
    {1, -7, 14, -7, -27},
    {6, 9, 16, -10, -15},
    {1, 5, 10, 23, -4}};
static const WDATA_T conv3_weights_70_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-21, -8, 12, 6, -2},
    {5, 4, 8, -11, 3},
    {-10, -13, -9, -9, 6},
    {-12, -5, 1, -1, -1},
    {3, 11, 15, 10, -3}};
static const WDATA_T conv3_weights_70_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -24, -11, -9, 0},
    {-3, 1, -8, 1, 6},
    {15, 17, 6, -6, -1},
    {8, 19, 13, -3, -4},
    {2, 1, 10, 5, 8}};
static const WDATA_T conv3_weights_70_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 12, 6, 13, 5},
    {6, 7, 5, 18, -2},
    {-4, -10, -6, 1, -2},
    {2, 0, 8, 6, -1},
    {2, 9, 4, -4, 2}};
static const WDATA_T conv3_weights_70_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 7, 9, 7},
    {-12, -7, -1, 6, 3},
    {6, 8, -9, -5, -10},
    {-2, -5, 4, -8, -15},
    {-3, -4, -3, -8, 0}};
static const WDATA_T conv3_weights_70_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 11, 4, 0, -7},
    {-4, 2, 4, 6, -7},
    {-4, 1, 11, 12, -1},
    {4, 11, 6, 9, 9},
    {10, -2, 2, 5, -1}};
static const WDATA_T conv3_weights_70_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -36, -40, -11, -4},
    {0, -6, -13, 0, -6},
    {5, 8, -7, 8, 1},
    {2, 1, 9, 10, 1},
    {7, 8, 19, 7, 7}};
static const WDATA_T conv3_weights_70_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 27, 37, 18, 5},
    {-1, 8, -2, 13, 6},
    {-2, -4, -6, 14, -2},
    {23, 16, 13, 1, -9},
    {2, -7, 5, 2, -9}};
static const WDATA_T conv3_weights_70_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 17, 11, -2, 2},
    {1, 1, 6, 20, 1},
    {-4, -20, 15, 18, 2},
    {4, -4, 8, -8, -11},
    {0, 9, 7, -4, -2}};
static const WDATA_T conv3_weights_70_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -10, 9, 9, 5},
    {-24, -30, -24, -6, -14},
    {-13, -1, 12, 4, -2},
    {4, 19, -7, 2, -3},
    {15, -5, -8, -2, 5}};
static const WDATA_T conv3_weights_70_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -18, -11, -10, -3},
    {-10, -29, 0, -1, -17},
    {-9, -11, -16, -25, 0},
    {-14, -8, 4, 11, 7},
    {23, 36, 39, 22, 3}};
static const WDATA_T conv3_weights_70_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, 0, -2, 0},
    {-3, 3, 1, -3, 0},
    {-2, 1, 1, 1, -1},
    {-2, 1, 0, 0, 4},
    {-4, 0, 0, -4, -2}};
static const WDATA_T conv3_weights_70_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, 6, 2, 3},
    {4, -1, 3, 4, 5},
    {0, -1, 1, 3, 0},
    {0, 1, 2, -4, 2},
    {-5, 3, 2, 2, 2}};
static const WDATA_T conv3_weights_70_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -10, -12, -21, -7},
    {-11, 28, 23, 6, -3},
    {-3, 16, 19, 5, -2},
    {21, 32, 20, -3, -7},
    {30, 2, 9, 1, -1}};
static const WDATA_T conv3_weights_70_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -21, -16, -13, -8},
    {13, 17, 6, -15, -20},
    {-7, 18, 23, 7, -5},
    {-6, 4, 27, 6, -14},
    {-10, 3, 1, 0, 0}};
static const WDATA_T conv3_weights_70_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 5, -11, -5},
    {5, 20, 31, 11, -6},
    {-4, -18, -14, -6, -3},
    {-17, -27, -17, -3, 1},
    {4, 22, 12, 21, 8}};
static const WDATA_T conv3_weights_70_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 10, 9, 2, 9},
    {16, 10, -1, -4, 2},
    {10, -11, 1, 11, -19},
    {25, 3, 10, -4, -23},
    {2, 7, 6, -2, 4}};
static const WDATA_T conv3_weights_71_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -22, 2, 5, -3},
    {-11, -20, 0, -12, -7},
    {-5, -18, -19, -15, -4},
    {-9, -9, -5, -16, -4},
    {3, -4, -10, -8, -4}};
static const WDATA_T conv3_weights_71_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -10, -8, -10, 4},
    {2, 3, -15, 1, 0},
    {4, -6, -15, -14, -11},
    {7, 7, -11, -8, -14},
    {0, 2, 5, -8, -5}};
static const WDATA_T conv3_weights_71_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 5, -14, 14, 8},
    {1, 4, -17, 10, -4},
    {3, -11, -12, -6, -5},
    {13, 2, 0, -1, -5},
    {4, 3, -1, -3, -4}};
static const WDATA_T conv3_weights_71_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, -6, -5, -4},
    {-7, -10, -7, -6, 10},
    {-7, -10, -14, -14, 4},
    {-7, -6, 0, 4, 3},
    {-7, -2, -1, 0, -13}};
static const WDATA_T conv3_weights_71_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -9, 0, -4, -3},
    {-4, -2, 5, -2, -6},
    {0, 6, 8, 7, 3},
    {1, 8, 6, 0, -1},
    {1, -1, -4, -3, -5}};
static const WDATA_T conv3_weights_71_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -18, -36, 0, -3},
    {2, -5, -24, -8, -5},
    {4, -5, -16, -12, -12},
    {5, 0, -6, -12, -17},
    {3, 7, 0, -5, -17}};
static const WDATA_T conv3_weights_71_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, 16, 23, 10, 2},
    {4, 20, -3, 5, 6},
    {4, 9, -18, 0, 2},
    {7, -1, 3, 6, 1},
    {-7, -8, 5, 7, 0}};
static const WDATA_T conv3_weights_71_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -1, 0, -18, -3},
    {-3, -9, -3, 7, 7},
    {-3, -8, 5, 14, 5},
    {-1, -5, 3, 16, 9},
    {-6, 1, 21, 3, 1}};
static const WDATA_T conv3_weights_71_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, 3, 9, 13, -3},
    {-9, -3, -8, -2, -8},
    {-2, -7, -24, -2, -3},
    {-4, -1, -3, 3, -5},
    {-7, -8, -2, 8, 1}};
static const WDATA_T conv3_weights_71_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-21, -29, -7, 8, -2},
    {-16, -23, -1, 4, 1},
    {-8, 8, 17, -11, -14},
    {-6, 4, 12, -4, -15},
    {7, 10, 9, -15, -10}};
static const WDATA_T conv3_weights_71_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 1, -2, 0},
    {1, 1, 4, 1, -1},
    {4, 0, 4, 1, 0},
    {-1, -2, -3, -2, 0},
    {-4, 1, 0, -2, -2}};
static const WDATA_T conv3_weights_71_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -2, -2, 0},
    {-3, -3, -4, -2, 0},
    {-2, -1, 1, -2, 0},
    {-1, 1, 0, 3, 2},
    {2, -1, -3, -1, 0}};
static const WDATA_T conv3_weights_71_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, 8, 3, 0, -3},
    {-10, 24, 13, 4, -4},
    {4, 8, -9, 2, -2},
    {14, 15, 0, -6, 1},
    {5, 4, -4, 1, 1}};
static const WDATA_T conv3_weights_71_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -4, 3, -1, -3},
    {-13, -10, -3, 2, -4},
    {-8, -10, -8, -5, -8},
    {1, 0, -2, -6, -9},
    {-1, -2, -2, 3, 1}};
static const WDATA_T conv3_weights_71_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -18, -13, -2, -3},
    {-7, -9, -8, -10, -7},
    {-6, -12, -13, -20, -16},
    {1, -13, -20, -6, -12},
    {13, 19, 7, -12, -12}};
static const WDATA_T conv3_weights_71_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 10, 14, 1, -1},
    {16, 10, 13, 10, -4},
    {9, 3, 5, 21, 9},
    {2, -3, -2, 14, 21},
    {-1, 3, -1, 21, 2}};
static const WDATA_T conv3_weights_72_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -15, -2, 6, -1},
    {-9, 9, 6, -2, 3},
    {-31, -14, 16, 15, 11},
    {-16, -24, 12, -4, 0},
    {-22, 19, 17, -18, -15}};
static const WDATA_T conv3_weights_72_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 15, 9, -2, -1},
    {4, 4, 11, 12, -15},
    {1, 12, 15, 22, 10},
    {-3, -10, 10, 38, 24},
    {-9, -14, 6, 28, 25}};
static const WDATA_T conv3_weights_72_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, -1, -4, 15, -1},
    {-1, -2, -16, -9, -7},
    {-8, 7, 2, 12, 7},
    {-1, -5, 18, 1, 15},
    {9, 3, 1, -13, 31}};
static const WDATA_T conv3_weights_72_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 3, -2, 8},
    {-4, 2, 17, 30, 17},
    {0, -2, 19, 12, 11},
    {-4, -21, -35, -18, -2},
    {-5, -19, -28, -19, -28}};
static const WDATA_T conv3_weights_72_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, 10, 4, 2},
    {11, 2, 8, 12, -1},
    {19, 15, -2, 8, 1},
    {10, 15, -7, 6, 4},
    {13, 1, 2, 12, 5}};
static const WDATA_T conv3_weights_72_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -7, 5, 13, 11},
    {11, -3, -5, 9, -4},
    {-2, -4, 2, 5, 4},
    {-2, -25, -2, 21, 18},
    {5, -10, -25, -3, 13}};
static const WDATA_T conv3_weights_72_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -10, 3, 0, -3},
    {-7, -3, 8, 11, 11},
    {-13, 38, 24, 8, 3},
    {25, 14, 11, -1, -9},
    {-9, -31, -6, 3, -9}};
static const WDATA_T conv3_weights_72_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -6, 18, 17, 7},
    {-7, -2, 12, 3, 8},
    {-9, 31, 8, -1, -2},
    {-5, 28, 5, -3, 6},
    {-1, 18, 24, 19, 29}};
static const WDATA_T conv3_weights_72_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 1, -8, 8, 1},
    {15, 25, 3, -1, 5},
    {8, 7, -4, 9, -10},
    {28, -2, -40, -22, -11},
    {23, -25, -35, -1, -15}};
static const WDATA_T conv3_weights_72_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, 11, 16, 2, 3},
    {8, 21, -2, -31, -1},
    {1, -4, 3, -6, -5},
    {-14, -4, 4, -28, -42},
    {7, -12, 26, 33, 11}};
static const WDATA_T conv3_weights_72_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -1, 4, 0},
    {1, -2, 0, -2, -2},
    {-1, 2, 2, 0, 4},
    {1, 0, 0, -2, 5},
    {-1, -1, -2, -2, -5}};
static const WDATA_T conv3_weights_72_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, 1, 0},
    {-2, 0, 0, 3, 0},
    {9, 11, 6, -4, 3},
    {-1, 7, 6, 0, 0},
    {0, 0, 0, -10, -6}};
static const WDATA_T conv3_weights_72_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 3, 10, 18, -5},
    {-12, 0, -8, 7, 8},
    {-14, 6, -22, -5, 0},
    {14, 1, -12, -12, -12},
    {25, 1, 22, 3, -11}};
static const WDATA_T conv3_weights_72_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 31, 20, 12, 6},
    {-5, -3, 2, -4, 2},
    {10, -7, -5, 6, -5},
    {5, -11, -16, -19, -20},
    {-15, 10, 8, 4, -7}};
static const WDATA_T conv3_weights_72_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 1, 10, -2, 5},
    {-2, -35, -26, -9, -12},
    {-9, -27, -49, -19, -10},
    {-44, -44, -31, -6, -20},
    {-12, -14, 18, 13, -22}};
static const WDATA_T conv3_weights_72_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 10, 12, 5, 16},
    {0, 2, -2, 3, 19},
    {-5, 2, 5, 22, 19},
    {8, 14, 9, -22, -11},
    {2, 20, 0, -25, 27}};
static const WDATA_T conv3_weights_73_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {35, 58, 31, -1, 10},
    {25, 34, -19, -36, -11},
    {23, 26, -48, -32, -2},
    {27, 18, -5, 13, 8},
    {-3, 10, 29, 37, 20}};
static const WDATA_T conv3_weights_73_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 26, 30, 6, -17},
    {21, 18, 41, -40, -22},
    {-10, 1, 46, -9, -44},
    {-38, -24, -18, -35, -43},
    {-18, -18, -24, -18, -21}};
static const WDATA_T conv3_weights_73_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, -18, 10, 30, 21},
    {10, -17, 13, 54, 24},
    {-21, -36, 4, 27, 4},
    {-20, -4, 15, 24, 6},
    {6, -4, 5, 0, -13}};
static const WDATA_T conv3_weights_73_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 2, -5, -3},
    {10, 11, 26, -10, -17},
    {-16, 12, 8, -51, -8},
    {-2, 38, -1, -46, 19},
    {20, 34, 0, 34, 67}};
static const WDATA_T conv3_weights_73_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 15, 5, 4, 6},
    {21, 23, 15, 28, -8},
    {27, 18, 28, 19, 8},
    {18, 15, 37, 19, -5},
    {5, 23, 29, -2, 0}};
static const WDATA_T conv3_weights_73_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 10, 17, 42, 20},
    {6, 28, 39, 35, 8},
    {-2, 15, 23, 20, -15},
    {-18, -7, 10, -15, -13},
    {-14, -19, 20, 8, 6}};
static const WDATA_T conv3_weights_73_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {25, 1, 3, -6, -6},
    {23, 7, -34, -2, 10},
    {36, 3, -26, -3, 15},
    {37, 28, -5, 7, 16},
    {18, -13, -9, -21, 7}};
static const WDATA_T conv3_weights_73_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-22, -19, -4, 30, 29},
    {-38, -4, 20, 25, 40},
    {-6, -17, 8, 27, -6},
    {4, -6, 21, -18, -21},
    {3, 13, -4, -30, -52}};
static const WDATA_T conv3_weights_73_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 2, -3, 8, -3},
    {-35, -52, -4, 5, -4},
    {-31, -15, -34, 3, -7},
    {9, -5, -3, 19, 41},
    {-11, -32, -18, -10, 13}};
static const WDATA_T conv3_weights_73_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 21, 32, 1, 13},
    {17, -20, -4, -27, -12},
    {43, 23, -58, -5, 44},
    {51, 30, -34, -2, 8},
    {24, -21, -23, -14, -24}};
static const WDATA_T conv3_weights_73_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -1, 1, -1},
    {3, 4, 2, -1, 3},
    {0, -3, 2, 0, 5},
    {0, -3, 0, 0, -2},
    {1, 2, -1, -1, -1}};
static const WDATA_T conv3_weights_73_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 4, 8, 4, -10},
    {1, 13, 9, -6, -8},
    {0, 0, 0, -8, 0},
    {3, -2, -13, 0, 7},
    {9, -1, 7, 17, 5}};
static const WDATA_T conv3_weights_73_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {38, 8, -3, 7, -1},
    {41, 24, 39, 31, 4},
    {13, 8, 47, 15, 25},
    {8, 14, 34, 35, 49},
    {20, 24, 17, 23, 21}};
static const WDATA_T conv3_weights_73_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, -3, -10, 1, -28},
    {16, 3, -3, -6, -50},
    {-33, -37, 7, 13, 12},
    {-46, -54, 2, 22, 18},
    {-58, -36, 4, 23, 25}};
static const WDATA_T conv3_weights_73_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 11, 12, 1, -3},
    {18, 69, 29, -4, 24},
    {7, 22, -27, -30, 18},
    {-14, -15, -31, -30, 32},
    {5, 11, 24, 36, 61}};
static const WDATA_T conv3_weights_73_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, -15, -40, -64, -48},
    {-7, -8, -52, -24, -49},
    {22, -1, 8, 9, 48},
    {32, 19, 49, 20, 1},
    {-7, 8, 27, 0, -50}};
static const WDATA_T conv3_weights_74_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 23, 31, 15, 2},
    {2, 12, 6, 8, -4},
    {8, 6, 4, -9, -10},
    {8, 23, 0, -11, -7},
    {-6, -7, -6, -5, 2}};
static const WDATA_T conv3_weights_74_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -15, -13, 1, 23},
    {-13, -9, -2, -5, 0},
    {-1, -9, -3, 6, -13},
    {15, -5, 1, 0, 0},
    {2, 6, 1, -10, -1}};
static const WDATA_T conv3_weights_74_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -22, -26, -24, -20},
    {1, -23, -17, -25, -11},
    {2, -1, -6, -6, 0},
    {2, 1, -3, 4, 15},
    {0, -3, 0, 20, 17}};
static const WDATA_T conv3_weights_74_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, -1, -3, -7},
    {-4, 4, 17, 8, 6},
    {-11, 3, -5, -6, 10},
    {-6, -4, 2, 14, -6},
    {4, 1, -6, -24, -22}};
static const WDATA_T conv3_weights_74_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -2, -7, -8, -2},
    {8, 0, -6, -6, 2},
    {5, -5, -1, 0, -1},
    {-3, 0, 9, -4, -7},
    {1, 8, 8, -2, -2}};
static const WDATA_T conv3_weights_74_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, 7, 10, 5},
    {-2, -3, 2, 8, 8},
    {-4, -1, -11, -3, -15},
    {5, 9, 2, -7, -4},
    {1, -5, 7, 1, -3}};
static const WDATA_T conv3_weights_74_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 7, -2, -16, -8},
    {-2, -4, -4, -1, -2},
    {-8, -23, -10, 7, -3},
    {-4, -7, 2, 2, 2},
    {13, 24, 15, -1, -3}};
static const WDATA_T conv3_weights_74_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -5, -20, -17, -15},
    {-10, -7, -6, 7, -3},
    {-4, 4, 7, 21, 6},
    {4, -11, 15, 10, 9},
    {3, -11, -9, -2, 14}};
static const WDATA_T conv3_weights_74_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 9, 14, 7, 1},
    {-17, -24, -36, 1, 20},
    {-27, -46, -26, 4, 19},
    {-6, 6, 10, -11, 0},
    {7, 18, 12, -10, -7}};
static const WDATA_T conv3_weights_74_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 3, 22, 7, 1},
    {5, -6, -1, 38, 25},
    {-27, -16, 15, 11, -6},
    {-13, 3, -2, -5, -6},
    {-17, -4, 1, 1, -6}};
static const WDATA_T conv3_weights_74_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -2, 2, 2},
    {2, 0, 2, 3, -1},
    {1, 3, 0, 2, 1},
    {2, 4, 1, -1, -3},
    {2, -1, 1, -5, -1}};
static const WDATA_T conv3_weights_74_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 2, 0, 1},
    {0, 2, -1, 1, 2},
    {-1, -5, 2, 2, -1},
    {-7, -3, 5, -2, 4},
    {-3, 1, 2, -2, -4}};
static const WDATA_T conv3_weights_74_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -15, -16, -2, 5},
    {-1, -5, -43, -12, -11},
    {-6, 7, -12, 7, -1},
    {-12, -17, 11, 9, -2},
    {-6, -14, 13, 8, 2}};
static const WDATA_T conv3_weights_74_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -15, 2, 4, 0},
    {-30, -43, -14, -4, 3},
    {25, 16, 8, -3, 4},
    {6, 12, -1, -5, -2},
    {10, 0, -5, -6, 1}};
static const WDATA_T conv3_weights_74_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -13, -6, 1, 4},
    {21, 12, 9, 7, 15},
    {24, 30, 4, -12, -4},
    {1, 9, -6, -21, -10},
    {-5, 13, -3, -20, -23}};
static const WDATA_T conv3_weights_74_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, -19, -9, -15},
    {-4, -5, -37, -25, -28},
    {-3, 11, 2, 13, -5},
    {-6, 11, -15, -4, -6},
    {4, -7, 7, 35, 11}};
static const WDATA_T conv3_weights_75_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, 9, 5, 0},
    {-1, 4, 6, 0, 0},
    {-4, 1, 2, -2, 4},
    {-1, -6, 4, -3, -6},
    {4, 1, 2, -2, -4}};
static const WDATA_T conv3_weights_75_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -5, -6, 0},
    {-1, -1, 0, -8, 10},
    {9, 10, -6, -12, -9},
    {5, 3, 2, -6, -11},
    {2, -4, -2, 5, -6}};
static const WDATA_T conv3_weights_75_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 3, -2, 2, 4},
    {-1, 3, -5, -5, 0},
    {2, 3, -6, 0, -4},
    {5, -1, -2, -3, -8},
    {-1, -1, -4, -2, -3}};
static const WDATA_T conv3_weights_75_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 0, 0, 1},
    {2, -1, -7, -3, -4},
    {4, 4, 1, 3, -3},
    {3, -6, -8, 6, 13},
    {-4, -1, -1, 15, 6}};
static const WDATA_T conv3_weights_75_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 0, 0, 1},
    {-1, 1, -1, 1, 3},
    {-5, 1, 2, 6, 3},
    {0, 3, 1, -1, 0},
    {-4, -3, 0, 1, 1}};
static const WDATA_T conv3_weights_75_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -3, -5, 2},
    {-1, -3, -6, -4, -3},
    {5, 0, -1, 0, -8},
    {9, 5, 0, 2, -10},
    {4, 6, -5, 4, -4}};
static const WDATA_T conv3_weights_75_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -4, -3, -5, -2},
    {-9, 5, 7, 1, 2},
    {-10, 4, 0, -3, -1},
    {-4, -2, -3, -1, 5},
    {-4, 0, -1, 4, 3}};
static const WDATA_T conv3_weights_75_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -5, 0, -1, 3},
    {-1, -3, -8, -6, 5},
    {3, 2, -9, -15, 4},
    {-1, -3, 3, -4, 5},
    {-3, -3, 12, 10, -3}};
static const WDATA_T conv3_weights_75_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, 4, 3, -2},
    {-6, -6, -1, 10, 0},
    {-6, -4, 12, 8, -1},
    {-2, -10, -17, -4, -4},
    {-2, 2, 4, 0, 2}};
static const WDATA_T conv3_weights_75_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -5, -5, -1},
    {-5, -10, -11, 5, 8},
    {-7, -22, -1, 9, 8},
    {-2, 8, 11, 0, -7},
    {9, 11, -4, -9, -3}};
static const WDATA_T conv3_weights_75_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 1, -1, -2},
    {0, 1, -1, -3, -1},
    {0, 0, 1, -1, -2},
    {0, 0, -3, 3, -3},
    {2, 2, 2, 0, 0}};
static const WDATA_T conv3_weights_75_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, -1, -1, 0},
    {-3, -1, 1, -1, 1},
    {1, 0, 1, 3, 5},
    {-5, -1, 3, 0, 0},
    {1, 0, 4, 3, 2}};
static const WDATA_T conv3_weights_75_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -9, 5, 1, -2},
    {-4, 2, -4, 0, -6},
    {1, 7, -7, -3, -6},
    {7, 17, 2, -1, -5},
    {1, 1, -1, -1, 3}};
static const WDATA_T conv3_weights_75_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 0, 14, 7, 0},
    {1, -2, 12, 4, -3},
    {-9, 0, 6, -1, -4},
    {-1, 1, -1, 4, -5},
    {7, 4, 5, 1, -2}};
static const WDATA_T conv3_weights_75_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 1, 10, 8},
    {-2, -7, -5, -1, 0},
    {-3, -9, -11, -7, -1},
    {6, 3, 8, -3, -4},
    {6, 0, 5, -2, -9}};
static const WDATA_T conv3_weights_75_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 3, 1, 0, 0},
    {2, 2, 1, -2, -3},
    {6, -2, -4, -7, 4},
    {3, 0, -6, 0, -1},
    {-2, -2, 1, 0, 2}};
static const WDATA_T conv3_weights_76_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 4, 0, 3, 5},
    {2, 4, 6, 4, -2},
    {-6, -4, -2, -1, -4},
    {-2, -11, -9, -1, -2},
    {-10, -10, -9, -4, 0}};
static const WDATA_T conv3_weights_76_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 3, 4, 2},
    {-4, 0, 1, -5, 2},
    {1, 9, 10, 7, 1},
    {1, -5, -7, -6, -5},
    {0, -5, -7, -12, -3}};
static const WDATA_T conv3_weights_76_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, -4, -2, -3},
    {0, -7, -5, -2, -6},
    {0, -4, -4, -9, -9},
    {1, -4, 4, -4, -5},
    {-1, -6, -2, -1, -6}};
static const WDATA_T conv3_weights_76_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 0, -6, -2},
    {-1, -2, 0, -7, 0},
    {6, -2, -1, 6, 12},
    {-9, -12, -10, -7, -2},
    {-6, -10, 13, 14, 6}};
static const WDATA_T conv3_weights_76_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -1, 0, -1},
    {2, 4, 2, -2, 1},
    {1, 0, -3, 2, -2},
    {-3, 1, -1, -2, -2},
    {-1, 4, 2, 3, 0}};
static const WDATA_T conv3_weights_76_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 12, 11, 10, 6},
    {-4, -2, -11, -2, -3},
    {-4, 3, 5, 4, 2},
    {-7, -6, 0, -5, -5},
    {-3, -7, -6, -7, -11}};
static const WDATA_T conv3_weights_76_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, -4, -6, -1},
    {-7, -7, -5, -2, 1},
    {-13, 1, -2, -1, 5},
    {-2, -2, -8, 1, 8},
    {12, -4, 3, 4, 7}};
static const WDATA_T conv3_weights_76_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -8, -3, -9},
    {1, -2, -1, -6, -1},
    {1, 0, 2, -8, 3},
    {2, -1, 2, -1, 0},
    {-2, 4, 18, 19, 2}};
static const WDATA_T conv3_weights_76_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -4, 1, -2},
    {3, 4, -1, -1, -1},
    {7, 12, 6, 1, -3},
    {3, -2, -5, 2, 2},
    {18, 2, -8, -8, -5}};
static const WDATA_T conv3_weights_76_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, -3, 8, 16},
    {-5, 0, -3, 1, 8},
    {-9, -5, -7, 4, 6},
    {-4, 2, -2, 2, -5},
    {3, 6, -9, -6, -13}};
static const WDATA_T conv3_weights_76_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 4, 1, 1},
    {2, 2, 1, 0, 2},
    {-7, -2, -3, 0, -1},
    {0, -1, 0, -1, 0},
    {0, 2, 0, -1, 2}};
static const WDATA_T conv3_weights_76_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, 1, -2},
    {3, -1, 2, 2, 3},
    {-1, 3, -2, 1, -2},
    {1, -2, -1, -1, 1},
    {2, -2, -3, -2, 1}};
static const WDATA_T conv3_weights_76_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 4, 2, 8, 0},
    {-7, 0, -7, -2, -1},
    {-6, 9, 2, -2, -3},
    {-1, 1, -7, -1, -1},
    {12, 7, -7, -2, -4}};
static const WDATA_T conv3_weights_76_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, -5, -3, -3},
    {8, 9, 8, 0, 1},
    {-6, -1, 1, 5, 0},
    {5, -6, -6, -4, -2},
    {-14, -7, -2, -12, -11}};
static const WDATA_T conv3_weights_76_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 4, 4, 4, 1},
    {3, 2, -3, 1, 1},
    {-6, -5, -3, -5, -3},
    {-19, -15, -6, -1, -2},
    {-20, -26, -21, -14, -8}};
static const WDATA_T conv3_weights_76_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -2, -4, -4, -1},
    {-1, -4, -7, 2, -3},
    {-4, -5, 0, 2, 2},
    {1, -3, -1, 12, 11},
    {-1, 2, 11, 3, 0}};
static const WDATA_T conv3_weights_77_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -7, -5, -3, 0},
    {1, -9, -1, -3, -5},
    {12, 8, -1, -8, -2},
    {7, 2, 3, 2, 4},
    {3, -5, 0, -1, 4}};
static const WDATA_T conv3_weights_77_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 11, 0, -10, -8},
    {4, -6, -3, -4, -3},
    {-1, 3, 10, 13, 7},
    {-3, -3, -1, -7, 1},
    {1, -4, -8, -7, -5}};
static const WDATA_T conv3_weights_77_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -2, -13, -1, 6},
    {1, -9, -8, 2, 6},
    {5, -8, -11, -7, 7},
    {2, 6, -1, -3, 4},
    {3, -1, -5, 3, -4}};
static const WDATA_T conv3_weights_77_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -1, 1, 3},
    {-5, -4, -11, -12, -3},
    {-8, -3, -3, -6, -4},
    {8, 8, -6, -11, -13},
    {10, 14, -13, -6, -4}};
static const WDATA_T conv3_weights_77_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -4, -1, 2, 1},
    {5, -1, -2, 0, 0},
    {0, 0, 1, 3, 0},
    {1, 0, 3, -1, 4},
    {-2, -3, 4, 0, 11}};
static const WDATA_T conv3_weights_77_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 0, 2, 3},
    {5, 1, -4, -6, -6},
    {5, 0, 1, 1, 4},
    {3, 9, 7, 7, 5},
    {-1, -3, -8, -3, -3}};
static const WDATA_T conv3_weights_77_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -1, -1, 5, 5},
    {8, 8, -8, 3, 4},
    {9, -3, 3, -3, -1},
    {-7, 3, -1, -9, -8},
    {-3, 7, 1, -3, -1}};
static const WDATA_T conv3_weights_77_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -2, -1, 4, 9},
    {9, -4, -6, 19, 8},
    {7, 0, 1, -5, -2},
    {-3, 4, -7, -13, 16},
    {2, -6, -2, 3, 10}};
static const WDATA_T conv3_weights_77_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 9, 15, 4, -2},
    {3, 2, -1, -8, -4},
    {-9, -10, -6, -8, -3},
    {-5, -3, -2, -3, -2},
    {1, 12, 10, 0, -12}};
static const WDATA_T conv3_weights_77_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -9, -1, 10, -3},
    {8, 21, 10, -11, -4},
    {12, 8, -15, -11, 4},
    {6, 3, 12, 13, -1},
    {2, -2, -1, -5, -9}};
static const WDATA_T conv3_weights_77_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 3, -1, -2, -3},
    {-2, 0, -1, 1, -3},
    {-2, 1, 1, 1, -1},
    {-3, 0, 5, -2, 0},
    {0, 1, 4, -1, -2}};
static const WDATA_T conv3_weights_77_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, -1, 1, 1},
    {0, -3, 0, -2, -4},
    {0, -2, -2, 0, 2},
    {1, 3, 0, 1, 1},
    {1, 2, 2, 4, 3}};
static const WDATA_T conv3_weights_77_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, 1, 12, 14, -6},
    {0, -7, -6, 11, -3},
    {-4, -10, -2, 8, 4},
    {7, 1, -8, 1, 2},
    {-7, 2, -8, -4, 1}};
static const WDATA_T conv3_weights_77_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, 0, 0, -13},
    {-10, 5, 9, 4, -3},
    {-9, 2, 1, -1, -2},
    {-1, 0, -5, -2, -1},
    {9, 4, 0, 6, 3}};
static const WDATA_T conv3_weights_77_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -8, -4, -7, -5},
    {-6, -12, -9, 1, 4},
    {7, -3, -17, -11, 1},
    {21, 22, 8, -11, 3},
    {6, 5, 4, -5, 3}};
static const WDATA_T conv3_weights_77_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, 0, -5, -7},
    {5, 8, -3, 4, -7},
    {5, 12, 1, -10, -3},
    {0, 2, -13, -15, 10},
    {0, 4, -10, 10, 8}};
static const WDATA_T conv3_weights_78_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -16, -3, -2, 0},
    {-7, -19, -12, -1, 8},
    {3, -17, -12, -3, 5},
    {-9, -26, -13, -11, -4},
    {1, -8, -10, -7, -3}};
static const WDATA_T conv3_weights_78_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, 6, -4, 8},
    {7, 0, 5, 8, -4},
    {-1, 0, -17, -3, 17},
    {5, 3, 2, -19, -2},
    {-3, -7, -6, -7, -5}};
static const WDATA_T conv3_weights_78_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 5, 3, 10, 12},
    {-5, -3, -10, -2, -1},
    {-6, -17, -28, -15, -1},
    {6, -9, -17, -15, -7},
    {-1, -11, -12, -15, -2}};
static const WDATA_T conv3_weights_78_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 0, -3, 0},
    {-9, -16, -20, -19, -10},
    {-10, -9, -16, -19, 8},
    {-2, -6, -5, -7, 17},
    {3, -6, -9, 4, 7}};
static const WDATA_T conv3_weights_78_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -13, -6, -8, 0},
    {-6, -11, -6, -4, -3},
    {-2, -3, -3, -3, 0},
    {-3, -4, -9, -13, -3},
    {-4, -9, -20, -11, 4}};
static const WDATA_T conv3_weights_78_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 6, 4, 6, 13},
    {3, 2, -6, -2, -4},
    {5, -7, -22, -11, 10},
    {0, 0, 2, -14, -3},
    {-2, -4, -10, -18, -6}};
static const WDATA_T conv3_weights_78_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 1, -4, 7, -5},
    {-1, 4, -8, -6, -4},
    {-15, -2, -8, -9, -2},
    {-9, 3, -4, -8, 5},
    {-7, -9, 0, 8, 7}};
static const WDATA_T conv3_weights_78_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -7, -8, -5, 7},
    {-1, 2, 8, 10, 8},
    {-3, -1, 3, 21, 16},
    {-1, 3, 9, 8, 41},
    {-4, -4, 23, 26, 42}};
static const WDATA_T conv3_weights_78_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, -5, -8, 4, 0},
    {-12, -20, -4, 0, -7},
    {-5, -2, -2, -6, -4},
    {11, -3, -13, -3, 0},
    {23, 9, -2, 3, 0}};
static const WDATA_T conv3_weights_78_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -9, -19, -3, 8},
    {-2, -7, -9, -7, 8},
    {-3, -13, -15, -7, -2},
    {-2, 10, 12, 0, -2},
    {32, 34, -1, 5, 8}};
static const WDATA_T conv3_weights_78_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -4, -2, 1},
    {5, -1, -2, 2, -1},
    {2, 3, 1, 0, 1},
    {2, 0, -3, 1, 1},
    {0, 1, 1, -2, -1}};
static const WDATA_T conv3_weights_78_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -4, -1, 0, -8},
    {3, -2, -1, -1, -3},
    {-1, 0, -4, 0, 0},
    {1, -1, -3, -1, -2},
    {1, 1, 3, 2, 1}};
static const WDATA_T conv3_weights_78_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 9, 7, 8, -2},
    {20, 9, 5, 7, 1},
    {4, -11, -16, -12, -6},
    {18, 15, 4, -4, -5},
    {5, 0, -12, -3, -1}};
static const WDATA_T conv3_weights_78_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -7, -1, 2, -9},
    {6, -8, -19, -9, -4},
    {-2, -11, -9, -9, -3},
    {-10, -15, 2, -6, -8},
    {7, 2, -6, 5, -1}};
static const WDATA_T conv3_weights_78_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -10, -17, -14, -2},
    {5, 4, -3, -1, -6},
    {-1, -10, -26, -7, 2},
    {14, 14, -2, -8, 0},
    {8, 26, 29, 25, 9}};
static const WDATA_T conv3_weights_78_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 3, 3, -11, -6},
    {6, 2, -16, -26, 11},
    {0, -5, -19, -21, -1},
    {4, -5, -34, -10, 16},
    {-4, 3, 2, -6, 19}};
static const WDATA_T conv3_weights_79_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -1, 0, 2, 1},
    {5, 1, 3, 8, -2},
    {15, -4, -4, 4, 3},
    {4, -3, 5, -1, 2},
    {-1, -3, 2, 5, 5}};
static const WDATA_T conv3_weights_79_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 7, -3, -10, -5},
    {5, -5, 3, -14, -16},
    {-2, -7, -7, 1, -2},
    {-2, -2, -10, -6, 1},
    {0, 1, -6, 0, 0}};
static const WDATA_T conv3_weights_79_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, 5, -12, 0},
    {-1, -2, 2, -9, 1},
    {-1, -9, -3, -11, -13},
    {-2, 10, 3, 7, -7},
    {2, 4, 7, 6, -1}};
static const WDATA_T conv3_weights_79_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -1, -2, -3},
    {-4, -7, -7, -4, -5},
    {-5, -8, -1, 6, 9},
    {-4, 7, 11, 5, -2},
    {22, 20, 7, 6, -12}};
static const WDATA_T conv3_weights_79_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 7, 7, 7, -1},
    {1, 9, 11, 4, -1},
    {4, 12, 14, 7, 5},
    {6, 13, 11, 0, 4},
    {3, 5, -1, 0, 1}};
static const WDATA_T conv3_weights_79_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -7, -13, -15, -10},
    {4, 4, 3, 3, -4},
    {3, -3, -14, 4, -7},
    {8, 3, -11, -4, -2},
    {0, -2, -2, 0, 6}};
static const WDATA_T conv3_weights_79_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 6, 16, 5, -3},
    {0, 7, 8, -1, 5},
    {-11, 2, 6, 4, 9},
    {-6, 3, 7, 8, -3},
    {4, 11, 3, 3, -7}};
static const WDATA_T conv3_weights_79_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, -9, -13, 5},
    {-5, 1, 0, -13, 2},
    {-1, -5, 10, 2, 2},
    {-2, 3, 9, -1, -1},
    {0, 6, -4, -10, -4}};
static const WDATA_T conv3_weights_79_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 7, 12, 6, -1},
    {8, 11, 8, 4, 0},
    {-7, 12, 8, 6, -2},
    {6, 13, 0, 4, -3},
    {12, 10, 14, 12, 2}};
static const WDATA_T conv3_weights_79_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -6, 4, 18, 14},
    {11, 15, 15, 11, 1},
    {11, 19, 8, -6, -6},
    {4, 30, 14, 0, -6},
    {4, 0, -15, -2, -6}};
static const WDATA_T conv3_weights_79_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, 0, 3, 3},
    {-4, -1, 1, -1, 5},
    {0, 0, 1, 2, 0},
    {0, -2, 1, -2, 1},
    {1, 0, 0, -2, 0}};
static const WDATA_T conv3_weights_79_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 0, 1, 2},
    {1, -2, 6, 4, 1},
    {-1, 1, 8, 0, 3},
    {0, 1, 1, 1, 1},
    {-1, 4, 6, 3, -1}};
static const WDATA_T conv3_weights_79_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, 3, 6, 1, 1},
    {-4, 5, -5, -1, 8},
    {-12, -7, -17, -14, -1},
    {-8, 0, -4, -4, 2},
    {-2, -3, -6, 2, 8}};
static const WDATA_T conv3_weights_79_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 4, 2, 6},
    {3, -2, -6, 2, 4},
    {5, 8, -3, -2, -3},
    {-6, -7, 5, 2, 5},
    {2, 0, 3, 11, 4}};
static const WDATA_T conv3_weights_79_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -12, -14, -8, -1},
    {-7, -4, 2, 4, 2},
    {-1, -15, -7, -2, 1},
    {16, 2, -9, 4, 6},
    {-4, -8, -9, 1, 2}};
static const WDATA_T conv3_weights_79_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 11, 11, 6, 5},
    {-5, 6, 1, 7, 14},
    {9, 0, 11, 13, -3},
    {6, 3, 18, 13, -15},
    {3, 8, 2, -12, -19}};
static const WDATA_T conv3_weights_80_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 28, 68, 31, 10},
    {-1, 14, 30, 26, 9},
    {-10, 20, 17, -8, -49},
    {13, -6, 14, -50, -34},
    {2, 9, -25, -59, -19}};
static const WDATA_T conv3_weights_80_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 21, 7, 11, 40},
    {-9, -25, -25, 4, 11},
    {6, 4, -28, 5, 36},
    {0, 7, -5, 10, -3},
    {24, 10, 3, 6, -6}};
static const WDATA_T conv3_weights_80_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, -30, -46, -29, -13},
    {-2, -25, -66, -63, -16},
    {26, 33, -9, -12, 1},
    {27, 32, 0, 29, 2},
    {-12, 9, 7, 29, 12}};
static const WDATA_T conv3_weights_80_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, 0, 0, 15},
    {-8, -18, -24, 14, 23},
    {-9, -20, 1, 38, 37},
    {-5, -22, 32, 31, -5},
    {-26, -29, 2, -3, -42}};
static const WDATA_T conv3_weights_80_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -2, 11, 6, -5},
    {19, 23, -6, -12, 3},
    {22, 20, -9, 8, 9},
    {-1, 9, 4, 4, 2},
    {-3, 3, 8, 11, 9}};
static const WDATA_T conv3_weights_80_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 15, -2, -1, 12},
    {7, -9, -27, 1, 13},
    {7, 1, -47, -19, 23},
    {-2, 1, -18, 14, 0},
    {1, 10, -32, -12, -40}};
static const WDATA_T conv3_weights_80_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, -2, -5, -35, -22},
    {-7, -2, -2, -20, -2},
    {-21, -11, 15, -8, 1},
    {-18, -15, 1, 3, 4},
    {9, -2, 22, 39, 19}};
static const WDATA_T conv3_weights_80_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -26, -39, -20, -16},
    {-21, -13, 1, -7, -1},
    {-13, 11, 10, 16, 51},
    {8, 13, -10, 38, 56},
    {6, -16, -5, 7, 28}};
static const WDATA_T conv3_weights_80_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 17, 6, 8, -3},
    {-5, -16, -12, -4, 13},
    {-29, -31, -15, 7, 16},
    {-25, 8, 27, 25, -14},
    {-9, -7, -1, 28, 10}};
static const WDATA_T conv3_weights_80_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-22, -15, -16, 20, 1},
    {-7, -5, 13, 24, -9},
    {-41, 1, 48, 13, -21},
    {-21, 0, 23, 46, -23},
    {-19, 3, 24, 20, -14}};
static const WDATA_T conv3_weights_80_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 2, 2, 2},
    {1, 1, -2, -2, -3},
    {2, 1, -1, 1, 0},
    {6, -1, 2, -2, 1},
    {-2, 2, 3, 2, 2}};
static const WDATA_T conv3_weights_80_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -1, 2, 3},
    {-3, 1, 1, -1, 1},
    {7, 4, 7, 1, 3},
    {0, 1, 11, 4, 4},
    {2, 0, -9, -8, 8}};
static const WDATA_T conv3_weights_80_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 16, 18, 10, 9},
    {-25, -21, -76, -21, -4},
    {8, 13, -54, -12, -9},
    {2, -11, -9, -17, -20},
    {-11, -13, 20, -3, -17}};
static const WDATA_T conv3_weights_80_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 23, 15, -14, 7},
    {4, -25, -44, -23, 3},
    {-9, -30, -20, 0, -14},
    {22, 18, -18, -16, -43},
    {32, 23, 1, -12, -23}};
static const WDATA_T conv3_weights_80_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -20, -21, 11},
    {-6, -14, -17, 32, 27},
    {7, -14, -12, -18, -12},
    {9, 9, 15, -13, -36},
    {10, 8, 8, -43, -64}};
static const WDATA_T conv3_weights_80_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 18, -9, 26, -2},
    {-6, -11, -28, -11, -21},
    {-3, 24, 21, 3, -58},
    {2, 38, -22, -14, 46},
    {12, 11, 4, 19, 66}};
static const WDATA_T conv3_weights_81_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -26, -44, -17, 12},
    {-25, -21, -22, -21, -33},
    {12, 0, -13, -25, -17},
    {-10, -9, 4, -8, 7},
    {5, 7, -1, 14, 11}};
static const WDATA_T conv3_weights_81_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 13, 18, -11, 1},
    {-8, -18, -12, 21, 35},
    {-47, -26, 4, 1, -10},
    {-32, 3, -5, -16, -21},
    {-3, -5, -8, -32, -35}};
static const WDATA_T conv3_weights_81_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 20, 33, 13, 16},
    {13, 37, -3, 24, 0},
    {18, 19, 13, 5, -15},
    {6, 24, 2, 5, -6},
    {-1, 5, -5, -9, -6}};
static const WDATA_T conv3_weights_81_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -2, -8, -13},
    {-1, 18, 17, 6, -6},
    {0, 26, -1, -17, -59},
    {-13, -2, -13, -15, -38},
    {13, 20, 21, 23, 32}};
static const WDATA_T conv3_weights_81_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 7, 0, 18, -6},
    {19, 17, 5, 7, 6},
    {10, 15, 6, 7, 31},
    {7, 1, 6, 4, 31},
    {-2, -19, -1, -4, 14}};
static const WDATA_T conv3_weights_81_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 3, -11, -6, -18},
    {8, 2, -7, 24, 16},
    {-21, -28, -12, -35, -1},
    {-6, 3, 11, -7, -26},
    {-4, -5, 35, 3, -30}};
static const WDATA_T conv3_weights_81_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {29, 54, 46, 26, -1},
    {62, 44, 8, 4, 6},
    {5, 5, 5, 11, 10},
    {-30, -19, -2, 3, 4},
    {-28, -24, -7, 20, 12}};
static const WDATA_T conv3_weights_81_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 12, 24, -6, 33},
    {36, 10, 2, -5, 35},
    {38, 4, 16, -3, 5},
    {21, 31, 35, 2, -15},
    {18, -6, 5, -2, -14}};
static const WDATA_T conv3_weights_81_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 4, 6, 11, -14},
    {-8, -12, 14, -10, -30},
    {-27, -27, 13, -4, -10},
    {-72, -75, -15, -5, -38},
    {-43, -28, 4, 20, 25}};
static const WDATA_T conv3_weights_81_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 17, 9, 9, -12},
    {19, 16, -22, -42, -61},
    {-14, 25, -63, -52, 4},
    {-9, -13, -13, 10, 34},
    {-6, -5, -21, 4, 23}};
static const WDATA_T conv3_weights_81_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, -2, 0, -2},
    {-4, 0, 1, -3, 0},
    {0, 2, 0, 0, 0},
    {-6, -2, 2, 0, 1},
    {-1, 1, -1, -2, 3}};
static const WDATA_T conv3_weights_81_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 0, -2, 2, 5},
    {-8, -3, -2, 1, 1},
    {-3, -12, -2, -5, -4},
    {2, -3, 1, 1, 1},
    {-2, 3, 7, 11, 8}};
static const WDATA_T conv3_weights_81_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 37, 15, -6, -9},
    {25, 0, 5, 23, 7},
    {32, -10, -13, 4, 10},
    {14, 22, -10, 15, 19},
    {-12, 6, -14, 14, 5}};
static const WDATA_T conv3_weights_81_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -24, -6, 6, 10},
    {-79, -60, 0, 49, 6},
    {-117, -45, 13, 40, 18},
    {-43, -37, 33, 16, 1},
    {11, 15, 27, 17, 6}};
static const WDATA_T conv3_weights_81_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -6, -21, 2, 2},
    {-38, -38, -14, -6, 14},
    {-39, -67, -45, -42, -21},
    {29, 13, 5, 7, 1},
    {8, -3, 41, 55, 10}};
static const WDATA_T conv3_weights_81_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {39, 15, 38, 23, 5},
    {16, 31, 22, 6, -57},
    {30, 25, -2, -13, -7},
    {28, -4, -11, -7, 33},
    {3, 7, -4, -3, 32}};
static const WDATA_T conv3_weights_82_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, 0, 11, -3},
    {3, 1, 0, 3, 7},
    {-2, -7, -9, -4, 4},
    {-1, -4, -3, 1, 0},
    {1, -2, -6, -5, 1}};
static const WDATA_T conv3_weights_82_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, 4, -2, 0},
    {-6, -9, -9, -7, 2},
    {4, 2, 0, -6, 6},
    {3, 2, 1, 1, 3},
    {-1, 2, -3, 5, -1}};
static const WDATA_T conv3_weights_82_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 7, 1, 0, 4},
    {0, 1, 6, -2, 1},
    {-4, 5, 5, -6, -4},
    {0, -3, 3, -2, 2},
    {0, 0, 4, -2, 3}};
static const WDATA_T conv3_weights_82_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -5, 2, 0},
    {3, -1, -6, -17, -8},
    {1, 3, 6, 4, 7},
    {3, 4, 3, -2, -5},
    {1, 5, -1, -3, -7}};
static const WDATA_T conv3_weights_82_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 1, 4, 3},
    {-5, -3, -2, 1, -1},
    {2, -5, -1, -3, -4},
    {2, -4, -2, 2, -1},
    {3, 0, 0, -1, 3}};
static const WDATA_T conv3_weights_82_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 4, 1, -2, 4},
    {-3, -2, -11, -8, -3},
    {4, 2, -3, -5, 2},
    {-1, -3, -2, 1, -4},
    {1, -1, -3, 4, 0}};
static const WDATA_T conv3_weights_82_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 5, 4, 3, -1},
    {0, -2, -1, 0, 0},
    {-2, -2, 1, 2, 4},
    {2, 2, 1, -6, -4},
    {4, 3, 3, 0, 1}};
static const WDATA_T conv3_weights_82_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, -9, 4, -3},
    {-1, -1, -3, 4, 5},
    {-5, -5, 8, 4, 11},
    {-3, -3, 5, 2, 4},
    {0, 2, 0, -3, 5}};
static const WDATA_T conv3_weights_82_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, 3, 1, -2},
    {-4, -6, -1, -8, -10},
    {-3, 11, 8, 0, -5},
    {2, 4, 2, 1, -3},
    {4, 8, -2, 0, -1}};
static const WDATA_T conv3_weights_82_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -13, -7, 2, 6},
    {-1, -4, 3, -5, -4},
    {-1, -4, -2, -6, -2},
    {3, -1, -5, -3, -7},
    {-3, -2, 0, 0, 4}};
static const WDATA_T conv3_weights_82_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, 1, -1},
    {2, -1, -2, -3, -2},
    {1, -4, -4, 0, 3},
    {-3, 0, 1, -2, -2},
    {0, -1, -2, -3, -1}};
static const WDATA_T conv3_weights_82_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, 4, -3, 0},
    {-2, -1, 2, -1, 1},
    {-3, 0, 0, 0, -2},
    {3, 0, -3, -3, 2},
    {0, 2, -1, 5, 2}};
static const WDATA_T conv3_weights_82_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 3, 11, -3, 1},
    {5, 0, 0, -2, -2},
    {-1, 5, -2, 0, 2},
    {-2, 3, 2, 7, 1},
    {-1, 1, 4, 5, -3}};
static const WDATA_T conv3_weights_82_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -10, -10, -8, -3},
    {4, 7, -6, -13, -10},
    {10, -3, -1, -4, -5},
    {-5, -3, 2, 7, 1},
    {-3, -6, -1, 0, 1}};
static const WDATA_T conv3_weights_82_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 6, 1, -3},
    {10, 11, -1, 13, 13},
    {5, 6, -3, -1, 1},
    {-1, -5, -2, -2, -5},
    {3, 2, 2, -1, -6}};
static const WDATA_T conv3_weights_82_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, -4, -3, 12},
    {-2, -4, -1, -1, 13},
    {-3, -9, -4, -9, -14},
    {-1, 1, 3, -6, -3},
    {-2, -1, 2, -1, -9}};
static const WDATA_T conv3_weights_83_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -12, -8, 3, -2},
    {-7, -18, -12, -11, -5},
    {-12, -11, 2, -1, 1},
    {1, 1, 10, 9, 0},
    {-6, -5, 0, -2, -5}};
static const WDATA_T conv3_weights_83_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 12, 9, 4, 1},
    {-3, -4, 0, 15, 7},
    {-4, -11, -13, -11, -5},
    {-1, -4, 0, 6, 5},
    {-2, 3, 10, 11, 6}};
static const WDATA_T conv3_weights_83_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -6, -4, -6, -5},
    {-5, -7, -11, -7, -8},
    {-1, 5, -2, 4, 7},
    {3, 2, 1, 4, 5},
    {0, 1, 2, 2, 3}};
static const WDATA_T conv3_weights_83_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -1, -1, 5},
    {8, 11, 5, -3, -7},
    {1, 11, 6, -2, -16},
    {9, 1, -3, 3, 5},
    {-5, -2, 2, 1, 0}};
static const WDATA_T conv3_weights_83_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, -1, -3, -3},
    {-4, 0, 5, 2, -3},
    {1, -2, -1, -5, -2},
    {5, 0, -10, 0, 1},
    {1, -3, -3, -3, 0}};
static const WDATA_T conv3_weights_83_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 6, 12, 3, -6},
    {4, 3, 7, 10, 9},
    {-7, -8, -10, -1, -3},
    {-4, -7, -10, 3, -5},
    {0, 3, -4, 12, 14}};
static const WDATA_T conv3_weights_83_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -5, -5, -4, -3},
    {-6, 7, 9, -2, -3},
    {7, 27, 20, -2, -3},
    {9, 13, 2, 3, 0},
    {-4, 1, 1, -1, 0}};
static const WDATA_T conv3_weights_83_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -4, -4, 2, 2},
    {1, -3, -1, 1, 3},
    {1, 12, 2, 0, -1},
    {0, 6, -2, -9, -4},
    {-1, -8, -3, -5, -5}};
static const WDATA_T conv3_weights_83_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -8, -9, -3, 1},
    {-10, -11, -3, -3, 1},
    {17, 27, 10, -5, -4},
    {15, 7, -5, -3, 0},
    {-6, 1, 7, 3, -3}};
static const WDATA_T conv3_weights_83_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 0, -7, -16, -17},
    {13, 7, -4, -5, -4},
    {4, -1, 11, 11, 0},
    {3, 1, -1, -9, -9},
    {-7, -11, -17, 2, 7}};
static const WDATA_T conv3_weights_83_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -2, -1, 0},
    {-2, 0, 1, 6, 2},
    {2, 0, 0, 0, 2},
    {-4, -2, 0, -1, -1},
    {4, 0, -1, 2, -1}};
static const WDATA_T conv3_weights_83_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 1, -5, -1},
    {-4, -2, 0, 2, -3},
    {1, 0, 1, 3, 0},
    {0, 5, 6, 1, -1},
    {3, 3, 1, 0, -1}};
static const WDATA_T conv3_weights_83_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 4, 3, -1},
    {-4, -7, -9, 2, 4},
    {-7, 1, -7, 1, 1},
    {-8, -5, 0, -7, -8},
    {-9, 1, 6, 6, 3}};
static const WDATA_T conv3_weights_83_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 9, 13, 6},
    {-5, -12, 5, 3, -1},
    {-3, -18, -15, -10, -1},
    {9, 16, 8, 0, 3},
    {4, 11, -6, 3, 3}};
static const WDATA_T conv3_weights_83_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -1, 7, 6, -4},
    {4, -9, -4, 1, -7},
    {-2, -7, -4, 2, -2},
    {-10, -2, 10, 8, 2},
    {-1, -8, -8, -1, -11}};
static const WDATA_T conv3_weights_83_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -4, -8, -9},
    {2, 2, -1, -6, -13},
    {6, 20, 3, 11, 17},
    {-5, 14, 3, 4, -7},
    {-1, -1, -6, -17, -12}};
static const WDATA_T conv3_weights_84_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, 8, 5, 2},
    {3, 0, 11, -2, -3},
    {4, -7, 0, 2, -9},
    {-1, 10, 1, 1, 6},
    {-2, 4, 0, -1, -1}};
static const WDATA_T conv3_weights_84_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 7, 14, 8, 4},
    {-3, 5, 13, 15, 14},
    {-5, 2, 16, 5, -12},
    {10, 11, 0, -4, -14},
    {1, 9, -4, -7, 6}};
static const WDATA_T conv3_weights_84_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 4, 5, -4, -3},
    {0, 3, 6, -3, 3},
    {-5, -6, 5, -1, 5},
    {-6, -6, -3, -2, 6},
    {0, -4, -5, -1, 2}};
static const WDATA_T conv3_weights_84_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 4, 4, -2, -1},
    {10, 12, 8, -6, -7},
    {12, 17, 1, -10, -5},
    {1, 6, -10, -16, -5},
    {5, 14, 6, -6, 7}};
static const WDATA_T conv3_weights_84_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, -2, 1, -2},
    {1, 4, 0, 3, 1},
    {4, -1, 5, 6, 7},
    {5, -2, 11, 2, -1},
    {-2, -2, 6, 0, 1}};
static const WDATA_T conv3_weights_84_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 9, 3, -14},
    {1, -1, 6, 19, 7},
    {0, -2, 2, 5, 0},
    {6, 3, -6, -9, 0},
    {8, 12, 8, -10, 3}};
static const WDATA_T conv3_weights_84_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 0, -2, -2, 0},
    {-2, -12, -5, 4, 3},
    {-9, -8, -1, 11, -4},
    {0, 7, 10, -4, -2},
    {5, 4, 0, 0, 3}};
static const WDATA_T conv3_weights_84_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 5, 0, -4, 0},
    {-1, 5, 9, -7, -7},
    {-5, 5, 6, -8, -13},
    {1, -4, 0, -12, -8},
    {-2, -4, -11, 0, 7}};
static const WDATA_T conv3_weights_84_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -6, -7, 0, -2},
    {-7, -20, -4, 2, 1},
    {-4, -6, -7, 9, 5},
    {-1, -4, 4, -5, -7},
    {6, 12, -1, -2, -4}};
static const WDATA_T conv3_weights_84_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 1, 3, -10, -12},
    {3, -13, -8, -17, -12},
    {5, -1, -18, -8, 16},
    {6, -8, -11, 15, 3},
    {-6, 12, 37, 10, -22}};
static const WDATA_T conv3_weights_84_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 3, 0, 1},
    {2, 0, 0, 1, -2},
    {-2, -2, -1, -3, 0},
    {2, 0, 1, 3, 0},
    {-3, 0, 2, 2, -3}};
static const WDATA_T conv3_weights_84_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -2, 1, 1},
    {0, 6, 0, -5, 0},
    {1, 2, -1, -3, -2},
    {4, -2, 0, -2, 2},
    {-2, 1, 0, 1, 1}};
static const WDATA_T conv3_weights_84_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, -3, -10, -5, 3},
    {-4, -3, 4, 8, 2},
    {-9, -9, 8, 12, -2},
    {-5, 14, 17, -5, 0},
    {1, 7, -3, -2, -2}};
static const WDATA_T conv3_weights_84_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -6, 5, 9, 7},
    {1, -5, 6, 2, -2},
    {6, 4, 6, 5, 2},
    {3, 17, 7, -9, -6},
    {-9, 1, 2, 4, 1}};
static const WDATA_T conv3_weights_84_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 15, 17, 7, 3},
    {5, 3, 4, 0, 0},
    {5, 0, 3, -4, -5},
    {-15, -17, -4, -1, -3},
    {-2, -4, 1, 2, 4}};
static const WDATA_T conv3_weights_84_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, -8, -14, -14},
    {-2, -3, 7, -13, -30},
    {7, -5, -1, -19, -33},
    {15, -2, -17, -21, 16},
    {-2, -4, -6, 17, 19}};
static const WDATA_T conv3_weights_85_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 14, -25, -6, -1},
    {-15, -30, -22, 3, 0},
    {26, 42, -4, -36, -44},
    {1, -11, -25, -26, -25},
    {2, -30, -31, -14, -2}};
static const WDATA_T conv3_weights_85_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 17, -1, -7, 7},
    {-13, -15, 9, 16, 24},
    {-2, -38, -45, -20, 5},
    {48, 44, -5, -25, -22},
    {20, 37, 24, -18, -1}};
static const WDATA_T conv3_weights_85_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, 7, 22, -7, 9},
    {4, 0, 11, 8, -6},
    {31, 18, 20, 15, -13},
    {11, 18, 13, 6, -9},
    {-20, 24, 20, 17, 1}};
static const WDATA_T conv3_weights_85_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -7, 3, 7, 11},
    {-6, 2, 21, 27, -7},
    {-13, 3, -5, 5, -7},
    {23, 10, 33, 21, -21},
    {4, 0, 12, 9, 9}};
static const WDATA_T conv3_weights_85_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 9, 9, 9, -9},
    {14, 11, 21, -2, -24},
    {9, -6, 21, 0, -5},
    {0, -24, 10, -6, -5},
    {-1, -19, 1, -13, 0}};
static const WDATA_T conv3_weights_85_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {25, 16, 13, 1, -6},
    {7, -8, 12, 16, 15},
    {7, -30, -15, 3, 24},
    {-8, 7, 20, -2, -11},
    {6, 9, 25, 15, 7}};
static const WDATA_T conv3_weights_85_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-25, -7, -5, 14, -8},
    {-24, 46, 26, -19, -7},
    {-6, -33, -71, -21, 0},
    {-52, -18, -2, 0, 11},
    {35, 51, 41, 26, 30}};
static const WDATA_T conv3_weights_85_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-26, -4, 4, -21, -10},
    {20, 31, 8, 5, 21},
    {23, 9, 11, 47, 17},
    {-5, -5, 13, 29, 34},
    {12, 19, 4, 7, 23}};
static const WDATA_T conv3_weights_85_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -26, 3, 13, -3},
    {18, 21, 43, 20, 11},
    {13, 25, -2, -4, 17},
    {12, 23, 36, -12, -16},
    {34, 88, 39, -25, -7}};
static const WDATA_T conv3_weights_85_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 9, 15, 12, -4},
    {19, 20, -18, -20, -45},
    {-48, -38, -5, -55, -3},
    {-33, 2, -33, 10, 35},
    {7, 5, -31, 1, -25}};
static const WDATA_T conv3_weights_85_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, 2, 0, -1},
    {-3, -3, -1, 0, 0},
    {2, 3, -1, 2, -3},
    {-1, 2, 2, 3, 1},
    {2, 1, 1, 1, 2}};
static const WDATA_T conv3_weights_85_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -4, -3, 5, 8},
    {-5, -5, 2, 9, 5},
    {0, -8, 4, 6, 3},
    {-8, -5, 7, 4, 2},
    {-5, -9, -6, 3, -1}};
static const WDATA_T conv3_weights_85_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 30, 10, 6, -7},
    {-1, 16, 21, 8, -6},
    {9, -2, -12, 5, 14},
    {10, 5, 15, 6, 10},
    {-10, 8, 25, 12, 14}};
static const WDATA_T conv3_weights_85_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -28, 7, 10, -5},
    {-53, -24, 6, 28, 27},
    {7, 44, 49, 21, 16},
    {43, 76, 36, -30, 4},
    {31, -2, 13, -5, -1}};
static const WDATA_T conv3_weights_85_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -1, -2, 24, 25},
    {-9, -19, 21, 27, 44},
    {6, 5, 16, -19, -35},
    {6, 23, 8, -12, -10},
    {-34, -18, -39, -3, -16}};
static const WDATA_T conv3_weights_85_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -24, -1, 19, 25},
    {3, -3, 21, -15, -2},
    {-13, -1, -2, -9, -64},
    {-10, -47, -22, 19, 19},
    {33, 44, 60, 27, 14}};
static const WDATA_T conv3_weights_86_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 23, 12, 13, -18},
    {4, 0, 7, 20, -4},
    {-3, -6, 26, 35, 19},
    {7, -1, 7, 19, 2},
    {3, 19, 4, -11, -6}};
static const WDATA_T conv3_weights_86_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 14, -4, -5, 15},
    {29, 16, 8, -21, -14},
    {16, 23, 1, 8, 23},
    {10, -3, 1, 14, 10},
    {10, -13, -3, 25, 12}};
static const WDATA_T conv3_weights_86_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -34, -10, 6, -8},
    {-11, -28, -14, -4, -11},
    {-1, -10, -7, -10, -17},
    {0, -22, -7, -13, -2},
    {-3, -4, -13, -12, 5}};
static const WDATA_T conv3_weights_86_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 0, -7, -24},
    {20, -5, -35, -38, -40},
    {11, -16, -29, -27, 1},
    {-6, -19, -7, 32, 38},
    {-20, -25, 4, 22, 13}};
static const WDATA_T conv3_weights_86_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -10, -2, 3, 2},
    {2, -6, 2, 5, 8},
    {-5, 1, 2, 12, -5},
    {6, -5, -1, -6, -1},
    {1, 5, 3, 2, 5}};
static const WDATA_T conv3_weights_86_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 14, 16, 40, 21},
    {8, -32, -26, -8, -30},
    {18, -10, -20, -5, -11},
    {10, -10, -23, 17, 1},
    {15, 4, -2, 17, 8}};
static const WDATA_T conv3_weights_86_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-35, -45, -46, -35, -16},
    {-37, -30, -3, -12, -10},
    {-3, 5, -9, 7, 0},
    {-9, -33, -9, 2, 8},
    {-23, -26, -18, 1, -1}};
static const WDATA_T conv3_weights_86_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -28, 11, 4, -4},
    {-24, 0, 15, 11, 22},
    {-5, 6, 12, -17, -12},
    {-22, -22, 17, 13, -18},
    {-4, -1, 30, 26, 2}};
static const WDATA_T conv3_weights_86_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 44, 17, -10, -21},
    {71, 58, -8, 6, -30},
    {61, 48, 9, -3, -17},
    {16, -6, 9, -9, 2},
    {-3, 1, -3, 23, 3}};
static const WDATA_T conv3_weights_86_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, -2, -4, -5, -18},
    {8, 24, -2, 42, 57},
    {5, 9, 9, 25, 1},
    {8, -2, 16, -2, -10},
    {5, 19, 25, 24, 8}};
static const WDATA_T conv3_weights_86_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -2, 0, -4},
    {1, 0, 1, 1, -1},
    {2, 0, -2, 2, 3},
    {0, -1, -1, 2, 1},
    {-2, -2, 3, -3, -1}};
static const WDATA_T conv3_weights_86_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -5, -3, -4, -7},
    {0, 5, 2, 1, -10},
    {7, 14, 7, 5, 5},
    {-2, -2, -6, 1, -5},
    {0, -2, 1, -3, -5}};
static const WDATA_T conv3_weights_86_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-36, -36, 0, -19, -29},
    {-43, -23, -25, -4, -1},
    {-36, 11, -14, -4, 6},
    {4, 2, 15, 2, 6},
    {20, 8, 2, 7, -4}};
static const WDATA_T conv3_weights_86_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 30, 22, -24, -28},
    {38, 27, 34, -29, -25},
    {6, 11, 21, -9, 0},
    {4, -8, -24, -4, 6},
    {-1, 6, -1, -5, -10}};
static const WDATA_T conv3_weights_86_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -17, -13, -3, -30},
    {5, -2, -7, -4, -20},
    {-28, -32, -15, 9, 13},
    {-24, -34, -10, 14, 20},
    {21, 23, 17, -11, -10}};
static const WDATA_T conv3_weights_86_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-21, -42, -41, -2, 1},
    {-2, -18, 4, 67, 68},
    {9, -5, -10, 5, 30},
    {-17, -12, -11, -24, 4},
    {-1, -6, -28, -23, 6}};
static const WDATA_T conv3_weights_87_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, -22, 3, 29, -1},
    {-14, -31, -24, -7, 15},
    {-59, -71, -12, 4, 9},
    {1, -3, 13, 19, -7},
    {-19, 6, 10, -5, -5}};
static const WDATA_T conv3_weights_87_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 22, 18, 10, 2},
    {17, 5, 6, 3, -20},
    {1, 10, -1, -19, 9},
    {20, 29, 10, -1, -16},
    {-8, 17, 27, 23, -7}};
static const WDATA_T conv3_weights_87_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 6, -14, 9, -10},
    {10, -12, -34, 1, -1},
    {3, 2, 9, 19, 1},
    {-12, -6, 49, 12, 17},
    {1, -4, 10, -8, 11}};
static const WDATA_T conv3_weights_87_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 7, -1, 6},
    {-3, -3, 22, 14, 2},
    {-10, 1, 22, 13, 30},
    {-8, 0, -9, -21, 1},
    {-11, -25, -17, 34, 26}};
static const WDATA_T conv3_weights_87_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 7, 6, 5, 1},
    {15, 6, 16, 17, 8},
    {29, 20, 19, 21, 13},
    {15, 11, 18, -2, 11},
    {9, -1, 13, -2, 10}};
static const WDATA_T conv3_weights_87_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 30, 44, 38, 4},
    {14, 6, 6, 13, 15},
    {13, 6, -7, -22, 8},
    {-4, -19, -5, 0, -25},
    {4, 10, 20, 21, 0}};
static const WDATA_T conv3_weights_87_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, -40, -15, -9, -2},
    {-40, 0, 14, 9, 6},
    {2, 48, 29, 8, 13},
    {8, 24, 24, 10, 12},
    {-10, -26, -6, 1, 11}};
static const WDATA_T conv3_weights_87_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, -36, -15, 6, -20},
    {-26, -13, 3, 23, 27},
    {1, 49, 22, 13, 18},
    {-8, 24, 7, -23, -17},
    {-2, 36, 32, 23, -29}};
static const WDATA_T conv3_weights_87_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, -11, -17, 6, -4},
    {-19, 30, 27, -3, -12},
    {11, 19, -9, 1, 17},
    {12, -1, 5, 19, 15},
    {3, -29, -31, -2, 4}};
static const WDATA_T conv3_weights_87_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -6, 16, 22, 11},
    {0, 36, 13, -27, 16},
    {40, 15, -7, -9, -2},
    {14, -9, -30, -17, 10},
    {0, -30, 1, 9, -5}};
static const WDATA_T conv3_weights_87_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 3, 1, 5},
    {0, 0, 4, -2, 0},
    {-2, 3, 2, -1, 2},
    {-1, 1, 4, 0, 3},
    {2, 0, 0, -1, 1}};
static const WDATA_T conv3_weights_87_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -1, 2, -2},
    {-10, -4, 1, -2, -1},
    {4, 16, 4, 3, 6},
    {6, 11, 4, 2, 4},
    {0, -2, -5, 0, -7}};
static const WDATA_T conv3_weights_87_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 25, 0, 28, 9},
    {5, 60, 1, 20, 13},
    {8, 35, 5, -18, 6},
    {12, -7, -6, 5, 8},
    {19, 7, 53, 21, 2}};
static const WDATA_T conv3_weights_87_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 32, 17, 25, 16},
    {-10, -7, 17, -23, -18},
    {-1, -14, 28, 14, -10},
    {19, 2, 28, 20, 3},
    {-39, -14, 9, -5, -6}};
static const WDATA_T conv3_weights_87_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -2, 20, 11, -5},
    {-15, -55, -44, 26, 18},
    {-47, -73, -76, -5, 20},
    {-62, -74, -46, 0, -3},
    {0, -4, 3, -5, -34}};
static const WDATA_T conv3_weights_87_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -12, -9, 0, 20},
    {-3, -4, -20, -28, -7},
    {9, 5, 11, 2, 11},
    {7, 46, 39, 0, 1},
    {0, 35, 11, -33, 0}};
static const WDATA_T conv3_weights_88_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 14, 16, -9, -2},
    {5, 24, -5, -6, -10},
    {10, 23, -6, -15, -11},
    {-8, -9, -13, -8, -6},
    {-10, -24, -8, -3, -1}};
static const WDATA_T conv3_weights_88_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -22, -15, -4, 9},
    {-3, 3, -8, -10, 7},
    {-4, 1, -15, -11, -23},
    {17, 7, 5, -26, -21},
    {12, 21, 7, -7, -8}};
static const WDATA_T conv3_weights_88_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -9, 9, 4, 1},
    {4, 6, 11, 18, 2},
    {8, -14, 2, 0, -7},
    {1, -4, -5, 13, -6},
    {-10, 10, 10, 17, -6}};
static const WDATA_T conv3_weights_88_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -3, 0, -5},
    {-4, -7, -7, -6, 13},
    {-1, 3, -14, -8, 3},
    {-8, 5, 11, 3, 5},
    {-3, 3, 3, 11, 19}};
static const WDATA_T conv3_weights_88_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -3, -5, -7, -1},
    {4, -4, -4, -1, -1},
    {-7, -5, 6, 0, -1},
    {-8, -3, -4, -2, -7},
    {1, 2, -9, -11, -6}};
static const WDATA_T conv3_weights_88_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -12, -16, -2, -2},
    {-9, 2, -14, -5, -1},
    {-9, 0, 6, -1, -2},
    {3, 1, -2, -21, -15},
    {8, 15, 18, 5, -4}};
static const WDATA_T conv3_weights_88_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 16, 10, -5, -3},
    {-4, 5, -11, -3, -5},
    {-9, -39, -28, 7, -3},
    {-1, 5, 9, 10, 3},
    {19, 3, -2, 2, 6}};
static const WDATA_T conv3_weights_88_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 10, 14, -2, -4},
    {7, 1, 6, 13, 0},
    {1, -13, 2, 22, -12},
    {4, 0, 3, 6, -17},
    {3, -5, 1, -13, -19}};
static const WDATA_T conv3_weights_88_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 0, 0, -7},
    {-3, -13, -14, 13, 12},
    {-17, -22, -2, -3, -3},
    {4, 12, 3, 4, 4},
    {5, -18, -14, -1, 6}};
static const WDATA_T conv3_weights_88_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, -3, -6, -17, 0},
    {-7, -32, 0, 15, -7},
    {-18, -15, 1, 17, 16},
    {-17, -16, 0, 4, 10},
    {8, 8, -15, -4, -9}};
static const WDATA_T conv3_weights_88_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, 1, 0, 2},
    {1, -2, 1, 3, 3},
    {-1, -2, 1, -3, 1},
    {0, -2, 4, -1, -1},
    {3, 3, 1, 1, 1}};
static const WDATA_T conv3_weights_88_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, 2, 0},
    {1, 5, 1, -1, -1},
    {-4, 0, 0, 1, -3},
    {-2, -6, 1, 4, 4},
    {-7, -5, -4, 3, 5}};
static const WDATA_T conv3_weights_88_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -10, -10, -24, -4},
    {-6, 2, 0, -11, -6},
    {-6, -7, -3, -1, -4},
    {-9, -3, 6, -2, -7},
    {-2, 10, 22, 1, 7}};
static const WDATA_T conv3_weights_88_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -15, -19, -18, -16},
    {3, -1, -9, 0, 1},
    {33, 23, 15, 1, -5},
    {23, 44, 30, -4, -9},
    {-6, 3, 6, 0, 6}};
static const WDATA_T conv3_weights_88_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, -7, -1, 9},
    {-1, 24, 28, -4, -9},
    {21, 44, 33, 1, -7},
    {-18, -15, 3, -1, 6},
    {-12, -25, -17, 4, -10}};
static const WDATA_T conv3_weights_88_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -12, -8, -18},
    {-3, 4, -3, 18, -5},
    {-11, -18, -22, 3, -6},
    {1, -17, -6, 30, 6},
    {3, 5, 34, 22, -10}};
static const WDATA_T conv3_weights_89_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 0, 9, 13, 4},
    {-2, -18, -12, -1, 1},
    {5, -5, -14, -3, -2},
    {2, 10, 1, -10, -6},
    {-5, -1, -2, 2, 1}};
static const WDATA_T conv3_weights_89_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, 7, 10, 0},
    {-7, -5, -7, 18, 16},
    {-13, -5, -7, -5, 4},
    {1, 4, 2, -4, -11},
    {-3, 5, 6, -5, -8}};
static const WDATA_T conv3_weights_89_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -6, -3, 13, 5},
    {4, 4, -10, 10, 8},
    {3, -1, 2, 13, 11},
    {-5, 5, 15, 12, 5},
    {-4, 4, 6, 15, 2}};
static const WDATA_T conv3_weights_89_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, -2, 1},
    {6, 22, 16, 3, 3},
    {5, 9, 0, -7, -6},
    {5, -14, -19, -15, -9},
    {-1, 8, -1, -16, -8}};
static const WDATA_T conv3_weights_89_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 2, 1, 2, -1},
    {8, 3, 1, 6, 3},
    {14, 4, 2, 2, 5},
    {11, 3, 9, -1, 8},
    {6, 6, 8, -3, 4}};
static const WDATA_T conv3_weights_89_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 11, 17, 18, 2},
    {1, -8, -15, 4, 15},
    {-4, -1, -9, -20, -1},
    {-5, -5, 0, -2, -15},
    {0, -2, 13, 1, -8}};
static const WDATA_T conv3_weights_89_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 5, -7, -12, -5},
    {4, -4, -2, -4, -2},
    {-6, -6, -4, -4, -4},
    {-9, 12, -1, 4, 7},
    {4, 12, 8, 8, 2}};
static const WDATA_T conv3_weights_89_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -4, -7, 3, -1},
    {1, 4, 6, 37, 8},
    {0, 18, 6, 25, 2},
    {-3, 20, 9, 5, 4},
    {1, -4, 0, -3, -3}};
static const WDATA_T conv3_weights_89_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, 6, 0, -1},
    {5, -6, 3, 1, -1},
    {10, -2, -23, -12, 1},
    {-9, -3, -3, 2, 0},
    {-3, 1, -3, -9, -4}};
static const WDATA_T conv3_weights_89_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 18, 2, -3, -16},
    {6, 6, -27, -18, -13},
    {0, -11, -18, -21, -8},
    {2, -20, -16, -12, 12},
    {-18, -1, 10, 15, 12}};
static const WDATA_T conv3_weights_89_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -2, 2, 7},
    {0, -2, 1, 0, -2},
    {-3, 4, 0, 2, 1},
    {5, 3, -1, 1, -1},
    {1, 0, 3, 0, 3}};
static const WDATA_T conv3_weights_89_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 5, 2, -3},
    {2, 3, 1, 2, -1},
    {2, 1, 2, -3, 2},
    {-2, 3, -3, -3, -1},
    {-2, -4, 0, 0, 5}};
static const WDATA_T conv3_weights_89_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, -10, -10, -1},
    {-2, 0, -8, 4, -5},
    {-6, -10, 2, 1, 0},
    {-13, -9, 2, 2, 4},
    {3, 6, 5, 5, 6}};
static const WDATA_T conv3_weights_89_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -16, -2, -2, -5},
    {-18, -9, 4, -7, -16},
    {-6, -8, 10, 13, 1},
    {-4, 1, 7, 4, 1},
    {-6, -4, -3, 2, 0}};
static const WDATA_T conv3_weights_89_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -4, 2, 0, 0},
    {-5, -14, -9, -4, 5},
    {-1, -17, -19, -14, -2},
    {-13, -9, -4, -16, -4},
    {-9, -7, 12, 11, 2}};
static const WDATA_T conv3_weights_89_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, -12, -11, -4},
    {2, 10, -4, -24, -16},
    {3, 10, -9, -12, 5},
    {2, 1, -17, 3, -1},
    {0, -1, 12, 28, 8}};
static const WDATA_T conv3_weights_90_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 45, 50, 16, 26},
    {-10, 11, 20, -1, 7},
    {14, 47, -7, -25, -9},
    {26, 25, -13, -26, -15},
    {0, 17, -16, -15, -2}};
static const WDATA_T conv3_weights_90_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 20, 6, -3, 3},
    {20, 5, -3, -22, -32},
    {32, 14, 21, 2, -14},
    {11, 22, 3, 1, -25},
    {-3, 12, -11, 4, -34}};
static const WDATA_T conv3_weights_90_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -46, -22, -17, 22},
    {6, 3, -2, 10, 42},
    {-3, -17, 7, 4, 38},
    {8, -14, 8, -6, 9},
    {17, 22, 10, 23, 6}};
static const WDATA_T conv3_weights_90_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, -2, -3, -3},
    {0, -1, 8, -18, -15},
    {4, 6, 13, 4, 7},
    {1, 19, -8, -32, 18},
    {1, 31, -11, -15, 7}};
static const WDATA_T conv3_weights_90_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 14, 1, 2, 7},
    {5, 21, 2, 9, 12},
    {4, 23, 5, 7, 15},
    {9, 20, 12, 0, 4},
    {12, 21, 31, 6, 12}};
static const WDATA_T conv3_weights_90_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 14, 49, 74, 63},
    {-1, -5, 6, -3, -8},
    {16, 7, -10, -15, -25},
    {11, 17, 8, 1, -21},
    {0, 25, 21, 2, -19}};
static const WDATA_T conv3_weights_90_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -20, -29, -33, -11},
    {-7, -24, -35, 0, 7},
    {10, -21, -14, 11, 1},
    {23, -8, 11, -2, 14},
    {-12, -14, -15, 2, 5}};
static const WDATA_T conv3_weights_90_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-33, -38, -40, 37, 9},
    {-39, 11, 3, 29, 28},
    {-14, 24, 0, -2, -6},
    {-1, -23, -27, -5, 11},
    {13, -27, -31, -19, 5}};
static const WDATA_T conv3_weights_90_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, -5, 15, 11, 1},
    {3, 1, -23, 14, 34},
    {16, -5, 2, 12, 7},
    {3, -16, 1, 8, 19},
    {-3, 14, 39, 16, 2}};
static const WDATA_T conv3_weights_90_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -10, -34, -2, -10},
    {-12, -30, 7, 9, 10},
    {21, -23, -39, 32, 46},
    {21, -4, 12, 4, 3},
    {9, 20, 23, 12, 25}};
static const WDATA_T conv3_weights_90_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, 1, -1, 4},
    {4, 2, -2, 1, 1},
    {1, -2, 1, 2, -2},
    {0, 3, 1, -2, 1},
    {1, 0, 1, -1, -1}};
static const WDATA_T conv3_weights_90_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 0, 0, -7},
    {0, 6, 8, -8, -12},
    {-1, 6, 7, 2, 2},
    {-6, -6, 2, -5, 5},
    {3, -2, 0, 5, 2}};
static const WDATA_T conv3_weights_90_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, -12, 8, 2, 9},
    {18, 1, -32, 11, -10},
    {15, -7, 4, 38, 29},
    {-10, -66, 0, 27, 16},
    {-17, -36, 22, 2, 15}};
static const WDATA_T conv3_weights_90_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 23, 34, 5, -34},
    {27, -5, 2, -45, -72},
    {33, 20, 8, -17, 1},
    {-11, 7, -16, 24, 6},
    {-5, -6, -13, 22, 14}};
static const WDATA_T conv3_weights_90_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -8, 8, 3, 15},
    {-2, 12, 24, 27, 46},
    {-1, 14, 29, -12, 21},
    {-13, -5, 15, -27, -13},
    {38, 21, 3, 1, 2}};
static const WDATA_T conv3_weights_90_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -47, -62, -67, -66},
    {-6, -7, -14, -3, -69},
    {-8, 18, 12, 6, 44},
    {1, 19, 15, 26, 6},
    {-5, -11, -4, 36, 11}};
static const WDATA_T conv3_weights_91_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -4, 0, 3},
    {-3, 5, -3, 0, -3},
    {2, 0, 3, 3, -4},
    {0, 1, 1, -2, 0},
    {-1, 2, 0, 2, -1}};
static const WDATA_T conv3_weights_91_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -2, -4, 4},
    {0, -2, 4, 3, 2},
    {0, 0, 0, -2, -1},
    {-2, -1, 3, -2, 3},
    {3, 0, 0, -3, 0}};
static const WDATA_T conv3_weights_91_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -1, -2, 0},
    {0, 3, 1, -3, -1},
    {-1, 2, 0, 2, 2},
    {-1, -2, 2, -1, 2},
    {1, 3, -1, 1, -2}};
static const WDATA_T conv3_weights_91_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -1, 0, -2},
    {0, -1, 0, -5, 1},
    {-2, 2, -2, -3, 0},
    {2, -3, 0, 2, -1},
    {2, -2, -3, -5, 4}};
static const WDATA_T conv3_weights_91_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -2, 4, 0},
    {1, 3, 3, -3, -1},
    {-2, 2, -1, 1, 4},
    {3, 1, 1, 0, 2},
    {2, 0, 0, 2, 2}};
static const WDATA_T conv3_weights_91_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, -2, 2, -1},
    {2, -3, -1, -5, -1},
    {1, 0, -1, 0, -4},
    {3, 2, -4, -3, 0},
    {-1, 2, 0, -2, 0}};
static const WDATA_T conv3_weights_91_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, -1, 2, 2},
    {2, 1, 0, -1, -4},
    {0, 0, 0, -1, 2},
    {-1, 3, 0, 1, 2},
    {-1, -2, 1, -1, 1}};
static const WDATA_T conv3_weights_91_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -4, -3, 2},
    {-1, 0, -4, 0, 4},
    {0, -1, 1, -1, 0},
    {-3, 0, -1, -3, -1},
    {3, -1, -2, 0, 0}};
static const WDATA_T conv3_weights_91_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, 2, -2, 3},
    {0, 0, 1, 2, 3},
    {1, -2, -1, 2, 0},
    {0, 2, 0, 2, -2},
    {1, -2, 0, 0, -3}};
static const WDATA_T conv3_weights_91_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -1, -3, -2},
    {-2, -2, 3, 2, -1},
    {-1, -4, 1, -2, 0},
    {-1, -2, -1, 1, -3},
    {-2, -1, -4, 3, -1}};
static const WDATA_T conv3_weights_91_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 3, -2, 1},
    {2, 0, -3, 2, -2},
    {-2, 3, 1, 2, 2},
    {-3, 3, 0, -1, -3},
    {1, 0, -1, -6, 2}};
static const WDATA_T conv3_weights_91_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 5, -1, -3, -1},
    {1, 0, 1, -4, 3},
    {-1, -2, 1, 3, -2},
    {1, -1, 0, -2, 0},
    {3, 0, 1, 0, -1}};
static const WDATA_T conv3_weights_91_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -1, -1, -2},
    {-2, -4, 2, -2, -1},
    {-3, 0, 0, -2, 2},
    {2, 0, -2, -2, -1},
    {-1, 0, 1, 0, 0}};
static const WDATA_T conv3_weights_91_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -2, -5, -2},
    {-1, -1, 0, 2, -2},
    {1, 1, 0, -1, -1},
    {-1, -4, -1, 1, -3},
    {0, 2, 1, 0, 1}};
static const WDATA_T conv3_weights_91_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, 3, -1, -2},
    {-5, -3, 1, 1, 1},
    {2, -2, 0, -2, -1},
    {2, -2, 2, 3, 2},
    {1, -3, 0, 0, -1}};
static const WDATA_T conv3_weights_91_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, -1, 0, 3},
    {0, -2, -1, 2, -3},
    {2, 0, -2, -1, 1},
    {0, -1, -3, -2, 1},
    {-1, 2, 1, -1, 0}};
static const WDATA_T conv3_weights_92_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 1, 5, -1},
    {-3, 4, -2, -1, 1},
    {-2, -1, 5, -1, 1},
    {7, 3, 3, 2, -3},
    {-2, 1, -3, -1, -1}};
static const WDATA_T conv3_weights_92_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 2, -1, 1},
    {1, -3, -2, 1, 0},
    {3, 3, -1, -7, -5},
    {4, 0, 2, 0, 0},
    {0, -3, 2, -1, -4}};
static const WDATA_T conv3_weights_92_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 3, -5, 2, -3},
    {-1, -3, 0, -1, -7},
    {-2, -2, -1, 2, 0},
    {2, -3, 2, -2, -4},
    {-1, 4, 5, 0, 2}};
static const WDATA_T conv3_weights_92_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -1, -3, 1},
    {3, -2, -4, 0, -2},
    {1, -3, 0, 1, 2},
    {-5, -1, -1, 3, 4},
    {0, 3, 3, 6, 1}};
static const WDATA_T conv3_weights_92_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 2, -2, 1},
    {-1, 0, 0, 2, 2},
    {-2, 5, 2, 3, -3},
    {0, -1, 4, 3, 1},
    {-2, 1, 2, 2, 0}};
static const WDATA_T conv3_weights_92_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -1, -3, 0},
    {2, -1, -3, -1, 1},
    {-1, 4, 2, -4, -4},
    {4, 7, 3, 1, -4},
    {0, 0, -4, 7, -1}};
static const WDATA_T conv3_weights_92_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -6, 0, 3, 0},
    {-4, 0, 2, 1, 1},
    {-3, 3, 2, -2, 0},
    {-3, -3, -1, 0, 1},
    {-3, -2, 0, 3, 4}};
static const WDATA_T conv3_weights_92_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -1, 0, -2},
    {-4, -3, -4, -5, 2},
    {0, -1, 2, -6, 0},
    {-4, -4, -1, 0, -2},
    {-1, -1, 1, 4, -1}};
static const WDATA_T conv3_weights_92_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, 1, 1, 0},
    {-5, -3, 3, 5, 3},
    {1, 0, 4, 3, 0},
    {-2, -1, -5, 0, -2},
    {-2, 3, 3, 2, 1}};
static const WDATA_T conv3_weights_92_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -4, 4, -1, -2},
    {-3, -7, -3, 1, 6},
    {-1, -6, 0, 2, 0},
    {-1, 2, 2, 0, -3},
    {-6, -1, -3, 0, -1}};
static const WDATA_T conv3_weights_92_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 1, -2, 4},
    {0, 1, 0, 3, 0},
    {0, 1, -3, 1, -1},
    {-2, -2, -1, -1, 0},
    {-3, 2, 1, -2, 1}};
static const WDATA_T conv3_weights_92_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -2, -1, 2},
    {1, -3, 1, -2, 4},
    {2, -4, -1, 1, 4},
    {-1, -1, -2, 3, 1},
    {6, 1, 2, 2, 0}};
static const WDATA_T conv3_weights_92_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -4, 0, 1, -1},
    {-1, -2, -1, -1, 1},
    {0, 1, 1, 2, -1},
    {3, 0, -1, -5, -1},
    {4, 0, -1, -1, -2}};
static const WDATA_T conv3_weights_92_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 1, 1, 3, -3},
    {-2, 2, 2, 0, -3},
    {0, 1, 3, 0, -3},
    {2, 0, 1, 5, -5},
    {2, 5, 4, -1, -1}};
static const WDATA_T conv3_weights_92_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -4, 3, 6, 0},
    {0, -1, -1, -1, 2},
    {2, 0, 0, -6, 0},
    {7, 6, 5, 0, 0},
    {4, 2, 1, -1, -3}};
static const WDATA_T conv3_weights_92_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, 1, -2, -2},
    {-2, 2, -2, -1, -4},
    {-2, 3, -4, -1, 2},
    {-4, -1, -3, -3, 2},
    {2, -2, -2, 2, 1}};
static const WDATA_T conv3_weights_93_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 15, 21, -4, -4},
    {6, 4, -2, 9, -1},
    {1, 1, 3, 10, 6},
    {1, -7, 7, -5, -6},
    {-8, -12, 2, 6, 8}};
static const WDATA_T conv3_weights_93_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, -9, -12, -18, -3},
    {9, -2, 21, 6, 12},
    {-5, 1, 2, 12, 11},
    {-11, -10, -28, -37, -3},
    {-20, -17, -18, -15, -2}};
static const WDATA_T conv3_weights_93_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, -6, -11, 7, 1},
    {6, -5, -14, 13, -16},
    {9, 10, -14, 0, -16},
    {0, -10, -5, 15, -5},
    {-5, -10, -3, 10, -5}};
static const WDATA_T conv3_weights_93_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, 3, -1, -4},
    {2, 3, -3, 5, 20},
    {-7, -17, -9, 1, 13},
    {-6, -10, -7, 10, 10},
    {-7, -23, 16, 34, 16}};
static const WDATA_T conv3_weights_93_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 15, 16, 4, 2},
    {6, 11, 9, 2, -3},
    {11, 9, 15, 6, -7},
    {3, 12, 22, -3, -5},
    {-8, 14, 6, -4, -2}};
static const WDATA_T conv3_weights_93_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 9, 1, 9, -8},
    {3, -14, -21, 14, -2},
    {4, 0, -10, 19, 28},
    {0, -7, -8, -4, -1},
    {-16, -22, -7, 3, -1}};
static const WDATA_T conv3_weights_93_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 21, 6, -7, -7},
    {10, 4, 25, 17, 6},
    {-6, 14, 1, 10, 2},
    {4, -15, -22, -2, 3},
    {-1, -20, -12, -6, -2}};
static const WDATA_T conv3_weights_93_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 0, -14, -13, -6},
    {-4, -8, -2, -7, -8},
    {10, 1, 7, -12, -11},
    {13, -6, 26, 21, 2},
    {-6, 1, 52, 34, 9}};
static const WDATA_T conv3_weights_93_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 27, 8, -7, -2},
    {7, 12, 10, -6, -18},
    {1, 40, -8, -1, -3},
    {-8, -4, -19, -7, 0},
    {-21, -23, -12, -5, 0}};
static const WDATA_T conv3_weights_93_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 32, 48, 24, 5},
    {-4, 2, -7, -11, -12},
    {-2, -7, -18, 5, 2},
    {-8, 20, 3, -5, -14},
    {6, -18, -76, -42, -25}};
static const WDATA_T conv3_weights_93_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -3, -2, 2, 1},
    {3, 1, 1, 3, 4},
    {-2, 2, 2, 0, 0},
    {2, 0, 3, -1, 2},
    {0, 0, 0, 0, 0}};
static const WDATA_T conv3_weights_93_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 3, 1, -1, 3},
    {-2, 4, -2, 0, -1},
    {2, 10, -5, 1, 0},
    {8, 8, -4, 4, 5},
    {1, 3, 4, 11, 2}};
static const WDATA_T conv3_weights_93_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 6, -2, -23, -16},
    {3, -2, -20, -8, 11},
    {12, 24, 14, -5, -5},
    {1, 24, 14, 10, 1},
    {8, -4, -12, -3, 0}};
static const WDATA_T conv3_weights_93_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -3, 2, 6, 4},
    {14, 23, 17, 30, 27},
    {-12, -13, 7, 25, -4},
    {-21, -40, -15, -8, -17},
    {-14, -16, 0, 0, 3}};
static const WDATA_T conv3_weights_93_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -11, -12, -3, 1},
    {-6, -29, -19, 6, 9},
    {-22, -19, -16, -8, 8},
    {6, 2, -9, -1, 7},
    {-21, -16, 14, 9, 16}};
static const WDATA_T conv3_weights_93_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 7, 3, 4, 25},
    {-6, 11, 14, 16, 25},
    {32, 24, 27, 11, -35},
    {12, -7, 4, 8, -17},
    {-13, 1, 10, 0, -15}};
static const WDATA_T conv3_weights_94_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 7, 0, 0},
    {2, -3, 4, 1, 3},
    {7, -4, 5, 1, 0},
    {3, 7, 9, 0, 1},
    {-2, 3, 13, -3, 1}};
static const WDATA_T conv3_weights_94_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, -7, 4, 1},
    {13, 10, 6, 11, 11},
    {-6, -11, -20, 2, 12},
    {-10, 1, -7, -1, -2},
    {2, 0, 2, 1, 0}};
static const WDATA_T conv3_weights_94_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 5, 6, 13, 0},
    {-2, 1, -9, 4, -3},
    {1, -12, -9, -5, 1},
    {2, -4, 3, 2, 2},
    {2, 6, 1, -2, 1}};
static const WDATA_T conv3_weights_94_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 4, 2, 1},
    {-2, -11, -12, -10, -7},
    {-1, -8, -4, 2, -5},
    {-2, 3, 18, 21, 4},
    {2, 9, 5, -9, -9}};
static const WDATA_T conv3_weights_94_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 5, -1, 4},
    {-1, -3, 1, 3, -1},
    {5, 7, 0, 0, 1},
    {4, 15, 1, 6, 0},
    {-6, 3, 2, 4, 3}};
static const WDATA_T conv3_weights_94_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -8, -14, -4, -3},
    {0, 3, 4, 8, -1},
    {0, 6, 1, 6, 11},
    {-4, -3, -10, -6, -2},
    {-2, 4, -2, 2, -1}};
static const WDATA_T conv3_weights_94_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 3, 2, -4, -5},
    {7, 6, -11, -7, -2},
    {5, -3, -5, 1, -1},
    {-17, -1, 2, 6, -2},
    {-3, -1, -2, 2, 0}};
static const WDATA_T conv3_weights_94_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 2, 4, 0},
    {1, -6, 0, 6, -2},
    {-10, -16, -3, 7, 8},
    {0, 2, 0, -1, 1},
    {3, 7, -5, -20, -2}};
static const WDATA_T conv3_weights_94_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -8, -2, -2, -2},
    {-10, -6, -6, -8, -6},
    {5, 1, -5, -4, -4},
    {-17, -9, 9, 10, 4},
    {-2, -3, -7, -6, -4}};
static const WDATA_T conv3_weights_94_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -7, -16, -4, -17},
    {-5, -9, 7, 2, -6},
    {19, 27, 14, -6, -5},
    {7, -15, -15, -9, -1},
    {-15, -13, 0, 4, 8}};
static const WDATA_T conv3_weights_94_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -1, 3, -2},
    {0, 1, 1, 0, 3},
    {3, 1, -1, -3, 3},
    {-4, -2, 2, 1, -4},
    {-2, -2, 0, -4, 1}};
static const WDATA_T conv3_weights_94_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 5, 0, -2, 3},
    {-2, -2, 0, -1, 4},
    {0, 1, 3, -1, 1},
    {8, 9, 3, 0, -3},
    {1, -1, -2, 1, -4}};
static const WDATA_T conv3_weights_94_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -4, 0, -12, -7},
    {10, 16, 4, -2, 3},
    {8, 1, -8, 0, 0},
    {-14, -9, 3, 4, -2},
    {-4, 0, 3, 1, 1}};
static const WDATA_T conv3_weights_94_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 12, 4, -3, -4},
    {-1, 4, 4, -4, -5},
    {-20, -19, -11, -7, 0},
    {-2, 1, 10, 5, 1},
    {-1, 1, 2, 4, -1}};
static const WDATA_T conv3_weights_94_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 5, -5, -2, 0},
    {-3, 0, -1, 0, 3},
    {4, 7, 10, 14, 5},
    {12, 1, -5, -1, -4},
    {4, -6, 2, 5, 7}};
static const WDATA_T conv3_weights_94_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -1, -7, -2},
    {10, 1, -12, 4, -3},
    {-5, -9, -3, 0, -16},
    {-2, 16, 14, 0, -3},
    {-3, -2, -1, -3, -4}};
static const WDATA_T conv3_weights_95_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 8, 5, 8, 11},
    {20, 15, 3, 6, 15},
    {14, 8, 21, 11, 9},
    {14, -8, 3, 27, 6},
    {4, 5, 10, 11, -5}};
static const WDATA_T conv3_weights_95_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -2, 9, 9, 17},
    {-4, -3, -8, 16, 9},
    {9, 15, 3, -6, 8},
    {8, 5, 26, 21, 15},
    {7, 1, 7, 42, 24}};
static const WDATA_T conv3_weights_95_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -6, -5, -8},
    {10, -9, -9, -14, -13},
    {4, -14, -6, -7, -13},
    {3, -19, -5, -2, -16},
    {-4, -3, -3, -10, -10}};
static const WDATA_T conv3_weights_95_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -1, -3, 0},
    {5, 15, 17, 10, -14},
    {2, 2, 16, 7, -14},
    {-1, 13, 19, 6, -5},
    {2, 2, -1, 9, 10}};
static const WDATA_T conv3_weights_95_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 3, -4, 2, -2},
    {4, 9, -3, -3, 3},
    {3, 5, -5, -7, 8},
    {-7, 1, -9, -1, 16},
    {0, -3, -5, 12, 14}};
static const WDATA_T conv3_weights_95_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 7, 13, 12, 4},
    {0, -2, -11, 9, 7},
    {0, 18, 14, -1, 2},
    {3, 12, 15, 26, -12},
    {-1, 0, -9, 19, 11}};
static const WDATA_T conv3_weights_95_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 8, -7, -7, -3},
    {1, -4, 8, 3, -5},
    {-13, -2, -3, -16, 1},
    {-6, -15, -13, -2, 14},
    {-9, -12, -5, 3, 3}};
static const WDATA_T conv3_weights_95_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -8, 2, 16, 1},
    {9, -6, 6, 0, -15},
    {5, -12, -5, -17, -20},
    {-7, -19, -14, -30, -28},
    {3, 0, 2, -12, -20}};
static const WDATA_T conv3_weights_95_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 5, 4, 2, -3},
    {4, -9, -5, -8, -5},
    {-17, 2, 24, -2, 0},
    {-17, -10, 4, 9, 15},
    {-3, 2, -7, 13, 25}};
static const WDATA_T conv3_weights_95_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 16, 2, 1, -14},
    {10, 11, -3, -13, -18},
    {7, -1, -12, -4, 2},
    {-18, -17, -3, -7, 3},
    {10, -3, -52, -12, 45}};
static const WDATA_T conv3_weights_95_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 1, 1, -2},
    {-1, -1, -1, -1, 2},
    {-4, 2, -3, -3, 1},
    {-1, 2, 0, 0, -3},
    {0, -4, 2, -3, 0}};
static const WDATA_T conv3_weights_95_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, -2, 2, 1},
    {0, 2, 4, 5, -3},
    {2, 1, 2, 0, -2},
    {1, 0, 0, 2, 1},
    {-2, -3, -4, -8, 2}};
static const WDATA_T conv3_weights_95_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, -22, -8, 10},
    {-6, -9, -11, 4, 7},
    {-17, -1, -3, -1, 15},
    {-17, -21, -30, -5, 8},
    {-16, -7, 2, 17, 0}};
static const WDATA_T conv3_weights_95_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 1, -2, -4, 9},
    {1, 14, 17, 1, -5},
    {-8, 15, 24, 12, 16},
    {-1, 4, 10, 27, 23},
    {-8, -3, 0, 4, -8}};
static const WDATA_T conv3_weights_95_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 17, 14, 0, 0},
    {-8, -3, 9, 4, 13},
    {18, 4, 4, 14, 16},
    {8, -10, 15, 9, 4},
    {1, -28, -15, 18, 4}};
static const WDATA_T conv3_weights_95_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -3, -9, 5, 5},
    {8, 16, 10, 0, -4},
    {7, 7, -13, 12, -6},
    {4, -19, -10, 13, -20},
    {-2, 4, 0, -37, -64}};
static const WDATA_T conv3_weights_96_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -3, 0, 4, 0},
    {-1, -5, -5, -5, 1},
    {-1, 2, -4, -1, -5},
    {-1, -2, -3, -6, -1},
    {0, 1, -4, -3, 1}};
static const WDATA_T conv3_weights_96_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, -3, -5, 3},
    {1, 0, -8, 2, 2},
    {-4, -2, -3, -4, 0},
    {-1, -3, 1, -5, -6},
    {0, 4, -3, 1, -2}};
static const WDATA_T conv3_weights_96_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 0, -2, 4, 1},
    {0, -1, -9, 0, -2},
    {1, -1, -4, 1, 2},
    {2, 3, 0, 1, 0},
    {-6, 2, -6, -3, -1}};
static const WDATA_T conv3_weights_96_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 3, -1, -3, -3},
    {-1, -1, 0, -3, 9},
    {0, -2, -8, -5, 6},
    {-3, -5, -2, -2, -6},
    {-4, -3, -4, -6, -3}};
static const WDATA_T conv3_weights_96_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 3, 1, -1},
    {2, 0, -1, -5, -1},
    {1, -1, -3, 1, 0},
    {2, 2, -1, -3, 3},
    {0, 1, -1, -4, -2}};
static const WDATA_T conv3_weights_96_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -4, -10, -3, -6},
    {-1, -1, -9, 0, 1},
    {2, -3, -9, -5, 4},
    {0, 1, -3, -2, -4},
    {0, -2, -4, -3, -3}};
static const WDATA_T conv3_weights_96_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 6, 7, 5, 0},
    {3, 2, 2, 2, 4},
    {-2, -3, -9, 0, 3},
    {-1, -3, 0, 6, -5},
    {-3, -4, 4, 9, 3}};
static const WDATA_T conv3_weights_96_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -2, 3, -5, 2},
    {-1, 1, 2, 9, 3},
    {1, 2, 3, 10, 11},
    {0, 1, -1, 14, 8},
    {-1, 0, 4, 2, 7}};
static const WDATA_T conv3_weights_96_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 6, 3, 3, 2},
    {-2, -1, -5, -5, -3},
    {1, -5, -10, -2, -1},
    {-3, -8, -6, -3, -4},
    {-2, -3, 3, 5, -3}};
static const WDATA_T conv3_weights_96_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -3, 5, 8, 4},
    {0, -9, 3, 1, -5},
    {-7, 2, 4, -4, -5},
    {0, 3, 3, 1, -5},
    {1, 9, 11, 4, 1}};
static const WDATA_T conv3_weights_96_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 1, 3, 1},
    {0, -2, -1, -1, -2},
    {0, -1, 1, -2, -1},
    {1, -2, 1, -1, 0},
    {2, 0, -1, 2, 0}};
static const WDATA_T conv3_weights_96_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 0, 1, 0},
    {0, -2, -1, -1, 1},
    {0, 1, -1, 0, -1},
    {-3, 0, 2, 1, 0},
    {0, 3, 1, 3, -3}};
static const WDATA_T conv3_weights_96_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 4, 7, -7, 2},
    {-3, 5, 3, -1, -2},
    {2, -3, -3, -1, -1},
    {5, 0, 1, -6, 2},
    {-1, -6, -5, 4, 2}};
static const WDATA_T conv3_weights_96_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, -2, 1, -1},
    {-2, -8, -6, -9, -4},
    {-10, -11, -4, 0, -6},
    {1, -2, -1, 1, -1},
    {3, -1, -4, 1, 0}};
static const WDATA_T conv3_weights_96_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -9, -5, 1, -2},
    {-1, -5, -4, -2, -3},
    {-3, -3, -7, -5, -6},
    {1, -1, -2, -3, -5},
    {7, 6, 6, -2, -2}};
static const WDATA_T conv3_weights_96_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 0, 5, -3, 5},
    {2, 3, -7, 0, -2},
    {1, -2, -4, 3, -4},
    {0, -6, 4, 2, 10},
    {4, 4, 4, 11, 13}};
static const WDATA_T conv3_weights_97_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 2, -8, -15, -13},
    {8, 9, -8, -8, -6},
    {6, 13, -2, -10, -4},
    {3, 8, -3, 0, 3},
    {1, -3, -3, 2, 2}};
static const WDATA_T conv3_weights_97_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -5, 6, 11, 0},
    {3, -1, -10, -2, -5},
    {-1, -2, -2, -12, -12},
    {0, 6, -1, -14, -14},
    {11, 14, 1, -2, 1}};
static const WDATA_T conv3_weights_97_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -11, 5, 3, -3},
    {1, 1, 3, 16, 4},
    {2, 1, 1, 16, 3},
    {-4, 4, -1, 18, 0},
    {-9, 3, -8, 7, -2}};
static const WDATA_T conv3_weights_97_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 3, 1, 2, -1},
    {-1, 0, -4, -18, -16},
    {2, 1, -8, -11, -5},
    {3, 3, 5, -2, 0},
    {-8, 4, -2, -2, 6}};
static const WDATA_T conv3_weights_97_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 2, -2, 1},
    {10, 3, 6, 3, -2},
    {2, 0, 8, 6, 7},
    {3, 0, 10, -2, 0},
    {4, -4, 5, -3, 2}};
static const WDATA_T conv3_weights_97_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 3, 10, -1},
    {0, -1, -9, 1, 3},
    {-2, 0, 0, -6, -5},
    {2, -1, 0, -1, -1},
    {8, 9, 4, 0, 3}};
static const WDATA_T conv3_weights_97_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -13, -4, -3, -2},
    {-10, -4, 1, 2, -1},
    {-6, -9, 2, 7, -3},
    {-4, -5, 6, -2, -3},
    {-3, -8, -4, -3, -3}};
static const WDATA_T conv3_weights_97_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 3, 5, 5, 1},
    {-1, 5, 13, 14, 2},
    {3, 11, 1, 3, -13},
    {1, -6, 3, 2, -9},
    {-3, -5, -1, 0, -5}};
static const WDATA_T conv3_weights_97_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 2, -3, -2, -1},
    {-1, 6, 0, 6, -3},
    {-2, 4, 4, 2, -2},
    {-7, -6, 6, 6, -1},
    {-10, -6, 9, 6, -1}};
static const WDATA_T conv3_weights_97_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 4, -7, -20, -12},
    {-4, -10, 8, 6, -1},
    {-14, -6, -5, 6, 11},
    {-4, -12, 1, 18, -1},
    {1, 9, 8, 0, -13}};
static const WDATA_T conv3_weights_97_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 2, -3, 1},
    {-1, 3, -2, 1, -1},
    {3, -1, -1, 0, 0},
    {-1, -1, 1, -3, -4},
    {-3, -2, -1, 1, -1}};
static const WDATA_T conv3_weights_97_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -1, -2, 0, -3},
    {-1, 3, 1, 1, -1},
    {2, 4, -2, 0, 1},
    {3, 1, 2, 1, -1},
    {-1, 0, 2, 4, -3}};
static const WDATA_T conv3_weights_97_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -17, -14, -9, -12},
    {-12, -8, 3, 0, 3},
    {-2, -7, 9, 0, -4},
    {-2, -3, 9, -5, -3},
    {-5, -3, 3, -3, 6}};
static const WDATA_T conv3_weights_97_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 4, -2, -8, -6},
    {4, 4, -4, -12, -4},
    {9, 15, 13, -1, -7},
    {9, 26, 19, -4, -2},
    {-2, 9, 7, 1, 1}};
static const WDATA_T conv3_weights_97_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, -8, -5, -6},
    {5, 3, 5, -2, -4},
    {-2, 10, 15, -6, -5},
    {-14, 2, 12, -2, -3},
    {-3, -3, -3, 4, 1}};
static const WDATA_T conv3_weights_97_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -10, -3, 2, -9},
    {-3, 6, 6, 29, 10},
    {3, -1, 5, 9, 4},
    {0, -15, -6, -7, 10},
    {1, -3, -7, 6, 1}};
static const WDATA_T conv3_weights_98_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, 11, 6, -8, -12},
    {13, 15, -3, -8, -4},
    {2, -15, -19, -13, 3},
    {5, -3, -3, 0, 4},
    {-1, 7, 17, 10, 7}};
static const WDATA_T conv3_weights_98_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -10, -6, -9, -6},
    {1, -10, 6, -12, -22},
    {3, -7, -8, -1, 2},
    {-6, -7, -3, -3, 14},
    {11, 14, 20, 5, 12}};
static const WDATA_T conv3_weights_98_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -16, 10, 11, 5},
    {0, -3, 9, 31, 1},
    {-6, -9, -5, 10, -3},
    {-6, 7, 12, 26, 3},
    {-1, 1, 6, -6, 0}};
static const WDATA_T conv3_weights_98_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 2, 1, -1, -6},
    {-14, -12, -12, -9, -9},
    {-7, -12, -24, 8, 1},
    {-13, -13, 1, 6, -6},
    {11, 13, 6, -3, -19}};
static const WDATA_T conv3_weights_98_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 0, -2, -6, 0},
    {2, 2, 4, 3, -4},
    {3, 5, 17, 7, -4},
    {4, 15, 14, 4, -4},
    {0, 7, -2, 2, 1}};
static const WDATA_T conv3_weights_98_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -22, -11, 1, -1},
    {-4, -6, -11, 16, -7},
    {0, 5, -5, 7, -7},
    {0, -7, -14, 10, -1},
    {6, 6, 8, 15, 11}};
static const WDATA_T conv3_weights_98_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 5, 9, -2, -1},
    {1, -5, -11, -4, -1},
    {-3, -9, -2, 3, 3},
    {-3, -3, -2, 1, -3},
    {-2, -7, -3, -6, -11}};
static const WDATA_T conv3_weights_98_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 2, -2, 6, -1},
    {-3, -6, 20, 25, -9},
    {-10, -21, 21, 40, 0},
    {-4, -11, 16, 15, -7},
    {0, -2, 0, -25, -6}};
static const WDATA_T conv3_weights_98_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 11, 11, 0, -2},
    {-7, -7, -16, -1, -8},
    {-7, 7, 8, -4, 3},
    {-11, -1, -6, 3, 0},
    {5, -2, 10, 10, 1}};
static const WDATA_T conv3_weights_98_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -4, -8, -5},
    {0, -10, 22, 15, -7},
    {-2, 34, 17, -19, -15},
    {6, 1, -12, -25, -10},
    {-13, -1, -1, -1, 9}};
static const WDATA_T conv3_weights_98_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 1, -4, -1},
    {1, 1, -2, 1, -1},
    {-3, 4, -2, -4, 1},
    {-1, -5, 0, 1, -3},
    {0, 0, 1, 2, 2}};
static const WDATA_T conv3_weights_98_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -1, -2, 0, -2},
    {4, 3, 1, 1, 0},
    {4, 0, 3, 1, 3},
    {-6, 1, 7, -3, 2},
    {2, 2, 1, -5, -4}};
static const WDATA_T conv3_weights_98_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -25, -18, -18, -5},
    {-4, 7, 8, -1, -3},
    {-8, -1, 2, -5, -3},
    {-6, 13, -1, -4, 3},
    {1, 2, 11, 5, 5}};
static const WDATA_T conv3_weights_98_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -7, -15, -15, -8},
    {6, -1, -14, -12, -8},
    {-1, -1, -3, -3, -2},
    {-1, 14, 26, -2, -4},
    {0, 14, 11, 4, 7}};
static const WDATA_T conv3_weights_98_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -2, -13, -11, -10},
    {3, 10, 20, -4, -7},
    {8, -3, -7, 6, 3},
    {-3, -9, -8, 4, 4},
    {-9, -5, 0, 19, 18}};
static const WDATA_T conv3_weights_98_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 7, -4, 13},
    {2, 17, 4, 18, 16},
    {-4, -10, -3, 29, 4},
    {1, 11, 14, 21, -28},
    {0, 2, 7, -18, -36}};
static const WDATA_T conv3_weights_99_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 2, -3, -1, 1},
    {1, 2, -3, 3, 0},
    {0, 0, 1, 1, 0},
    {-1, 2, 0, 2, 3},
    {0, 2, 0, -2, -1}};
static const WDATA_T conv3_weights_99_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 4, 0, 2, 3},
    {-1, -4, -2, -2, -2},
    {1, 3, 1, -1, -1},
    {0, 1, -3, 1, 2},
    {-2, -1, 0, 1, -2}};
static const WDATA_T conv3_weights_99_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 2, -2, 0},
    {-2, -1, -3, 2, 1},
    {0, -1, -4, -2, -1},
    {-1, 3, -5, 0, -2},
    {4, 3, -2, 0, -2}};
static const WDATA_T conv3_weights_99_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 2, -4, 2},
    {-3, 1, 0, -3, 0},
    {-3, -3, 2, -1, 1},
    {0, 1, 1, -1, 1},
    {-1, -2, 0, 0, -4}};
static const WDATA_T conv3_weights_99_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 3, -3, -3, 0},
    {-2, -1, 1, -2, 2},
    {-3, 0, 1, 1, 0},
    {-3, -3, 1, -1, -3},
    {0, -2, 0, -1, -1}};
static const WDATA_T conv3_weights_99_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 0, 2, 0},
    {0, 0, -2, -3, -1},
    {-1, -2, 1, 1, 0},
    {-1, -1, -4, 0, 0},
    {-1, 1, -2, 2, -3}};
static const WDATA_T conv3_weights_99_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -1, -1, -1},
    {3, 2, -2, 2, 1},
    {-1, 0, -4, 0, -2},
    {3, -1, -2, 1, 5},
    {1, 2, -1, -3, 0}};
static const WDATA_T conv3_weights_99_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, 0, 2, 0},
    {-1, 2, -3, 0, -1},
    {-2, -3, 0, 0, -3},
    {-1, -1, -3, -2, 2},
    {-1, 1, -1, 1, 0}};
static const WDATA_T conv3_weights_99_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, -1, -4, 1},
    {0, -1, -3, -3, -2},
    {2, -4, 2, 0, 0},
    {-2, -5, 0, -2, 1},
    {-2, 3, 2, -1, -1}};
static const WDATA_T conv3_weights_99_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, 0, 1, -1},
    {-2, -1, -1, -2, -1},
    {1, -2, -2, 3, -1},
    {1, -1, -2, 0, 0},
    {-3, 0, 2, -1, -1}};
static const WDATA_T conv3_weights_99_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -1, 1, 3},
    {3, 0, 3, 0, 1},
    {2, -2, -2, -2, 0},
    {-1, -2, -1, -5, -1},
    {-4, 0, 3, 0, 0}};
static const WDATA_T conv3_weights_99_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, 0, 0, -1},
    {3, 0, 3, -1, 1},
    {-1, 2, -2, 4, 0},
    {0, 1, -2, -2, -2},
    {-1, -4, 1, 1, 1}};
static const WDATA_T conv3_weights_99_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 1, -1, 1, 3},
    {1, 3, 4, -1, 0},
    {-2, -2, 2, 0, -1},
    {1, 0, 2, -1, -1},
    {1, 0, -2, -1, -3}};
static const WDATA_T conv3_weights_99_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, 3, -2, -1},
    {1, -1, 0, -1, 2},
    {0, -4, -2, 3, -3},
    {1, -2, -1, -2, 1},
    {-1, -1, 2, 2, -3}};
static const WDATA_T conv3_weights_99_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 0, 0, 0},
    {0, -1, 0, 3, 0},
    {-2, -2, 1, 1, 0},
    {0, -2, -2, -1, 0},
    {2, 0, 2, -1, 0}};
static const WDATA_T conv3_weights_99_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, 1, 0, 2},
    {-2, 1, -1, -1, 0},
    {-1, -1, 1, 0, -2},
    {-2, -2, 2, -4, 0},
    {3, 0, -1, 1, -1}};
static const WDATA_T conv3_weights_100_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 8, 17, -4, -11},
    {7, 15, 0, 2, 8},
    {3, 27, 9, -4, 19},
    {-15, 13, 15, 29, 19},
    {1, 2, 19, 17, 11}};
static const WDATA_T conv3_weights_100_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -10, -1, 10, -22},
    {-6, -7, 0, 16, 10},
    {-18, -8, -25, 7, 25},
    {-22, -10, -21, -17, -1},
    {5, -1, -3, 15, 19}};
static const WDATA_T conv3_weights_100_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 15, 16, 25, -10},
    {2, 15, 4, 19, -28},
    {17, 5, -26, 7, -29},
    {19, 17, -28, 21, -8},
    {5, 0, -4, 8, -3}};
static const WDATA_T conv3_weights_100_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 0, -5, 3, -1},
    {6, -1, -43, -33, 11},
    {3, -22, -50, -26, -13},
    {-7, -1, 12, 13, 20},
    {-27, -14, 1, -5, 13}};
static const WDATA_T conv3_weights_100_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, -3, 11, 4, 5},
    {9, -4, 11, 1, 1},
    {2, 5, 20, -4, -2},
    {4, 13, 2, 1, 4},
    {1, 0, 18, 7, 9}};
static const WDATA_T conv3_weights_100_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -18, -20, 12, -32},
    {-10, 1, -14, 3, 4},
    {-19, -28, -17, 8, 27},
    {-12, -6, -6, 23, 25},
    {3, -11, -15, 12, 35}};
static const WDATA_T conv3_weights_100_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 30, 9, 7, 7},
    {23, 9, -3, -7, -3},
    {4, -9, -2, -10, 2},
    {22, 15, 7, 22, -13},
    {-7, -7, -9, -20, -20}};
static const WDATA_T conv3_weights_100_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 27, 29, -11, -12},
    {14, 9, 5, 1, -30},
    {22, -20, 14, 12, -35},
    {4, -4, -7, 37, -27},
    {-4, 3, -11, 21, -1}};
static const WDATA_T conv3_weights_100_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 19, 5, 1, -6},
    {42, -11, -40, -4, -16},
    {-13, -28, -7, -21, -25},
    {-3, -9, 0, -4, -9},
    {-30, -41, -3, -3, 10}};
static const WDATA_T conv3_weights_100_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, -21, -8, -13, -5},
    {2, 8, 27, 26, 16},
    {-4, 25, 49, 9, -4},
    {4, 18, -12, -18, 9},
    {-4, -20, -32, 15, 6}};
static const WDATA_T conv3_weights_100_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, 2, 0, 1},
    {-3, -1, 1, 3, 0},
    {3, -2, 0, 1, -1},
    {3, 0, -1, 2, 1},
    {3, 1, -1, 1, 3}};
static const WDATA_T conv3_weights_100_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 1, 1, -2, -4},
    {5, 1, 0, 0, -1},
    {4, 5, 4, 0, -3},
    {2, 7, 5, -1, -9},
    {4, 1, 0, 5, 5}};
static const WDATA_T conv3_weights_100_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -10, -19, -37, -25},
    {-6, -7, 14, -19, 0},
    {-4, -16, -15, -21, 0},
    {27, 13, 13, -9, -6},
    {7, 3, 3, 7, 1}};
static const WDATA_T conv3_weights_100_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -10, -32, -27, -17},
    {-9, -2, -27, -32, 3},
    {-23, -18, -28, -18, -17},
    {-2, 9, -2, -4, 0},
    {4, 18, 7, -1, -1}};
static const WDATA_T conv3_weights_100_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 4, -24, -31, -22},
    {8, 39, 34, -13, -26},
    {-27, -5, 24, 4, 8},
    {3, 26, 33, 4, -1},
    {-8, 2, -11, 1, 35}};
static const WDATA_T conv3_weights_100_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 10, 36, 29, 6},
    {-9, 1, 8, 40, 45},
    {-2, 17, 0, 36, 30},
    {7, 2, -10, 16, -12},
    {0, 12, -11, -15, -31}};
static const WDATA_T conv3_weights_101_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 19, 11, -1, -4},
    {8, 6, 0, -2, -10},
    {2, 5, 6, 12, 1},
    {0, 11, 21, 16, 3},
    {-7, 0, 10, 6, 2}};
static const WDATA_T conv3_weights_101_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 1, 6, 11, 4},
    {18, 12, -3, -13, 2},
    {11, 1, -7, -13, -14},
    {-4, -8, -14, -21, -10},
    {-7, -13, -7, -6, 0}};
static const WDATA_T conv3_weights_101_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -7, -5, -4, -8},
    {6, -3, 9, 15, 9},
    {1, 1, -6, 6, 6},
    {-6, -6, -22, -3, -3},
    {1, -5, -8, 10, 1}};
static const WDATA_T conv3_weights_101_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -5, -4, -6},
    {12, 8, -13, -18, 0},
    {20, 12, -8, -23, -1},
    {8, -1, -10, -1, 15},
    {5, 3, 4, 5, 16}};
static const WDATA_T conv3_weights_101_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 5, 2, 4, 10},
    {7, 7, 10, 5, 6},
    {0, -3, 7, 6, -7},
    {1, 3, 5, 3, -3},
    {-1, 10, 15, 2, -2}};
static const WDATA_T conv3_weights_101_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 13, 13, 10, 14},
    {9, 4, 1, -6, 3},
    {6, 8, -4, -4, -1},
    {-1, 2, -8, -18, -1},
    {-5, -17, -9, 7, 3}};
static const WDATA_T conv3_weights_101_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, -3, -23, 2, 2},
    {8, -9, -6, -7, -1},
    {-3, -10, 4, 10, 1},
    {6, 1, 0, 5, 1},
    {17, 14, -3, -10, -4}};
static const WDATA_T conv3_weights_101_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -25, -16, -8},
    {-2, 2, -9, -6, -8},
    {2, 3, -8, -14, -4},
    {0, -6, 7, -2, -1},
    {-4, -9, 10, 10, 7}};
static const WDATA_T conv3_weights_101_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, -6, -8, -4, 2},
    {14, 20, 2, -10, -14},
    {14, 11, -6, 1, -8},
    {4, 4, 8, 1, 0},
    {9, 7, -12, -18, -14}};
static const WDATA_T conv3_weights_101_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 22, 0, -4, 8},
    {12, 5, 8, 31, 26},
    {-3, -18, 0, 24, 18},
    {3, -13, -4, 2, 0},
    {-13, -9, -11, -12, -13}};
static const WDATA_T conv3_weights_101_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -3, -1, -3},
    {2, -1, -1, -4, -1},
    {0, 1, 1, 1, 1},
    {2, 0, 2, -2, 1},
    {-1, -2, 2, 0, 2}};
static const WDATA_T conv3_weights_101_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 2, 0, 0, 2},
    {0, 9, 2, 0, -2},
    {1, 5, 3, 6, 3},
    {1, -1, 0, -1, 0},
    {0, -2, -1, 2, -3}};
static const WDATA_T conv3_weights_101_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {23, -7, -12, -13, -9},
    {22, -28, -10, 6, -9},
    {0, -11, 13, 6, -3},
    {-12, -21, 2, 11, 0},
    {5, -2, -4, -2, 4}};
static const WDATA_T conv3_weights_101_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 6, 4, -8, -10},
    {27, 10, -3, -24, -20},
    {7, 4, 5, -14, -11},
    {-4, -23, -25, -6, -2},
    {8, -12, -15, -7, 0}};
static const WDATA_T conv3_weights_101_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 10, 3, -5, -3},
    {14, 23, 7, -1, -7},
    {6, 12, 28, 5, 4},
    {5, -2, -6, -16, 6},
    {-14, -10, -8, -23, 4}};
static const WDATA_T conv3_weights_101_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -7, -10, -16, -3},
    {-9, -15, -8, 25, 39},
    {-8, 2, 5, 26, 27},
    {-10, -14, -18, -9, -4},
    {-1, -8, -9, 1, 13}};
static const WDATA_T conv3_weights_102_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -8, -1, -23, -13},
    {-6, -6, -3, -1, -3},
    {-3, 4, 5, -7, 9},
    {-6, -5, 6, -1, 19},
    {5, 14, 14, 20, 9}};
static const WDATA_T conv3_weights_102_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -4, -18, -13, 2},
    {-9, -4, 30, 13, -2},
    {-19, -3, -6, 29, 17},
    {-8, -1, -2, -6, 5},
    {3, 3, 9, 11, 32}};
static const WDATA_T conv3_weights_102_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {24, 18, 19, 5, 4},
    {11, -8, -1, -1, -20},
    {7, -15, -19, -10, 3},
    {8, 6, -13, 20, 4},
    {-4, -5, -11, -19, -14}};
static const WDATA_T conv3_weights_102_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 6, -3, -16},
    {-16, -2, 9, 24, 24},
    {-14, -17, -39, -3, 12},
    {-21, -12, 24, 19, -18},
    {-8, -13, 11, -2, 4}};
static const WDATA_T conv3_weights_102_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 24, 15, 8, -3},
    {-4, 21, 16, 5, -4},
    {-1, 19, 33, 6, 1},
    {7, 25, 24, -4, 1},
    {4, 4, -1, -5, 0}};
static const WDATA_T conv3_weights_102_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -30, -36, -21, -27},
    {10, 7, 1, 8, -19},
    {-9, -2, -12, 20, 18},
    {10, 18, 16, 20, 13},
    {4, -2, 14, 13, 35}};
static const WDATA_T conv3_weights_102_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 45, 54, 30, -7},
    {16, 27, 28, 28, 4},
    {-15, 12, 13, 17, -1},
    {6, 2, -11, 1, -3},
    {-5, -17, -19, -10, -15}};
static const WDATA_T conv3_weights_102_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, 43, 24, -17, 0},
    {18, 4, 13, -13, -17},
    {6, -20, 24, 22, 14},
    {14, 3, 29, 31, 11},
    {-8, 11, 29, 4, 20}};
static const WDATA_T conv3_weights_102_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -12, 5, 15, 5},
    {-16, -36, -22, -1, -13},
    {-25, -30, 0, 1, -5},
    {-22, -27, -29, -9, -10},
    {-8, -18, -5, -4, -3}};
static const WDATA_T conv3_weights_102_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 9, 22, 12, 14},
    {-5, -18, -7, -2, -23},
    {-13, 13, 3, -4, -14},
    {-15, 4, 15, -12, -26},
    {22, 0, -43, -36, -3}};
static const WDATA_T conv3_weights_102_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, 1, 0, 2},
    {-3, 1, 3, 1, -2},
    {2, 0, -2, 1, -3},
    {1, -2, -1, 1, -1},
    {1, 1, 2, -2, -1}};
static const WDATA_T conv3_weights_102_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 5, 3, 0, 6},
    {2, 0, -1, 0, 5},
    {-4, -9, -2, -5, -4},
    {-1, 6, 3, 2, 0},
    {-5, 3, 2, 5, 1}};
static const WDATA_T conv3_weights_102_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 2, -14, -11, -5},
    {14, 37, 9, -20, -11},
    {15, 10, 7, -6, -3},
    {20, 36, 34, -2, 1},
    {8, -12, -10, -5, -3}};
static const WDATA_T conv3_weights_102_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -13, -12, -19, -3},
    {-20, -9, -14, 6, 4},
    {-14, -2, -11, 1, -2},
    {0, 15, 35, -11, -12},
    {17, 9, 24, 14, 9}};
static const WDATA_T conv3_weights_102_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 1, -21, -14, 6},
    {-10, -13, 25, -6, -23},
    {-9, -22, -5, 0, -11},
    {22, 9, 5, 25, 14},
    {-14, -18, 18, 42, 39}};
static const WDATA_T conv3_weights_102_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 31, 21, 21, 29},
    {26, 29, -20, -5, 11},
    {27, 8, 7, 20, -8},
    {16, 3, 5, 17, 1},
    {-3, 1, -4, -16, -44}};
static const WDATA_T conv3_weights_103_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -9, -20, -16, 3},
    {12, -3, -16, -1, 1},
    {22, -4, -3, 5, 6},
    {18, 1, -2, 10, 11},
    {8, 4, -1, 8, -1}};
static const WDATA_T conv3_weights_103_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, -13, -12, 6},
    {-2, -1, -4, 4, -2},
    {5, 11, 3, -6, -7},
    {15, 10, -4, -4, -5},
    {2, 4, -7, 4, 2}};
static const WDATA_T conv3_weights_103_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -5, 2, 4, -9},
    {3, -11, -7, -2, -15},
    {7, -9, 1, -2, -10},
    {-3, -4, 0, 4, -10},
    {-5, 1, 0, -6, -10}};
static const WDATA_T conv3_weights_103_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 2, -8, -7},
    {-2, 8, 15, 16, 4},
    {1, 11, 4, 2, -5},
    {-4, 0, -15, -10, -1},
    {6, 11, 11, 6, 14}};
static const WDATA_T conv3_weights_103_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 8, 3, -2, -2},
    {4, 6, 3, 0, 4},
    {-1, 10, 5, 1, 8},
    {-6, 1, 5, -7, 3},
    {0, -3, -6, -2, 4}};
static const WDATA_T conv3_weights_103_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, 7, -2, -3, -7},
    {2, -5, -9, -9, -10},
    {1, 15, 2, -4, -2},
    {10, 25, 6, 8, 7},
    {-3, 12, -3, -6, 2}};
static const WDATA_T conv3_weights_103_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {18, -2, -9, 0, -3},
    {-1, -8, 4, 16, 0},
    {-16, -4, 18, 9, -3},
    {-15, 2, -2, -6, 2},
    {-7, -8, -4, 1, 3}};
static const WDATA_T conv3_weights_103_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -8, -1, 11, 3},
    {6, -13, 7, 3, -13},
    {6, -8, 7, -1, -10},
    {8, -9, 0, -15, -13},
    {3, -6, -9, -18, -8}};
static const WDATA_T conv3_weights_103_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 6, 1, 1, 5},
    {-5, -4, 14, 11, 10},
    {-17, -8, 10, 2, 2},
    {-16, -10, -5, -9, 4},
    {8, 1, 10, 18, 11}};
static const WDATA_T conv3_weights_103_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 26, 19, 5, -6},
    {21, 17, -8, -2, -2},
    {3, -10, -15, 12, 17},
    {-4, 1, 3, 11, 18},
    {2, -1, -13, -2, 8}};
static const WDATA_T conv3_weights_103_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -1, -3, 2, 1},
    {1, 0, -2, 2, 2},
    {-2, 1, -1, 0, 1},
    {1, 0, 2, 3, 0},
    {1, 1, -3, 1, 1}};
static const WDATA_T conv3_weights_103_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 4, 3, -3, 0},
    {1, 2, 2, -1, 2},
    {2, -1, 1, 3, -2},
    {2, -4, 0, 1, -1},
    {-5, 1, -3, -4, 4}};
static const WDATA_T conv3_weights_103_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 10, -8, -9, -3},
    {-1, -5, -3, -3, 1},
    {-15, -2, 12, -2, 8},
    {-21, 4, 1, -1, 8},
    {-13, -3, -8, 0, 1}};
static const WDATA_T conv3_weights_103_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, 2, 5, -2, 4},
    {-12, -2, 4, 5, 9},
    {-5, 7, 8, -4, 8},
    {0, 16, 9, -10, 13},
    {6, 2, 8, 6, 3}};
static const WDATA_T conv3_weights_103_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, -4, -2, 2, 3},
    {-7, -9, -3, -11, -11},
    {10, -5, -11, -9, -4},
    {21, -3, -5, 9, 15},
    {14, 6, -2, 14, 7}};
static const WDATA_T conv3_weights_103_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, -5, -11, 7, 19},
    {5, 10, 10, -5, 0},
    {18, 17, -1, 5, -20},
    {7, 2, -6, 6, -19},
    {-5, -4, -6, -24, -21}};
static const WDATA_T conv3_weights_104_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -7, -1, -6, -22},
    {-1, -2, 6, 7, -13},
    {7, 23, 29, 7, -9},
    {8, -7, -5, -6, -18},
    {-7, -26, -20, -15, -14}};
static const WDATA_T conv3_weights_104_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {16, 7, -1, 1, 21},
    {6, 1, -22, 1, 24},
    {4, -11, -46, -23, 11},
    {39, 28, -5, -25, -12},
    {20, 17, 5, -4, -3}};
static const WDATA_T conv3_weights_104_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-24, -27, -9, 11, -5},
    {-12, -16, -10, 18, 4},
    {22, -14, -20, -11, -3},
    {6, -19, -25, -7, -7},
    {-7, 13, 4, 7, 3}};
static const WDATA_T conv3_weights_104_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -1, 0, -15},
    {8, -19, -45, -39, -29},
    {20, 1, -20, -13, -15},
    {5, -24, 4, 15, 9},
    {-33, -41, 15, 17, 22}};
static const WDATA_T conv3_weights_104_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -9, 12, 9, -8},
    {-1, 2, 11, -5, -8},
    {1, 4, 6, -4, -15},
    {-4, -7, -3, -4, -3},
    {-5, 10, 1, 0, -5}};
static const WDATA_T conv3_weights_104_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 13, 8, 25, 16},
    {13, -24, -28, -12, -8},
    {11, -4, -23, -14, -2},
    {3, 7, 2, -10, -19},
    {15, 22, -3, 6, -18}};
static const WDATA_T conv3_weights_104_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-37, -35, -35, -9, -9},
    {-11, -12, -11, -18, -11},
    {-40, -10, -32, -6, -10},
    {-43, -15, -4, 24, 15},
    {22, 21, 11, 35, 30}};
static const WDATA_T conv3_weights_104_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -14, 0, -6, -11},
    {-2, 6, 14, 6, 3},
    {-6, -11, -4, -5, 16},
    {-3, -19, -12, 16, 27},
    {4, -8, 10, 20, 29}};
static const WDATA_T conv3_weights_104_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 18, 18, 0, -7},
    {70, 64, 15, 7, -26},
    {48, 38, 19, -6, -21},
    {1, -1, 11, 18, -2},
    {20, 18, -10, -6, -13}};
static const WDATA_T conv3_weights_104_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, -2, -15, -15, -23},
    {27, 26, 9, 35, 9},
    {-25, -31, 14, 36, 1},
    {-38, -39, -19, 13, 13},
    {3, 22, -15, 25, 10}};
static const WDATA_T conv3_weights_104_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 2, -2, 3},
    {0, 5, -1, -1, 1},
    {-1, 1, 0, -2, 1},
    {0, 1, 1, 4, -3},
    {0, 2, 0, -1, 1}};
static const WDATA_T conv3_weights_104_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -7, -2, 0, -3},
    {-1, -3, 0, 3, -1},
    {3, 11, 9, 8, 1},
    {0, -4, 0, 6, 3},
    {-6, -16, -11, -1, 0}};
static const WDATA_T conv3_weights_104_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-43, -28, -3, -16, -30},
    {-49, -43, -13, 5, 0},
    {-38, -14, -17, -9, -11},
    {-27, -24, 1, -5, -11},
    {-19, 4, 11, -8, -16}};
static const WDATA_T conv3_weights_104_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 30, 13, -27, -25},
    {0, 4, 14, -21, -30},
    {19, 45, 39, -4, -9},
    {37, 46, 28, -8, -11},
    {10, 4, -14, -28, -26}};
static const WDATA_T conv3_weights_104_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 1, -9, -9, -17},
    {-9, -14, 9, 10, -17},
    {-12, 8, 57, 27, -4},
    {-9, -9, 6, -4, -9},
    {-22, -62, -50, -23, -20}};
static const WDATA_T conv3_weights_104_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -36, -31, 3, 10},
    {-2, 5, 11, 80, 74},
    {-11, 3, -13, -13, 10},
    {-2, -13, -28, 9, 21},
    {16, 11, 36, 16, 25}};
static const WDATA_T conv3_weights_105_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 6, 0, 5, -1},
    {5, -1, 7, -1, 3},
    {-1, -3, -2, -4, -4},
    {-1, -2, -1, 1, 2},
    {-1, 0, 3, -1, -1}};
static const WDATA_T conv3_weights_105_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -1, -1, 0, 1},
    {-2, -3, -4, 1, 4},
    {3, 2, -2, 0, 4},
    {-1, 0, 4, 4, -4},
    {0, 1, 2, 2, 1}};
static const WDATA_T conv3_weights_105_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, -2, -3},
    {0, -4, -2, -1, 3},
    {0, -3, 1, -6, 4},
    {0, -1, -1, -1, 2},
    {0, 1, -3, -1, 1}};
static const WDATA_T conv3_weights_105_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, 3, -1, 3},
    {-1, 2, 3, 3, -4},
    {0, 6, 1, 1, 0},
    {4, 2, 5, 0, -1},
    {-3, -2, -7, -4, -2}};
static const WDATA_T conv3_weights_105_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, -1, 0, -1},
    {-2, 4, 2, 2, 1},
    {0, -1, -3, -1, 3},
    {1, 0, -6, -3, 0},
    {-2, 0, 0, -1, -2}};
static const WDATA_T conv3_weights_105_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 0, -4, -4},
    {0, 3, -2, 0, 3},
    {-2, 3, 1, -2, -2},
    {-1, -3, 1, 1, -1},
    {2, -1, 3, 2, -3}};
static const WDATA_T conv3_weights_105_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 1, -1, 0},
    {-4, -1, -1, 2, 1},
    {0, -3, -2, -2, -1},
    {0, 2, 0, 7, -3},
    {0, 0, 0, -1, 0}};
static const WDATA_T conv3_weights_105_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 0, -1, 0, 0},
    {-1, -1, -5, -5, 1},
    {1, -1, -2, 2, 3},
    {0, -1, -4, -2, 6},
    {-2, -1, -2, 0, 0}};
static const WDATA_T conv3_weights_105_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, -1, -1, -3},
    {-7, -4, -1, 0, -3},
    {-4, -1, 1, 0, 0},
    {2, 4, 0, 0, -1},
    {0, -3, -7, -3, 0}};
static const WDATA_T conv3_weights_105_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, 2, -1, -5},
    {1, 2, -2, -4, -3},
    {0, -1, -3, -5, -1},
    {0, 0, -4, -2, 0},
    {-2, -2, -5, 0, 0}};
static const WDATA_T conv3_weights_105_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 2, 1, 1, 1},
    {-2, -1, 0, -3, -2},
    {-3, -2, 3, -1, 2},
    {1, -3, -3, -3, 1},
    {-2, -1, 1, -1, 1}};
static const WDATA_T conv3_weights_105_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, -2, 0, 4},
    {2, -2, 3, 1, 0},
    {-1, 2, -2, 0, 1},
    {-1, 1, 1, -2, 0},
    {0, 0, 2, 1, -1}};
static const WDATA_T conv3_weights_105_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -1, -1, 3},
    {0, -3, -1, -4, -6},
    {-3, -3, 2, -1, 1},
    {0, 3, 1, 2, 1},
    {0, -1, 2, 4, -1}};
static const WDATA_T conv3_weights_105_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -3, 0, 1, 0},
    {-1, -1, -2, -3, 0},
    {-2, -5, 5, 0, -2},
    {-1, -1, 0, -1, 5},
    {-4, 0, -1, 0, -1}};
static const WDATA_T conv3_weights_105_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 3, 5, 1},
    {1, 5, 2, 2, -2},
    {3, 4, 1, -2, 1},
    {-4, -1, -5, -3, -3},
    {0, -1, 0, 4, -4}};
static const WDATA_T conv3_weights_105_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -1, 0, 6},
    {-1, 1, -4, -6, -3},
    {2, -1, 1, -3, -3},
    {1, 3, 2, -3, -4},
    {0, -4, 0, -2, -3}};
static const WDATA_T conv3_weights_106_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 25, 49, 6, 1},
    {13, 34, 40, -1, -7},
    {44, 103, 39, -21, -5},
    {10, 40, 31, -9, 13},
    {7, 26, 8, 5, 1}};
static const WDATA_T conv3_weights_106_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -8, 11, 8, 20},
    {-20, -34, -4, 42, 17},
    {12, 15, -10, 10, -5},
    {-12, -3, 26, 8, -11},
    {5, 11, 22, 35, 8}};
static const WDATA_T conv3_weights_106_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, -25, -31, -22, 13},
    {-10, 12, -13, -18, -5},
    {8, -7, -19, 4, 22},
    {25, 12, -4, 15, 5},
    {21, 20, 5, 25, 12}};
static const WDATA_T conv3_weights_106_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 6, 6, 0, -2},
    {14, 17, -6, -20, -9},
    {20, 2, -25, 2, -7},
    {6, 8, 24, 24, 14},
    {-1, 54, 12, -26, -21}};
static const WDATA_T conv3_weights_106_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 13, 6, 18, 2},
    {-1, 20, 3, 9, 19},
    {-13, 15, 7, 9, 23},
    {10, 16, -15, 8, 22},
    {17, -14, 1, 5, 22}};
static const WDATA_T conv3_weights_106_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -33, -8, 26, 16},
    {-14, -9, -17, 0, 13},
    {15, 1, -21, -1, 15},
    {21, 6, 20, 20, 14},
    {20, 17, 2, 6, 5}};
static const WDATA_T conv3_weights_106_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {43, 41, 32, -5, -12},
    {21, -6, 3, 20, 13},
    {24, -38, -25, -5, 9},
    {4, 12, 0, 8, -8},
    {-47, -15, -9, 10, -21}};
static const WDATA_T conv3_weights_106_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, -2, 3, 15, 46},
    {2, -10, -5, -4, 17},
    {-12, -8, 2, -6, -11},
    {-12, -6, -12, 3, 22},
    {-1, -25, -21, -46, 5}};
static const WDATA_T conv3_weights_106_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {42, 42, 44, 13, -5},
    {27, -11, -14, 2, 11},
    {-37, -34, -4, 15, 14},
    {-42, -21, 12, -6, 11},
    {-26, 2, 36, 31, 28}};
static const WDATA_T conv3_weights_106_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {40, 3, -11, -17, -36},
    {-5, -30, 22, 37, -9},
    {-34, 3, 9, -4, -1},
    {-5, -1, 50, -6, -30},
    {4, 34, 59, 39, 49}};
static const WDATA_T conv3_weights_106_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -4, -1, 0},
    {3, 3, -3, 0, 2},
    {3, -2, 1, 3, 4},
    {-3, 0, 0, -2, -1},
    {-4, -4, -3, -1, 0}};
static const WDATA_T conv3_weights_106_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 4, 2, -3},
    {11, -6, -3, -2, 3},
    {5, -9, 8, 2, 2},
    {-8, -6, 18, -4, 1},
    {-1, 17, 19, 2, 7}};
static const WDATA_T conv3_weights_106_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -32, -21, -58, -17},
    {-37, -68, -36, -12, -8},
    {12, -53, -31, 18, 13},
    {31, -43, -39, -13, -32},
    {-13, -13, -3, 8, 12}};
static const WDATA_T conv3_weights_106_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -5, 0, -23, -29},
    {-4, -14, -18, -7, -10},
    {6, -13, -37, -11, -16},
    {-21, 17, -4, 12, -1},
    {25, 41, 10, 46, 37}};
static const WDATA_T conv3_weights_106_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-21, -6, -13, -19, 11},
    {17, 15, 24, -24, 8},
    {29, 23, 9, -16, -11},
    {31, 19, 30, 8, 12},
    {86, 71, 59, 8, -2}};
static const WDATA_T conv3_weights_106_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {31, 9, -10, -34, -37},
    {7, 18, 32, 18, -17},
    {22, -32, -13, 13, 5},
    {-4, -58, -29, -10, -18},
    {1, -5, -40, 25, 1}};
static const WDATA_T conv3_weights_107_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -5, -38, 1, -10},
    {-9, -41, -36, -23, -20},
    {16, -21, -34, -21, -5},
    {10, -12, -12, 14, 4},
    {0, -19, 6, 19, 10}};
static const WDATA_T conv3_weights_107_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 20, 25, -3, -9},
    {31, 16, 0, -3, 8},
    {-7, -28, -10, -17, -8},
    {10, 16, -20, -29, -9},
    {-8, 0, -10, -11, -8}};
static const WDATA_T conv3_weights_107_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-11, -12, 7, 12, 6},
    {-2, -24, 0, 43, 15},
    {-2, -17, 4, 29, 16},
    {0, 17, 26, 1, 8},
    {-2, 9, 11, -17, -6}};
static const WDATA_T conv3_weights_107_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -4, -1, -1, -10},
    {2, 8, 10, -11, -24},
    {-12, -24, -12, 1, -17},
    {-8, -8, 10, -27, -14},
    {16, 39, 5, 17, 20}};
static const WDATA_T conv3_weights_107_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, 4, 9, 0},
    {10, 1, 20, 19, -13},
    {14, 9, 28, 17, -4},
    {11, 4, 10, -1, -3},
    {-6, -6, -6, -15, 0}};
static const WDATA_T conv3_weights_107_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -8, 18, 46, 8},
    {11, 0, 5, 35, 8},
    {5, -8, -26, -10, -10},
    {1, 6, 1, 6, -3},
    {4, 3, 18, 19, 11}};
static const WDATA_T conv3_weights_107_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 9, -19, 0, -4},
    {4, 21, 16, 13, 9},
    {4, 2, -19, 6, 8},
    {-36, -5, 11, 9, 3},
    {7, 26, 23, 11, 7}};
static const WDATA_T conv3_weights_107_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-23, -11, -6, 11, 33},
    {-11, 4, 9, 33, 39},
    {-10, -15, 33, 33, -4},
    {14, 10, 39, 12, 10},
    {17, 19, -14, -5, 15}};
static const WDATA_T conv3_weights_107_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 0, 19, 16, -3},
    {3, 16, 56, 17, -17},
    {29, 58, 38, -11, -7},
    {-17, 3, -3, 1, -16},
    {5, 50, 45, -16, -7}};
static const WDATA_T conv3_weights_107_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-15, 6, -2, 3, -7},
    {15, 30, -8, -35, -37},
    {29, 2, -42, -26, 10},
    {13, 7, 21, -1, 23},
    {26, 40, -4, -20, 1}};
static const WDATA_T conv3_weights_107_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, 3, 0, -2},
    {-1, 3, 3, 2, -2},
    {-2, 1, 1, 1, 5},
    {-3, -2, 2, -5, -1},
    {0, 0, 3, 5, 1}};
static const WDATA_T conv3_weights_107_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -5, 0, 0, -5},
    {-7, 0, 3, 1, -2},
    {-10, -4, 1, 1, 0},
    {3, 7, 5, 2, -1},
    {4, -4, 5, 11, 4}};
static const WDATA_T conv3_weights_107_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, 19, 20, 9, -9},
    {26, 21, 19, 14, -6},
    {-5, -21, 9, 11, -2},
    {-8, -2, 11, 14, 23},
    {5, 8, -20, 15, 20}};
static const WDATA_T conv3_weights_107_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 2, 11, -6, -23},
    {7, 10, 49, 6, -31},
    {-22, 13, 29, 13, -3},
    {12, 28, 5, 16, 25},
    {-1, -7, 5, 11, 5}};
static const WDATA_T conv3_weights_107_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -6, -10, 12, -9},
    {-16, -17, 1, 2, 10},
    {-32, -24, -20, -23, -8},
    {11, 22, 17, 2, 14},
    {-15, -36, -22, 32, 42}};
static const WDATA_T conv3_weights_107_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -32, -24, -37, -35},
    {-2, -5, -24, -22, -30},
    {-23, 9, 33, 23, 37},
    {7, 9, 41, 32, 24},
    {12, 19, 13, -15, -17}};
static const WDATA_T conv3_weights_108_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -2, -1, 2, 0},
    {-1, -1, -1, -1, 0},
    {0, 1, 4, -3, 3},
    {-1, 2, 1, 2, 3},
    {-4, 2, 1, 1, -1}};
static const WDATA_T conv3_weights_108_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 13, 10, 1, -6},
    {2, 3, 5, 4, 8},
    {0, -3, -4, 2, 4},
    {-1, -2, -8, -5, 1},
    {-1, -1, -4, 0, 3}};
static const WDATA_T conv3_weights_108_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 7, 2, 1, -2},
    {5, -4, -1, 3, 0},
    {2, -1, -1, -2, 1},
    {3, 3, -1, 0, 2},
    {3, -1, 4, -2, 2}};
static const WDATA_T conv3_weights_108_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -1, -4, 0, 1},
    {-3, -5, -6, -4, -1},
    {-4, -3, -11, -5, -1},
    {-2, 0, 1, 1, 0},
    {-7, -4, 1, -2, 0}};
static const WDATA_T conv3_weights_108_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, -1, 2, 1},
    {5, 4, 0, 4, 1},
    {0, 3, 7, 1, -2},
    {4, 3, 6, 3, 2},
    {2, 3, 5, 0, -1}};
static const WDATA_T conv3_weights_108_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 6, 8, -1, -7},
    {-4, 1, 9, 8, 5},
    {0, -2, 0, 3, 4},
    {-2, -3, 1, 2, 5},
    {-3, -3, -3, -4, 3}};
static const WDATA_T conv3_weights_108_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -5, 1, 7, -4},
    {-5, 1, -7, -2, -1},
    {-5, -4, -5, -2, 2},
    {-1, 0, -2, 0, 2},
    {1, -1, 1, 0, -5}};
static const WDATA_T conv3_weights_108_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, 3, -1, 0},
    {5, 7, 1, 0, 1},
    {2, 1, 10, 6, 4},
    {3, 1, 6, 6, 6},
    {4, 5, 4, 3, 9}};
static const WDATA_T conv3_weights_108_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, -1, 3, 0},
    {-2, 0, 1, -4, -3},
    {-4, -9, -4, -5, -7},
    {-4, -1, 3, 2, -1},
    {-3, -5, 3, 4, -1}};
static const WDATA_T conv3_weights_108_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -7, -7, -2, 2},
    {-5, -2, -2, 7, 5},
    {-1, -1, 4, 3, -5},
    {-1, 4, 5, -5, 0},
    {2, 0, -5, -5, -4}};
static const WDATA_T conv3_weights_108_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 4, -2, -2, 3},
    {-3, 0, 0, -3, 0},
    {4, 2, 2, 2, -3},
    {4, -1, 1, 1, 1},
    {-2, -4, 0, 0, 1}};
static const WDATA_T conv3_weights_108_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, -1, 0, 3},
    {0, 0, -5, -1, -3},
    {2, -1, 0, -1, -1},
    {0, 0, 2, 4, 0},
    {0, 0, 0, 0, -2}};
static const WDATA_T conv3_weights_108_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, -6, -7},
    {10, 6, 8, 3, -1},
    {-3, -2, -6, -3, -3},
    {4, -5, -4, 0, 0},
    {-2, -3, -2, 3, 1}};
static const WDATA_T conv3_weights_108_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 6, 2, 5, -1},
    {-5, -7, -1, 0, -7},
    {-4, -5, 6, -2, -3},
    {0, 3, 0, -4, -1},
    {-3, 4, -1, 2, -1}};
static const WDATA_T conv3_weights_108_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 0, -2, -5, -2},
    {-2, 4, 6, 0, -3},
    {-10, -8, 1, 1, 6},
    {0, 0, 3, -2, 2},
    {4, 1, -4, 0, 7}};
static const WDATA_T conv3_weights_108_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -3, 1, -1, -4},
    {-2, 1, -3, -3, 2},
    {0, 2, 1, 3, 2},
    {0, -2, 0, 4, -4},
    {-3, 2, 4, 5, -7}};
static const WDATA_T conv3_weights_109_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 4, -4, -3, 7},
    {4, 2, 3, -8, -6},
    {4, 2, 8, 0, -5},
    {4, 8, 10, -4, 0},
    {8, 11, 3, 3, -1}};
static const WDATA_T conv3_weights_109_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 6, 5, -10, -19},
    {2, 11, -1, -7, 2},
    {-4, -1, 2, -4, -6},
    {4, 4, -6, 2, -8},
    {-1, 5, 1, -1, -2}};
static const WDATA_T conv3_weights_109_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 3, 6, 7, 2},
    {-3, 1, -3, 6, -2},
    {5, -12, -3, 4, -5},
    {-3, 5, -10, 3, -7},
    {-4, 3, -7, 1, 1}};
static const WDATA_T conv3_weights_109_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, 2, -1, -4},
    {-7, -6, -7, -7, 9},
    {1, 1, 0, -1, -4},
    {-1, -3, 3, 9, 4},
    {-9, 1, 19, 16, 6}};
static const WDATA_T conv3_weights_109_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 2, 11, 5, 2},
    {4, 7, 12, 10, 7},
    {3, 13, 7, 7, 6},
    {8, 10, 9, 4, -1},
    {4, 3, 4, 3, 3}};
static const WDATA_T conv3_weights_109_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -2, -9, -12, -12},
    {7, 10, 4, 1, 2},
    {-3, 1, -5, -4, -7},
    {0, 3, -3, -1, -6},
    {-2, 7, -1, 1, 2}};
static const WDATA_T conv3_weights_109_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, 0, 6, 5, -5},
    {2, 9, -1, -3, 3},
    {2, 1, 9, 5, 1},
    {5, -8, -4, 9, 1},
    {-16, -10, 0, 16, 0}};
static const WDATA_T conv3_weights_109_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 2, 3, -9, -3},
    {1, 6, -2, -12, 4},
    {2, -7, 1, -2, 0},
    {-5, -5, -7, 0, -2},
    {-6, 2, -4, 1, -2}};
static const WDATA_T conv3_weights_109_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -4, 4, 7, 4},
    {5, 1, 0, 3, -1},
    {4, -2, 4, 2, -3},
    {5, -1, -5, 0, -1},
    {-16, -9, 13, 12, 1}};
static const WDATA_T conv3_weights_109_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -10, -7, 8, 7},
    {-2, 0, 15, 10, 1},
    {4, 16, 2, 17, -2},
    {4, 15, 24, 8, -15},
    {15, 11, 6, -6, -1}};
static const WDATA_T conv3_weights_109_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 1, -1, -1},
    {0, 3, -2, -1, 2},
    {1, 0, 0, -1, 1},
    {-3, -3, -2, 1, -1},
    {-2, 3, 0, 3, 0}};
static const WDATA_T conv3_weights_109_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 0, 0, 0},
    {-1, 0, 0, -1, 0},
    {1, 1, -1, 2, -3},
    {0, 0, 0, 5, 4},
    {-1, 5, 6, 3, 3}};
static const WDATA_T conv3_weights_109_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, 6, 9, 1, -4},
    {-1, 6, 2, -1, 0},
    {-6, -2, -6, -5, -2},
    {2, -4, 1, -2, -4},
    {-4, -9, 3, -1, -2}};
static const WDATA_T conv3_weights_109_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 12, 5, 2, 1},
    {-9, -6, 1, -7, -12},
    {-1, 1, 2, -3, -5},
    {-7, 8, 10, 3, -9},
    {4, 8, 5, 1, -1}};
static const WDATA_T conv3_weights_109_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -4, -7, -3, -8},
    {-3, -6, -10, -11, -3},
    {-13, -12, 1, -5, -5},
    {-6, -15, -10, 6, -5},
    {22, 7, 3, 2, -6}};
static const WDATA_T conv3_weights_109_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 8, 4, -8, -2},
    {10, 9, -16, 7, -12},
    {4, 8, 5, 5, 8},
    {-1, 7, -6, 13, 13},
    {-4, -1, 5, 12, 2}};
static const WDATA_T conv3_weights_110_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 11, 15, -3, -9},
    {-16, 8, 5, 2, -5},
    {-16, -3, -6, -15, -5},
    {-10, -11, -10, -20, -3},
    {-2, 4, -12, -24, -4}};
static const WDATA_T conv3_weights_110_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 5, 7, -2, -1},
    {-2, 5, 2, 2, -5},
    {-19, 4, 3, 9, 2},
    {3, -2, -4, -18, -10},
    {9, 6, 7, -5, -10}};
static const WDATA_T conv3_weights_110_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 5, 17, 12, 17},
    {-1, 7, -5, 1, 9},
    {15, 9, -1, -13, 7},
    {10, 16, 6, 23, 3},
    {-1, 3, 4, 10, 4}};
static const WDATA_T conv3_weights_110_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, 0, 0, -4},
    {-12, -9, -3, -10, 7},
    {-4, -20, -20, -5, 8},
    {-11, -15, -15, -9, 2},
    {-24, -19, -12, 8, 0}};
static const WDATA_T conv3_weights_110_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 2, 8, 4, -2},
    {5, 9, 9, 6, -3},
    {5, 16, 19, 15, 3},
    {1, 14, 7, 2, 0},
    {0, 2, 7, 1, 7}};
static const WDATA_T conv3_weights_110_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -2, 5, 14, 5},
    {1, 5, -10, -3, -7},
    {-7, -27, -5, 2, 21},
    {-6, -11, -3, 6, 0},
    {3, -3, -8, 2, -9}};
static const WDATA_T conv3_weights_110_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 1, 10, 2, -8},
    {-1, 8, 9, 9, 0},
    {-12, -4, 3, 3, -3},
    {-12, -10, -10, 1, 6},
    {-7, -12, -4, 12, -2}};
static const WDATA_T conv3_weights_110_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 5, -5, -18, -3},
    {-1, 16, 14, 6, 6},
    {0, 19, 21, 15, 5},
    {-2, 11, 13, 13, 4},
    {-4, -5, 24, 29, 17}};
static const WDATA_T conv3_weights_110_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 6, -6, 7, -2},
    {-4, -6, -25, 5, -8},
    {0, -8, -4, -3, -13},
    {-4, -29, -49, -5, -6},
    {0, 9, -2, 4, -8}};
static const WDATA_T conv3_weights_110_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-17, -19, -12, 6, 1},
    {-18, -7, 0, -6, -8},
    {-15, -3, -4, 18, -3},
    {-2, 10, 18, -12, -30},
    {7, -8, 8, 9, -11}};
static const WDATA_T conv3_weights_110_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 0, -4, 0},
    {0, 0, 3, -4, 0},
    {1, 0, -3, -1, -2},
    {1, 0, -2, 1, 1},
    {0, -1, -2, 4, 2}};
static const WDATA_T conv3_weights_110_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -3, -3, 1, -1},
    {0, -1, -1, -1, 3},
    {0, 4, 2, 1, 2},
    {-2, 0, 3, 4, 1},
    {-2, -2, -3, -2, 0}};
static const WDATA_T conv3_weights_110_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 0, 6, -7, -16},
    {10, 5, -15, 2, 1},
    {4, -15, -5, 2, -8},
    {6, 16, 15, -3, -6},
    {-4, 16, 7, -3, -9}};
static const WDATA_T conv3_weights_110_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 6, 11, -3, -11},
    {-6, -13, -17, 0, -6},
    {-10, -29, -28, -6, -23},
    {12, 32, 2, -3, -10},
    {4, 3, 0, -2, -7}};
static const WDATA_T conv3_weights_110_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, 0, -8, -6, -7},
    {-11, -12, 3, 4, -5},
    {-32, -26, -16, -22, -4},
    {-2, -8, 5, -13, -13},
    {-15, -15, 8, -10, -24}};
static const WDATA_T conv3_weights_110_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 14, 13, 4, 6},
    {1, -1, -6, -1, 6},
    {0, -1, 8, 2, 21},
    {9, -1, -6, 13, 28},
    {1, 11, 9, 38, 16}};
static const WDATA_T conv3_weights_111_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, -15, -8, 10, -2},
    {-13, -37, -32, -29, -19},
    {-8, -39, -41, -25, -10},
    {-20, -23, -3, -19, -2},
    {-17, -13, -10, -14, -3}};
static const WDATA_T conv3_weights_111_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -11, 11, 19, 13},
    {21, 9, -13, 3, 7},
    {-7, -23, -24, -29, -17},
    {-5, -10, -31, -34, -22},
    {1, 0, -5, -19, -13}};
static const WDATA_T conv3_weights_111_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, 4, -20, 0, 0},
    {-1, -15, -32, 8, -2},
    {3, -14, -21, -14, -6},
    {15, 15, 13, -6, 6},
    {10, 7, 8, -2, 6}};
static const WDATA_T conv3_weights_111_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -2, 3, -4, -4},
    {-4, -8, 0, -3, 7},
    {4, -23, -27, 1, 9},
    {-4, 2, 5, -6, 4},
    {-3, 0, -5, 12, -11}};
static const WDATA_T conv3_weights_111_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -11, -1, -7, -9},
    {-6, -9, 9, -6, -2},
    {-1, 7, 17, 14, 6},
    {-1, 9, 15, 8, 0},
    {-5, -1, -8, -3, 0}};
static const WDATA_T conv3_weights_111_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-7, -22, -18, 21, 8},
    {13, -3, -25, -2, 10},
    {7, -9, -25, -31, -17},
    {-8, -20, -16, -22, -31},
    {3, -6, -14, -16, -26}};
static const WDATA_T conv3_weights_111_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-27, 9, 24, 0, -7},
    {1, 20, 5, 5, 7},
    {16, 28, 15, 11, 2},
    {14, 20, 23, 9, 8},
    {11, 11, 18, 16, 6}};
static const WDATA_T conv3_weights_111_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-8, -7, -15, -28, -18},
    {-3, -11, -10, 15, 14},
    {-5, -4, 7, 28, 32},
    {-3, -3, 9, 3, 19},
    {-7, -7, -2, -5, 5}};
static const WDATA_T conv3_weights_111_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-18, 13, 13, 11, -4},
    {-2, 2, 9, 9, -7},
    {0, 11, 20, 4, -8},
    {-18, 6, 18, 2, -8},
    {-14, -15, 6, 21, -5}};
static const WDATA_T conv3_weights_111_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-19, -30, -16, 19, 8},
    {-13, 10, 23, 6, -11},
    {6, 40, 7, 7, 0},
    {-10, 15, 33, 16, -31},
    {9, 19, 9, -15, -19}};
static const WDATA_T conv3_weights_111_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 3, 3, 2, -2},
    {-2, 2, -1, 1, 0},
    {-4, -1, -1, -2, -3},
    {1, -1, 1, 3, -1},
    {0, 0, 1, -2, 0}};
static const WDATA_T conv3_weights_111_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -6, -3, 0, 4},
    {-7, -6, 2, -4, -2},
    {-6, 1, 4, 4, 0},
    {-2, 5, 5, 5, 6},
    {-2, -2, 0, 1, 0}};
static const WDATA_T conv3_weights_111_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-24, 2, -3, 5, 6},
    {0, 38, 14, 14, -2},
    {8, 0, -3, 3, -3},
    {12, 14, -20, -19, -6},
    {35, 31, 3, 1, -11}};
static const WDATA_T conv3_weights_111_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, -8, 5, 11},
    {-2, -12, -11, 3, 5},
    {-20, -26, -27, -5, -8},
    {-14, -13, -3, -2, -9},
    {-20, -10, 1, -4, -5}};
static const WDATA_T conv3_weights_111_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, -2, 0, -7},
    {1, -13, -17, -11, -3},
    {-8, -30, -37, -32, -18},
    {-11, -23, -22, -6, -12},
    {-10, -9, -3, -26, -25}};
static const WDATA_T conv3_weights_111_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 18, 12, -8, -16},
    {8, 3, 5, 1, -20},
    {2, -11, 25, 40, 21},
    {12, -9, -4, 15, 47},
    {2, 18, -6, -5, 3}};
static const WDATA_T conv3_weights_112_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 28, 10, 2, -2},
    {1, 9, 5, 6, 9},
    {-24, -19, -9, 13, 7},
    {9, 7, -1, 15, 8},
    {-3, 4, 12, 9, 0}};
static const WDATA_T conv3_weights_112_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 18, 21, 13, 1},
    {12, 26, 30, -20, -17},
    {-3, 7, 26, 8, 2},
    {-14, -15, -5, 13, -4},
    {-14, -15, -10, -4, -8}};
static const WDATA_T conv3_weights_112_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, -1, -19, -10, -13},
    {-1, -8, -22, 7, 0},
    {-11, -3, -7, 3, -10},
    {-10, 0, 0, 4, -3},
    {-5, 0, -8, 1, 2}};
static const WDATA_T conv3_weights_112_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, 4, 4, 7},
    {1, 2, 21, 8, 4},
    {-9, -1, 21, 2, 9},
    {-1, 6, -6, -19, 1},
    {-2, -20, -17, 12, 28}};
static const WDATA_T conv3_weights_112_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 8, 4, -1, 2},
    {4, 5, 3, 2, -5},
    {9, 5, 1, 6, 4},
    {1, -2, 16, 6, -1},
    {-1, 5, 11, 8, -3}};
static const WDATA_T conv3_weights_112_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 23, 19, 8, 6},
    {6, 16, 19, 5, 12},
    {-7, -1, 15, 16, 15},
    {-6, -9, 1, 0, 1},
    {-21, -21, -1, 3, -1}};
static const WDATA_T conv3_weights_112_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -31, -18, -11, 5},
    {-9, -9, -7, -2, 1},
    {15, 17, 17, -3, 6},
    {21, 12, 2, 0, 2},
    {11, -2, -6, -9, 4}};
static const WDATA_T conv3_weights_112_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, -11, -16, 5, -5},
    {-15, -8, 5, 6, 5},
    {-6, 18, -5, -7, -1},
    {0, 12, -8, -11, -18},
    {4, 4, 7, -2, -30}};
static const WDATA_T conv3_weights_112_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -4, -23, -3, 1},
    {-26, -5, -3, -5, 5},
    {18, 33, -26, -8, 7},
    {26, -4, -18, 2, 16},
    {-7, -14, -29, -5, 11}};
static const WDATA_T conv3_weights_112_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -8, 8, 10, 1},
    {-2, 0, -9, -23, 5},
    {21, 5, -17, -9, 15},
    {31, 13, -11, -14, 14},
    {-8, -15, -9, -10, -6}};
static const WDATA_T conv3_weights_112_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 3, 0, 3, 1},
    {0, -1, -1, -2, 2},
    {0, -1, 0, -3, 0},
    {0, 1, -1, 1, 0},
    {0, 1, -1, 4, 0}};
static const WDATA_T conv3_weights_112_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 4, 3, 2, 0},
    {-5, 7, -2, 3, 2},
    {2, 5, -2, -1, 2},
    {7, 6, -6, -2, 2},
    {7, 4, -1, 2, -2}};
static const WDATA_T conv3_weights_112_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, -4, -8, 11, 10},
    {18, 4, -5, 10, 16},
    {13, 19, 32, -6, 14},
    {10, -13, 1, 14, 16},
    {9, -1, 20, 9, 2}};
static const WDATA_T conv3_weights_112_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 27, 18, 21, 20},
    {27, 21, 21, 4, 12},
    {-13, -20, 5, 16, 20},
    {-31, -47, -24, 6, 12},
    {-16, -34, -10, -1, -3}};
static const WDATA_T conv3_weights_112_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 17, 22, 12, 3},
    {3, 8, -3, 20, 14},
    {-27, -23, -38, 3, 21},
    {-11, -12, -29, -4, 20},
    {-1, 13, 9, -3, 10}};
static const WDATA_T conv3_weights_112_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-5, -1, -8, -13, 8},
    {-8, -7, -27, -22, 4},
    {0, -4, 12, -23, -6},
    {3, 19, 22, -10, 5},
    {-4, 7, -8, -1, -18}};
static const WDATA_T conv3_weights_113_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -2, 13, -3, 3},
    {28, 21, -9, -20, -12},
    {3, -10, -19, -8, 8},
    {-1, -9, 4, 15, 14},
    {-25, -19, 17, 18, 11}};
static const WDATA_T conv3_weights_113_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 14, 20, -6, 3},
    {12, 13, 27, -12, 5},
    {7, 24, 20, -9, -18},
    {-8, -11, -24, -62, -26},
    {-30, -24, -20, -11, -1}};
static const WDATA_T conv3_weights_113_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -12, -14, 6, 11},
    {9, -15, -7, 10, 12},
    {-5, -11, -15, 0, 6},
    {-18, -13, -16, 24, 18},
    {1, -15, -7, -9, 10}};
static const WDATA_T conv3_weights_113_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 1, -1, 0, -3},
    {9, 13, -3, -26, -11},
    {18, 15, -7, -15, -4},
    {18, 7, -24, -32, 10},
    {21, 20, 12, 14, 26}};
static const WDATA_T conv3_weights_113_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 4, 8, 7, -4},
    {8, 4, 18, 22, 7},
    {11, 6, 21, 21, 4},
    {2, 7, 17, 13, -2},
    {-11, 14, 12, 3, -3}};
static const WDATA_T conv3_weights_113_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 11, 13, 18, 3},
    {23, 3, -11, 13, 2},
    {17, 6, 4, 27, 4},
    {5, 11, -5, -9, -26},
    {-21, -28, -25, -3, -13}};
static const WDATA_T conv3_weights_113_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 23, 21, -3, 3},
    {6, -2, 4, 14, 7},
    {-21, -15, 14, 24, 12},
    {31, 36, 10, 14, 2},
    {23, 7, -1, -33, -13}};
static const WDATA_T conv3_weights_113_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 9, -8, -8, -7},
    {-10, -9, -6, -8, 12},
    {-5, -7, -1, -22, 6},
    {3, -14, 22, -10, 10},
    {-17, 11, 46, 35, 19}};
static const WDATA_T conv3_weights_113_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {12, 15, 19, 2, -3},
    {-8, -9, 1, -10, -31},
    {-31, -7, 5, 25, -22},
    {23, 21, -15, 25, 11},
    {39, 5, -31, -29, -24}};
static const WDATA_T conv3_weights_113_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 15, 15, 0, 3},
    {13, 4, -7, -22, -3},
    {-18, -27, -11, 33, 38},
    {16, 20, -15, -12, -23},
    {5, -36, -64, -12, -34}};
static const WDATA_T conv3_weights_113_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -2, -5, -1, -2},
    {1, 4, 2, 1, 1},
    {0, -1, -1, 0, 4},
    {-3, -1, -3, -1, -3},
    {1, 0, -2, 2, 2}};
static const WDATA_T conv3_weights_113_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, 1, -3, 3},
    {2, 9, 0, -6, -3},
    {5, 10, -1, -4, 1},
    {2, 2, -6, 1, 6},
    {1, -2, 1, 5, -3}};
static const WDATA_T conv3_weights_113_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 16, 10, 4, -6},
    {7, 13, -5, 15, 13},
    {-4, 13, 24, 7, 0},
    {0, 35, 21, 20, 2},
    {3, 14, -18, 5, -1}};
static const WDATA_T conv3_weights_113_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {8, 9, 20, 9, 5},
    {17, 24, 3, 13, 5},
    {19, 20, 12, 9, -28},
    {-12, -36, -21, -14, -16},
    {-44, -51, -12, 5, 3}};
static const WDATA_T conv3_weights_113_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 2, -18, -13, -3},
    {22, 0, -3, 11, 4},
    {38, 28, 2, -20, 7},
    {-17, -22, -33, -22, -4},
    {-37, -24, 8, 2, 21}};
static const WDATA_T conv3_weights_113_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 26, 9, -5, -10},
    {3, 3, -4, -5, 13},
    {26, 3, 14, -5, 8},
    {10, -13, -8, -16, 20},
    {-24, -13, -6, -14, 14}};
static const WDATA_T conv3_weights_114_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-9, 22, 26, -3, 3},
    {23, 19, 7, -3, 5},
    {27, 58, 19, -19, -3},
    {-11, -16, -4, -28, -5},
    {5, 15, -10, -27, 3}};
static const WDATA_T conv3_weights_114_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-14, -19, -19, -8, 20},
    {-38, -23, -5, 30, 34},
    {0, -3, -14, 4, 7},
    {16, 14, -1, -5, -1},
    {24, 17, 13, 11, 16}};
static const WDATA_T conv3_weights_114_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, 9, 45, 21, 32},
    {-1, 22, 27, -4, -6},
    {13, 12, -1, -12, -1},
    {20, -2, -9, 11, -7},
    {6, 0, -6, -17, 2}};
static const WDATA_T conv3_weights_114_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -1, 0, -13},
    {-12, 0, -7, -26, -19},
    {10, 8, -22, -10, 7},
    {-5, -6, 4, 34, 22},
    {-3, 3, 6, -21, -38}};
static const WDATA_T conv3_weights_114_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, 12, 9, 8, 0},
    {-1, 10, 6, -1, 1},
    {-15, 5, 14, 8, -3},
    {-17, 14, -10, 7, 12},
    {4, -4, 8, 15, 14}};
static const WDATA_T conv3_weights_114_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -24, -10, 11, 4},
    {-13, -5, -24, -9, -22},
    {5, -5, 12, -3, -8},
    {-2, 18, 6, 17, 7},
    {17, 14, -11, 4, -1}};
static const WDATA_T conv3_weights_114_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {31, 38, 37, 32, -8},
    {10, 10, 6, 14, 3},
    {-18, -43, -39, 1, -16},
    {-20, -28, -21, 1, -7},
    {-6, -15, -4, 11, -10}};
static const WDATA_T conv3_weights_114_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {11, 26, 33, -19, -9},
    {12, 9, 11, -17, -6},
    {-3, -43, 21, 20, 11},
    {-5, -24, 2, 27, 33},
    {-8, 6, 7, 9, 37}};
static const WDATA_T conv3_weights_114_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 13, 14, 19, -1},
    {11, -29, -6, 15, -6},
    {-57, -52, 15, 18, -10},
    {-22, -28, 7, 15, -6},
    {29, 33, 23, 22, -15}};
static const WDATA_T conv3_weights_114_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 9, -2, -2, -4},
    {8, -36, -3, 31, 7},
    {-33, -3, 31, 20, -7},
    {-35, -9, 9, 11, -33},
    {1, 10, 33, 44, 11}};
static const WDATA_T conv3_weights_114_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, -2, -2, -4, -2},
    {-1, -2, 0, 0, 1},
    {4, 3, 0, -3, 0},
    {1, 2, 3, 3, -1},
    {3, 4, 0, 0, -1}};
static const WDATA_T conv3_weights_114_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -5, 1, -1, 0},
    {9, -3, 3, 4, -4},
    {9, -9, -2, -1, 0},
    {-10, -8, 7, 3, -2},
    {-7, 1, -7, -6, 2}};
static const WDATA_T conv3_weights_114_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-12, 2, 17, -17, -12},
    {-38, -19, 14, -32, -15},
    {-11, -13, -27, -3, -14},
    {5, 23, 6, -5, -20},
    {1, -5, -24, -11, -7}};
static const WDATA_T conv3_weights_114_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-20, -25, -36, -33, -34},
    {-33, -39, -31, -1, -26},
    {-15, -21, -35, -5, -30},
    {17, 66, 33, 3, -19},
    {25, 33, 4, 14, 2}};
static const WDATA_T conv3_weights_114_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 7, -1, 7, 0},
    {8, 7, 18, -17, 0},
    {48, 29, 33, -17, -13},
    {36, 4, 7, -10, -24},
    {3, 3, 1, -12, -17}};
static const WDATA_T conv3_weights_114_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {34, 26, 11, 5, 14},
    {14, 17, 24, 29, 8},
    {11, 2, -17, 21, -13},
    {3, -45, -23, -16, -15},
    {9, 13, 12, 33, 35}};
static const WDATA_T conv3_weights_115_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 46, 43, 8, -5},
    {13, 22, 10, -6, -18},
    {28, 37, 9, -23, -12},
    {-1, 1, 12, -4, 4},
    {-9, 0, 5, 8, 5}};
static const WDATA_T conv3_weights_115_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -14, -1, 14, 26},
    {-9, -19, 2, 15, 9},
    {-4, -18, -14, 10, -8},
    {1, 1, -1, -3, -9},
    {19, 21, 17, 8, 1}};
static const WDATA_T conv3_weights_115_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -41, -21, -32, -5},
    {-11, -27, -19, -26, -15},
    {-2, 0, -3, -8, -6},
    {2, -9, 4, 11, 6},
    {-3, -5, 4, 7, 4}};
static const WDATA_T conv3_weights_115_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 0, 2, -1, -6},
    {11, 11, 1, -4, -2},
    {5, 0, -31, -9, -2},
    {1, 0, 8, 23, 2},
    {-4, 17, 11, 2, -9}};
static const WDATA_T conv3_weights_115_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, -5, -4, -11, -13},
    {5, 0, -7, -3, 1},
    {-3, 2, -5, 6, 6},
    {-4, -2, -7, -4, 3},
    {-9, -14, -11, -13, 1}};
static const WDATA_T conv3_weights_115_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, -4, -2, 8, -1},
    {-1, -4, -10, 3, 7},
    {4, -3, -21, -6, -7},
    {8, 2, -5, -6, -3},
    {7, 1, 2, 6, 0}};
static const WDATA_T conv3_weights_115_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {30, 20, 9, -17, -19},
    {3, 1, -4, -11, -3},
    {-14, -38, -17, 4, 8},
    {-25, -10, 2, 1, 2},
    {0, 4, 0, 2, -8}};
static const WDATA_T conv3_weights_115_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, -2, -13, -27, -1},
    {-11, -19, -8, -5, 17},
    {-15, -11, 11, 23, 10},
    {-12, -9, 14, 23, -2},
    {-1, -9, -10, -39, -23}};
static const WDATA_T conv3_weights_115_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {19, 27, 18, 6, -7},
    {13, -6, 1, 11, -3},
    {-32, -6, 14, 11, 3},
    {-14, -4, 9, -4, 4},
    {-2, 40, 38, 35, 31}};
static const WDATA_T conv3_weights_115_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {20, 13, -3, -9, -29},
    {5, -26, 5, 31, -15},
    {-30, -3, 38, 8, -14},
    {-9, 11, 25, 4, -4},
    {-21, -13, 14, 11, 2}};
static const WDATA_T conv3_weights_115_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, -1, 0, 3},
    {-1, 2, 1, 1, 3},
    {2, -2, 0, 2, 0},
    {-2, 3, 3, 0, -4},
    {3, 1, -3, 2, -1}};
static const WDATA_T conv3_weights_115_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -3, -1, -1, -2},
    {7, 3, -1, -3, -3},
    {5, -3, 4, -1, -1},
    {-8, -4, 8, 5, -2},
    {-2, 3, 5, 4, 11}};
static const WDATA_T conv3_weights_115_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -20, -15, -29, -11},
    {-10, -23, -38, -30, -9},
    {-7, -20, -52, -2, 5},
    {-19, -9, -12, -7, -10},
    {-8, 5, 3, 14, 9}};
static const WDATA_T conv3_weights_115_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, 1, -2, -9},
    {-3, -20, -20, 6, 13},
    {24, 6, -17, -1, -5},
    {9, 34, 11, 2, 2},
    {21, 37, 19, 23, 26}};
static const WDATA_T conv3_weights_115_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -4, -9, -3, 4},
    {13, 21, 20, -16, -9},
    {16, 16, 7, -17, -13},
    {20, 34, 29, 12, 6},
    {-14, -12, 20, 9, -18}};
static const WDATA_T conv3_weights_115_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 7, -19, -25, -30},
    {-11, -9, -13, -6, -27},
    {-12, -22, -7, 24, 9},
    {-10, -35, -7, 9, 16},
    {-4, -9, -3, 15, -7}};
static const WDATA_T conv3_weights_116_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -16, -23, -3, 0},
    {10, -9, -13, -16, -3},
    {7, -16, -17, -7, 5},
    {3, 19, 14, 8, 0},
    {7, 15, 18, 19, -2}};
static const WDATA_T conv3_weights_116_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -9, -9, -14, -13},
    {6, 0, -8, -22, -30},
    {18, 11, 11, -4, -19},
    {20, 28, 3, -8, -6},
    {-4, 4, 8, -7, -5}};
static const WDATA_T conv3_weights_116_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 19, 9, 8, -14},
    {4, 0, -4, 17, -20},
    {-13, -9, -9, 16, -9},
    {-26, 11, 0, 23, -12},
    {-8, 4, 3, 1, -15}};
static const WDATA_T conv3_weights_116_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 1, -4, -2, 5},
    {-2, 8, 13, 11, 9},
    {-3, 0, 2, 18, 14},
    {-10, -3, -10, -18, -18},
    {10, 8, 1, 7, 4}};
static const WDATA_T conv3_weights_116_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 14, 18, 10, 2},
    {3, 22, 27, 7, 2},
    {11, 10, 27, 7, 6},
    {4, 17, 27, 4, -2},
    {1, 8, 7, 4, -9}};
static const WDATA_T conv3_weights_116_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, -10, -10, -17},
    {2, -3, -8, -2, -14},
    {3, 7, -6, 1, -23},
    {5, 15, 14, 17, 5},
    {-1, 11, 21, 19, 14}};
static const WDATA_T conv3_weights_116_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {3, 20, 20, 10, 7},
    {-2, 9, 4, 12, 6},
    {-5, 21, 29, 12, 13},
    {-11, 7, 10, 2, 1},
    {5, 5, -5, -2, 3}};
static const WDATA_T conv3_weights_116_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 11, -9, 0, -5},
    {1, 5, -9, -1, -3},
    {-6, 1, -5, 4, -2},
    {-13, 3, -15, -32, -34},
    {3, 6, -34, -32, -30}};
static const WDATA_T conv3_weights_116_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -18, -9, 1, 7},
    {-21, -21, -10, -6, -7},
    {10, 16, 18, 0, 15},
    {15, 18, -15, 0, -2},
    {11, 4, -1, 13, 15}};
static const WDATA_T conv3_weights_116_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, 12, 24, 19, 23},
    {3, 27, 10, -15, -4},
    {17, 31, -11, -12, -4},
    {6, 0, -1, 8, 23},
    {-1, 9, 0, -8, -14}};
static const WDATA_T conv3_weights_116_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 0, -3, -1, 1},
    {0, 2, -3, -1, 0},
    {2, 0, -3, 2, -2},
    {0, 2, 0, 1, -1},
    {1, 1, -4, 1, -2}};
static const WDATA_T conv3_weights_116_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -3, 5, 0, 1},
    {0, 5, 2, 2, 4},
    {-1, 3, -3, 1, 1},
    {2, 3, -2, 2, 0},
    {3, 0, -4, 5, -1}};
static const WDATA_T conv3_weights_116_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 21, 9, 11, 12},
    {16, 8, 4, -3, -1},
    {-17, -23, 11, -4, 6},
    {-21, -2, 21, 5, 20},
    {-4, -21, -2, 7, 1}};
static const WDATA_T conv3_weights_116_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, -16, -21, -8, 1},
    {19, 23, 2, 1, -2},
    {41, 45, 5, 10, 19},
    {16, 10, 14, 2, 1},
    {-4, -3, 1, 3, 2}};
static const WDATA_T conv3_weights_116_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -2, -1, 2},
    {6, -2, -9, -7, 5},
    {-6, -9, -30, -15, -6},
    {-13, 0, -4, 15, 15},
    {-22, -23, -3, 18, 18}};
static const WDATA_T conv3_weights_116_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {14, 25, 20, 18, 10},
    {8, 0, 1, -19, -30},
    {4, 7, 29, 23, -1},
    {2, 20, 29, 16, -18},
    {5, 4, 1, -17, -32}};
static const WDATA_T conv3_weights_117_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {21, 15, 13, 2, -1},
    {25, 6, 24, 18, 29},
    {7, -10, 13, 23, 12},
    {5, -10, 5, 10, -17},
    {20, 14, 11, -7, -9}};
static const WDATA_T conv3_weights_117_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, -3, -17, -2, 9},
    {-4, 8, -9, -18, -17},
    {13, 3, -3, -7, 30},
    {14, 11, -3, 2, 20},
    {8, -1, 0, 11, 20}};
static const WDATA_T conv3_weights_117_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {15, 37, 29, 16, -6},
    {1, 14, 11, -17, -12},
    {-1, 10, 7, -11, -5},
    {-6, 7, 1, 9, -16},
    {-6, -9, 9, -12, -12}};
static const WDATA_T conv3_weights_117_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 1, -2, 5, 17},
    {-6, 5, 16, 15, 0},
    {11, -1, -9, -3, 24},
    {9, -12, 3, 11, -5},
    {-6, -43, -18, 14, -12}};
static const WDATA_T conv3_weights_117_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {4, 7, 14, 2, 1},
    {3, 1, 8, -6, -8},
    {8, 0, 6, -3, -8},
    {-1, 7, 4, 3, -7},
    {0, 6, 7, 16, 1}};
static const WDATA_T conv3_weights_117_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 4, -20, -24, -4},
    {0, 11, 14, -15, -14},
    {-1, -2, 6, 11, 4},
    {-7, 8, -4, 19, 9},
    {2, -10, -10, 4, 10}};
static const WDATA_T conv3_weights_117_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-13, 2, 7, 14, 10},
    {-14, 4, 5, 4, -3},
    {-19, -7, 9, -17, -17},
    {-30, -11, -19, -5, -7},
    {1, -12, 0, 4, 6}};
static const WDATA_T conv3_weights_117_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 9, -2, -25, -36},
    {8, 3, 2, -21, -42},
    {-17, -18, 18, 6, -4},
    {-13, -9, -1, 4, 10},
    {-1, 5, 15, 24, 11}};
static const WDATA_T conv3_weights_117_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-4, -21, -16, 1, 9},
    {1, -5, -2, 1, -7},
    {11, 0, -15, -22, 1},
    {24, 13, -5, -4, -5},
    {25, 18, -1, -3, -7}};
static const WDATA_T conv3_weights_117_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {9, 8, 10, 17, 28},
    {-5, -1, 4, 11, 27},
    {-1, 5, 3, -23, -22},
    {-4, -11, -29, -12, -14},
    {-17, -25, 8, 30, 0}};
static const WDATA_T conv3_weights_117_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 5, 2, -2, 2},
    {-2, -2, 4, 4, -1},
    {2, 2, 2, 0, -2},
    {1, 2, 5, -4, 2},
    {-3, -1, 3, 0, 3}};
static const WDATA_T conv3_weights_117_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 1, 4, 2, 1},
    {-2, -1, 1, 1, 2},
    {0, 3, -1, 0, 0},
    {-1, 4, -4, -1, -3},
    {0, -5, -7, -7, -7}};
static const WDATA_T conv3_weights_117_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 31, 26, 27, 21},
    {-2, 28, 1, -11, -2},
    {-12, 25, -5, -11, 0},
    {-8, 38, 11, -16, -4},
    {-16, 4, -9, 4, -8}};
static const WDATA_T conv3_weights_117_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -4, -19, -3, 9},
    {8, -8, -24, -15, 0},
    {16, 8, 3, -6, -10},
    {21, 19, 8, -15, -6},
    {9, -5, -12, -24, -21}};
static const WDATA_T conv3_weights_117_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {17, 6, 3, -8, -2},
    {24, 9, -9, -3, 1},
    {-6, -5, -2, 12, 7},
    {2, 0, -10, 0, -19},
    {-21, -1, 0, -23, -33}};
static const WDATA_T conv3_weights_117_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-6, 16, 32, 61, 46},
    {0, -8, 9, 7, 24},
    {-18, -4, -1, -10, -20},
    {-7, 10, -29, -14, -9},
    {6, 15, 6, 0, 19}};
static const WDATA_T conv3_weights_118_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-10, -37, -54, -15, -5},
    {-11, -27, -23, -18, 1},
    {-26, -47, -13, 11, 4},
    {-12, -13, -2, 31, 12},
    {-17, -13, 5, 18, 9}};
static const WDATA_T conv3_weights_118_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 20, 8, -4, -27},
    {20, 31, 9, -5, 4},
    {-2, -2, 4, -24, -8},
    {1, 5, -20, -23, -41},
    {-11, -20, -18, -8, -7}};
static const WDATA_T conv3_weights_118_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {22, 57, 45, 32, 1},
    {20, 22, 42, 30, 0},
    {4, 5, 8, 14, -4},
    {-5, -5, -1, 12, 3},
    {-6, -4, -2, -17, -4}};
static const WDATA_T conv3_weights_118_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, 2, 3, 3, -5},
    {-2, -1, -5, -6, -6},
    {3, 9, 13, -6, -9},
    {3, -3, -15, -17, -3},
    {12, -7, -4, 31, 55}};
static const WDATA_T conv3_weights_118_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 12, 10, 10, -1},
    {-1, 4, 16, 5, -7},
    {8, 5, 18, -4, 2},
    {8, -1, 18, -1, 4},
    {6, 4, 1, -4, -4}};
static const WDATA_T conv3_weights_118_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {6, 21, 13, -2, -21},
    {22, 10, 23, 13, 0},
    {1, -5, 9, 8, 10},
    {-2, 0, -9, 11, -2},
    {-9, -15, -10, 0, 0}};
static const WDATA_T conv3_weights_118_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-37, -22, -18, 37, 22},
    {-12, 3, 12, 11, 0},
    {-10, 62, 32, 13, 10},
    {13, 35, 3, 8, 7},
    {21, 29, 19, -7, 8}};
static const WDATA_T conv3_weights_118_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {5, 29, 27, 5, -29},
    {18, 32, 20, -3, -10},
    {25, 7, 3, -8, 6},
    {14, 15, 5, -5, -22},
    {-3, 20, 7, 24, -6}};
static const WDATA_T conv3_weights_118_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -28, -34, 2, 4},
    {-18, -1, 30, -2, -18},
    {26, 27, -1, -15, -15},
    {27, 16, -9, 3, -6},
    {25, 1, -32, -16, 6}};
static const WDATA_T conv3_weights_118_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, -19, -10, 5, 19},
    {8, 33, -8, -22, 2},
    {33, -1, -45, -10, 5},
    {20, -16, -39, -3, 44},
    {4, -11, -34, -27, -10}};
static const WDATA_T conv3_weights_118_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -1, 2, -3},
    {0, -2, -1, 2, 1},
    {-1, 1, 1, 1, 2},
    {1, 2, 0, -1, -1},
    {2, 1, 0, 3, 1}};
static const WDATA_T conv3_weights_118_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -2, 1, 1, 2},
    {-7, -4, 1, 2, -3},
    {-1, 7, -5, -1, 0},
    {9, 10, -12, 6, -1},
    {4, -3, -6, 4, 2}};
static const WDATA_T conv3_weights_118_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {13, 23, 22, 40, 11},
    {27, 29, 46, 16, 7},
    {7, 21, 37, -9, 5},
    {-1, 35, 39, 10, 20},
    {0, 11, 11, -2, 1}};
static const WDATA_T conv3_weights_118_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {7, -8, -3, 11, 24},
    {3, 24, 23, -13, -5},
    {-1, 14, 15, 10, -4},
    {19, -7, 13, -10, 2},
    {-11, -27, 5, -4, -6}};
static const WDATA_T conv3_weights_118_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {10, 5, 13, -1, -13},
    {-8, -1, -10, 1, -9},
    {-28, -15, -23, 2, 8},
    {-12, -13, -7, 25, 17},
    {-42, -48, -39, 12, 41}};
static const WDATA_T conv3_weights_118_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-16, 8, 37, 46, 45},
    {10, 6, 21, 5, 26},
    {18, 17, 11, -7, -10},
    {17, 35, 5, 2, 13},
    {8, 23, 10, -27, -23}};
static const WDATA_T conv3_weights_119_0[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, -2, -2, -2, 2},
    {-2, 3, 0, 3, -3},
    {1, 5, -1, -2, -2},
    {-2, -3, -1, -1, -2},
    {0, 1, -2, 0, -2}};
static const WDATA_T conv3_weights_119_1[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, -2, -1, -2},
    {2, 2, 0, 1, 2},
    {-4, -2, -2, 0, 1},
    {2, -1, 0, 0, 0},
    {1, -1, 1, -1, -3}};
static const WDATA_T conv3_weights_119_2[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-2, 1, -2, 0, 0},
    {-2, -1, 1, 0, -3},
    {-4, 1, 2, -1, 0},
    {0, -2, 2, 1, 2},
    {-1, 0, -1, 3, 0}};
static const WDATA_T conv3_weights_119_3[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, -4, 1, 2},
    {0, -1, -1, 1, 3},
    {-1, 0, 2, 0, -3},
    {2, -2, -4, 0, -1},
    {-2, 0, 0, -1, 0}};
static const WDATA_T conv3_weights_119_4[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -3, -2, -1, 0},
    {-1, 0, 2, 3, 1},
    {1, -2, -1, 1, 1},
    {-1, -2, 0, 0, 1},
    {-1, 0, 2, 2, 2}};
static const WDATA_T conv3_weights_119_5[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {0, -1, 0, 0, 3},
    {1, -1, 2, -1, -3},
    {1, 0, -1, -3, 1},
    {-4, 0, -3, -2, -1},
    {2, -4, -2, 1, 2}};
static const WDATA_T conv3_weights_119_6[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 0, -1, 0, 2},
    {0, 1, 0, 1, -1},
    {1, -1, -2, -1, 0},
    {1, 1, 1, 1, 0},
    {-3, -1, 0, 2, 0}};
static const WDATA_T conv3_weights_119_7[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-3, 2, 4, -2, 1},
    {-2, -1, -3, 0, -3},
    {-1, 0, -1, -2, 1},
    {-1, 0, -3, 0, 0},
    {-1, 3, 3, -4, -3}};
static const WDATA_T conv3_weights_119_8[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 1, -1, 3, -1},
    {-2, -2, 3, -2, -1},
    {-1, 1, 0, 0, -1},
    {0, 0, 0, 2, 0},
    {-4, -4, -2, 0, -1}};
static const WDATA_T conv3_weights_119_9[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, -2, -2, -4},
    {0, -1, 0, 1, -1},
    {-4, 1, 0, 0, -2},
    {-1, -3, 1, -1, -3},
    {-4, -1, -1, 2, 2}};
static const WDATA_T conv3_weights_119_10[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {-1, -1, 2, 1, 3},
    {-3, -2, -3, 2, -1},
    {0, 3, -2, 2, 0},
    {1, -1, -1, -2, -2},
    {-1, 2, 2, 3, 0}};
static const WDATA_T conv3_weights_119_11[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 0, 0, 1},
    {0, -3, -4, -1, 1},
    {1, -6, -1, -1, -1},
    {-3, -2, 4, 1, -1},
    {0, 0, 1, 1, 0}};
static const WDATA_T conv3_weights_119_12[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, -1, 3, -2},
    {-1, 0, -1, 0, -1},
    {2, -1, 1, -1, 0},
    {2, -1, 1, -3, -4},
    {1, 2, 2, 0, 1}};
static const WDATA_T conv3_weights_119_13[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, 2, -1, 3, 0},
    {1, 1, 0, -3, -1},
    {0, 1, 0, -2, -1},
    {1, 0, -2, 3, 1},
    {1, 0, -4, -1, 2}};
static const WDATA_T conv3_weights_119_14[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {1, 0, 0, 0, -3},
    {-3, 2, -1, -3, 5},
    {-3, 0, -1, -4, -1},
    {1, 4, 0, 0, -1},
    {3, -1, -1, 0, 0}};
static const WDATA_T conv3_weights_119_15[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH] = {
    {2, -2, -1, -4, 2},
    {-2, -5, 0, 2, -1},
    {2, 2, 2, 2, -4},
    {2, 1, -4, 0, 0},
    {-3, -1, 1, 0, 1}};
typedef WDATA_T CONV3_KERNEL_T[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH];
static const CONV3_KERNEL_T* conv3_weights[CONV3_NB_OUTPUTS][CONV3_NB_CHANNELS] = {
    {&conv3_weights_0_0, &conv3_weights_0_1, &conv3_weights_0_2, &conv3_weights_0_3, &conv3_weights_0_4, &conv3_weights_0_5, &conv3_weights_0_6, &conv3_weights_0_7, &conv3_weights_0_8, &conv3_weights_0_9, &conv3_weights_0_10, &conv3_weights_0_11, &conv3_weights_0_12, &conv3_weights_0_13, &conv3_weights_0_14, &conv3_weights_0_15},
    {&conv3_weights_1_0, &conv3_weights_1_1, &conv3_weights_1_2, &conv3_weights_1_3, &conv3_weights_1_4, &conv3_weights_1_5, &conv3_weights_1_6, &conv3_weights_1_7, &conv3_weights_1_8, &conv3_weights_1_9, &conv3_weights_1_10, &conv3_weights_1_11, &conv3_weights_1_12, &conv3_weights_1_13, &conv3_weights_1_14, &conv3_weights_1_15},
    {&conv3_weights_2_0, &conv3_weights_2_1, &conv3_weights_2_2, &conv3_weights_2_3, &conv3_weights_2_4, &conv3_weights_2_5, &conv3_weights_2_6, &conv3_weights_2_7, &conv3_weights_2_8, &conv3_weights_2_9, &conv3_weights_2_10, &conv3_weights_2_11, &conv3_weights_2_12, &conv3_weights_2_13, &conv3_weights_2_14, &conv3_weights_2_15},
    {&conv3_weights_3_0, &conv3_weights_3_1, &conv3_weights_3_2, &conv3_weights_3_3, &conv3_weights_3_4, &conv3_weights_3_5, &conv3_weights_3_6, &conv3_weights_3_7, &conv3_weights_3_8, &conv3_weights_3_9, &conv3_weights_3_10, &conv3_weights_3_11, &conv3_weights_3_12, &conv3_weights_3_13, &conv3_weights_3_14, &conv3_weights_3_15},
    {&conv3_weights_4_0, &conv3_weights_4_1, &conv3_weights_4_2, &conv3_weights_4_3, &conv3_weights_4_4, &conv3_weights_4_5, &conv3_weights_4_6, &conv3_weights_4_7, &conv3_weights_4_8, &conv3_weights_4_9, &conv3_weights_4_10, &conv3_weights_4_11, &conv3_weights_4_12, &conv3_weights_4_13, &conv3_weights_4_14, &conv3_weights_4_15},
    {&conv3_weights_5_0, &conv3_weights_5_1, &conv3_weights_5_2, &conv3_weights_5_3, &conv3_weights_5_4, &conv3_weights_5_5, &conv3_weights_5_6, &conv3_weights_5_7, &conv3_weights_5_8, &conv3_weights_5_9, &conv3_weights_5_10, &conv3_weights_5_11, &conv3_weights_5_12, &conv3_weights_5_13, &conv3_weights_5_14, &conv3_weights_5_15},
    {&conv3_weights_6_0, &conv3_weights_6_1, &conv3_weights_6_2, &conv3_weights_6_3, &conv3_weights_6_4, &conv3_weights_6_5, &conv3_weights_6_6, &conv3_weights_6_7, &conv3_weights_6_8, &conv3_weights_6_9, &conv3_weights_6_10, &conv3_weights_6_11, &conv3_weights_6_12, &conv3_weights_6_13, &conv3_weights_6_14, &conv3_weights_6_15},
    {&conv3_weights_7_0, &conv3_weights_7_1, &conv3_weights_7_2, &conv3_weights_7_3, &conv3_weights_7_4, &conv3_weights_7_5, &conv3_weights_7_6, &conv3_weights_7_7, &conv3_weights_7_8, &conv3_weights_7_9, &conv3_weights_7_10, &conv3_weights_7_11, &conv3_weights_7_12, &conv3_weights_7_13, &conv3_weights_7_14, &conv3_weights_7_15},
    {&conv3_weights_8_0, &conv3_weights_8_1, &conv3_weights_8_2, &conv3_weights_8_3, &conv3_weights_8_4, &conv3_weights_8_5, &conv3_weights_8_6, &conv3_weights_8_7, &conv3_weights_8_8, &conv3_weights_8_9, &conv3_weights_8_10, &conv3_weights_8_11, &conv3_weights_8_12, &conv3_weights_8_13, &conv3_weights_8_14, &conv3_weights_8_15},
    {&conv3_weights_9_0, &conv3_weights_9_1, &conv3_weights_9_2, &conv3_weights_9_3, &conv3_weights_9_4, &conv3_weights_9_5, &conv3_weights_9_6, &conv3_weights_9_7, &conv3_weights_9_8, &conv3_weights_9_9, &conv3_weights_9_10, &conv3_weights_9_11, &conv3_weights_9_12, &conv3_weights_9_13, &conv3_weights_9_14, &conv3_weights_9_15},
    {&conv3_weights_10_0, &conv3_weights_10_1, &conv3_weights_10_2, &conv3_weights_10_3, &conv3_weights_10_4, &conv3_weights_10_5, &conv3_weights_10_6, &conv3_weights_10_7, &conv3_weights_10_8, &conv3_weights_10_9, &conv3_weights_10_10, &conv3_weights_10_11, &conv3_weights_10_12, &conv3_weights_10_13, &conv3_weights_10_14, &conv3_weights_10_15},
    {&conv3_weights_11_0, &conv3_weights_11_1, &conv3_weights_11_2, &conv3_weights_11_3, &conv3_weights_11_4, &conv3_weights_11_5, &conv3_weights_11_6, &conv3_weights_11_7, &conv3_weights_11_8, &conv3_weights_11_9, &conv3_weights_11_10, &conv3_weights_11_11, &conv3_weights_11_12, &conv3_weights_11_13, &conv3_weights_11_14, &conv3_weights_11_15},
    {&conv3_weights_12_0, &conv3_weights_12_1, &conv3_weights_12_2, &conv3_weights_12_3, &conv3_weights_12_4, &conv3_weights_12_5, &conv3_weights_12_6, &conv3_weights_12_7, &conv3_weights_12_8, &conv3_weights_12_9, &conv3_weights_12_10, &conv3_weights_12_11, &conv3_weights_12_12, &conv3_weights_12_13, &conv3_weights_12_14, &conv3_weights_12_15},
    {&conv3_weights_13_0, &conv3_weights_13_1, &conv3_weights_13_2, &conv3_weights_13_3, &conv3_weights_13_4, &conv3_weights_13_5, &conv3_weights_13_6, &conv3_weights_13_7, &conv3_weights_13_8, &conv3_weights_13_9, &conv3_weights_13_10, &conv3_weights_13_11, &conv3_weights_13_12, &conv3_weights_13_13, &conv3_weights_13_14, &conv3_weights_13_15},
    {&conv3_weights_14_0, &conv3_weights_14_1, &conv3_weights_14_2, &conv3_weights_14_3, &conv3_weights_14_4, &conv3_weights_14_5, &conv3_weights_14_6, &conv3_weights_14_7, &conv3_weights_14_8, &conv3_weights_14_9, &conv3_weights_14_10, &conv3_weights_14_11, &conv3_weights_14_12, &conv3_weights_14_13, &conv3_weights_14_14, &conv3_weights_14_15},
    {&conv3_weights_15_0, &conv3_weights_15_1, &conv3_weights_15_2, &conv3_weights_15_3, &conv3_weights_15_4, &conv3_weights_15_5, &conv3_weights_15_6, &conv3_weights_15_7, &conv3_weights_15_8, &conv3_weights_15_9, &conv3_weights_15_10, &conv3_weights_15_11, &conv3_weights_15_12, &conv3_weights_15_13, &conv3_weights_15_14, &conv3_weights_15_15},
    {&conv3_weights_16_0, &conv3_weights_16_1, &conv3_weights_16_2, &conv3_weights_16_3, &conv3_weights_16_4, &conv3_weights_16_5, &conv3_weights_16_6, &conv3_weights_16_7, &conv3_weights_16_8, &conv3_weights_16_9, &conv3_weights_16_10, &conv3_weights_16_11, &conv3_weights_16_12, &conv3_weights_16_13, &conv3_weights_16_14, &conv3_weights_16_15},
    {&conv3_weights_17_0, &conv3_weights_17_1, &conv3_weights_17_2, &conv3_weights_17_3, &conv3_weights_17_4, &conv3_weights_17_5, &conv3_weights_17_6, &conv3_weights_17_7, &conv3_weights_17_8, &conv3_weights_17_9, &conv3_weights_17_10, &conv3_weights_17_11, &conv3_weights_17_12, &conv3_weights_17_13, &conv3_weights_17_14, &conv3_weights_17_15},
    {&conv3_weights_18_0, &conv3_weights_18_1, &conv3_weights_18_2, &conv3_weights_18_3, &conv3_weights_18_4, &conv3_weights_18_5, &conv3_weights_18_6, &conv3_weights_18_7, &conv3_weights_18_8, &conv3_weights_18_9, &conv3_weights_18_10, &conv3_weights_18_11, &conv3_weights_18_12, &conv3_weights_18_13, &conv3_weights_18_14, &conv3_weights_18_15},
    {&conv3_weights_19_0, &conv3_weights_19_1, &conv3_weights_19_2, &conv3_weights_19_3, &conv3_weights_19_4, &conv3_weights_19_5, &conv3_weights_19_6, &conv3_weights_19_7, &conv3_weights_19_8, &conv3_weights_19_9, &conv3_weights_19_10, &conv3_weights_19_11, &conv3_weights_19_12, &conv3_weights_19_13, &conv3_weights_19_14, &conv3_weights_19_15},
    {&conv3_weights_20_0, &conv3_weights_20_1, &conv3_weights_20_2, &conv3_weights_20_3, &conv3_weights_20_4, &conv3_weights_20_5, &conv3_weights_20_6, &conv3_weights_20_7, &conv3_weights_20_8, &conv3_weights_20_9, &conv3_weights_20_10, &conv3_weights_20_11, &conv3_weights_20_12, &conv3_weights_20_13, &conv3_weights_20_14, &conv3_weights_20_15},
    {&conv3_weights_21_0, &conv3_weights_21_1, &conv3_weights_21_2, &conv3_weights_21_3, &conv3_weights_21_4, &conv3_weights_21_5, &conv3_weights_21_6, &conv3_weights_21_7, &conv3_weights_21_8, &conv3_weights_21_9, &conv3_weights_21_10, &conv3_weights_21_11, &conv3_weights_21_12, &conv3_weights_21_13, &conv3_weights_21_14, &conv3_weights_21_15},
    {&conv3_weights_22_0, &conv3_weights_22_1, &conv3_weights_22_2, &conv3_weights_22_3, &conv3_weights_22_4, &conv3_weights_22_5, &conv3_weights_22_6, &conv3_weights_22_7, &conv3_weights_22_8, &conv3_weights_22_9, &conv3_weights_22_10, &conv3_weights_22_11, &conv3_weights_22_12, &conv3_weights_22_13, &conv3_weights_22_14, &conv3_weights_22_15},
    {&conv3_weights_23_0, &conv3_weights_23_1, &conv3_weights_23_2, &conv3_weights_23_3, &conv3_weights_23_4, &conv3_weights_23_5, &conv3_weights_23_6, &conv3_weights_23_7, &conv3_weights_23_8, &conv3_weights_23_9, &conv3_weights_23_10, &conv3_weights_23_11, &conv3_weights_23_12, &conv3_weights_23_13, &conv3_weights_23_14, &conv3_weights_23_15},
    {&conv3_weights_24_0, &conv3_weights_24_1, &conv3_weights_24_2, &conv3_weights_24_3, &conv3_weights_24_4, &conv3_weights_24_5, &conv3_weights_24_6, &conv3_weights_24_7, &conv3_weights_24_8, &conv3_weights_24_9, &conv3_weights_24_10, &conv3_weights_24_11, &conv3_weights_24_12, &conv3_weights_24_13, &conv3_weights_24_14, &conv3_weights_24_15},
    {&conv3_weights_25_0, &conv3_weights_25_1, &conv3_weights_25_2, &conv3_weights_25_3, &conv3_weights_25_4, &conv3_weights_25_5, &conv3_weights_25_6, &conv3_weights_25_7, &conv3_weights_25_8, &conv3_weights_25_9, &conv3_weights_25_10, &conv3_weights_25_11, &conv3_weights_25_12, &conv3_weights_25_13, &conv3_weights_25_14, &conv3_weights_25_15},
    {&conv3_weights_26_0, &conv3_weights_26_1, &conv3_weights_26_2, &conv3_weights_26_3, &conv3_weights_26_4, &conv3_weights_26_5, &conv3_weights_26_6, &conv3_weights_26_7, &conv3_weights_26_8, &conv3_weights_26_9, &conv3_weights_26_10, &conv3_weights_26_11, &conv3_weights_26_12, &conv3_weights_26_13, &conv3_weights_26_14, &conv3_weights_26_15},
    {&conv3_weights_27_0, &conv3_weights_27_1, &conv3_weights_27_2, &conv3_weights_27_3, &conv3_weights_27_4, &conv3_weights_27_5, &conv3_weights_27_6, &conv3_weights_27_7, &conv3_weights_27_8, &conv3_weights_27_9, &conv3_weights_27_10, &conv3_weights_27_11, &conv3_weights_27_12, &conv3_weights_27_13, &conv3_weights_27_14, &conv3_weights_27_15},
    {&conv3_weights_28_0, &conv3_weights_28_1, &conv3_weights_28_2, &conv3_weights_28_3, &conv3_weights_28_4, &conv3_weights_28_5, &conv3_weights_28_6, &conv3_weights_28_7, &conv3_weights_28_8, &conv3_weights_28_9, &conv3_weights_28_10, &conv3_weights_28_11, &conv3_weights_28_12, &conv3_weights_28_13, &conv3_weights_28_14, &conv3_weights_28_15},
    {&conv3_weights_29_0, &conv3_weights_29_1, &conv3_weights_29_2, &conv3_weights_29_3, &conv3_weights_29_4, &conv3_weights_29_5, &conv3_weights_29_6, &conv3_weights_29_7, &conv3_weights_29_8, &conv3_weights_29_9, &conv3_weights_29_10, &conv3_weights_29_11, &conv3_weights_29_12, &conv3_weights_29_13, &conv3_weights_29_14, &conv3_weights_29_15},
    {&conv3_weights_30_0, &conv3_weights_30_1, &conv3_weights_30_2, &conv3_weights_30_3, &conv3_weights_30_4, &conv3_weights_30_5, &conv3_weights_30_6, &conv3_weights_30_7, &conv3_weights_30_8, &conv3_weights_30_9, &conv3_weights_30_10, &conv3_weights_30_11, &conv3_weights_30_12, &conv3_weights_30_13, &conv3_weights_30_14, &conv3_weights_30_15},
    {&conv3_weights_31_0, &conv3_weights_31_1, &conv3_weights_31_2, &conv3_weights_31_3, &conv3_weights_31_4, &conv3_weights_31_5, &conv3_weights_31_6, &conv3_weights_31_7, &conv3_weights_31_8, &conv3_weights_31_9, &conv3_weights_31_10, &conv3_weights_31_11, &conv3_weights_31_12, &conv3_weights_31_13, &conv3_weights_31_14, &conv3_weights_31_15},
    {&conv3_weights_32_0, &conv3_weights_32_1, &conv3_weights_32_2, &conv3_weights_32_3, &conv3_weights_32_4, &conv3_weights_32_5, &conv3_weights_32_6, &conv3_weights_32_7, &conv3_weights_32_8, &conv3_weights_32_9, &conv3_weights_32_10, &conv3_weights_32_11, &conv3_weights_32_12, &conv3_weights_32_13, &conv3_weights_32_14, &conv3_weights_32_15},
    {&conv3_weights_33_0, &conv3_weights_33_1, &conv3_weights_33_2, &conv3_weights_33_3, &conv3_weights_33_4, &conv3_weights_33_5, &conv3_weights_33_6, &conv3_weights_33_7, &conv3_weights_33_8, &conv3_weights_33_9, &conv3_weights_33_10, &conv3_weights_33_11, &conv3_weights_33_12, &conv3_weights_33_13, &conv3_weights_33_14, &conv3_weights_33_15},
    {&conv3_weights_34_0, &conv3_weights_34_1, &conv3_weights_34_2, &conv3_weights_34_3, &conv3_weights_34_4, &conv3_weights_34_5, &conv3_weights_34_6, &conv3_weights_34_7, &conv3_weights_34_8, &conv3_weights_34_9, &conv3_weights_34_10, &conv3_weights_34_11, &conv3_weights_34_12, &conv3_weights_34_13, &conv3_weights_34_14, &conv3_weights_34_15},
    {&conv3_weights_35_0, &conv3_weights_35_1, &conv3_weights_35_2, &conv3_weights_35_3, &conv3_weights_35_4, &conv3_weights_35_5, &conv3_weights_35_6, &conv3_weights_35_7, &conv3_weights_35_8, &conv3_weights_35_9, &conv3_weights_35_10, &conv3_weights_35_11, &conv3_weights_35_12, &conv3_weights_35_13, &conv3_weights_35_14, &conv3_weights_35_15},
    {&conv3_weights_36_0, &conv3_weights_36_1, &conv3_weights_36_2, &conv3_weights_36_3, &conv3_weights_36_4, &conv3_weights_36_5, &conv3_weights_36_6, &conv3_weights_36_7, &conv3_weights_36_8, &conv3_weights_36_9, &conv3_weights_36_10, &conv3_weights_36_11, &conv3_weights_36_12, &conv3_weights_36_13, &conv3_weights_36_14, &conv3_weights_36_15},
    {&conv3_weights_37_0, &conv3_weights_37_1, &conv3_weights_37_2, &conv3_weights_37_3, &conv3_weights_37_4, &conv3_weights_37_5, &conv3_weights_37_6, &conv3_weights_37_7, &conv3_weights_37_8, &conv3_weights_37_9, &conv3_weights_37_10, &conv3_weights_37_11, &conv3_weights_37_12, &conv3_weights_37_13, &conv3_weights_37_14, &conv3_weights_37_15},
    {&conv3_weights_38_0, &conv3_weights_38_1, &conv3_weights_38_2, &conv3_weights_38_3, &conv3_weights_38_4, &conv3_weights_38_5, &conv3_weights_38_6, &conv3_weights_38_7, &conv3_weights_38_8, &conv3_weights_38_9, &conv3_weights_38_10, &conv3_weights_38_11, &conv3_weights_38_12, &conv3_weights_38_13, &conv3_weights_38_14, &conv3_weights_38_15},
    {&conv3_weights_39_0, &conv3_weights_39_1, &conv3_weights_39_2, &conv3_weights_39_3, &conv3_weights_39_4, &conv3_weights_39_5, &conv3_weights_39_6, &conv3_weights_39_7, &conv3_weights_39_8, &conv3_weights_39_9, &conv3_weights_39_10, &conv3_weights_39_11, &conv3_weights_39_12, &conv3_weights_39_13, &conv3_weights_39_14, &conv3_weights_39_15},
    {&conv3_weights_40_0, &conv3_weights_40_1, &conv3_weights_40_2, &conv3_weights_40_3, &conv3_weights_40_4, &conv3_weights_40_5, &conv3_weights_40_6, &conv3_weights_40_7, &conv3_weights_40_8, &conv3_weights_40_9, &conv3_weights_40_10, &conv3_weights_40_11, &conv3_weights_40_12, &conv3_weights_40_13, &conv3_weights_40_14, &conv3_weights_40_15},
    {&conv3_weights_41_0, &conv3_weights_41_1, &conv3_weights_41_2, &conv3_weights_41_3, &conv3_weights_41_4, &conv3_weights_41_5, &conv3_weights_41_6, &conv3_weights_41_7, &conv3_weights_41_8, &conv3_weights_41_9, &conv3_weights_41_10, &conv3_weights_41_11, &conv3_weights_41_12, &conv3_weights_41_13, &conv3_weights_41_14, &conv3_weights_41_15},
    {&conv3_weights_42_0, &conv3_weights_42_1, &conv3_weights_42_2, &conv3_weights_42_3, &conv3_weights_42_4, &conv3_weights_42_5, &conv3_weights_42_6, &conv3_weights_42_7, &conv3_weights_42_8, &conv3_weights_42_9, &conv3_weights_42_10, &conv3_weights_42_11, &conv3_weights_42_12, &conv3_weights_42_13, &conv3_weights_42_14, &conv3_weights_42_15},
    {&conv3_weights_43_0, &conv3_weights_43_1, &conv3_weights_43_2, &conv3_weights_43_3, &conv3_weights_43_4, &conv3_weights_43_5, &conv3_weights_43_6, &conv3_weights_43_7, &conv3_weights_43_8, &conv3_weights_43_9, &conv3_weights_43_10, &conv3_weights_43_11, &conv3_weights_43_12, &conv3_weights_43_13, &conv3_weights_43_14, &conv3_weights_43_15},
    {&conv3_weights_44_0, &conv3_weights_44_1, &conv3_weights_44_2, &conv3_weights_44_3, &conv3_weights_44_4, &conv3_weights_44_5, &conv3_weights_44_6, &conv3_weights_44_7, &conv3_weights_44_8, &conv3_weights_44_9, &conv3_weights_44_10, &conv3_weights_44_11, &conv3_weights_44_12, &conv3_weights_44_13, &conv3_weights_44_14, &conv3_weights_44_15},
    {&conv3_weights_45_0, &conv3_weights_45_1, &conv3_weights_45_2, &conv3_weights_45_3, &conv3_weights_45_4, &conv3_weights_45_5, &conv3_weights_45_6, &conv3_weights_45_7, &conv3_weights_45_8, &conv3_weights_45_9, &conv3_weights_45_10, &conv3_weights_45_11, &conv3_weights_45_12, &conv3_weights_45_13, &conv3_weights_45_14, &conv3_weights_45_15},
    {&conv3_weights_46_0, &conv3_weights_46_1, &conv3_weights_46_2, &conv3_weights_46_3, &conv3_weights_46_4, &conv3_weights_46_5, &conv3_weights_46_6, &conv3_weights_46_7, &conv3_weights_46_8, &conv3_weights_46_9, &conv3_weights_46_10, &conv3_weights_46_11, &conv3_weights_46_12, &conv3_weights_46_13, &conv3_weights_46_14, &conv3_weights_46_15},
    {&conv3_weights_47_0, &conv3_weights_47_1, &conv3_weights_47_2, &conv3_weights_47_3, &conv3_weights_47_4, &conv3_weights_47_5, &conv3_weights_47_6, &conv3_weights_47_7, &conv3_weights_47_8, &conv3_weights_47_9, &conv3_weights_47_10, &conv3_weights_47_11, &conv3_weights_47_12, &conv3_weights_47_13, &conv3_weights_47_14, &conv3_weights_47_15},
    {&conv3_weights_48_0, &conv3_weights_48_1, &conv3_weights_48_2, &conv3_weights_48_3, &conv3_weights_48_4, &conv3_weights_48_5, &conv3_weights_48_6, &conv3_weights_48_7, &conv3_weights_48_8, &conv3_weights_48_9, &conv3_weights_48_10, &conv3_weights_48_11, &conv3_weights_48_12, &conv3_weights_48_13, &conv3_weights_48_14, &conv3_weights_48_15},
    {&conv3_weights_49_0, &conv3_weights_49_1, &conv3_weights_49_2, &conv3_weights_49_3, &conv3_weights_49_4, &conv3_weights_49_5, &conv3_weights_49_6, &conv3_weights_49_7, &conv3_weights_49_8, &conv3_weights_49_9, &conv3_weights_49_10, &conv3_weights_49_11, &conv3_weights_49_12, &conv3_weights_49_13, &conv3_weights_49_14, &conv3_weights_49_15},
    {&conv3_weights_50_0, &conv3_weights_50_1, &conv3_weights_50_2, &conv3_weights_50_3, &conv3_weights_50_4, &conv3_weights_50_5, &conv3_weights_50_6, &conv3_weights_50_7, &conv3_weights_50_8, &conv3_weights_50_9, &conv3_weights_50_10, &conv3_weights_50_11, &conv3_weights_50_12, &conv3_weights_50_13, &conv3_weights_50_14, &conv3_weights_50_15},
    {&conv3_weights_51_0, &conv3_weights_51_1, &conv3_weights_51_2, &conv3_weights_51_3, &conv3_weights_51_4, &conv3_weights_51_5, &conv3_weights_51_6, &conv3_weights_51_7, &conv3_weights_51_8, &conv3_weights_51_9, &conv3_weights_51_10, &conv3_weights_51_11, &conv3_weights_51_12, &conv3_weights_51_13, &conv3_weights_51_14, &conv3_weights_51_15},
    {&conv3_weights_52_0, &conv3_weights_52_1, &conv3_weights_52_2, &conv3_weights_52_3, &conv3_weights_52_4, &conv3_weights_52_5, &conv3_weights_52_6, &conv3_weights_52_7, &conv3_weights_52_8, &conv3_weights_52_9, &conv3_weights_52_10, &conv3_weights_52_11, &conv3_weights_52_12, &conv3_weights_52_13, &conv3_weights_52_14, &conv3_weights_52_15},
    {&conv3_weights_53_0, &conv3_weights_53_1, &conv3_weights_53_2, &conv3_weights_53_3, &conv3_weights_53_4, &conv3_weights_53_5, &conv3_weights_53_6, &conv3_weights_53_7, &conv3_weights_53_8, &conv3_weights_53_9, &conv3_weights_53_10, &conv3_weights_53_11, &conv3_weights_53_12, &conv3_weights_53_13, &conv3_weights_53_14, &conv3_weights_53_15},
    {&conv3_weights_54_0, &conv3_weights_54_1, &conv3_weights_54_2, &conv3_weights_54_3, &conv3_weights_54_4, &conv3_weights_54_5, &conv3_weights_54_6, &conv3_weights_54_7, &conv3_weights_54_8, &conv3_weights_54_9, &conv3_weights_54_10, &conv3_weights_54_11, &conv3_weights_54_12, &conv3_weights_54_13, &conv3_weights_54_14, &conv3_weights_54_15},
    {&conv3_weights_55_0, &conv3_weights_55_1, &conv3_weights_55_2, &conv3_weights_55_3, &conv3_weights_55_4, &conv3_weights_55_5, &conv3_weights_55_6, &conv3_weights_55_7, &conv3_weights_55_8, &conv3_weights_55_9, &conv3_weights_55_10, &conv3_weights_55_11, &conv3_weights_55_12, &conv3_weights_55_13, &conv3_weights_55_14, &conv3_weights_55_15},
    {&conv3_weights_56_0, &conv3_weights_56_1, &conv3_weights_56_2, &conv3_weights_56_3, &conv3_weights_56_4, &conv3_weights_56_5, &conv3_weights_56_6, &conv3_weights_56_7, &conv3_weights_56_8, &conv3_weights_56_9, &conv3_weights_56_10, &conv3_weights_56_11, &conv3_weights_56_12, &conv3_weights_56_13, &conv3_weights_56_14, &conv3_weights_56_15},
    {&conv3_weights_57_0, &conv3_weights_57_1, &conv3_weights_57_2, &conv3_weights_57_3, &conv3_weights_57_4, &conv3_weights_57_5, &conv3_weights_57_6, &conv3_weights_57_7, &conv3_weights_57_8, &conv3_weights_57_9, &conv3_weights_57_10, &conv3_weights_57_11, &conv3_weights_57_12, &conv3_weights_57_13, &conv3_weights_57_14, &conv3_weights_57_15},
    {&conv3_weights_58_0, &conv3_weights_58_1, &conv3_weights_58_2, &conv3_weights_58_3, &conv3_weights_58_4, &conv3_weights_58_5, &conv3_weights_58_6, &conv3_weights_58_7, &conv3_weights_58_8, &conv3_weights_58_9, &conv3_weights_58_10, &conv3_weights_58_11, &conv3_weights_58_12, &conv3_weights_58_13, &conv3_weights_58_14, &conv3_weights_58_15},
    {&conv3_weights_59_0, &conv3_weights_59_1, &conv3_weights_59_2, &conv3_weights_59_3, &conv3_weights_59_4, &conv3_weights_59_5, &conv3_weights_59_6, &conv3_weights_59_7, &conv3_weights_59_8, &conv3_weights_59_9, &conv3_weights_59_10, &conv3_weights_59_11, &conv3_weights_59_12, &conv3_weights_59_13, &conv3_weights_59_14, &conv3_weights_59_15},
    {&conv3_weights_60_0, &conv3_weights_60_1, &conv3_weights_60_2, &conv3_weights_60_3, &conv3_weights_60_4, &conv3_weights_60_5, &conv3_weights_60_6, &conv3_weights_60_7, &conv3_weights_60_8, &conv3_weights_60_9, &conv3_weights_60_10, &conv3_weights_60_11, &conv3_weights_60_12, &conv3_weights_60_13, &conv3_weights_60_14, &conv3_weights_60_15},
    {&conv3_weights_61_0, &conv3_weights_61_1, &conv3_weights_61_2, &conv3_weights_61_3, &conv3_weights_61_4, &conv3_weights_61_5, &conv3_weights_61_6, &conv3_weights_61_7, &conv3_weights_61_8, &conv3_weights_61_9, &conv3_weights_61_10, &conv3_weights_61_11, &conv3_weights_61_12, &conv3_weights_61_13, &conv3_weights_61_14, &conv3_weights_61_15},
    {&conv3_weights_62_0, &conv3_weights_62_1, &conv3_weights_62_2, &conv3_weights_62_3, &conv3_weights_62_4, &conv3_weights_62_5, &conv3_weights_62_6, &conv3_weights_62_7, &conv3_weights_62_8, &conv3_weights_62_9, &conv3_weights_62_10, &conv3_weights_62_11, &conv3_weights_62_12, &conv3_weights_62_13, &conv3_weights_62_14, &conv3_weights_62_15},
    {&conv3_weights_63_0, &conv3_weights_63_1, &conv3_weights_63_2, &conv3_weights_63_3, &conv3_weights_63_4, &conv3_weights_63_5, &conv3_weights_63_6, &conv3_weights_63_7, &conv3_weights_63_8, &conv3_weights_63_9, &conv3_weights_63_10, &conv3_weights_63_11, &conv3_weights_63_12, &conv3_weights_63_13, &conv3_weights_63_14, &conv3_weights_63_15},
    {&conv3_weights_64_0, &conv3_weights_64_1, &conv3_weights_64_2, &conv3_weights_64_3, &conv3_weights_64_4, &conv3_weights_64_5, &conv3_weights_64_6, &conv3_weights_64_7, &conv3_weights_64_8, &conv3_weights_64_9, &conv3_weights_64_10, &conv3_weights_64_11, &conv3_weights_64_12, &conv3_weights_64_13, &conv3_weights_64_14, &conv3_weights_64_15},
    {&conv3_weights_65_0, &conv3_weights_65_1, &conv3_weights_65_2, &conv3_weights_65_3, &conv3_weights_65_4, &conv3_weights_65_5, &conv3_weights_65_6, &conv3_weights_65_7, &conv3_weights_65_8, &conv3_weights_65_9, &conv3_weights_65_10, &conv3_weights_65_11, &conv3_weights_65_12, &conv3_weights_65_13, &conv3_weights_65_14, &conv3_weights_65_15},
    {&conv3_weights_66_0, &conv3_weights_66_1, &conv3_weights_66_2, &conv3_weights_66_3, &conv3_weights_66_4, &conv3_weights_66_5, &conv3_weights_66_6, &conv3_weights_66_7, &conv3_weights_66_8, &conv3_weights_66_9, &conv3_weights_66_10, &conv3_weights_66_11, &conv3_weights_66_12, &conv3_weights_66_13, &conv3_weights_66_14, &conv3_weights_66_15},
    {&conv3_weights_67_0, &conv3_weights_67_1, &conv3_weights_67_2, &conv3_weights_67_3, &conv3_weights_67_4, &conv3_weights_67_5, &conv3_weights_67_6, &conv3_weights_67_7, &conv3_weights_67_8, &conv3_weights_67_9, &conv3_weights_67_10, &conv3_weights_67_11, &conv3_weights_67_12, &conv3_weights_67_13, &conv3_weights_67_14, &conv3_weights_67_15},
    {&conv3_weights_68_0, &conv3_weights_68_1, &conv3_weights_68_2, &conv3_weights_68_3, &conv3_weights_68_4, &conv3_weights_68_5, &conv3_weights_68_6, &conv3_weights_68_7, &conv3_weights_68_8, &conv3_weights_68_9, &conv3_weights_68_10, &conv3_weights_68_11, &conv3_weights_68_12, &conv3_weights_68_13, &conv3_weights_68_14, &conv3_weights_68_15},
    {&conv3_weights_69_0, &conv3_weights_69_1, &conv3_weights_69_2, &conv3_weights_69_3, &conv3_weights_69_4, &conv3_weights_69_5, &conv3_weights_69_6, &conv3_weights_69_7, &conv3_weights_69_8, &conv3_weights_69_9, &conv3_weights_69_10, &conv3_weights_69_11, &conv3_weights_69_12, &conv3_weights_69_13, &conv3_weights_69_14, &conv3_weights_69_15},
    {&conv3_weights_70_0, &conv3_weights_70_1, &conv3_weights_70_2, &conv3_weights_70_3, &conv3_weights_70_4, &conv3_weights_70_5, &conv3_weights_70_6, &conv3_weights_70_7, &conv3_weights_70_8, &conv3_weights_70_9, &conv3_weights_70_10, &conv3_weights_70_11, &conv3_weights_70_12, &conv3_weights_70_13, &conv3_weights_70_14, &conv3_weights_70_15},
    {&conv3_weights_71_0, &conv3_weights_71_1, &conv3_weights_71_2, &conv3_weights_71_3, &conv3_weights_71_4, &conv3_weights_71_5, &conv3_weights_71_6, &conv3_weights_71_7, &conv3_weights_71_8, &conv3_weights_71_9, &conv3_weights_71_10, &conv3_weights_71_11, &conv3_weights_71_12, &conv3_weights_71_13, &conv3_weights_71_14, &conv3_weights_71_15},
    {&conv3_weights_72_0, &conv3_weights_72_1, &conv3_weights_72_2, &conv3_weights_72_3, &conv3_weights_72_4, &conv3_weights_72_5, &conv3_weights_72_6, &conv3_weights_72_7, &conv3_weights_72_8, &conv3_weights_72_9, &conv3_weights_72_10, &conv3_weights_72_11, &conv3_weights_72_12, &conv3_weights_72_13, &conv3_weights_72_14, &conv3_weights_72_15},
    {&conv3_weights_73_0, &conv3_weights_73_1, &conv3_weights_73_2, &conv3_weights_73_3, &conv3_weights_73_4, &conv3_weights_73_5, &conv3_weights_73_6, &conv3_weights_73_7, &conv3_weights_73_8, &conv3_weights_73_9, &conv3_weights_73_10, &conv3_weights_73_11, &conv3_weights_73_12, &conv3_weights_73_13, &conv3_weights_73_14, &conv3_weights_73_15},
    {&conv3_weights_74_0, &conv3_weights_74_1, &conv3_weights_74_2, &conv3_weights_74_3, &conv3_weights_74_4, &conv3_weights_74_5, &conv3_weights_74_6, &conv3_weights_74_7, &conv3_weights_74_8, &conv3_weights_74_9, &conv3_weights_74_10, &conv3_weights_74_11, &conv3_weights_74_12, &conv3_weights_74_13, &conv3_weights_74_14, &conv3_weights_74_15},
    {&conv3_weights_75_0, &conv3_weights_75_1, &conv3_weights_75_2, &conv3_weights_75_3, &conv3_weights_75_4, &conv3_weights_75_5, &conv3_weights_75_6, &conv3_weights_75_7, &conv3_weights_75_8, &conv3_weights_75_9, &conv3_weights_75_10, &conv3_weights_75_11, &conv3_weights_75_12, &conv3_weights_75_13, &conv3_weights_75_14, &conv3_weights_75_15},
    {&conv3_weights_76_0, &conv3_weights_76_1, &conv3_weights_76_2, &conv3_weights_76_3, &conv3_weights_76_4, &conv3_weights_76_5, &conv3_weights_76_6, &conv3_weights_76_7, &conv3_weights_76_8, &conv3_weights_76_9, &conv3_weights_76_10, &conv3_weights_76_11, &conv3_weights_76_12, &conv3_weights_76_13, &conv3_weights_76_14, &conv3_weights_76_15},
    {&conv3_weights_77_0, &conv3_weights_77_1, &conv3_weights_77_2, &conv3_weights_77_3, &conv3_weights_77_4, &conv3_weights_77_5, &conv3_weights_77_6, &conv3_weights_77_7, &conv3_weights_77_8, &conv3_weights_77_9, &conv3_weights_77_10, &conv3_weights_77_11, &conv3_weights_77_12, &conv3_weights_77_13, &conv3_weights_77_14, &conv3_weights_77_15},
    {&conv3_weights_78_0, &conv3_weights_78_1, &conv3_weights_78_2, &conv3_weights_78_3, &conv3_weights_78_4, &conv3_weights_78_5, &conv3_weights_78_6, &conv3_weights_78_7, &conv3_weights_78_8, &conv3_weights_78_9, &conv3_weights_78_10, &conv3_weights_78_11, &conv3_weights_78_12, &conv3_weights_78_13, &conv3_weights_78_14, &conv3_weights_78_15},
    {&conv3_weights_79_0, &conv3_weights_79_1, &conv3_weights_79_2, &conv3_weights_79_3, &conv3_weights_79_4, &conv3_weights_79_5, &conv3_weights_79_6, &conv3_weights_79_7, &conv3_weights_79_8, &conv3_weights_79_9, &conv3_weights_79_10, &conv3_weights_79_11, &conv3_weights_79_12, &conv3_weights_79_13, &conv3_weights_79_14, &conv3_weights_79_15},
    {&conv3_weights_80_0, &conv3_weights_80_1, &conv3_weights_80_2, &conv3_weights_80_3, &conv3_weights_80_4, &conv3_weights_80_5, &conv3_weights_80_6, &conv3_weights_80_7, &conv3_weights_80_8, &conv3_weights_80_9, &conv3_weights_80_10, &conv3_weights_80_11, &conv3_weights_80_12, &conv3_weights_80_13, &conv3_weights_80_14, &conv3_weights_80_15},
    {&conv3_weights_81_0, &conv3_weights_81_1, &conv3_weights_81_2, &conv3_weights_81_3, &conv3_weights_81_4, &conv3_weights_81_5, &conv3_weights_81_6, &conv3_weights_81_7, &conv3_weights_81_8, &conv3_weights_81_9, &conv3_weights_81_10, &conv3_weights_81_11, &conv3_weights_81_12, &conv3_weights_81_13, &conv3_weights_81_14, &conv3_weights_81_15},
    {&conv3_weights_82_0, &conv3_weights_82_1, &conv3_weights_82_2, &conv3_weights_82_3, &conv3_weights_82_4, &conv3_weights_82_5, &conv3_weights_82_6, &conv3_weights_82_7, &conv3_weights_82_8, &conv3_weights_82_9, &conv3_weights_82_10, &conv3_weights_82_11, &conv3_weights_82_12, &conv3_weights_82_13, &conv3_weights_82_14, &conv3_weights_82_15},
    {&conv3_weights_83_0, &conv3_weights_83_1, &conv3_weights_83_2, &conv3_weights_83_3, &conv3_weights_83_4, &conv3_weights_83_5, &conv3_weights_83_6, &conv3_weights_83_7, &conv3_weights_83_8, &conv3_weights_83_9, &conv3_weights_83_10, &conv3_weights_83_11, &conv3_weights_83_12, &conv3_weights_83_13, &conv3_weights_83_14, &conv3_weights_83_15},
    {&conv3_weights_84_0, &conv3_weights_84_1, &conv3_weights_84_2, &conv3_weights_84_3, &conv3_weights_84_4, &conv3_weights_84_5, &conv3_weights_84_6, &conv3_weights_84_7, &conv3_weights_84_8, &conv3_weights_84_9, &conv3_weights_84_10, &conv3_weights_84_11, &conv3_weights_84_12, &conv3_weights_84_13, &conv3_weights_84_14, &conv3_weights_84_15},
    {&conv3_weights_85_0, &conv3_weights_85_1, &conv3_weights_85_2, &conv3_weights_85_3, &conv3_weights_85_4, &conv3_weights_85_5, &conv3_weights_85_6, &conv3_weights_85_7, &conv3_weights_85_8, &conv3_weights_85_9, &conv3_weights_85_10, &conv3_weights_85_11, &conv3_weights_85_12, &conv3_weights_85_13, &conv3_weights_85_14, &conv3_weights_85_15},
    {&conv3_weights_86_0, &conv3_weights_86_1, &conv3_weights_86_2, &conv3_weights_86_3, &conv3_weights_86_4, &conv3_weights_86_5, &conv3_weights_86_6, &conv3_weights_86_7, &conv3_weights_86_8, &conv3_weights_86_9, &conv3_weights_86_10, &conv3_weights_86_11, &conv3_weights_86_12, &conv3_weights_86_13, &conv3_weights_86_14, &conv3_weights_86_15},
    {&conv3_weights_87_0, &conv3_weights_87_1, &conv3_weights_87_2, &conv3_weights_87_3, &conv3_weights_87_4, &conv3_weights_87_5, &conv3_weights_87_6, &conv3_weights_87_7, &conv3_weights_87_8, &conv3_weights_87_9, &conv3_weights_87_10, &conv3_weights_87_11, &conv3_weights_87_12, &conv3_weights_87_13, &conv3_weights_87_14, &conv3_weights_87_15},
    {&conv3_weights_88_0, &conv3_weights_88_1, &conv3_weights_88_2, &conv3_weights_88_3, &conv3_weights_88_4, &conv3_weights_88_5, &conv3_weights_88_6, &conv3_weights_88_7, &conv3_weights_88_8, &conv3_weights_88_9, &conv3_weights_88_10, &conv3_weights_88_11, &conv3_weights_88_12, &conv3_weights_88_13, &conv3_weights_88_14, &conv3_weights_88_15},
    {&conv3_weights_89_0, &conv3_weights_89_1, &conv3_weights_89_2, &conv3_weights_89_3, &conv3_weights_89_4, &conv3_weights_89_5, &conv3_weights_89_6, &conv3_weights_89_7, &conv3_weights_89_8, &conv3_weights_89_9, &conv3_weights_89_10, &conv3_weights_89_11, &conv3_weights_89_12, &conv3_weights_89_13, &conv3_weights_89_14, &conv3_weights_89_15},
    {&conv3_weights_90_0, &conv3_weights_90_1, &conv3_weights_90_2, &conv3_weights_90_3, &conv3_weights_90_4, &conv3_weights_90_5, &conv3_weights_90_6, &conv3_weights_90_7, &conv3_weights_90_8, &conv3_weights_90_9, &conv3_weights_90_10, &conv3_weights_90_11, &conv3_weights_90_12, &conv3_weights_90_13, &conv3_weights_90_14, &conv3_weights_90_15},
    {&conv3_weights_91_0, &conv3_weights_91_1, &conv3_weights_91_2, &conv3_weights_91_3, &conv3_weights_91_4, &conv3_weights_91_5, &conv3_weights_91_6, &conv3_weights_91_7, &conv3_weights_91_8, &conv3_weights_91_9, &conv3_weights_91_10, &conv3_weights_91_11, &conv3_weights_91_12, &conv3_weights_91_13, &conv3_weights_91_14, &conv3_weights_91_15},
    {&conv3_weights_92_0, &conv3_weights_92_1, &conv3_weights_92_2, &conv3_weights_92_3, &conv3_weights_92_4, &conv3_weights_92_5, &conv3_weights_92_6, &conv3_weights_92_7, &conv3_weights_92_8, &conv3_weights_92_9, &conv3_weights_92_10, &conv3_weights_92_11, &conv3_weights_92_12, &conv3_weights_92_13, &conv3_weights_92_14, &conv3_weights_92_15},
    {&conv3_weights_93_0, &conv3_weights_93_1, &conv3_weights_93_2, &conv3_weights_93_3, &conv3_weights_93_4, &conv3_weights_93_5, &conv3_weights_93_6, &conv3_weights_93_7, &conv3_weights_93_8, &conv3_weights_93_9, &conv3_weights_93_10, &conv3_weights_93_11, &conv3_weights_93_12, &conv3_weights_93_13, &conv3_weights_93_14, &conv3_weights_93_15},
    {&conv3_weights_94_0, &conv3_weights_94_1, &conv3_weights_94_2, &conv3_weights_94_3, &conv3_weights_94_4, &conv3_weights_94_5, &conv3_weights_94_6, &conv3_weights_94_7, &conv3_weights_94_8, &conv3_weights_94_9, &conv3_weights_94_10, &conv3_weights_94_11, &conv3_weights_94_12, &conv3_weights_94_13, &conv3_weights_94_14, &conv3_weights_94_15},
    {&conv3_weights_95_0, &conv3_weights_95_1, &conv3_weights_95_2, &conv3_weights_95_3, &conv3_weights_95_4, &conv3_weights_95_5, &conv3_weights_95_6, &conv3_weights_95_7, &conv3_weights_95_8, &conv3_weights_95_9, &conv3_weights_95_10, &conv3_weights_95_11, &conv3_weights_95_12, &conv3_weights_95_13, &conv3_weights_95_14, &conv3_weights_95_15},
    {&conv3_weights_96_0, &conv3_weights_96_1, &conv3_weights_96_2, &conv3_weights_96_3, &conv3_weights_96_4, &conv3_weights_96_5, &conv3_weights_96_6, &conv3_weights_96_7, &conv3_weights_96_8, &conv3_weights_96_9, &conv3_weights_96_10, &conv3_weights_96_11, &conv3_weights_96_12, &conv3_weights_96_13, &conv3_weights_96_14, &conv3_weights_96_15},
    {&conv3_weights_97_0, &conv3_weights_97_1, &conv3_weights_97_2, &conv3_weights_97_3, &conv3_weights_97_4, &conv3_weights_97_5, &conv3_weights_97_6, &conv3_weights_97_7, &conv3_weights_97_8, &conv3_weights_97_9, &conv3_weights_97_10, &conv3_weights_97_11, &conv3_weights_97_12, &conv3_weights_97_13, &conv3_weights_97_14, &conv3_weights_97_15},
    {&conv3_weights_98_0, &conv3_weights_98_1, &conv3_weights_98_2, &conv3_weights_98_3, &conv3_weights_98_4, &conv3_weights_98_5, &conv3_weights_98_6, &conv3_weights_98_7, &conv3_weights_98_8, &conv3_weights_98_9, &conv3_weights_98_10, &conv3_weights_98_11, &conv3_weights_98_12, &conv3_weights_98_13, &conv3_weights_98_14, &conv3_weights_98_15},
    {&conv3_weights_99_0, &conv3_weights_99_1, &conv3_weights_99_2, &conv3_weights_99_3, &conv3_weights_99_4, &conv3_weights_99_5, &conv3_weights_99_6, &conv3_weights_99_7, &conv3_weights_99_8, &conv3_weights_99_9, &conv3_weights_99_10, &conv3_weights_99_11, &conv3_weights_99_12, &conv3_weights_99_13, &conv3_weights_99_14, &conv3_weights_99_15},
    {&conv3_weights_100_0, &conv3_weights_100_1, &conv3_weights_100_2, &conv3_weights_100_3, &conv3_weights_100_4, &conv3_weights_100_5, &conv3_weights_100_6, &conv3_weights_100_7, &conv3_weights_100_8, &conv3_weights_100_9, &conv3_weights_100_10, &conv3_weights_100_11, &conv3_weights_100_12, &conv3_weights_100_13, &conv3_weights_100_14, &conv3_weights_100_15},
    {&conv3_weights_101_0, &conv3_weights_101_1, &conv3_weights_101_2, &conv3_weights_101_3, &conv3_weights_101_4, &conv3_weights_101_5, &conv3_weights_101_6, &conv3_weights_101_7, &conv3_weights_101_8, &conv3_weights_101_9, &conv3_weights_101_10, &conv3_weights_101_11, &conv3_weights_101_12, &conv3_weights_101_13, &conv3_weights_101_14, &conv3_weights_101_15},
    {&conv3_weights_102_0, &conv3_weights_102_1, &conv3_weights_102_2, &conv3_weights_102_3, &conv3_weights_102_4, &conv3_weights_102_5, &conv3_weights_102_6, &conv3_weights_102_7, &conv3_weights_102_8, &conv3_weights_102_9, &conv3_weights_102_10, &conv3_weights_102_11, &conv3_weights_102_12, &conv3_weights_102_13, &conv3_weights_102_14, &conv3_weights_102_15},
    {&conv3_weights_103_0, &conv3_weights_103_1, &conv3_weights_103_2, &conv3_weights_103_3, &conv3_weights_103_4, &conv3_weights_103_5, &conv3_weights_103_6, &conv3_weights_103_7, &conv3_weights_103_8, &conv3_weights_103_9, &conv3_weights_103_10, &conv3_weights_103_11, &conv3_weights_103_12, &conv3_weights_103_13, &conv3_weights_103_14, &conv3_weights_103_15},
    {&conv3_weights_104_0, &conv3_weights_104_1, &conv3_weights_104_2, &conv3_weights_104_3, &conv3_weights_104_4, &conv3_weights_104_5, &conv3_weights_104_6, &conv3_weights_104_7, &conv3_weights_104_8, &conv3_weights_104_9, &conv3_weights_104_10, &conv3_weights_104_11, &conv3_weights_104_12, &conv3_weights_104_13, &conv3_weights_104_14, &conv3_weights_104_15},
    {&conv3_weights_105_0, &conv3_weights_105_1, &conv3_weights_105_2, &conv3_weights_105_3, &conv3_weights_105_4, &conv3_weights_105_5, &conv3_weights_105_6, &conv3_weights_105_7, &conv3_weights_105_8, &conv3_weights_105_9, &conv3_weights_105_10, &conv3_weights_105_11, &conv3_weights_105_12, &conv3_weights_105_13, &conv3_weights_105_14, &conv3_weights_105_15},
    {&conv3_weights_106_0, &conv3_weights_106_1, &conv3_weights_106_2, &conv3_weights_106_3, &conv3_weights_106_4, &conv3_weights_106_5, &conv3_weights_106_6, &conv3_weights_106_7, &conv3_weights_106_8, &conv3_weights_106_9, &conv3_weights_106_10, &conv3_weights_106_11, &conv3_weights_106_12, &conv3_weights_106_13, &conv3_weights_106_14, &conv3_weights_106_15},
    {&conv3_weights_107_0, &conv3_weights_107_1, &conv3_weights_107_2, &conv3_weights_107_3, &conv3_weights_107_4, &conv3_weights_107_5, &conv3_weights_107_6, &conv3_weights_107_7, &conv3_weights_107_8, &conv3_weights_107_9, &conv3_weights_107_10, &conv3_weights_107_11, &conv3_weights_107_12, &conv3_weights_107_13, &conv3_weights_107_14, &conv3_weights_107_15},
    {&conv3_weights_108_0, &conv3_weights_108_1, &conv3_weights_108_2, &conv3_weights_108_3, &conv3_weights_108_4, &conv3_weights_108_5, &conv3_weights_108_6, &conv3_weights_108_7, &conv3_weights_108_8, &conv3_weights_108_9, &conv3_weights_108_10, &conv3_weights_108_11, &conv3_weights_108_12, &conv3_weights_108_13, &conv3_weights_108_14, &conv3_weights_108_15},
    {&conv3_weights_109_0, &conv3_weights_109_1, &conv3_weights_109_2, &conv3_weights_109_3, &conv3_weights_109_4, &conv3_weights_109_5, &conv3_weights_109_6, &conv3_weights_109_7, &conv3_weights_109_8, &conv3_weights_109_9, &conv3_weights_109_10, &conv3_weights_109_11, &conv3_weights_109_12, &conv3_weights_109_13, &conv3_weights_109_14, &conv3_weights_109_15},
    {&conv3_weights_110_0, &conv3_weights_110_1, &conv3_weights_110_2, &conv3_weights_110_3, &conv3_weights_110_4, &conv3_weights_110_5, &conv3_weights_110_6, &conv3_weights_110_7, &conv3_weights_110_8, &conv3_weights_110_9, &conv3_weights_110_10, &conv3_weights_110_11, &conv3_weights_110_12, &conv3_weights_110_13, &conv3_weights_110_14, &conv3_weights_110_15},
    {&conv3_weights_111_0, &conv3_weights_111_1, &conv3_weights_111_2, &conv3_weights_111_3, &conv3_weights_111_4, &conv3_weights_111_5, &conv3_weights_111_6, &conv3_weights_111_7, &conv3_weights_111_8, &conv3_weights_111_9, &conv3_weights_111_10, &conv3_weights_111_11, &conv3_weights_111_12, &conv3_weights_111_13, &conv3_weights_111_14, &conv3_weights_111_15},
    {&conv3_weights_112_0, &conv3_weights_112_1, &conv3_weights_112_2, &conv3_weights_112_3, &conv3_weights_112_4, &conv3_weights_112_5, &conv3_weights_112_6, &conv3_weights_112_7, &conv3_weights_112_8, &conv3_weights_112_9, &conv3_weights_112_10, &conv3_weights_112_11, &conv3_weights_112_12, &conv3_weights_112_13, &conv3_weights_112_14, &conv3_weights_112_15},
    {&conv3_weights_113_0, &conv3_weights_113_1, &conv3_weights_113_2, &conv3_weights_113_3, &conv3_weights_113_4, &conv3_weights_113_5, &conv3_weights_113_6, &conv3_weights_113_7, &conv3_weights_113_8, &conv3_weights_113_9, &conv3_weights_113_10, &conv3_weights_113_11, &conv3_weights_113_12, &conv3_weights_113_13, &conv3_weights_113_14, &conv3_weights_113_15},
    {&conv3_weights_114_0, &conv3_weights_114_1, &conv3_weights_114_2, &conv3_weights_114_3, &conv3_weights_114_4, &conv3_weights_114_5, &conv3_weights_114_6, &conv3_weights_114_7, &conv3_weights_114_8, &conv3_weights_114_9, &conv3_weights_114_10, &conv3_weights_114_11, &conv3_weights_114_12, &conv3_weights_114_13, &conv3_weights_114_14, &conv3_weights_114_15},
    {&conv3_weights_115_0, &conv3_weights_115_1, &conv3_weights_115_2, &conv3_weights_115_3, &conv3_weights_115_4, &conv3_weights_115_5, &conv3_weights_115_6, &conv3_weights_115_7, &conv3_weights_115_8, &conv3_weights_115_9, &conv3_weights_115_10, &conv3_weights_115_11, &conv3_weights_115_12, &conv3_weights_115_13, &conv3_weights_115_14, &conv3_weights_115_15},
    {&conv3_weights_116_0, &conv3_weights_116_1, &conv3_weights_116_2, &conv3_weights_116_3, &conv3_weights_116_4, &conv3_weights_116_5, &conv3_weights_116_6, &conv3_weights_116_7, &conv3_weights_116_8, &conv3_weights_116_9, &conv3_weights_116_10, &conv3_weights_116_11, &conv3_weights_116_12, &conv3_weights_116_13, &conv3_weights_116_14, &conv3_weights_116_15},
    {&conv3_weights_117_0, &conv3_weights_117_1, &conv3_weights_117_2, &conv3_weights_117_3, &conv3_weights_117_4, &conv3_weights_117_5, &conv3_weights_117_6, &conv3_weights_117_7, &conv3_weights_117_8, &conv3_weights_117_9, &conv3_weights_117_10, &conv3_weights_117_11, &conv3_weights_117_12, &conv3_weights_117_13, &conv3_weights_117_14, &conv3_weights_117_15},
    {&conv3_weights_118_0, &conv3_weights_118_1, &conv3_weights_118_2, &conv3_weights_118_3, &conv3_weights_118_4, &conv3_weights_118_5, &conv3_weights_118_6, &conv3_weights_118_7, &conv3_weights_118_8, &conv3_weights_118_9, &conv3_weights_118_10, &conv3_weights_118_11, &conv3_weights_118_12, &conv3_weights_118_13, &conv3_weights_118_14, &conv3_weights_118_15},
    {&conv3_weights_119_0, &conv3_weights_119_1, &conv3_weights_119_2, &conv3_weights_119_3, &conv3_weights_119_4, &conv3_weights_119_5, &conv3_weights_119_6, &conv3_weights_119_7, &conv3_weights_119_8, &conv3_weights_119_9, &conv3_weights_119_10, &conv3_weights_119_11, &conv3_weights_119_12, &conv3_weights_119_13, &conv3_weights_119_14, &conv3_weights_119_15}};

void convcell_upropagate_conv3(
  DATA_T (&inputs)[CONV3_NB_CHANNELS][CONV3_CHANNELS_HEIGHT][CONV3_CHANNELS_WIDTH],
  DATA_T (&outputs)[CONV3_NB_OUTPUTS][CONV3_OUTPUTS_HEIGHT][CONV3_OUTPUTS_WIDTH],
  const BDATA_T (&bias)[CONV3_NB_OUTPUTS],
  const WDATA_T (*weights[CONV3_NB_OUTPUTS][CONV3_NB_CHANNELS])[CONV3_KERNEL_HEIGHT][CONV3_KERNEL_WIDTH]);

#endif
