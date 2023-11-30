#include <stdlib.h>
#include <unistd.h>

int my_atoi(char *str);
char *my_itoa(int n);

int in_fibonacci(int n) {
  if (n < 0) {
    return 0;
  }
  int a = 0;
  int b = 1;

  for(int i = 0; i < (n-2); i++) {
    int tmp = a;
    a = b;
    b = tmp + b;
  }
  return b;
}


int main(int argc, char *argv[]) {
  if (argc < 2) {
    char *usage = "Usage: <program_name> <number>\n";
    write(STDERR_FILENO, usage, strlen(usage));
    return EXIT_FAILURE;
  }

  int n = my_atoi(argv[1]);
  int result = in_fibonacci(n);
  char *str = (char *) my_itoa(result);
  write(STDOUT_FILENO, str, strlen(str));
  free(str);
  return EXIT_SUCCESS;
}