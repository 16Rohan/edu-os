#include "boot.h"
#include "kernel.h"
#include "shell.h"
#include "system_state.h"
#include <stdio.h>

int main(void) {
    SystemState state;

    simulate_boot();
    simulate_kernel_init(&state);
    start_shell(&state);

    return 0;
}
