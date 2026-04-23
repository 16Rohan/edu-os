#include "sysinfo.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>

void cmd_uptime(SystemState *state, ParsedCommand *cmd) {
    (void)cmd;
    time_t now = time(NULL);
    int elapsed = (int)difftime(now, state->start_time);
    int hours = elapsed / 3600;
    int mins = (elapsed % 3600) / 60;
    int secs = elapsed % 60;
    printf("Uptime: %02d:%02d:%02d\n", hours, mins, secs);
}

void cmd_uname(SystemState *state, ParsedCommand *cmd) {
    (void)state;
    (void)cmd;
    printf("EDU-OS v0.2 (Educational Build) — Custom Shell Wrapper\n");
}

void cmd_whoami(SystemState *state, ParsedCommand *cmd) {
    (void)state;
    (void)cmd;
    printf("guest\n");
}

void cmd_version(SystemState *state, ParsedCommand *cmd) {
    (void)state;
    (void)cmd;
    print_color(COLOR_CYAN, "EDU-OS ");
    printf("v0.2\n");
    printf("Educational OS Simulator\n");
    printf("Built with GCC on Windows\n");
}

void cmd_history(SystemState *state, ParsedCommand *cmd) {
    (void)cmd;
    if (state->history_count == 0) {
        printf("(no history)\n");
        return;
    }
    for (int i = 0; i < state->history_count; i++) {
        printf("  %3d  %s\n", i + 1, state->history[i]);
    }
}
