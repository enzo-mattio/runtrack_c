#define NULL ((void *)0)
char **sort(char **tab, int (*cmp)(char *, char *))
{
    int i = 0;
    int j = 0;
    char *tmp;
    while (tab[i] != NULL)
    {
        j = 0;
        while (tab[j] != NULL)
        {
            if (cmp(tab[i], tab[j]) < 0)
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return tab;
}