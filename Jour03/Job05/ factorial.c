#include <unistd.h>
#include <stdlib.h>

int my_atoi(char *str);
char *my_itoa(int n);

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main(int argc, char *argv[]){
  if (argc < 2) {
    char *usage = "Usage: <program_name> <number>\n";
    write(STDERR_FILENO, usage, strlen(usage));
    return EXIT_FAILURE;
  }

  int n = my_atoi(argv[1]);
  int result = factorial(n);
  char *str = (char *) my_itoa(result);
  write(STDOUT_FILENO, str, strlen(str));
  free(str);
  return EXIT_SUCCESS;
}



