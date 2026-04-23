#include "filesystem.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

void cmd_ls(SystemState *state, ParsedCommand *cmd) {
    (void)cmd;
    if (state->file_count == 0) {
        printf("(no files)\n");
        return;
    }
    print_color(COLOR_CYAN, "NAME                             SIZE\n");
    for (int i = 0; i < state->file_count; i++) {
        printf("%-32s %zu bytes\n", state->files[i].name, strlen(state->files[i].content));
    }
}

void cmd_touch(SystemState *state, ParsedCommand *cmd) {
    if (cmd->argc < 1) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Usage: touch <filename>\n");
        return;
    }
    // Check if file already exists
    for (int i = 0; i < state->file_count; i++) {
        if (strcmp(state->files[i].name, cmd->argv[0]) == 0) {
            print_color(COLOR_YELLOW, "[WARN] ");
            printf("File '%s' already exists\n", cmd->argv[0]);
            return;
        }
    }
    if (state->file_count >= MAX_FILES) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("File limit reached (%d)\n", MAX_FILES);
        return;
    }

    File *f = &state->files[state->file_count];
    strncpy(f->name, cmd->argv[0], sizeof(f->name) - 1);
    f->name[sizeof(f->name) - 1] = '\0';
    f->content[0] = '\0';
    state->file_count++;

    print_color(COLOR_GREEN, "[OK] ");
    printf("File created\n");
}

void cmd_cat(SystemState *state, ParsedCommand *cmd) {
    if (cmd->argc < 1) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Usage: cat <filename>\n");
        return;
    }
    for (int i = 0; i < state->file_count; i++) {
        if (strcmp(state->files[i].name, cmd->argv[0]) == 0) {
            if (strlen(state->files[i].content) == 0) {
                printf("(empty file)\n");
            } else {
                printf("%s\n", state->files[i].content);
            }
            return;
        }
    }
    print_color(COLOR_RED, "[ERROR] ");
    printf("File not found: %s\n", cmd->argv[0]);
}

void cmd_write(SystemState *state, ParsedCommand *cmd) {
    if (cmd->argc < 2) {
        print_color(COLOR_RED, "[ERROR] ");
        printf("Usage: write <filename> <content...>\n");
        return;
    }
    for (int i = 0; i < state->file_count; i++) {
        if (strcmp(state->files[i].name, cmd->argv[0]) == 0) {
            // Concatenate all args after filename as content
            state->files[i].content[0] = '\0';
            for (int j = 1; j < cmd->argc; j++) {
                if (j > 1) strncat(state->files[i].content, " ", sizeof(state->files[i].content) - strlen(state->files[i].content) - 1);
                strncat(state->files[i].content, cmd->argv[j], sizeof(state->files[i].content) - strlen(state->files[i].content) - 1);
            }
            print_color(COLOR_GREEN, "[OK] ");
            printf("Written to %s\n", cmd->argv[0]);
            return;
        }
    }
    print_color(COLOR_RED, "[ERROR] ");
    printf("File not found: %s\n", cmd->argv[0]);
}
