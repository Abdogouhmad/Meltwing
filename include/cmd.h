#ifndef CMD_H
#define CMD_H
// libs header
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
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
/**
 * @file cmd.h
 * @brief Contains the declaration of the WorkFlow function.
 */

/**
 * @brief Executes a workflow based on the provided arguments.
 *
 * This function takes an array of strings as input, representing command-line
 * arguments, and an integer representing the number of arguments. It performs
 * some workflow based on the provided arguments.
 *
 * @param argv An array of strings containing the command-line arguments.
 * @param argc The number of command-line arguments passed to the function.
 *
 * @return An integer representing the status of the workflow execution.
 *         0 if the workflow executed successfully, otherwise a non-zero value
 *         indicating an error.
 *
 * @note This function is designed to be used as a callback or entry point for
 *       executing a specific workflow.
 *
 * @warning The `argc` parameter is currently marked as unused, but it is
 * provided for consistency with the standard C main function signature.
 */
int OptionCommand(char *argv[], int __attribute__((__unused__)) argc);
/**
 * @brief Execute a command
 * @param pathcommand
 * @param argemnts
 * @return int
 */
int exe(const char *pathcommand, char *const argemnts[]);
/*
 * @brief Print the error when the argument didn't match
 * @param filename
 * @return exit (1)
 */
int PrintERROR(char *arg);

/*
 * @brief Delete the file logs in desktop
 * @param file log path
 * @return eithe 0 or 1 exit
 */
int CleanLogs(const char *PathLog);
#endif
