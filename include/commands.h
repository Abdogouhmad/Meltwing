#define COMMAND_H
#ifndef H_COMMAND
// macros
#define MAX_BUFFER 1000

// libs
#include <git2.h>
#include <git2/global.h>

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
int CommandArguments(char *argv[], int __attribute__((__unused__)) argc);

int Controlflow(char *cmd);
int Clone();
#endif
