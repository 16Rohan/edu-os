#ifndef SYSINFO_H
#define SYSINFO_H

#include "system_state.h"
#include "parser.h"

void cmd_uptime(SystemState *state, ParsedCommand *cmd);
void cmd_uname(SystemState *state, ParsedCommand *cmd);
void cmd_whoami(SystemState *state, ParsedCommand *cmd);
void cmd_version(SystemState *state, ParsedCommand *cmd);
void cmd_history(SystemState *state, ParsedCommand *cmd);

#endif
