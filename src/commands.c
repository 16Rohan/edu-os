#include "commands.h"
#include "process.h"
#include "filesystem.h"
#include "sysinfo.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ── Built-in handlers ─────────────────────────────────────────────── */

static void cmd_help(SystemState *state, ParsedCommand *cmd) {
    (void)state;
    (void)cmd;
    print_color(COLOR_GREEN, "EDU-OS v0.2 — Available Commands:\n\n");

    print_color(COLOR_CYAN, "  General\n");
    printf("    help       Show this help message\n");
    printf("    echo       Print text back to the terminal\n");
    printf("    clear      Clear the terminal screen\n");
    printf("    exit       End the OS session cleanly\n\n");

    print_color(COLOR_CYAN, "  Process Manager\n");
    printf("    ps         List all running processes\n");
    printf("    run        Start a fake process (run <name>)\n");
    printf("    kill       Kill a process by PID (kill <pid>)\n\n");

    print_color(COLOR_CYAN, "  File System\n");
    printf("    ls         List all files\n");
    printf("    touch      Create an empty file (touch <name>)\n");
    printf("    cat        Display file contents (cat <name>)\n");
    printf("    write      Write to a file (write <name> <text...>)\n\n");

    print_color(COLOR_CYAN, "  System\n");
    printf("    uptime     Show time since boot\n");
    printf("    uname      Show system information\n");
    printf("    whoami     Show current user\n");
    printf("    version    Show simulator version\n");
    printf("    history    Show command history\n");
}

static void cmd_echo(SystemState *state, ParsedCommand *cmd) {
    (void)state;
    for (int i = 0; i < cmd->argc; i++) {
        if (i > 0) printf(" ");
        printf("%s", cmd->argv[i]);
    }
    printf("\n");
}

static void cmd_clear(SystemState *state, ParsedCommand *cmd) {
    (void)state;
    (void)cmd;
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* ── Command table ─────────────────────────────────────────────────── */

typedef struct {
    const char *name;
    void (*handler)(SystemState*, ParsedCommand*);
} CommandEntry;

static CommandEntry command_table[] = {
    // General
    { "help",    cmd_help    },
    { "echo",    cmd_echo    },
    { "clear",   cmd_clear   },
    // Process manager
    { "ps",      cmd_ps      },
    { "run",     cmd_run     },
    { "kill",    cmd_kill    },
    // File system
    { "ls",      cmd_ls      },
    { "touch",   cmd_touch   },
    { "cat",     cmd_cat     },
    { "write",   cmd_write   },
    // System info
    { "uptime",  cmd_uptime  },
    { "uname",   cmd_uname   },
    { "whoami",  cmd_whoami  },
    { "version", cmd_version },
    { "history", cmd_history },
    { NULL,      NULL        }
};

/* ── Dispatcher ────────────────────────────────────────────────────── */

int execute_command(SystemState *state, ParsedCommand *cmd) {
    if (cmd->name == NULL || strlen(cmd->name) == 0) {
        return 1;  // Empty input, keep running
    }

    // Check for exit (and alias "quit")
    if (strcmp(cmd->name, "exit") == 0 || strcmp(cmd->name, "quit") == 0) {
        return 0;
    }

    // Lookup in command table
    for (int i = 0; command_table[i].name != NULL; i++) {
        if (strcmp(cmd->name, command_table[i].name) == 0) {
            command_table[i].handler(state, cmd);
            return 1;
        }
    }

    print_color(COLOR_RED, "[ERROR] ");
    printf("Unknown command: %s\n", cmd->name);
    return 1;
}
