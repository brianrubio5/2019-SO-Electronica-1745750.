#include <stdio.h>
#include "entero.h"

int main(int argc, char** argv) {
  entero a,b;

  a = 20;
  b = 2;
  printf("la multiplicacion de %d / %d es %f \n",a,b,division(a,b));
}

