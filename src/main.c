#include "../include/cmd.h"
#include "../include/commands.h"
#include <stdio.h>

int main(int __attribute__((__unused__)) argc, char *argv[]) {

  if (argc < 2) {
    printf(BRED "No arguments provided: Usage: meltwing -h to provide more "
                "insight.\n" RESET);
    return 1;
  }
  // option commands
  if (OptionCommand(argv, argc) != 0) {
    int rst =
        fprintf(stderr, "An error occurred while processing the commands.\n");
    return rst;
  }

  // commands
  if (CommandArguments(argv, argc) != 0) {
    int rst =
        fprintf(stderr, "An error occurred while processing the commands.\n");
    return rst;
  }

  // return
  return 0;
}
