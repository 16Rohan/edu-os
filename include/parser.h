#ifndef PARSER_H
#define PARSER_H

#define MAX_INPUT_LEN 256
#define MAX_ARGS 32

typedef struct {
    char *name;
    int argc;
    char *argv[MAX_ARGS];
} ParsedCommand;

void parse_input(char *input, ParsedCommand *cmd);

#endif
