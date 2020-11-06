#include <stdio.h>
#include <assert.h>
#include <limits.h>

void print_binary(int amount, int num)
{
  assert(amount <= 32);
  for (int i = amount-1; i >= 0; i--)
    printf("%d", (num & (1<<i)) ? 1 : 0);
}


int main(){
 for (int i = SHRT_MIN; i <= SHRT_MAX; i++)
 {
   print_binary(16, i);                     
   printf(" "); print_binary(16, i);        
   printf(" "); print_binary(16, i >> 1);   
   printf(" "); print_binary(16, i >> 2);   
   printf(" "); print_binary(16, i >> 3);   
   printf(" "); print_binary(16, i >> 4);   
   printf(" "); print_binary(16, i >> 5);   
   printf(" "); print_binary(16, i >> 6);   
   printf(" "); print_binary(16, i >> 7);   
   printf(" "); print_binary(16, i << 1);   
   printf(" "); print_binary(16, i << 2);   
   printf(" "); print_binary(16, i << 3);   
   printf(" "); print_binary(16, i << 4);   
   printf(" "); print_binary(16, i << 5);   
   printf(" "); print_binary(16, i << 6);   
   printf(" "); print_binary(16, i << 7);   

   printf ("\n");
 }
 return 0;
}
