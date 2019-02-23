#include <stdlib.h>
#include <math.h>
#include "probably.h"

// generate the result of a dice roll.
int dice(int sides, int dice) {
  int roll = 0;
  while (dice) {
    roll += 1 + (rand() % sides);
    dice -= 1;
  }
  return roll;
}

// generate coordinates of a point on a surface of a unit sphere of arbitrary dimensions.
double * ndSphere(int dimensions) {
  double *coordinates = malloc(sizeof (double) * dimensions);
  double total;
  int i;
  for (i = 0; i < dimensions; i++) {
    total += coordinates[i] = (double)rand();
  }
  for (i = 0; i < dimensions; i++) {
    coordinates[i] = sqrt(coordinates[i] / total);
  }
  return coordinates;
}
