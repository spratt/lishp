#include <stdio.h>
#include <string.h>

#include "lisp.h"

char in_buffer[16384];
char out_buffer[16384];

char* read(void) {
  return fgets(in_buffer, sizeof(in_buffer), stdin);
}

char* eval(char* input) {
  if(input == NULL) {
    return strncpy(out_buffer, "Error reading input", sizeof(out_buffer));
  }
  // otherwise actually evaluate stuff
  return out_buffer;
}

int print(char* output) {
  if(output == NULL) {
    return fputs("Error evaluating input", stdout);
  }
  return fputs(output, stdout);
}

int repl(const char* title, const char* prompt) {
  fputs(title, stdout);
  int ret;
  do {
    fputs(prompt, stdout);
    ret = print(eval(read()));
  } while(ret > 0);
  return ret;
}
