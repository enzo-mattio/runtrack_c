int power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  } else {
    int result = 1;
    while (exponent > 0) {
      result *= base;
      exponent--;
    }
    return result;
  }
}