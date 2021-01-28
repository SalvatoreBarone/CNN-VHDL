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


#define CONV2_NB_OUTPUTS 16
#define CONV2_NB_CHANNELS 6
#define CONV2_OUTPUTS_WIDTH 10
#define CONV2_OUTPUTS_HEIGHT 10
#define CONV2_OUTPUT_OFFSET 0
#define CONV2_OX_SIZE 10
#define CONV2_OY_SIZE 10
#define CONV2_CHANNELS_WIDTH 14
#define CONV2_CHANNELS_HEIGHT 14
#define CONV2_KERNEL_WIDTH 5
#define CONV2_KERNEL_HEIGHT 5
#define CONV2_SUB_SAMPLE_X 1
#define CONV2_SUB_SAMPLE_Y 1
#define CONV2_STRIDE_X 1
#define CONV2_STRIDE_Y 1
#define CONV2_PADDING_X 0
#define CONV2_PADDING_Y 0

#define CONV2_ACTIVATION Rectifier
#define CONV2_SHIFT 2
static const BDATA_T conv2_biases[CONV2_NB_OUTPUTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const WDATA_T conv2_weights_0_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {12, 29, 45, 46, 25},
    {8, 20, 27, 9, 8},
    {13, 7, 63, 105, 87},
    {0, -17, -6, 19, 27},
    {7, 23, 11, 24, 68}};
static const WDATA_T conv2_weights_0_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-16, -25, -43, -34, -9},
    {-8, -5, 6, 63, 127},
    {-34, -15, -7, -46, -18},
    {-21, -13, 74, 115, 3},
    {-17, -41, -21, 88, 50}};
static const WDATA_T conv2_weights_0_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {8, 26, 19, -4, -20},
    {13, 1, -1, -6, -12},
    {-5, -1, -19, -20, -5},
    {-20, -1, -35, -46, -23},
    {-42, -40, -35, -36, -36}};
static const WDATA_T conv2_weights_1_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {48, 38, -21, -35, -16},
    {12, 61, 66, -2, -36},
    {-11, -12, 64, 70, 5},
    {35, -7, 6, 71, 64},
    {35, 7, -29, 0, 29}};
static const WDATA_T conv2_weights_1_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-41, -40, -20, 30, 50},
    {-39, -49, -55, -4, 0},
    {-25, -32, -45, -36, -21},
    {0, 0, -5, -4, 13},
    {31, 24, -3, -3, 8}};
static const WDATA_T conv2_weights_1_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-19, -13, 28, 21, 3},
    {13, -37, -11, 20, 18},
    {21, -13, -49, -26, 2},
    {-12, 9, -23, -53, -43},
    {-3, 10, -4, -10, -13}};
static const WDATA_T conv2_weights_2_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {81, 60, -3, -25, 65},
    {55, 39, -24, 7, 81},
    {38, 29, -34, 17, 51},
    {17, 8, -26, 18, 29},
    {-6, 18, -11, 13, 8}};
static const WDATA_T conv2_weights_2_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-37, -27, -48, -63, -55},
    {-21, -23, -39, -56, -50},
    {-29, -32, -40, -47, -33},
    {-12, -27, -42, -33, -13},
    {2, -25, -53, -38, 20}};
static const WDATA_T conv2_weights_2_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {21, 35, 12, -15, -20},
    {23, 63, 6, -34, 3},
    {10, 50, -16, -45, 10},
    {-12, 22, -19, -31, 7},
    {-14, 32, 18, -22, -16}};
static const WDATA_T conv2_weights_3_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {80, 105, 101, 70, 16},
    {23, 14, 27, 19, -10},
    {18, 1, -15, -30, -39},
    {17, 18, -2, -9, -22},
    {0, 8, -7, -6, -20}};
static const WDATA_T conv2_weights_3_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {12, -19, -2, -8, -24},
    {5, -22, -19, -17, -32},
    {21, -13, -17, -15, -29},
    {15, -11, -15, -13, -31},
    {0, -9, -17, -24, -25}};
static const WDATA_T conv2_weights_3_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {44, 19, -8, 9, 4},
    {9, -11, -35, -28, -9},
    {-28, -13, -22, -28, -11},
    {-26, 16, -10, -19, -7},
    {1, 3, -6, -12, -15}};
static const WDATA_T conv2_weights_4_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {13, 22, 24, 19, 48},
    {10, 31, 9, 38, 52},
    {19, 20, 11, 54, 15},
    {40, 28, 45, 64, 23},
    {45, 31, 35, 35, 14}};
static const WDATA_T conv2_weights_4_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-13, -7, -25, 16, -24},
    {3, -13, -53, 33, -59},
    {12, -31, -50, 48, -72},
    {17, -43, -40, 25, -44},
    {-3, -49, -36, -4, -5}};
static const WDATA_T conv2_weights_4_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-6, -7, 4, -5, 35},
    {-7, 13, 13, -28, 62},
    {-28, 29, 0, -36, 66},
    {-21, 27, -14, -15, 49},
    {-3, 27, -14, -7, 9}};
static const WDATA_T conv2_weights_5_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-8, -17, -27, -15, -4},
    {-11, -9, -10, -14, -12},
    {4, 3, -8, -17, -16},
    {16, 11, 9, 5, -5},
    {15, 1, 1, -1, -5}};
static const WDATA_T conv2_weights_5_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {54, 20, -15, -14, -4},
    {63, 69, 19, 1, -8},
    {10, 63, 46, 33, 24},
    {-14, 19, 28, 21, 15},
    {-74, -43, -10, -9, -7}};
static const WDATA_T conv2_weights_5_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {0, 2, -40, -50, -37},
    {-7, 19, -28, -39, -33},
    {-19, 35, -3, -27, -29},
    {-19, 40, 23, -6, -22},
    {-12, 15, 14, 2, -9}};
static const WDATA_T conv2_weights_6_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {7, 4, -11, -15, -12},
    {0, 3, -3, -5, 4},
    {8, -1, -6, -2, 36},
    {6, -1, 6, 35, 55},
    {-6, -9, 13, 16, -8}};
static const WDATA_T conv2_weights_6_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-11, -22, -27, -35, -50},
    {-16, -25, -35, -19, 6},
    {-8, -12, -3, 18, 22},
    {-28, -21, 2, -13, -30},
    {-12, -15, -15, -27, -17}};
static const WDATA_T conv2_weights_6_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {7, 0, -6, -19, -4},
    {-3, -8, -6, 0, 57},
    {-15, -15, 13, 54, 74},
    {-10, 12, 69, 59, 37},
    {30, 58, 74, 22, 0}};
static const WDATA_T conv2_weights_6_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {32, 29, 14, -4, -5},
    {33, 17, -16, -60, -64},
    {24, 15, -13, -43, -43},
    {10, -3, -29, -44, -23},
    {-18, -38, -56, -61, -45}};
static const WDATA_T conv2_weights_7_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-29, -11, -2, -11, -18},
    {-60, -60, -25, -3, -20},
    {-66, -58, -43, -12, -13},
    {-51, -47, -44, -16, -16},
    {-44, -32, -14, 2, 21}};
static const WDATA_T conv2_weights_7_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {3, 3, -3, -29, 0},
    {-33, 14, 14, -16, 23},
    {-32, 26, 15, 3, 44},
    {1, 26, 12, 30, 33},
    {2, 0, 15, 21, -2}};
static const WDATA_T conv2_weights_7_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {11, -6, -15, -20, -31},
    {2, 6, -20, -31, -36},
    {1, 3, -40, -37, -41},
    {18, 26, -1, -42, -52},
    {32, 34, 1, -54, -60}};
static const WDATA_T conv2_weights_7_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {70, 37, 35, 0, -36},
    {33, 44, 60, -19, -30},
    {7, 56, 50, -20, -13},
    {2, 44, 16, 3, -9},
    {-22, 4, 13, 33, 1}};
static const WDATA_T conv2_weights_8_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {1, 35, 63, 7, -23},
    {-28, -22, -17, 15, 31},
    {1, 40, 110, 104, 59},
    {61, 73, 63, 13, -9},
    {18, -1, -25, -25, 13}};
static const WDATA_T conv2_weights_8_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-7, -19, 13, 54, 62},
    {69, 97, 117, 74, 8},
    {45, 39, 5, -38, -10},
    {-46, -54, -18, 20, 39},
    {-33, -10, 17, 33, 8}};
static const WDATA_T conv2_weights_8_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-11, 1, -14, -33, -34},
    {-17, -23, -59, -48, -31},
    {-37, -33, -49, -31, -38},
    {-43, -40, -36, -14, -7},
    {-36, -17, 3, 9, -10}};
static const WDATA_T conv2_weights_8_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-20, -8, 11, 14, 8},
    {-53, -19, 12, -8, -35},
    {-74, -29, -26, -57, -22},
    {-59, -29, -13, -6, 13},
    {-11, -6, -23, -18, -28}};
static const WDATA_T conv2_weights_9_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-7, 9, 17, -11, -22},
    {6, 4, -12, 33, 38},
    {-10, 11, 57, 81, 6},
    {27, 71, 51, 17, -12},
    {23, -9, -23, -8, -19}};
static const WDATA_T conv2_weights_9_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-10, 0, 15, -8, -56},
    {-28, -18, -24, -51, -18},
    {-39, -36, -39, 12, 20},
    {-28, -5, 45, 49, 4},
    {67, 60, 32, 7, -26}};
static const WDATA_T conv2_weights_9_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {14, 11, -14, 0, 31},
    {6, 3, 11, 25, 25},
    {7, 32, 25, 6, -9},
    {17, -8, -11, -19, -38},
    {-15, -32, -29, -51, -55}};
static const WDATA_T conv2_weights_9_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-11, -12, -4, -37, -45},
    {-12, -3, -3, -35, 16},
    {2, -20, -16, 40, 58},
    {-7, 3, 30, 38, 23},
    {7, 8, -14, -16, -38}};
static const WDATA_T conv2_weights_10_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {0, 0, 0, 2, 1},
    {3, -2, 3, 0, 1},
    {-1, 0, -1, -1, 0},
    {-2, -3, -1, -2, 0},
    {3, -4, -4, -2, 3}};
static const WDATA_T conv2_weights_10_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-2, 0, 3, 0, 1},
    {-2, -1, 0, 4, 4},
    {-4, 2, -1, -3, -1},
    {-1, 0, -1, -5, -4},
    {1, 2, 1, 6, 5}};
static const WDATA_T conv2_weights_10_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {2, -1, -4, -4, -1},
    {0, 0, 1, -1, 2},
    {0, 2, 0, 2, -2},
    {-1, 1, 1, 1, 0},
    {-1, -3, -3, 3, 7}};
static const WDATA_T conv2_weights_10_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-1, -1, -3, 1, -4},
    {1, 0, -2, -1, -3},
    {0, 0, 0, -2, 1},
    {2, -1, -5, 1, 0},
    {-2, -2, 0, -2, -3}};
static const WDATA_T conv2_weights_11_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {8, 3, 11, 18, 8},
    {2, 3, 14, 6, 2},
    {-6, 0, -1, 0, -1},
    {-4, -2, -2, -3, -5},
    {-5, -2, -3, -2, -2}};
static const WDATA_T conv2_weights_11_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {6, 3, 4, -2, -11},
    {-7, -1, 1, -6, -14},
    {-12, -9, 1, 1, -3},
    {-6, -7, -2, 7, 10},
    {1, -2, -4, -3, -5}};
static const WDATA_T conv2_weights_11_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-1, 10, 17, 17, 2},
    {-2, 7, 3, 3, 0},
    {-9, -1, -3, -6, 2},
    {-13, -5, -5, -5, 1},
    {-7, -2, -4, -7, -9}};
static const WDATA_T conv2_weights_11_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {11, 6, 10, 16, 12},
    {12, 2, 16, 20, 6},
    {-4, -11, 7, 5, -6},
    {-14, -18, -8, -9, -10},
    {-14, -17, -15, -14, -9}};
static const WDATA_T conv2_weights_12_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-3, -7, -16, -23, -23},
    {0, -5, -18, -31, -49},
    {-8, 0, -19, -39, -37},
    {3, 7, -11, -22, 0},
    {27, 18, 2, -2, 4}};
static const WDATA_T conv2_weights_12_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {2, -12, -41, -47, -22},
    {-9, -8, -23, -40, -29},
    {-8, 11, 14, -5, -17},
    {30, 43, 47, 26, -20},
    {-8, -3, -6, -14, -51}};
static const WDATA_T conv2_weights_12_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-9, -33, -40, -50, -71},
    {-10, -27, -31, -37, -72},
    {-6, -19, -28, -26, -52},
    {3, 6, -11, -27, -28},
    {39, 60, 12, -16, 15}};
static const WDATA_T conv2_weights_12_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-8, -20, -23, 23, 37},
    {-13, -24, -33, 18, 64},
    {-14, -28, -38, 11, 80},
    {-5, -17, -18, 31, 75},
    {-14, -18, -6, 52, 55}};
static const WDATA_T conv2_weights_13_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-3, 9, 6, 9, 13},
    {-21, -10, 3, 12, 11},
    {10, 7, -9, -17, -20},
    {62, 85, 96, 59, 26},
    {33, 61, 89, 101, 59}};
static const WDATA_T conv2_weights_13_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-27, -3, 22, 39, 54},
    {-28, -10, 29, 33, 35},
    {-38, -61, -60, -49, -32},
    {18, -27, -62, -67, -34},
    {52, 32, 29, 18, -2}};
static const WDATA_T conv2_weights_13_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {10, 14, 13, 31, 30},
    {-18, -6, 9, 33, 29},
    {-45, -35, -12, 11, -6},
    {-31, -43, -44, -36, -34},
    {-6, -5, -5, -25, -26}};
static const WDATA_T conv2_weights_13_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {27, 26, 12, 1, 7},
    {-16, -26, -14, -4, 16},
    {-65, -59, -36, -23, -2},
    {-63, -49, -51, -56, -56},
    {-6, 0, -16, -22, -44}};
static const WDATA_T conv2_weights_14_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {8, 29, 36, 38, 27},
    {-14, 7, 44, 49, 38},
    {-26, -30, 2, 38, 27},
    {-16, -12, -11, 18, 33},
    {-24, -12, -9, -3, 4}};
static const WDATA_T conv2_weights_14_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {15, 35, 23, -7, 1},
    {-13, -1, -20, -15, -2},
    {-14, -13, -39, -20, 9},
    {-48, -50, -60, -57, -33},
    {-19, -31, -35, -34, -39}};
static const WDATA_T conv2_weights_14_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-22, -43, -26, -9, -18},
    {6, -43, -37, -12, 3},
    {46, 8, -30, 2, 12},
    {49, 84, 59, 14, -18},
    {-21, 50, 83, 74, 43}};
static const WDATA_T conv2_weights_14_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {23, 39, 24, -5, 8},
    {-2, 27, 47, 5, 15},
    {-37, -14, 9, -4, -2},
    {-56, -54, -36, -43, -26},
    {-44, -56, -50, -37, -10}};
static const WDATA_T conv2_weights_15_0[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {2, 4, -4, -12, -15},
    {39, 46, 6, -11, -4},
    {60, 28, 3, -2, 2},
    {21, 6, 1, -4, 17},
    {-2, 2, 0, 17, 33}};
static const WDATA_T conv2_weights_15_1[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-23, -14, -16, -45, -43},
    {-13, -20, -43, -45, -33},
    {-18, -32, -23, -10, -1},
    {-23, -5, 23, 32, 31},
    {0, 43, 57, 31, 27}};
static const WDATA_T conv2_weights_15_2[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {0, 15, 11, -5, 14},
    {51, 39, 2, -4, 9},
    {47, 9, -6, -6, 18},
    {-19, -12, 6, 24, 27},
    {-16, 19, 29, 27, 14}};
static const WDATA_T conv2_weights_15_3[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {2, -30, -45, -30, -18},
    {-22, -21, -9, -29, -45},
    {-16, 10, -4, -20, -34},
    {11, -19, -25, -24, -8},
    {6, -15, -11, -16, -11}};
static const WDATA_T conv2_weights_15_4[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {30, 53, 3, -21, -35},
    {50, 35, -19, -42, -45},
    {12, -16, -43, -42, -34},
    {-29, -33, -36, -17, -10},
    {-17, -2, -1, 3, 10}};
static const WDATA_T conv2_weights_15_5[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
    {-11, 26, 63, 27, 1},
    {-5, 62, 74, 1, -25},
    {51, 69, 21, -24, -34},
    {45, 0, -30, -34, -27},
    {-17, -35, -11, -11, 13}};

static const WDATA_T null_weights[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH] = {
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}};


typedef WDATA_T CONV2_KERNEL_T[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH];
static const CONV2_KERNEL_T* conv2_weights[CONV2_NB_OUTPUTS][CONV2_NB_CHANNELS] = {
    {&conv2_weights_0_0, &conv2_weights_0_1, &conv2_weights_0_2, &null_weights, &null_weights, &null_weights},
    {&null_weights, &conv2_weights_1_1, &conv2_weights_1_2, &conv2_weights_1_3, &null_weights, &null_weights},
    {&null_weights, &null_weights, &conv2_weights_2_2, &conv2_weights_2_3, &conv2_weights_2_4, &null_weights},
    {&null_weights, &null_weights, &null_weights, &conv2_weights_3_3, &conv2_weights_3_4, &conv2_weights_3_5},
    {&conv2_weights_4_0, &null_weights, &null_weights, &null_weights, &conv2_weights_4_4, &conv2_weights_4_5},
    {&conv2_weights_5_0, &conv2_weights_5_1, &null_weights, &null_weights, &null_weights, &conv2_weights_5_5},
    {&conv2_weights_6_0, &conv2_weights_6_1, &conv2_weights_6_2, &conv2_weights_6_3, &null_weights, &null_weights},
    {&null_weights, &conv2_weights_7_1, &conv2_weights_7_2, &conv2_weights_7_3, &conv2_weights_7_4, &null_weights},
    {&null_weights, &null_weights, &conv2_weights_8_2, &conv2_weights_8_3, &conv2_weights_8_4, &conv2_weights_8_5},
    {&conv2_weights_9_0, &null_weights, &null_weights, &conv2_weights_9_3, &conv2_weights_9_4, &conv2_weights_9_5},
    {&conv2_weights_10_0, &conv2_weights_10_1, &null_weights, &null_weights, &conv2_weights_10_4, &conv2_weights_10_5},
    {&conv2_weights_11_0, &conv2_weights_11_1, &conv2_weights_11_2, &null_weights, &null_weights, &conv2_weights_11_5},
    {&conv2_weights_12_0, &conv2_weights_12_1, &null_weights, &conv2_weights_12_3, &conv2_weights_12_4, &null_weights},
    {&null_weights, &conv2_weights_13_1, &conv2_weights_13_2, &null_weights, &conv2_weights_13_4, &conv2_weights_13_5},
    {&conv2_weights_14_0, &null_weights, &conv2_weights_14_2, &conv2_weights_14_3, &null_weights, &conv2_weights_14_5},
    {&conv2_weights_15_0, &conv2_weights_15_1, &conv2_weights_15_2, &conv2_weights_15_3, &conv2_weights_15_4, &conv2_weights_15_5}};


void convcell_upropagate_conv2(
  DATA_T (&inputs)[CONV2_NB_CHANNELS][CONV2_CHANNELS_HEIGHT][CONV2_CHANNELS_WIDTH],
  DATA_T (&outputs)[CONV2_NB_OUTPUTS][CONV2_OUTPUTS_HEIGHT][CONV2_OUTPUTS_WIDTH],
  const BDATA_T (&bias)[CONV2_NB_OUTPUTS],
  const WDATA_T (*weights[CONV2_NB_OUTPUTS][CONV2_NB_CHANNELS])[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH]);

#endif
