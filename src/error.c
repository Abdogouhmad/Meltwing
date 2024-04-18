#include "../include/cmd.h"

int Print_ERROR(char *arg) {
  if (strstr(arg, "-")) {    // Fixed the missing closing parenthesis
    const char Error_arg[] = // Added the declaration of Error_arg and corrected
                             // its type
        BRED "error:" RESET BWHT " unexpected argument" RESET BRED " %s " RESET
             "found\n\n" BRED "Usage:" RESET " meltwing " BGRN
             "[OPTIONS] [COMMAND]\n\n" RESET "For more information, try " BCYN
             " '--help / -h'. \n";
    (void)fprintf(stderr, Error_arg, arg); // Corrected the fprintf arguments
  }
  exit(1);
}
