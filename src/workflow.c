#include "../include/cmd.h"

const char HELP[MAXHELP] =
    "   _____           .__     __    __      __ .__                  \n"
    "  /     \\    ____  |  |  _/  |_ /  \\    /  \\|__|  ____     ____  \n"
    " /  \\ /  \\ _/ __ \\ |  |  \\   __\\\\   \\/\\/   /|  |/    \\   / ___\\ "
    "\n"
    "/    Y    \\\\  ___/ |  |__ |  |   \\        / |  ||   |  \\ / /_/  >\n"
    "\\____|__  / \\___  >|____/ |__|    \\__/\\  /  |__||___|  / \\___  / \n"
    "        \\/      \\/                     \\/            \\/ /_____/  \n"
    "\n" BWHT "Meltwing is a CLI tool that executes simple "
    "commands quickly to automate processes.🕯️\n\n" RESET BRED
    "Usage: \n\n" RESET "meltwing" BGRN " [OPTIONS] [COMMAND]\n\n" RESET BCYN
    "Commands:\n\n" RESET GRN "  clone\t\t" RESET
    "Clone any repo. Use 'meltwing help clone' to know more 🫠\n" GRN
    "  push\t\t" RESET "Push the changes to GitHub 😃\n" GRN "  release\t" RESET
    "Create release tag through the shell command 🙂\n" GRN "  zip\t\t" RESET
    "Zip your folder 📦\n" GRN "  help\t\t" RESET
    "Print this message or the help of the given subcommand(s)\n\n" BCYN
    "Options:\n\n" RESET GRN "  -w, --weight\t\t" RESET
    "Measure the files within a directory\n" GRN "  -c, --create\t\t" RESET
    "create a file logs within folder log\n" GRN "  -h, --help\t\t" RESET
    "Get help\n" GRN "  -V, --version\t\t" RESET "CLI version\n";

int WorkFlow(char *argv[], int __attribute__((__unused__)) argc) {
  for (int i = 1; i < argc; i++) {
    switch (argv[i][0]) {
    case '-':
      // helper command
      if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
        printf("%s\n", HELP);
        return 0; // Exit after printing help
      }
      // version command
      if (strcmp(argv[i], "-V") == 0 || strcmp(argv[i], "--version") == 0) {
        printf("meltwing 1.0.0\n");
        return 0; // Exit after printing version
      }
      // weight command
      if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--weight") == 0) {
        // called the exe function
        char *const du_arg[] = {"du", "-h", "--max-depth=1", ".", NULL};
        exe("/usr/bin/du", du_arg);
        /*
          execute the command duff
          char *const duf_args[] = {"--all"};
          exe("/usr/bin/duf", duf_args);
          char *duf_arg[] = {"--all"};
          exe("/usr/bin/duf", duf_arg);
          execlp("du", "du", du_arg, NULL);
        */
        return 0;
      }
      // create logs folder
      if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--create") == 0) {
        printf("creating...\n");
        FILE *file = OpenLogs("~/Desktop/lgC/pacman.log", "w", "hello world\n");
        if (file != NULL) {
          printf("File created and written successfully.\n");
          fclose(file);
        } else {
          fprintf(stderr, "Failed to create file.\n");
        }
        return 0;
      }
      break;
    case 'p':
      if (strcmp(argv[i], "push") == 0) {
        printf("Pushing\n");
        return 0; // Exit after handling "push" command
      }
      break;
    default:
      printf(BRED "Invalid option. Use '-h' or '--help' for usage "
                  "information.\n" RESET);
      return 1;
      break;
    }
  }
  return 0;
}
