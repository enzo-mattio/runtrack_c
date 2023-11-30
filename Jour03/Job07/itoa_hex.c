#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int my_atoi(char *str);

char getHexChar(int remainder) {
  if (remainder >= 0 && remainder <= 9) {
    return (char) ('0' + remainder);
  } else {
    return (char) ('A' + remainder - 10);
  }
}

char *itoa_hex(int n) {
  int index = 0;
  char *hexadecimalNumber = malloc(sizeof(char) * 100);

  while (n > 0) {
    int remainder = n % 16;
    hexadecimalNumber[index++] = getHexChar(remainder);
    n /= 16;
  }

  // Ajouter le caractère de fin de chaîne
  hexadecimalNumber[index] = '\0';

  // Inverser la chaîne pour obtenir le résultat final
  int start = 0;
  int end = index - 1;
  while (start < end) {
    // Échanger les caractères
    char temp = hexadecimalNumber[start];
    hexadecimalNumber[start] = hexadecimalNumber[end];
    hexadecimalNumber[end] = temp;

    // Passer aux positions suivantes
    start++;
    end--;
  }

  return hexadecimalNumber; // Ajouter cette ligne pour renvoyer le résultat
}





