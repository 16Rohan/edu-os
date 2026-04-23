#include "parser.h"
#include <string.h>
#include <ctype.h>

void parse_input(char *input, ParsedCommand *cmd) {
    cmd->argc = 0;
    cmd->name = NULL;

    // Remove trailing newline
    input[strcspn(input, "\r\n")] = 0;

    char *token = strtok(input, " \t");
    if (token != NULL) {
        cmd->name = token;
        while ((token = strtok(NULL, " \t")) != NULL && cmd->argc < MAX_ARGS) {
            cmd->argv[cmd->argc++] = token;
        }
    }
}
