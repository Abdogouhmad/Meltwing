#include "../include/cmd.h"

int PrintERROR(char *arg) {
  // check if the argument has signiture of the option arg
  if (strstr(arg, "-")) {
    const char Error_arg[] =
        BRED "error:" RESET BWHT " unexpected argument" RESET BRED " %s " RESET
             "found\n\n" BRED "Usage:" RESET " meltwing " BGRN
             "[OPTIONS] [COMMAND]\n\n" RESET "For more information, try " BCYN
             " '--help / -h'. \n";
    (void)fprintf(stderr, Error_arg, arg);
  } else if (strstr(arg, arg)) {
    // if not check read it as subcommand
    const char Error_arg[] =
        BRED "error:" RESET BWHT " unexpected subcommand" RESET BRED
             " %s " RESET "found\n\n" BRED "Usage:" RESET " meltwing " BGRN
             "[OPTIONS] [COMMAND]\n\n" RESET "For more information, try " BCYN
             " '--help / -h'. \n";
    (void)fprintf(stderr, Error_arg, arg);
  }
  exit(1);
}
