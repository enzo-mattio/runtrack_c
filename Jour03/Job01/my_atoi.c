int my_atoi(const char *str) {
  int result = 0;
  int sign = 1;
  int i = 0;

  // Handle the sign
  if (str[0] == '-') {
    sign = -1;
    i++;
  }

  // Convert each digit to an integer
  while (str[i] != '\0') {
    result = result * 10 + (str[i] - '0');
    i++;
  }

  return sign * result;
}
