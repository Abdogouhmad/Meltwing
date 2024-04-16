#include "../include/cmd.h"

int exe(const char *pathcommand, char *const argemnts[]) {
  // check if the command path is declared if not print error
  if (pathcommand == NULL) {
    perror("No command entered");
    exit(EXIT_FAILURE);
  }
  // check if the argument is NULL or not
  if (argemnts == NULL) {
    perror("No argument entered");
    exit(EXIT_FAILURE);
  }

  // execlp(pathcommand, pathcommand, argemnts, NULL); // worked for duf
  // command execve(pathcommand, argemnts, NULL); // worked but not
  // effectively
  // execvp(pathcommand, argemnts); // worked as command but didn't work for duf
  execv(pathcommand, argemnts);
  // print error during failed
  perror("Failed to execute the command");
  exit(EXIT_FAILURE);

  return 0;
}
