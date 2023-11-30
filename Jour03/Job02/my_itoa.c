//Vous devez implémenter la fonction my_itoa (dans un fichier my_itoa.c) qui prend en
//paramètre un int, et qui doit le convertir en chaîne de caractères.
//
//Fonctions autorisées : malloc.

#include <stdlib.h>

int my_intlen(int n) {
  int len = 0;
  while (n > 0) {
    n /= 10;
    len++;
  }
  return len;
}

char *my_itoa(int n) {
  int len = my_intlen(n);
  char *str = malloc(sizeof(char) * (len + 1));
  str[len] = '\0';
  while (len > 0) {
    str[len - 1] = n % 10 + '0';
    n /= 10;
    len--;
  }
  return str;
}