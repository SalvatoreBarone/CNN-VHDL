#include "fc1.h"

int int_max(int a, int b)
{
    return (a > b) ? a : b;
}

int int_min(int a, int b)
{
    return (a < b) ? a : b;
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

void fccell_upropagate_2d(
  DATA_T (&inputs)[CONV3_NB_OUTPUTS][CONV3_OUTPUTS_HEIGHT][CONV3_OUTPUTS_WIDTH],
  DATA_T (&outputs)[FC1_NB_OUTPUTS],
  const BDATA_T (&bias)[FC1_NB_OUTPUTS],
  const WDATA_T (&weights)[FC1_NB_OUTPUTS][FC1_NB_CHANNELS])
{
  for (unsigned int output = 0; output < FC1_NB_OUTPUTS; ++output)
  {
    SUM_T weightedSum = bias[output];
    unsigned int c = 0;
    for (unsigned int channel = 0; channel < CONV3_NB_OUTPUTS; ++channel)
      for (unsigned int iy = 0; iy < CONV3_OUTPUTS_HEIGHT; ++iy)
        for (unsigned int ix = 0; ix < CONV3_OUTPUTS_WIDTH; ++ix)
        {
          SUM_T prod = (SUM_T) weights[output][c++] * (SUM_T) ((UDATA_T) inputs[channel][iy][ix]);
          weightedSum = weightedSum + prod;
        }
    outputs[FC1_OUTPUT_OFFSET + output] = usat(weightedSum, FC1_ACTIVATION, true, FC1_SHIFT);
  }
}


