#include <cmd.h>
#include <sys.h>

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
    "Commands:\n\n" RESET GRN "  clone\t\t\t" RESET
    "Clone any repo. Use 'meltwing help clone' to know more 🫠\n" GRN
    "  push\t\t\t" RESET "Push the changes to GitHub 😃\n" GRN
    "  release\t\t" RESET
    "Create release tag through the shell command 🙂\n" GRN "  zip\t\t\t" RESET
    "Zip your folder 📦\n" GRN "  help\t\t\t" RESET
    "Print this message or the help of the given subcommand(s)\n\n" BCYN
    "Options:\n\n" RESET GRN "  -l, --list\t\t" RESET
    "List the pacman and yay packages that needs to be updated\n" GRN
    "  -d, --disk\t\t" RESET "Analysis your disk partition\n" GRN
    "  -w, --weight\t\t" RESET "Measure the files within a directory\n" GRN
    "  -p, --pacman\t\t" RESET
    "Update pacman packages with store the logs in desktop\n" GRN
    "  -y, --yay\t\t" RESET
    "Update pacman packages with store the logs in desktop\n" GRN
    "  -h, --help\t\t" RESET "Get help\n" GRN "  -V, --version\t\t" RESET
    "CLI version\n";

/*
 * @breif PrintHelp - print the manual of the cli tool
 * @retunr 0
 */
int PrintHelp() {
  printf("%s\n", HELP);
  return 0;
}

/*
 * @breif PrintVersion - print the version of the CLI
 * @retunr 0
 */
int PrintVersion() {
  printf("meltwing 1.0.0\n");
  return 0;
}

/*
 * @breif HandleWeightCommand - Execute the command du with important paramaters
 * @retunr 0
 */
int HandleWeightCommand() {
  char *const du_arg[] = {"du", "-h", "--max-depth=1", ".", NULL};
  exe("/usr/bin/du", du_arg);
  return 0;
}

/**
 * @brief HandlePacman - small function that call updateSys to update pacman
 * packages
 * @return 0
 */
int HandlePacman() {
  printf(BYEL "Updating Pacman...\n" RESET);
  return UpdateSys("sudo pacman -Syu --noconfirm");
}
/*
 * @breif HandleYay - Update yay packages
 * @retunr 0
 */
int HandleYay() {
  printf(BYEL "Updating Yay ...\n" RESET);
  return UpdateSys("yay -Syu --noconfirm");
}
/*
 * @breif HandleDiskCmmand - Execute the commadn DUF
 * @retunr 0
 */
int HandleDiskCommand() {
  char *const df_arg[] = {"-h", "--all", NULL};
  return exe("/usr/bin/duf", df_arg);
}

int HandlPackageListing() {
  char *const list[] = {"/usr/bin/pacman", "-Qu", "--color=always", NULL};
  char *const listing[] = {"/usr/bin/yay", "-Qu", NULL};
  exe("/usr/bin/yay", listing);
  exe("/usr/bin/pacman", list);
  return 0;
}

/*
 * @breif HandlOptions - match the argument entered
 * @param option - which the arguments entered
 * @retunr 0 or 1 if didn't match
 */
int HandlOptions(char *option) {

  // helper command
  if (strcmp(option, "-h") == 0 || strcmp(option, "--help") == 0) {
    return PrintHelp();
  }
  // version command
  if (strcmp(option, "-V") == 0 || strcmp(option, "--version") == 0) {
    return PrintVersion();
  }
  // weight command
  if (strcmp(option, "-w") == 0 || strcmp(option, "--weight") == 0) {
    return HandleWeightCommand();
  }
  // disk command
  if (strcmp(option, "-d") == 0 || strcmp(option, "--disk") == 0) {
    return HandleDiskCommand();
  }
  // list the updates
  if (strcmp(option, "-l") == 0 || strcmp(option, "--list") == 0) {
    return HandlPackageListing();
  }
  // Update Pacman
  if (strcmp(option, "-p") == 0 || strcmp(option, "--pacman") == 0) {
    return HandlePacman();
  }
  // Update Yay
  if (strcmp(option, "-y") == 0 || strcmp(option, "--yay") == 0) {
    return HandleYay();
  }
  PrintERROR(option);
  return 0;
}

// main workflow
int WorkFlow(char *argv[], int __attribute__((__unused__)) argc) {
  for (int i = 1; i < argc; i++) {
    HandlOptions(argv[i]);
  }
  return 0;
}
