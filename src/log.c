#include "../include/cmd.h"

char *ExpandPath(const char *path) {
  if (path[0] == '~') {
    const char *home_dir;
    if ((home_dir = getenv("HOME")) == NULL) {
      if ((home_dir = getpwuid(getuid())->pw_dir) == NULL) {
        return NULL;
      }
    }
    size_t home_len = strlen(home_dir);
    char *expanded_path = malloc(home_len + strlen(path) + 1);
    if (expanded_path == NULL) {
      return NULL;
    }
    strcpy(expanded_path, home_dir);
    strcat(expanded_path, path + 1);
    return expanded_path;
  } else {
    return strdup(path);
  }
}

FILE *OpenLogs(const char *path, const char *mode, const char *content) {
  char *expanded_path = ExpandPath(path);
  if (expanded_path == NULL) {
    perror("Failed to expand path");
    return NULL;
  }

  char *p = strdup(expanded_path);
  if (p == NULL) {
    perror("Memory allocation error");
    free(expanded_path);
    return NULL;
  }

  char *sep = strchr(p + 1, '/');
  while (sep != NULL) {
    *sep = '\0';
    if (mkdir(p, 0755) && errno != EEXIST) {
      fprintf(stderr, "Error while trying to create directory %s: %s\n", p,
              strerror(errno));
      free(p);
      free(expanded_path);
      return NULL;
    }
    *sep = '/';
    sep = strchr(sep + 1, '/');
  }
  free(p);

  FILE *file = fopen(expanded_path, mode);
  free(expanded_path);
  if (file == NULL) {
    perror("Failed to open file");
    return NULL;
  }

  if (content != NULL) {
    fprintf(file, "%s", content);
  }

  return file;
}
