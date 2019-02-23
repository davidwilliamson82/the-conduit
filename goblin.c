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
  myAttack = dice(6, 2);
  enemyHealth -= myAttack;
  printf("%s was dealt %d damage! \n", enemyName, myAttack);
  return myAttack;
}

int main(int argc, char **argv) {
  srand(time(0));   // Initialization, should only be called once.
  char statNames[6][13] = {"strength", "speed", "magic", "dexterity", "intelligence", "stamina"};
  double *statValues = ndSphere(6);
  int i;
  for (i = 0; i < 6; i ++) {
    printf("Your %s is %.2f.\n", statNames[i], statValues[i]);
  }

  int goblinAttack;
  char goblinName[] = "Goblin";
  int goblinHealth = 30;
  int myHealth = 30;
  while (goblinHealth > 0 && myHealth > 0) {
    goblinHealth -= attackPrompt(goblinName, goblinHealth);
    goblinAttack = dice(6, 2);
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
