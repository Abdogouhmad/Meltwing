#include <sys.h>
#include <cmd.h>

int UpdateSys(const char *cmd) {
  FILE *FileOpen;
  char buffer[MAXBUF];

  FileOpen = popen(cmd, "r");

  //  check if open pip cmd is NULL
  if (FileOpen == NULL) {
    perror("Failed to open pipe for command execution.\n");
    return -1;
  }
  // name the log file based on command using strstr
  const char *logFilename =
      (strstr(cmd, "yay")) ? "~/Desktop/logs/yay.log" : "~/Desktop/logs/pacman.log";
  // Open the output file for writing

  FILE *output = OpenLogs(logFilename, "w");

  if (output == NULL) {
    perror("Failed to open output file.\n");
    return -1;
  }
  // Read the command output line by line and write to the file
  while (fgets(buffer, sizeof(buffer), FileOpen) != NULL) {
    fprintf(output, "%s", buffer);
  }

  // Close the pipe and the output file
  pclose(FileOpen);
  fclose(output);

  printf(BGRN "Command output successfully stored in Desktop/logs folder\n" RESET);
  return 0;
}
