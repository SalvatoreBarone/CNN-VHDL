#include "fc2.h"

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


