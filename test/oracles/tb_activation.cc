#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <inttypes.h>
#include <stdbool.h>

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

int main()
{
 
 int actual_size = 16,
     final_size = 8, 
     int_min = -(1<<(actual_size-1)), 
     int_max = (1<<(actual_size-1))-1;
 for (int i = int_min; i <= int_max; i++)
 {
    print_binary(actual_size, i);

    // linear
    for (int j = -7; j < 8; j++) {
      printf(" "); print_binary(final_size, usat(i, Linear, false, j));
    }
    
    // rect on unsigned 
    for (int j = -7; j < 8; j++) {
      printf(" "); print_binary(final_size, usat(i, Rectifier, true, j));
    }
    
    // rect on signed
    for (int j = -7; j < 8; j++) {
      printf(" "); print_binary(final_size, usat(i, Rectifier, false, j));
    }
    printf("\n");
 }
  
  return 0;
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

