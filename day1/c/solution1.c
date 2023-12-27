#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *str) {
  if (!str || !*str)
    return str;

  int i = strlen(str) - 1, j = 0;

  char ch;
  while (i > j) {
    ch = str[i];
    str[i] = str[j];
    str[j] = ch;
    i--;
    j++;
  }
  return str;
}

int main(int argc, char *argv[]) {
  long int totalSum = 0;
  long int sum = 0;
  char lineStr[100];
  char reversedLineStr[100];
  char concatNumber[10];
  char firstNumber[2];
  char lastNumber[2];
  char *fileName = argv[1];
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
    }
    strcpy(reversedLineStr, lineStr);
    strrev(reversedLineStr);
    for (int i = 0; i < strlen(reversedLineStr); i++) {
      if (isdigit(reversedLineStr[i])) {
        lastNumber[0] = reversedLineStr[i];
        break;
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
  }

  fclose(fptr);
  printf("La Suma total es %ld\n", totalSum);

  return 0;
}
