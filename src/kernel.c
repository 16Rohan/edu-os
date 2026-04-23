#include "kernel.h"
#include "utils.h"
#include <stdio.h>

void simulate_kernel_init(SystemState *state) {
    // Initialize the shared system state
    init_system_state(state);

    print_color(COLOR_BLUE, "[KERNEL] ");
    printf("Initializing core services...\n");
    sleep_ms(300);

    print_color(COLOR_BLUE, "[KERNEL] ");
    printf("Mounting root filesystem ");
    print_color(COLOR_GREEN, "[OK]\n");
    sleep_ms(200);

    print_color(COLOR_BLUE, "[KERNEL] ");
    printf("Starting process manager ");
    print_color(COLOR_GREEN, "[OK]\n");
    sleep_ms(200);

    print_color(COLOR_BLUE, "[KERNEL] ");
    printf("Initializing file subsystem ");
    print_color(COLOR_GREEN, "[OK]\n");
    sleep_ms(200);

    print_color(COLOR_BLUE, "[KERNEL] ");
    printf("Starting task manager ");
    print_color(COLOR_GREEN, "[OK]\n");
    sleep_ms(200);

    print_color(COLOR_BLUE, "[KERNEL] ");
    printf("Waking up shell interface...\n");
    sleep_ms(400);
}
