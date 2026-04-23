#include "process.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cmd_ps(SystemState *state, ParsedCommand *cmd) {
    (void)cmd;
    print_color(COLOR_CYAN, "PID   NAME             STATE\n");
    for (int i = 0; i < state->process_count; i++) {
        Process *p = &state->processes[i];
        printf("%-5d %-16s %s\n", p->pid, p->name, p->state);
    }
}

void cmd_run(SystemState *state, ParsedCommand *cmd) {
    if (cmd->argc < 1) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Usage: run <name>\n");
        return;
    }
    if (state->process_count >= MAX_PROCS) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Process limit reached (%d)\n", MAX_PROCS);
        return;
    }

    Process *p = &state->processes[state->process_count];
    p->pid = state->next_pid++;
    strncpy(p->name, cmd->argv[0], sizeof(p->name) - 1);
    p->name[sizeof(p->name) - 1] = '\0';
    strncpy(p->state, "running", sizeof(p->state) - 1);
    state->process_count++;

    print_color(COLOR_GREEN, "[OK] ");
    printf("Process '%s' started with PID %d\n", p->name, p->pid);
}

void cmd_kill(SystemState *state, ParsedCommand *cmd) {
    if (cmd->argc < 1) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Usage: kill <pid>\n");
        return;
    }

    int pid = atoi(cmd->argv[0]);
    if (pid <= 0) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Invalid PID: %s\n", cmd->argv[0]);
        return;
    }
    if (pid == 1) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Cannot kill the shell process (PID 1)\n");
        return;
    }

    for (int i = 0; i < state->process_count; i++) {
        if (state->processes[i].pid == pid) {
            // Shift remaining processes down
            for (int j = i; j < state->process_count - 1; j++) {
                state->processes[j] = state->processes[j + 1];
            }
            state->process_count--;
            print_color(COLOR_GREEN, "[OK] ");
            printf("Process with PID %d killed\n", pid);
            return;
        }
    }

    print_color(COLOR_RED, "[ERROR] ");
    printf("No process with PID %d\n", pid);
}
