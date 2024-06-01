#include "../include/cmd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *valid_options[] = {
    "-l",       "--list", "-d",    "--disk", "-w",     "--weight", "-p",
    "--pacman", "-y",     "--yay", "-h",     "--help", "-V",       "--version"};

const char *valid_commands[] = {"clone", "push", "release", "zip", "help"};

int is_valid_option(char *arg) {
  for (size_t i = 0; i < sizeof(valid_options) / sizeof(valid_options[0]);
       i++) {
    if (strcmp(arg, valid_options[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int is_valid_command(char *arg) {
  for (size_t i = 0; i < sizeof(valid_commands) / sizeof(valid_commands[0]);
       i++) {
    if (strcmp(arg, valid_commands[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int PrintERROR(char *arg) {
  if (strstr(arg, "-")) {
    if (!is_valid_option(arg)) {
      const char Error_arg[] =
          BRED "error:" RESET BWHT " unexpected option" RESET BRED " %s " RESET
               "found\n\n" BRED "Usage:" RESET " meltwing " BGRN
               "[OPTIONS] [COMMAND]\n\n" RESET "For more information, try " BCYN
               " '--help / -h'. \n";
      (void)fprintf(stderr, Error_arg, arg);
    }
  } else {
    if (!is_valid_command(arg)) {
      const char Error_arg[] =
          BRED "error:" RESET BWHT " unexpected subcommand" RESET BRED
               " %s " RESET "found\n\n" BRED "Usage:" RESET " meltwing " BGRN
               "[OPTIONS] [COMMAND]\n\n" RESET "For more information, try " BCYN
               " '--help / -h'. \n";
      (void)fprintf(stderr, Error_arg, arg);
    }
  }
  exit(EXIT_FAILURE);
}
