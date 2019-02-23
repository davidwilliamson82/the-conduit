#include <stdlib.h>
#include <math.h>
#include "probably.h"

int dice(int sides, int dice) {
  int roll = 0;
  while (dice) {
    roll += 1 + (rand() % sides);
    dice -= 1;
  }
  return roll;
}

double * ndSphere(int dimensions) {
  double *coordinates = malloc(sizeof (double) * dimensions);
  double total;
  int i;
  for (i = 0; i < dimensions; i++) {
    total += coordinates[i] = (double)rand(); //sqrt((double)(rand()) / (double)RAND_MAX);
  }
  for (i = 0; i < dimensions; i++) {
    coordinates[i] = sqrt(coordinates[i] / total);
  }
  return coordinates;
}
