#include "conv1.h"
DATA_T sat32(SUM_T x, char rs);
UDATA_T usat32(SUM_T x, char rs);
DATA_T usat(SUM_T weightedSum, ActivationFunction_T func, bool unsigned_data, int shift);

int int_max(int a, int b)
{
    return (a > b) ? a : b;
}

int int_min(int a, int b)
{
    return (a < b) ? a : b;
}

SUM_T neuron_conv1(
  DATA_T (&inputs)[CONV1_NB_CHANNELS][CONV1_CHANNELS_HEIGHT][CONV1_CHANNELS_WIDTH],
  const BDATA_T (&bias)[CONV1_NB_OUTPUTS],
  const WDATA_T (*weights[CONV1_NB_OUTPUTS][CONV1_NB_CHANNELS])[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH],
  unsigned int output,
  unsigned int sxMin,
  unsigned int syMin,
  unsigned int sxMax,
  unsigned int syMax,
  int ix,
  int iy)
{
  SUM_T weightedSum = bias[output];
  for (unsigned int channel = 0; channel < CONV1_NB_CHANNELS; ++channel)
  {
    if (weights[output][channel] == NULL) continue;
    for (unsigned int sy = syMin; sy < syMax; ++sy)
      for (unsigned int sx = sxMin; sx < sxMax; ++sx)
      {
        SUM_T prod = (SUM_T) (*weights[output][channel])[sy][sx] * (SUM_T) ((UDATA_T) inputs[channel][iy + sy][ix + sx]);
        weightedSum = weightedSum + prod;
      }
  }
  return weightedSum;
}

void convcell_upropagate_conv1(
  DATA_T (&inputs)[CONV1_NB_CHANNELS][CONV1_CHANNELS_HEIGHT][CONV1_CHANNELS_WIDTH],
  DATA_T (&outputs)[CONV1_NB_OUTPUTS][CONV1_OUTPUTS_HEIGHT][CONV1_OUTPUTS_WIDTH],
  const BDATA_T (&bias)[CONV1_NB_OUTPUTS],
  const WDATA_T (*weights[CONV1_NB_OUTPUTS][CONV1_NB_CHANNELS])[CONV1_KERNEL_HEIGHT][CONV1_KERNEL_WIDTH])
{
  for (unsigned int output = 0; output < CONV1_NB_OUTPUTS; ++output)
    for (unsigned int oy = 0; oy < CONV1_OY_SIZE; ++oy)
      for (unsigned int ox = 0; ox < CONV1_OX_SIZE; ++ox)
      {
        const unsigned int sxMin = (unsigned int) int_max((int) CONV1_PADDING_X - (int) (ox * CONV1_STRIDE_X), 0);
        const unsigned int syMin = (unsigned int) int_max((int) CONV1_PADDING_Y - (int) (oy * CONV1_STRIDE_Y), 0);
        const unsigned int sxMax = (unsigned int) int_max(int_min((int) CONV1_CHANNELS_WIDTH + CONV1_PADDING_X - (int) (ox * CONV1_STRIDE_X),(int) CONV1_KERNEL_WIDTH),0);
        const unsigned int syMax = (unsigned int) int_max(int_min((int) CONV1_CHANNELS_HEIGHT + CONV1_PADDING_Y - (int) (oy * CONV1_STRIDE_Y),(int) CONV1_KERNEL_HEIGHT),0);
        const int ix = (int) (ox * CONV1_STRIDE_X) - (int) CONV1_PADDING_X;
        const int iy = (int) (oy * CONV1_STRIDE_Y) - (int) CONV1_PADDING_Y;
        outputs[CONV1_OUTPUT_OFFSET + output][oy][ox] = usat(neuron_conv1(inputs, bias, weights, output, sxMin, syMin, sxMax, syMax, ix, iy), CONV1_ACTIVATION, true, CONV1_SHIFT);
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

