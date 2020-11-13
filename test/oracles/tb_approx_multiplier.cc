#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "trunc.h"

#define DATA_SIZE 8


void print_binary(int amount, int num)
{
  assert(amount <= 32);
  for (int i = amount-1; i >= 0; i--)
    printf("%d", (num & (1<<i)) ? 1 : 0);
}


int main(){
 for (int i = SCHAR_MIN; i <= SCHAR_MAX; i++)
   for (int j = SCHAR_MIN; j <= SCHAR_MAX; j++)
   {
     print_binary(DATA_SIZE, i); printf(" "); print_binary(DATA_SIZE, j); printf(" "); print_binary(2*DATA_SIZE, i * j);
     for (int nab = 1; nab < DATA_SIZE-1; nab++)
     {
       char c_i = i, c_j = j;
       short res    = (short) (truncate::ax_integer(nab, c_i) * truncate::ax_integer(nab, c_j));
       printf(" "); print_binary(2*DATA_SIZE, res);
     }
     printf ("\n");
   }
 return 0;
}
