#include <malloc.h>

int my_strlen(char *str);


char *my_strdup(char *str)
{
    int i = 0;
    char *dest;

    // Allouer de la mémoire pour la nouvelle chaîne
    dest = malloc(sizeof(char) * (my_strlen(str) + 1)); // +1 pour le caractère nul

    // Vérifier si l'allocation a réussi
    if (dest == NULL) {
        perror("Allocation mémoire échouée");
        exit(EXIT_FAILURE);
    }

    // Copier les caractères de la chaîne source vers la nouvelle chaîne
    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }

    // Ajouter le caractère nul à la fin de la nouvelle chaîne
    dest[i] = '\0';

    return dest;
}
