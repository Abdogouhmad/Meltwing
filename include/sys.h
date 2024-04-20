#ifndef SYS_H
#define SYS_H

// defines
#define MAXBUF 1024
#define DIRECTORY_PERMISSIONS 0755
// libs header
#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
// func goes here

/**
 * @brief Open a log file
 * **create a dir called log if it doesn't exist inside it would**
 * create a file log.log
 * brief example: log/pacman.log or log/yay.log
 * @param filename
 * @param mode
 * @return FILE*
 */
FILE *OpenLogs(const char *path, const char *mode);

/**
 * @brief Update the system packages
 * @param cmd
 * @return 0/1
 */
int UpdateSys(const char *cmd);

#endif
