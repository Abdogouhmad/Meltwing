#include "../include/cmd.h"
#include "../include/sys.h"
#include <stdio.h>
#include <stdlib.h>

int CleanLogs(const char *PathLog) {
  // convert the ~/ to /home/username/Desktop/logs
  char *expanded_path = ExpandPath(PathLog);
  // if the path is null return error
  if (expanded_path == NULL) {
    perror("ExpandPath");
    return 1;
  }

  // open the dir
  DIR *d = opendir(expanded_path);
  if (d == NULL) {
    perror("opendir");
    free(expanded_path);
    exit(1);
  }

  size_t path_len = strlen(expanded_path);
  int r = 0;

  struct dirent *p;
  // loop over the dir and read the files inside it
  while ((p = readdir(d)) != NULL) {
    int r2 = -1;
    char *buf;
    size_t len;

    if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
      continue;
    }

    len = path_len + strlen(p->d_name) + 2;
    buf = malloc(len);
    if (buf == NULL) {
      perror("malloc");
      closedir(d);
      free(expanded_path);
      exit(1);
    }

    // concatenating the expanded_path string and the current directory entry
    // p->d_name using snprintf.
    (void)snprintf(buf, len, "%s/%s", expanded_path, p->d_name);
    struct stat statbuf;

    // checks if the file is a directory using the S_ISDIR macro. If so, it
    // recursively calls the CleanLogs function on the directory. Otherwise, it
    // attempts to delete the file using unlink.
    if (stat(buf, &statbuf) == 0) {
      if (S_ISDIR(statbuf.st_mode)) {
        r2 = CleanLogs(buf);
      } else {
        r2 = unlink(buf);
      }
    }
    free(buf);
    if (r2 != 0) {
      r = r2;
    }
  }
  closedir(d);
  // if r is still 0 then it means all files within the sub dir
  // are deleted. Hance, the rmdir is called to remove the emoty dir logs
  if (r == 0) {
    r = rmdir(expanded_path);
  }

  free(expanded_path);
  printf(BGRN " The log folder is Deleted \n" RESET);
  return r;
}
