#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include <time.h>

#define MAX_PROCS    32
#define MAX_FILES    32
#define MAX_HISTORY  20
#define MAX_INPUT_LEN 256

typedef struct {
    int pid;
    char name[32];
    char state[16];   // "running", "sleeping", "stopped"
} Process;

typedef struct {
    char name[32];
    char content[256];
} File;

typedef struct {
    Process processes[MAX_PROCS];
    int process_count;
    int next_pid;

    File files[MAX_FILES];
    int file_count;

    char history[MAX_HISTORY][MAX_INPUT_LEN];
    int history_count;

    time_t start_time;

    int running;
} SystemState;

void init_system_state(SystemState *state);

#endif
