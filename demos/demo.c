// demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>      /* printf */

char *asm_fn1(void) {
  asm("mov $50, %rax\n\t"
      "mov %rbp, %rsp\n\t"
      "pop %rbp\n\t"
      "ret");
}

int main(void)
{ 
    printf("delta %d\n", asm_fn1());
}