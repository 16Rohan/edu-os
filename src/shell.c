#include "shell.h"
#include "parser.h"
#include "commands.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

static void add_to_history(SystemState *state, const char *line) {
    if (state->history_count < MAX_HISTORY) {
        strncpy(state->history[state->history_count], line, MAX_INPUT_LEN - 1);
        state->history[state->history_count][MAX_INPUT_LEN - 1] = '\0';
        state->history_count++;
    } else {
        // Shift history up, drop oldest
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            strncpy(state->history[i], state->history[i + 1], MAX_INPUT_LEN);
        }
        strncpy(state->history[MAX_HISTORY - 1], line, MAX_INPUT_LEN - 1);
        state->history[MAX_HISTORY - 1][MAX_INPUT_LEN - 1] = '\0';
    }
}

void start_shell(SystemState *state) {
    char input[MAX_INPUT_LEN];
    char history_copy[MAX_INPUT_LEN];  // strtok in parser mutates the buffer
    ParsedCommand cmd;

    print_color(COLOR_CYAN, "\nEDU-OS v0.2 (Educational Build)\n");
    printf("Type 'help' to begin.\n\n");

    while (state->running) {
        print_color(COLOR_YELLOW, "edu-os> ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
            break;  // EOF or error
        }

        // Save a clean copy for history before parser mutates it
        input[strcspn(input, "\r\n")] = '\0';
        strncpy(history_copy, input, MAX_INPUT_LEN);

        // Skip blank lines for history
        if (strlen(history_copy) > 0) {
            add_to_history(state, history_copy);
        }

        parse_input(input, &cmd);

        if (execute_command(state, &cmd) == 0) {
            state->running = 0;
        }
    }

    print_color(COLOR_CYAN, "System halting...\n");
}
