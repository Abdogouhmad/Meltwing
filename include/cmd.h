#ifndef CMD_H
#define CMD_H
// libs header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
// defines
#define MAXHELP 2000
// bold colors
#define BBLK "\033[1;30m"
#define BRED "\033[1;31m"
#define BGRN "\033[1;32m"
#define BYEL "\033[1;33m"
#define BBLU "\033[1;34m"
#define BMAG "\033[1;35m"
#define BCYN "\033[1;36m"
#define BWHT "\033[1;37m"
#define RESET "\033[0m" // Reset color
// Regular colors
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

// functions
// the workflow of the CLI
int WorkFlow(char *argv[], int __attribute__((__unused__)) argc);
// the command executer
int exe(const char *pathcommand, char *const argemnts[], char *const envp[]);
#endif
