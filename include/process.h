#ifndef PROCESS_H
#define PROCESS_H

#include "system_state.h"
#include "parser.h"

void cmd_ps(SystemState *state, ParsedCommand *cmd);
void cmd_run(SystemState *state, ParsedCommand *cmd);
void cmd_kill(SystemState *state, ParsedCommand *cmd);

#endif
