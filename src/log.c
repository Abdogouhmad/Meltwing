#include "../include/sys.h"

char *ExpandPath(const char *path) {
  if (path[0] == '~') {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
      struct passwd *pw = getpwuid(getuid());
      if (pw == NULL) {
        return NULL;
      }
      home_dir = pw->pw_dir;
    }
    size_t home_len = strlen(home_dir);
    char *expanded_path = malloc(home_len + strlen(path) + 1);
    if (expanded_path == NULL) {
      return NULL;
    }
    (void)snprintf(expanded_path, home_len + strlen(path) + 1, "%s/%s",
                   home_dir, path + 1);
    return expanded_path;
  }
  return strdup(path);
}

FILE *OpenLogs(const char *path, const char *mode) {
  char *expanded_path = ExpandPath(path);
  if (expanded_path == NULL) {
    perror("Failed to expand path");
    return NULL;
  }

  char *pathfile = strdup(expanded_path);
  if (pathfile == NULL) {
    perror("Memory allocation error");
    free(expanded_path);
    return NULL;
  }

  char *sep = strchr(pathfile + 1, '/');
  while (sep != NULL) {
    *sep = '\0';
    if (mkdir(pathfile, DIRECTORY_PERMISSIONS) && errno != EEXIST) {
      (void)fprintf(stderr, "Error while trying to create directory %s: %s\n",
                    pathfile, strerror(errno));
      free(pathfile);
      free(expanded_path);
      return NULL;
    }
    *sep = '/';
    sep = strchr(sep + 1, '/');
  }
  free(pathfile);

  FILE *file = fopen(expanded_path, mode);
  free(expanded_path);
  if (file == NULL) {
    perror("Failed to open file");
    return NULL;
  }
  return file;
}
