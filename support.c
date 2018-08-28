#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void clearKeyboard(void) {
  while (getchar() != '\n');
}
int getInt(void) {
  int value;
  char newLine = 'x';
  scanf("%d%c", &value, &newLine);
  while (newLine != '\n') {
    printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    clearKeyboard();
    scanf("%d%c", &value, &newLine);
  }
  
  return value;
}

int getIntInRange(int lowerBound, int upperBound) {
  int value = getInt();
  while (value < lowerBound || value > upperBound) {
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
    value = getInt();
  }
  return value;
}
