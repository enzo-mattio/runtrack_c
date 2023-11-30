int my_sqrt(int x) {
  if (x < 0) {
    return 0;  // Square root of a negative number is undefined.
  }

  int result = 0;
  while (result * result <= x) {
    if (result * result == x) {
      return result;
    }
    result++;
  }

  return 0;  // If the square root is not an integer.
}