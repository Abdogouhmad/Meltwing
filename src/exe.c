#include "../include/cmd.h"

int exe(const char *pathcommand, char *const argemnts[]) {
  // check if the command path is declared if not print error
  if (pathcommand == NULL) {
    perror("No command entered");
    exit(EXIT_FAILURE);
  }
  if (argemnts == NULL) {
    perror("No argument entered");
    exit(EXIT_FAILURE);
  }

  // print the argument and command
  printf("the command is: %s\n", pathcommand);
  for (int i = 0; argemnts[i] != NULL; i++) {
    printf("the argument is: %s\n", argemnts[i]);
  }
  return 0;
}