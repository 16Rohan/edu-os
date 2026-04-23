#ifndef COMMANDS_H
#define COMMANDS_H

#include "system_state.h"
#include "parser.h"

// Returns 1 to continue executing, 0 to exit the shell.
int execute_command(SystemState *state, ParsedCommand *cmd);

#endif
