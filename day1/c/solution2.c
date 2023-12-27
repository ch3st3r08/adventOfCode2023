#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  long int totalSum = 0;
  long int sum = 0;
  char lineStr[100];
  char reversedLineStr[100];
  char concatNumber[20];
  char firstNumber[2];
  char lastNumber[2];
  char *fileName = argv[1];
  char posibleNumber[90];
  FILE *fptr;

  // Char type is not a null terminated string, so we need to add the null
  firstNumber[1] = '\0';
  lastNumber[1] = '\0';

  // use appropriate location if you are using MacOS or Linux
  if ((fptr = fopen(fileName, "r")) == NULL) {
    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  while (fgets(lineStr, 100, fptr) != NULL) {
    for (int i = 0; i < strlen(lineStr); i++) {

      if (isdigit(lineStr[i])) {
        firstNumber[0] = lineStr[i];
        break;
      }

      strncat(posibleNumber, &lineStr[i], 1);
      if (strlen(posibleNumber) >= 3) {

        if (strstr(posibleNumber, "one") != NULL) {
          firstNumber[0] = '1';
          break;
        }
        if (strstr(posibleNumber, "two") != NULL) {
          firstNumber[0] = '2';
          break;
        }
        if (strstr(posibleNumber, "three") != NULL) {
          firstNumber[0] = '3';
          break;
        }
        if (strstr(posibleNumber, "four") != NULL) {
          firstNumber[0] = '4';
          break;
        }
        if (strstr(posibleNumber, "five") != NULL) {
          firstNumber[0] = '5';
          break;
        }
        if (strstr(posibleNumber, "six") != NULL) {
          firstNumber[0] = '6';
          break;
        }
        if (strstr(posibleNumber, "seven") != NULL) {
          firstNumber[0] = '7';
          break;
        }
        if (strstr(posibleNumber, "eight") != NULL) {
          firstNumber[0] = '8';
          break;
        }
        if (strstr(posibleNumber, "nine") != NULL) {
          firstNumber[0] = '9';
          break;
        }
      }
    }
    // strcpy(reversedLineStr, lineStr);
    // strrev(reversedLineStr);
    strcpy(posibleNumber, "");
    for (int i = (strlen(lineStr) - 1); i >= 0; i--) {
      if (isdigit(lineStr[i])) {
        lastNumber[0] = lineStr[i];
        break;
      }

      strncat(posibleNumber, &lineStr[i], 1);
      if (strlen(posibleNumber) >= 3) {

        if (strstr(posibleNumber, "eno") != NULL) {
          lastNumber[0] = '1';
          break;
        }
        if (strstr(posibleNumber, "owt") != NULL) {
          lastNumber[0] = '2';
          break;
        }
        if (strstr(posibleNumber, "eerht") != NULL) {
          lastNumber[0] = '3';
          break;
        }
        if (strstr(posibleNumber, "ruof") != NULL) {
          lastNumber[0] = '4';
          break;
        }
        if (strstr(posibleNumber, "evif") != NULL) {
          lastNumber[0] = '5';
          break;
        }
        if (strstr(posibleNumber, "xis") != NULL) {
          lastNumber[0] = '6';
          break;
        }
        if (strstr(posibleNumber, "neves") != NULL) {
          lastNumber[0] = '7';
          break;
        }
        if (strstr(posibleNumber, "thgie") != NULL) {
          lastNumber[0] = '8';
          break;
        }
        if (strstr(posibleNumber, "enin") != NULL) {
          lastNumber[0] = '9';
          break;
        }
      }
    }
    // printf("Concatenated number before Concatenation: %s\n", concatNumber);
    strcat(concatNumber, firstNumber);
    // printf("Concatenated number after first Concatenation: %s\n",
    // concatNumber); printf("Lastnumber value: %s\n", lastNumber);
    strcat(concatNumber, lastNumber);
    // printf("Concatenated number: %s %p\n", concatNumber, &concatNumber);

    sum = strtol(concatNumber, NULL, 10);
    totalSum = totalSum + sum;
    printf("first: %c last: %c suma: %ld totalAcc: %ld cadena: %s",
           firstNumber[0], lastNumber[0], sum, totalSum, lineStr);
    strcpy(concatNumber, "");
    strcpy(posibleNumber, "");
  }

  fclose(fptr);
  printf("La Suma total es %ld\n", totalSum);

  return 0;
}
