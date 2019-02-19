#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "probably.h"

void flush_input() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}

int attackPrompt(char *enemyName, int enemyHealth) {
  char attack[20];
  int myAttack;
  printf("\nMake your attack: ");
  fgets(attack, 20, stdin);
  flush_input();
  printf("Oh no, not the %s \n", attack);
  myAttack = dice(6, 1);
  enemyHealth -= myAttack;
  printf("%s was dealt %d damage! \n", enemyName, myAttack);
  return myAttack;
}

int main(int argc, char **argv) {
  srand(time(0));   // Initialization, should only be called once.
  int goblinAttack;
  char goblinName[] = "Goblin";
  int goblinHealth = 20;
  int myHealth = 20;
  while (goblinHealth > 0 && myHealth > 0) {
    goblinHealth -= attackPrompt(goblinName, goblinHealth);
    goblinAttack = dice(6, 1);
    myHealth -= goblinAttack;
    printf("%s deals you %d damage! \n", goblinName, goblinAttack);
    printf("your health: %d\n", myHealth);
    // printf("\n%s health: %d\n", goblinName, goblinHealth);
  }
  if (myHealth > 0) {
    printf("\nYou have vanquished the %s!! \n\n", goblinName);
  } else {
    printf("\nThe %s has killed you.\nYou died doing what you loved. \n\n", goblinName);
  }
  return 0;
}
