#include <stdlib.h>
#include "probably.h"

int dice(int sides, int dice) {
  int roll = 0;
  while (dice) {
    roll += 1 + (rand() % 6);
    dice -= 1;
  }
  return roll;
}