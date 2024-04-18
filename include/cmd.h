#ifndef CMD_H
#define CMD_H
// libs header
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pwd.h>
// defines
#define MAXHELP 2000
#define MAXERROR 100
#define DIRECTORY_PERMISSIONS 0755
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
 * This function takes an array of strings as input, representing command-line arguments,
 * and an integer representing the number of arguments. It performs some workflow based
 * on the provided arguments.
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
 * @warning The `argc` parameter is currently marked as unused, but it is provided
 *          for consistency with the standard C main function signature.
 */
int WorkFlow(char *argv[], int __attribute__((__unused__)) argc);
/**
 * @brief Execute a command
 * @param pathcommand
 * @param argemnts
 * @return int
 */
int exe(const char *pathcommand, char *const argemnts[]);
/**
 * @brief Open a log file
 * **create a dir called log if it doesn't exist inside it would**
 * create a file log.log
 * brief example: log/pacman.log or log/yay.log
 * @param filename
 * @param mode
 * @return FILE*
 */
FILE *OpenLogs(const char *path, const char *mode, const char *content);
int Print_ERROR(char *arg);
#endif
