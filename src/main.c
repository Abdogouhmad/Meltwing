#include "../include/cmd.h"
#include "../include/commands.h"

int main(int __attribute__((__unused__)) argc, char *argv[]) {

  if (argc < 2) {
    printf(BRED "No arguments provided: Usage: meltwing -h to provide more "
                "insight.\n" RESET);
    return 1;
  }

  OptionCommand(argv, argc);
  // init git
  // git_libgit2_init();
  int results = CommandArguments(argv, argc);
  // shoutdown git
  // git_libgit2_shutdown();
  // If no matching option is found
  return results;
}
