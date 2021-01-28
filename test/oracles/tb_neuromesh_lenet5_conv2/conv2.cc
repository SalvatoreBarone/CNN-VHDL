#include "conv2.h"
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

SUM_T neuron_conv2
(
  DATA_T (&inputs)[CONV2_NB_CHANNELS][CONV2_CHANNELS_HEIGHT][CONV2_CHANNELS_WIDTH],
  const BDATA_T (&bias)[CONV2_NB_OUTPUTS],
  const WDATA_T (*weights[CONV2_NB_OUTPUTS][CONV2_NB_CHANNELS])[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH],
  unsigned int output,
  unsigned int sxMin,
  unsigned int syMin,
  unsigned int sxMax,
  unsigned int syMax,
  int ix,
  int iy
)
{
  SUM_T weightedSum = bias[output];
  for (unsigned int channel = 0; channel < CONV2_NB_CHANNELS; ++channel)
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

void convcell_upropagate_conv2(
  DATA_T (&inputs)[CONV2_NB_CHANNELS][CONV2_CHANNELS_HEIGHT][CONV2_CHANNELS_WIDTH],
  DATA_T (&outputs)[CONV2_NB_OUTPUTS][CONV2_OUTPUTS_HEIGHT][CONV2_OUTPUTS_WIDTH],
  const BDATA_T (&bias)[CONV2_NB_OUTPUTS],
  const WDATA_T (*weights[CONV2_NB_OUTPUTS][CONV2_NB_CHANNELS])[CONV2_KERNEL_HEIGHT][CONV2_KERNEL_WIDTH])
{
  for (unsigned int output = 0; output < CONV2_NB_OUTPUTS; ++output)
    for (unsigned int oy = 0; oy < CONV2_OY_SIZE; ++oy)
      for (unsigned int ox = 0; ox < CONV2_OX_SIZE; ++ox)
      {
        const unsigned int sxMin = (unsigned int) int_max((int) CONV2_PADDING_X - (int) (ox * CONV2_STRIDE_X), 0);
        const unsigned int syMin = (unsigned int) int_max((int) CONV2_PADDING_Y - (int) (oy * CONV2_STRIDE_Y), 0);
        const unsigned int sxMax = (unsigned int) int_max(int_min((int) CONV2_CHANNELS_WIDTH + CONV2_PADDING_X - (int) (ox * CONV2_STRIDE_X),(int) CONV2_KERNEL_WIDTH), 0);
        const unsigned int syMax = (unsigned int) int_max(int_min((int) CONV2_CHANNELS_HEIGHT + CONV2_PADDING_Y - (int) (oy * CONV2_STRIDE_Y),(int) CONV2_KERNEL_HEIGHT),0);
        const int ix = (int) (ox * CONV2_STRIDE_X) - (int) CONV2_PADDING_X;
        const int iy = (int) (oy * CONV2_STRIDE_Y) - (int) CONV2_PADDING_Y;
        outputs[CONV2_OUTPUT_OFFSET + output][oy][ox] = usat(neuron_conv2(inputs, bias, weights, output, sxMin, syMin, sxMax, syMax, ix, iy), CONV2_ACTIVATION, true, CONV2_SHIFT);
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

