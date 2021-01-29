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
     print_binary(DATA_SIZE, i); printf(" "); print_binary(DATA_SIZE, j); printf(" "); print_binary(DATA_SIZE, i + j);
     for (int nab = 1; nab < DATA_SIZE-1; nab++)
     {
       int res = truncate::ax_integer(nab, i) + truncate::ax_integer(nab, j);
       printf(" "); print_binary(DATA_SIZE, res);
     }
     printf ("\n");
   }
 return 0;
}
