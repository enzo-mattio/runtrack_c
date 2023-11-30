#include "malloc.h"

void **array_clone(char **strs, int n){
    void **tab = malloc(sizeof(void *) * n);
    int i = 0;
    while (i < n){
        tab[i] = strs[i];
        i++;
    }
    return tab;
}
