#include "system_state.h"
#include <string.h>
#include <time.h>

void init_system_state(SystemState *state) {
    memset(state, 0, sizeof(SystemState));

    state->start_time = time(NULL);
    state->running = 1;
    state->next_pid = 2;  // PID 1 is reserved for shell below

    // Seed the shell as PID 1
    state->processes[0].pid = 1;
    strncpy(state->processes[0].name, "shell", sizeof(state->processes[0].name) - 1);
    strncpy(state->processes[0].state, "running", sizeof(state->processes[0].state) - 1);
    state->process_count = 1;
}
