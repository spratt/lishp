#ifndef __LISP_H__
#define __LISP_H__

// reads into the input buffer, return: NULL -> error, input buffer -> success
char* read(void);

// evaluates the input buffer, return: NULL -> error, output buffer -> success
char* eval(char* input);

// prints the output buffer, returns non-negative on success
int print(char* input);

// print given title, then start a read-eval-print loop with given prompt
int repl(const char* title, const char* prompt);

#endif
