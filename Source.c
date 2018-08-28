#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


struct passPhrase {
  char word[11];
};

int getInt(void);
int getIntInRange(int lowerBound, int upperBound);
void clearKeyboard(void);

int main(void) {
  //declaring the variables
  int noOfPhrases = 0;
  int highest = 6;
  int lowest = 1;
  int randomNumber[5] = { 0 };
  int randomNumArray[20] = { 0 };
  struct passPhrase yourPhrase[20] = { {'\0'},{ '\0' },{ '\0' },{ '\0' },{ '\0' },{ '\0' } };
  int counter;
  int counter2;
  int sum = 0;
  const int base = 10;
  int compareNumber = 0;
  char compareWord[11];
  char position[3];
  char exitChoice = 'x';
  FILE* ptr = NULL;

  printf("                              PassPhrase Generator\n");
  printf(" ---------------------------------------------------------------------------------------\n");
  printf("|\"A passphrase is a sequence of words or other text used to control                    |\n");
  printf("|access to a computer system, program or data.A passphrase is similar                  |\n");
  printf("|to a password in usage, but is generally longer for added security.\"-wikipedia        |\n");
  printf(" ---------------------------------------------------------------------------------------\n\n");
  
  do {
    printf("How many phrases do you want? [Maximum 20]: ");
    noOfPhrases = getIntInRange(1, 20);

    //generating a random seed for random number
    srand(time(NULL));
    //generating 6 random numbers each consisting of 5 digits
    for (counter2 = 0; counter2 < noOfPhrases; counter2++) {
      for (counter = 0; counter < 5; counter++) {
        randomNumber[counter] = lowest + rand() % (highest + 1 - lowest);
        sum += (randomNumber[counter] * pow(base, counter));
      }
      randomNumArray[counter2] = sum;
      sum = 0;
    }
    ptr = fopen("wordlist.txt", "r");
    if (ptr != NULL) {
      for (counter = 0; counter < noOfPhrases; counter++) {
        while (fscanf(ptr, "%d,%s", &compareNumber, compareWord) != EOF && compareNumber != randomNumArray[counter]);
        strcpy(yourPhrase[counter].word, compareWord);

        if (counter == 0) {
          strcpy(position, "st");
        }
        else if (counter == 1) {
          strcpy(position, "nd");
        }
        else if (counter == 3) {
          strcpy(position, "rd");
        }
        else {
          strcpy(position, "th");
        }
        printf("%d%s phrase is: %s\n", counter + 1, position, yourPhrase[counter].word);
        rewind(ptr);
      }
    }
    else {
      printf("The word list file is missing\n");
    }

    printf("\nDo you want to generate more? (Y)es or (N)o: ");
    exitChoice= getchar();
    printf("\n");

  } while (exitChoice == 'y' || exitChoice == 'Y');

  //printf("\n");
  fclose(ptr);
  

  return 0;
}