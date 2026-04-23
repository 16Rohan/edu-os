#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "system_state.h"
#include "parser.h"

void cmd_ls(SystemState *state, ParsedCommand *cmd);
void cmd_touch(SystemState *state, ParsedCommand *cmd);
void cmd_cat(SystemState *state, ParsedCommand *cmd);
void cmd_write(SystemState *state, ParsedCommand *cmd);

#endif
