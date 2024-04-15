#include <cmd.h>
const char HELP[MAXHELP] =
    "Meltwing is a CLI tool that executes simple "
    "commands quickly to automate processes.\n\n" BRED "Usage: \n\n" RESET
    "meltwing" BGRN " [OPTIONS] [COMMAND]\n\n" RESET BCYN
    "Options:\n\n" RESET GRN "  -w, --weight\t\t" RESET
    "Measure the files within a directory\n" GRN "  -h, --help\t\t" RESET
    "Get help\n" GRN "  -V, --version\t\t" RESET "CLI version\n";

int WorkFlow(char *argv[], int __attribute__((__unused__)) argc) {
  for (int i = 1; i < argc; i++) {
    switch (argv[i][0]) {
    case '-':
      if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
        printf("%s\n", HELP);
        return 0; // Exit after printing help
      } else if (strcmp(argv[i], "-V") == 0 ||
                 strcmp(argv[i], "--version") == 0) {
        printf("meltwing 1.0.0\n");
        return 0; // Exit after printing version
      }
      break;
    default:
      printf("Invalid option. Use '-h' or '--help' for usage information.\n");
      break;
    }
  }
  return 1;
}
