#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Compare function for qsort
int compareStrings(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

// Trim leading and trailing whitespaces from a string
char *trim_(char *str) {
  while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r') {
    str++;
  }

  if (*str == '\0') {
    return str;
  }

  char *end = str + strlen(str) - 1;
  while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
    end--;
  }

  *(end + 1) = '\0';
  return str;
}

void writeString(const char *str) {
  size_t len = strlen(str);
  write(STDOUT_FILENO, str, len);
}

void writeChar(char c) {
  write(STDOUT_FILENO, &c, 1);
}

//int main(int argc, char *argv[]) {
//  // Check if there are arguments
//  if (argc < 2) {
//    char *usage = "Usage: <program_name> <string1> <string2> ... <stringN>\n";
//    write(STDERR_FILENO, usage, strlen(usage));
//    return EXIT_FAILURE;
//  }
//
//  // Allocate memory for an array of strings
//  char **strings = (char **)malloc((argc - 1) * sizeof(char *));
//  if (strings == NULL) {
//    perror("Memory allocation failed");
//    return EXIT_FAILURE;
//  }
//
//  // Copy and trim the input strings
//  for (int i = 1; i < argc; i++) {
//    strings[i - 1] = trim_(argv[i]);
//  }
//
//  // Sort the array of strings
//  qsort(strings, argc - 1, sizeof(char *), compareStrings);
//
//  // Print the sorted strings with spaces between them
//  for (int i = 0; i < argc - 1; i++) {
//    writeString(strings[i]);
//    if (i < argc - 2) {
//      writeChar(' ');
//    }
//  }
//
//  // Print a newline at the end
//  writeChar('\n');
//
//  // Free allocated memory
//  free(strings);
//
//  return EXIT_SUCCESS;
//}
