#include <cmd.h>

FILE *fopen_log(const char *filename, const char *mode, const char *constent) {
  const char *sep = strrchr(filename, '/');
  // check the filename and mode
  if (filename == NULL || mode == NULL || constent == NULL) {
    perror("Error: No filename, mode provided or constent provided");
    exit(EXIT_FAILURE);
  }

  // create a dir called log if it doesn't exist
  if (sep != NULL) {
    char *parent_path = strndup(filename, sep - filename);

    if (parent_path == NULL) {
      perror("Failed to allocate memory for parent directory path");
      exit(EXIT_FAILURE);
    }

    // Recursively create parent directories
    rek_mkdir(parent_path);

    free(parent_path);
  }

  FILE *fp = fopen(filename, mode);
  if (fp == NULL) {
    perror("Failed to open log file");
  }
  // write content
  fprintf(fp, "%s", constent);
  return fp;
}

void rek_mkdir(const char *path) {
  const char *sep = strrchr(path, '/');
  if (sep != NULL) {
    char *parent_path =
        strndup(path, sep - path); // Allocate memory for parent directory path
    if (parent_path == NULL) {
      perror("Failed to allocate memory for parent directory path");
      exit(EXIT_FAILURE);
    }

    // Recursively create parent directories
    rek_mkdir(parent_path);

    free(parent_path); // Free allocated memory
  }

  if (mkdir(path, 0777) && errno != EEXIST) {
    fprintf(stderr, "Failed to create directory '%s': %s\n", path,
            strerror(errno));
    exit(EXIT_FAILURE);
  }
}
