#include <malloc.h>



char *trim  (char *str)
{
    int i = 0;
    int j = 0;
    int len = sizeof(str);
    char *trimmed = malloc(sizeof(char) * len + 1);
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            trimmed[j] = str[i];
            j++;
        }
        i++;
    }
    trimmed[j] = '\0';
    return trimmed;
}