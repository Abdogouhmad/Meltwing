#include "../include/cmd.h"
#include "../include/commands.h"

int Controlflow(char *cmd) {
  if (strcmp(cmd, "clone") == 0) {
    int rst = Clone();
    exit(rst);
  }

  if (strcmp(cmd, "push") == 0) {
    printf("I am pushing ... \n");
    return 0;
  }
  PrintERROR(cmd);
  return 0;
  // (void)fprintf(stderr, "No command found: %s\n", cmd);
}
int CommandArguments(char *argv[], int argc) {
  for (int i = 1; i < argc; i++) {
    if (Controlflow(argv[i]) != 0) {
      return -1; // Return an error if Controlflow fails
    }
  }
  return 0;
}
