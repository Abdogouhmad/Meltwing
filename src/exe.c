#include "../include/cmd.h"

int exe(const char *pathcommand, char *const argemnts[], char *const envp[]) {
  if (strlen(pathcommand) == 0) {
    perror("No command entered");
    exit(EXIT_FAILURE);
  }
  return 0;
}