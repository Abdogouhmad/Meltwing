#include "../include/cmd.h"
#include "../include/commands.h"

int Clone() {
  // init with allocation
  char *repo_owner = malloc(MAX_BUFFER * sizeof(char));
  char *repo_name = malloc(MAX_BUFFER * sizeof(char));
  char *url = malloc(MAX_BUFFER * sizeof(char));
  char *path = malloc(MAX_BUFFER * sizeof(char));
  // check the the malloc of it is  not null
  if (repo_name == NULL || repo_owner == NULL || url == NULL || path == NULL) {
    int result = fprintf(stderr, "Memory allocation failed\n");
    exit(result);
  }
  // Get repository owner
  printf(BCYN " Enter repository owner: " RESET);
  if (scanf("%s", repo_owner) != 1) {
    (void)fprintf(stderr, "Failed to read repository owner\n");
    return -1;
  }

  // Get repo name
  printf(BCYN " Enter repository name: " RESET);
  if (scanf("%s", repo_name) != 1) {
    (void)fprintf(stderr, "Failed to read repository name\n");
    return -1;
  }

  // path that you name where the repo will be cloned at
  printf(BCYN " Enter path name: " RESET);
  if (scanf("%s", path) != 1) {
    (void)fprintf(stderr, "Failed to read repository name\n");
    return -1;
  }

  // bind the input with the url repo
  int rst = snprintf(url, MAX_BUFFER, "https://github.com/%s/%s.git",
                     repo_owner, repo_name);

  // if the input exeed the bufer return error
  if (rst >= MAX_BUFFER) {
    printf("Output was truncated. Needed %d characters.\n", rst);
    exit(EXIT_FAILURE);
  }

  // init the git
  git_libgit2_init();

  // oprate over the clone
  git_repository *repo = NULL;
  // clone the repo
  int error = git_clone(&repo, url, path, NULL);
  // op over the error
  if (error != 0) {
    const git_error *ero = git_error_last();
    int error_rst =
        fprintf(stderr, "Error %d/%d: %s\n", error, ero->klass, ero->message);
    exit(error_rst);
  }

  // free the vars & shotdown the shit
  git_repository_free(repo);
  git_libgit2_shutdown();
  printf(BGRN "Repository cloned successfully to: %s\n" RESET, path);
  free(repo_owner);
  free(repo_name);
  free(url);
  free(path);
  return 0;
}
