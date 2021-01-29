// Copyright 2020-2021	Salvatore Barone <salvatore.barone@unina.it>
// 
// This file is part of CNN-VHDL
// 
// This is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or any later version.
// 
// This is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
// 
// You should have received a copy of the GNU General Public License along with
// RMEncoder; if not, write to the Free Software Foundation, Inc., 51 Franklin
// Street, Fifth Floor, Boston, MA 02110-1301, USA.

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
