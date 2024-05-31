#include "../include/cmd.h"
#include "../include/commands.h"

// int clone_repository(const char *url, const char *dest_path) {
//     git_repository *repo = NULL;
//     git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;

//     // Set clone options
//     clone_opts.fetch_opts.callbacks.credentials = NULL;

//     int error = git_clone(&repo, url, dest_path, &clone_opts);
//     if (error != 0) {
//         const git_error *e = git_error_last();
//         (void)fprintf(stderr, "Error %d/%d: %s\n", error, e->klass,
//         e->message); return -1;
//     }

//     git_repository_free(repo);
//     return 0;
// }

int Controlflow(char *cmd) {
  if (strcmp(cmd, "clone") == 0) {
    Clone();
    // Construct Git URL
    // snprintf(url, sizeof(url), "git@github.com:%s/%s.git", repo_owner,
    //          repo_name);

    // Set default destination path
    // snprintf(dest_path, sizeof(dest_path), "./cln/%s", repo_name);

    // Perform clone operation
    // int result = clone_repository(url, dest_path);
    // if (result != 0) {
    //   (void)fprintf(stderr, "Failed to clone repository\n");
    //   return -1;
    // }

    // printf("Repository cloned successfully to %s\n", dest_path);
    return 0;
  }

  if (strcmp(cmd, "push") == 0) {
    printf("I am pushing ... \n");
    return 0;
  }

  (void)fprintf(stderr, "No command found: %s\n", cmd);
  return -1;
}
int CommandArguments(char *argv[], int argc) {
  for (int i = 1; i < argc; i++) {
    if (Controlflow(argv[i]) != 0) {
      return -1; // Return an error if Controlflow fails
    }
  }
  return 0;
}
