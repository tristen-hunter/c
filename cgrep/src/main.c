// USAGE - Goal
// ./cgrep "hello" test-files/hello.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HL_ON "\033[31m" /* bold red */
#define HL_OFF "\033[0m" /* reset */

void print_highlighted(const char *line, const char *term) {
  size_t term_len = strlen(term);

  const char *cur = line;
  const char *match;

  while ((match = strstr(cur, term)) != NULL) {
    printf("%.*s", (int)(match - cur),
           cur); /* plain text before the highlight */

    printf(HL_ON "%.*s" HL_OFF, (int)term_len,
           match); /* the match, highlighted */

    cur = match + term_len;
  }
  fputs(cur, stdout);
}

int main(int argc, char *argv[]) {
  char *search_term;
  FILE *search_file;
  char *line = NULL;
  size_t size = 0;
  ssize_t nread;
  int line_num = 1;

  // Validate call
  if (argc < 3) {
    printf("Too few arguments entered.\n");
    exit(EXIT_FAILURE);
  }
  search_term = argv[1];
  if (strlen(search_term) == 0) {
    fprintf(stderr, "Error: Search term cannot be empty.\n");
    return EXIT_FAILURE;
  }

  search_file = fopen(argv[2], "r");
  if (search_file == NULL) {
    printf("Error opening file!\n");
    exit(EXIT_FAILURE);
  }

  while ((nread = getline(&line, &size, search_file)) != -1) {
    char *match = strstr(line, search_term);
    if (match != NULL) {
      printf("%d.. ", line_num);
      print_highlighted(line, search_term);
    }
    line_num++;
  }

  free(line);
  fclose(search_file);
  exit(EXIT_SUCCESS);
}
