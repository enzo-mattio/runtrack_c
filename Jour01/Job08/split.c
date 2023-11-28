


#include <malloc.h>
#include <stdlib.h>

char **split(const char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len = 0;

    // Calculer la longueur de la chaîne str
    while (str[len] != '\0')
    {
        len++;
    }

    char **tokens = (char **)malloc(sizeof(char *) * (len + 1));

    while (str[i] != '\0')
    {
        j = 0;
        // Si le caractère n'est pas un espace, une tabulation ou un retour à la ligne
        while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
        {
            i++;
        }
        if(str[i] != '\0')
                {
                    tokens[k] = (char *)malloc(sizeof(char) * (j + 1));
                    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
                    {
                        tokens[k][j] = str[i];
                        i++;
                        j++;
                    }
                    tokens[k][j] = '\0';
                    // Copier le contenu de token dans tokens[k]
                    k++;
        }
    }
    tokens[k] = NULL;
    return tokens;
}