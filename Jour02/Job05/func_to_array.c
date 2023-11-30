#define NULL ((void *)0)

void func_to_array(char **strs, void(*func)(char *)){

  int i = 0;
    while(strs[i] != NULL)
    {
        func(strs[i]);
        i++;
    }
}
