#include "../include/cmd.h"

int main(int __attribute__((__unused__)) argc, char *argv[]) {
  if (argc < 2) {
    printf(BRED "No arguments provided: Usage: meltwing -h to provide more "
                "insight.\n" RESET);
    return 1;
  }

  WorkFlow(argv, argc);

  // If no matching option is found
  return 1;
}
